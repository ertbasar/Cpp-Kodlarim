/* Bu chapterın başında aptal pointerların kullanımının buglara neden olabileceğini ve bazı durumlarda da bellek sızıntısına neden olabileceğini 
incelemiştik. C++11 standart kütüphane ile birlikte de 4 adet smart pointer bulunmakta: auto_ptr, unique_ptr, shared_ptr ve weak_ptr. C++17 ile beraber
auto_ptr kullanımdan kalktı ancak benzerlerini bu chapter'da birkaç kez gördük. unique_ptr de zaten C++11 ile beraber auto_ptr'nin yerine gelen bir 
pointer türü diyebiliriz. Farklı objeler tarafından paylaşılmayan ve dinamik bellek tahsisi yapan objeler için kullanılmalıdır. Objenin %100 sahibi
olmalıdır, başka sınıflarla paylaşmamalıdır. <memory> altında bulunur. auto_ptr'nin aksine move semantics'i tam anlamıyla içinde barındırır. Hatta
unique_ptr özellikle move semantics'i barındırma anlamıyla tasarlandığından copy init ve assignment işlemleri engellenmiştir, move semantics kullanımı
zorunludur. Kendiliğinden overload edilmiş operator* ve operator-> fonksiyonları da mevcuttur. İçindeki verilere erişimde kullanılabilir. 
Bir unique_ptr her zaman bir objeyi yönetiyor olmayabilir. Bir işlem yapmadan önce bunun test edilmesi yararımıza olur. Auto_ptr'nin aksine unique_ptr
içinde skalar veya dizisel delete işlemi yapılıp yapılmayacağını bilebilir, ancak yine de burada pointer yerine std::array veya vektör kullanımının
tercihi smart pointerdan daha iyi olabilir. C++14'ten itibaren std::make_unique() fonksiyonu tanımlanmıştır. Bu şablon fonksiyon verilen türe göre
dinamik bir obje oluşturur. Direkt olarak unique pointer oluşturmak ve new anahtar sözcüğünü kullanmak yerine make_unique kullanmak daha iyidir.
unique_ptr'ler fonksiyonların geri dönüş türü olarak güvenli bir şekilde kullanılabilirler, ancak genel olarak by reference veya by pointer döndürmemek
gerekli diyebiliriz. Şimdi bu konuda biraz daha derine inmek istiyorum. Eğer bir fonksiyon bir unique_ptr döndürüyorsa:
1. Dönen unique_ptr bir geçici nesne olarak oluşturulur ve eğer bu değer bir değişkene atanmazsa, geçici nesne yok edilir. Ve bu durumda unique_ptr'ın
sahip olduğu kaynak otomatik olarak serbest bırakılır.
2. Fonksiyonun döndürdüğü unique_ptr bir değişkene atanırsa ve C++14 ve öncesiyse geçici unique_ptr'daki kaynak, unique_ptr'ın move constructor'ı 
aracılığıyla yeni işaretçiye taşınır. Geçici nesne artık kaynağı yönetmez.
3. Fonksiyonun döndürdüğü unique_ptr bir değişkene atanırsa ve C++17 ve sonrasıysa kaynak direkt olarak hedef nesneye yerleştirilir (move bile gerekmez).
Geçici nesne yaratılmadan optimize edilir.
Eğer bir fonksiyonun pointer'ın elemanlarına sahiplik de yapmak istiyorsan unique_ptr'yi fonksiyona değeriyle beraber gönderebilirsin. Burada kullanım
sırasında  std::move da kullanmak gerekli çünkü copy assignment ve init burada engelleniyor. Ancak şöyle bir durum var ki bu işlem çok sıkıntılı çünkü
fonksiyon bittiği zaman transferin yapıldığı objenin scope alanı bitiyor ve bu yüzden kullanılmaya devam edilmek istenen objenin içerisinde hiçbir şey
kalmıyor. Bu yüzden fonksiyona smart değil de dumb pointer göndermeyi tercih ediyoruz. unique_ptr'den raw (dumb) pointer elde etmek için get() üye
fonksiyonu kullanılabilir. Bu arada bu unique_ptr'leri sınıflarımızın içinde de tanımlayabiliriz. Bu sayede sınıfın destructor'unun tahsis edilen dinamik
alanı geri sisteme verdiğinden emin oluruz. Sadece sınıf objesinin de dinamik olarak ayarlandığı ve geri sisteme verilmediği taktirde beklenen şekilde
sızıntı olabilir. unique_ptr'leri yanlış şekilde kullanmak için aslında iki tane yol var diyebiliriz:
1. Birden fazla objenin aynı kaynağı yönetmesi (mantık olarak sorun olmasa da parçalanmada delete sırasında aynı yer iki defa delete yapılmaya çalışılır)
2. Manuel olarak silme işlemini yapmak (unique_ptr, bir nesneyi sahiplenir ve scope dışına çıktığında, otomatik olarak delete çağırarak nesnenin 
belleğini serbest bırakır. İki kere delete olmuş olur bu da istenmeyen davranışlara yol açabilir.)
*/

#include <iostream>
#include <memory>
#include <utility>

// işlemlerde kullanmak amacıyla basit bir sınıf tanımlayalım
class Coordinates{
private:
    int m_x{};
    int m_y{};
public:
    Coordinates(){
    std::cout << "Coordinates objesi default cons. ile oluşturuldu." << std::endl;
    }; 
    Coordinates(int x, int y):m_x{x},m_y{y}{
        std::cout << "Coordinates objesi paramtreli cons. ile oluşturuldu." << std::endl;
    }
    ~Coordinates(){std::cout << "Coordinates objesi parçalandı" << std::endl;}
    friend Coordinates operator+(const Coordinates& c1, const Coordinates& c2);
    void print(){
        std::cout << "x: " << m_x << std::endl; 
        std::cout << "y: " << m_y << std::endl; 
    }
    int getX() const{
        return m_x;
    }
    void setX(int x){
        m_x = x;
    }
};

// Fonksiyon geri dönüş türü olarak unique_ptr
std::unique_ptr<Coordinates> createCoordinates(const int& x = 0, const int& y = 0){
    return std::make_unique<Coordinates>(x,y);
}

// Aşağıda kötü bir fonksiyon kullanımı olacak. Fonksiyon sahipliği üstlenecek ve sonunda delete yaptığından sıkıntı çıkacak
void sahipCoordinates(std::unique_ptr<Coordinates> coord){
    if(coord)
        coord->getX();
}

// Aşağıdaki fonksiyon kullanımı iyi, unique_ptr içindeki Coordinates objesinin pointer değeriyle fonksiyona girilecek, tüm unique_ptr olarak değil
// Bu sayede de fonksiyonun sonunda bu smart pointer objesi parçalanmayacak. Bunun için de Coordinates* türünden bir adet parametre alacağız.
void kullanCoordinates(Coordinates* coord, const int& x = 25){
    if(coord)
        coord->setX(x);
}

int main(){
    std::cout << "Den1" << std::endl;
    // unique pointer değişkeni tanımlanması 1. yol -> std::unique_ptr<obje_türü> değişken_adı{new obje_türü{varsa init değeri}}
    std::unique_ptr<Coordinates> den1{new Coordinates{3,5}};

    std::cout << "Den2" << std::endl;
    // unique pointer değişkeni tanımlanması 2. yol (tercih edilmesi gereken) -> auto değişken_adı{std::make_unique<obje_türü>(varsa init değeri)}
    // Dikkat: bu şekilde yapacaksan init edilen değerleri {} yerine () ile vermelisin
    auto den2{std::make_unique<Coordinates>(3, 5)};

    std::cout << "Den3" << std::endl;
    // unique pointer ile bir diziye benzer yapı da oluşturabiliriz. Ancak direkt atama işlemi burada yapamayız.
    auto den3{std::make_unique<Coordinates[]>(4)}; 
    
    // Elemanları teker teker dolaşarak 3,5 girişi yaptık
    for (int i = 0; i < 4; ++i) {
        *(den3.get() + i) = Coordinates(3, 5); 
    }
    
    std::cout << "Den4" << std::endl;
    // Fonksiyondan geri dönen değerin kullanılması. Zaten büyük ihtimalle derleyici burada return by value yerine direkt olarak den4'e yazar.
    auto den4{createCoordinates(55,55)};
    
    std::cout << "sahipCoordinates" << std::endl;
    // sahipCoordinates fonksiyonu çağrımı
    // sahipCoordinates(den4); // Hata verir, özellikle silinmiş olan copy constructor çağrıldı der.
    sahipCoordinates(std::move(den4));
    // den4 şu an parçalanmış (çağrılan fonksiyonun sonunda parçalandı) durumda. Erişimi sakıncalı bir durumda
    
    std::cout << "kullanCoordinates" << std::endl;
    // kullanCoordinates fonksiyonu çağrımı. Artık bir pointer obje olduğundan operator. yerine operator-> kullanılıyor
    den2->print();
    kullanCoordinates(den2.get(), 23); // den2.get() ile fonksiyona den2'nin içindeki bilgilerin saklandığı yerin pointerını gönderdik
    den2->print(); // x = 23 değişmesini bekliyoruz
    std::cout << "son" << std::endl;

    return 0;
}