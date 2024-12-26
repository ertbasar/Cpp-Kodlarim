/* C++ genel olarak sınıflar hakkında pek de bir bilgiye sahip olmadığından dolayı, default copy constructor ve de default assignment operatörleri shallow
(memberwise) copy işlemi gerçekleştirirler. Bu da her bir elemanın teker teker kopyalanması işidir. Burada sınıf nispeten basit, ve de herhangi bir dinamik
olarak bellek tahsis edilmiş olmadığı zaman güzelce çalışır. Ancak dinamik olarak bellek tahsis edilen sınıflarda bu shallow copy işlemi bizi sıkıntıya
sokar. Çünkü burada pointerlar kopyalanırken, direkt olarak gösterdiği adresi kopyalar, yeni bir bellek tahsisi yapmadan eski alanı kullanmaya devam eder.
Burada özellikle kopyalama işlemi gerçekleştirildikten sonra scope alanı dışına çıkan bir obje destruct edilirse, kopyalanmış objedeki pointerlar direkt
olarak dangling pointer durumuna düşer. Burada kullanabileceğimiz kopyalama türü de deep copy olur. Deep copy, ilk olarak kopyalama işlemi için yeni bir
bellek alanı tahsis eder, daha sonrasında da bilgileri kopyalar. Bu şekilde kaynak ve kopya objeler farklı bellek alanlarına sahip olurlar ve birbirlerini
etkilemezler. Bunun gerçekleşmesi için de kendi copy constructor ve de operator= overload tanımlamalarımızı yapmamız gerekir. 
Aşağıdaki örnekte assignment operatörü ve copy constructor arasındaki üç fark:
1. self-assignment mı diye bir if bloğu
2. geri dönüşte *this kullanımı ki zincirleme yapalım
3. önceden önceden kalan bir bellek tahsisi varsa diye bellek sızıntısı olmaması adına delete işlemi
Standart kütüphane içerisindeki vektör ve string gibi dinamik olarak bellek tahsisi yapan objelerin kendi copy assignment ve de copy constructoları
kendiliğinden tanımlanmış halde zaten bulunur. Burada kendimiz yeniden yazmak yerine, buradaki kendiliğinden tanımlanmış yapılar sayesinde bu değikenleri
normal değişkenlermiş gibi kullanabiliriz. 
*/

#include <iostream>


class Coordinates{
private:
    int* m_x{};
    int m_y{};
public:
    // 2 farklı constructor tanımı
    Coordinates() : m_x{new int{}} {}
    Coordinates(int x, int y):m_x{new int{x}},m_y{y}{}
    
    // destructor tanımı
    ~Coordinates() {
        delete m_x;
    }

    // yazdırma fonksiyonu
    void print(){
        std::cout << "x: " << *m_x << std::endl; 
        std::cout << "y: " << m_y << std::endl; 
    }

    void printAdr(){
        std::cout << "Address for: " << std::endl;
        std::cout << "x: " << m_x << std::endl; 
        std::cout << "y: " << &m_y << std::endl; 
    }
    void setX(int x){
        *m_x = x;
    }
    void setY(int y){
        m_y = y;
    }

    // operator= overload işlemi. shallow copy olan örnek
    /*
    Coordinates& operator=(const Coordinates& coord){
        // ilk olarak self-assignment olup olmadığı kontrol edilir.
        if(this == &coord)
            return *this;

        // sırayla kopyalama işlemleri yapılır
        *m_y = *coord.m_y;
        m_x = coord.m_x;

        // en sonunda *this döndürürüz ki zincirleme işlemler de yapılabilsin
        return *this;
    }
    */
   
    // deep copy işlemi. burada copy kısmını assignment ve de constructor için kullanabileceğimiz şekilde ayarlıyoruz. Geri dönüşe gerek yok işlem direkt
    // olarak obje üzerinden gerçekleştiriliyor zaten
    void deepCopy(const Coordinates& source){
        // m_x dinamik bellek tahsis edilmiş bir değişken. Belleği sisteme geri verelim
        delete m_x;
        // m_y zaten normal değişken, dümdüz kopyala
        m_y = source.m_y;
        // source objesi içerisindeki m_x nullptr değilse eğer yeni bir alan tahsis et ve değeri kopyala, yoksa nullptr yap
        if(source.m_x){
            m_x = new int;
            *m_x = *source.m_x;
        }
        else 
        m_x = nullptr;
    }

    // copy constructor
    Coordinates(const Coordinates& source){
        deepCopy(source);
    }

    // assignment operator. ilk self-assignment olup olmadığına baktık
    Coordinates& operator=(const Coordinates& source){
        if(this != &source)
            deepCopy(source);
        return *this;
    }

};

int main(){
    Coordinates co1(3,9);
    Coordinates co2(2,4);

    co1.print();
    co1.setX(5);
    co1.print();
    co1.printAdr();
    co2.print();
    co2.printAdr();
    co2 = co1;
    co2.print();
    co2.printAdr();

    return 0; 
}
