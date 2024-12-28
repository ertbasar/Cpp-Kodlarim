/* C++ ile move semantics'in biraz da emri altında bulunmak üzere iki adet yeni fonksiyon gelmekte. Bunlar da moce constructor ve move assignment oluyor.
Bu iki fonksiyonun amacı, bir objeden diğer objeye kaynaksal sahipliğin transfer işlemlerinde bulunmak denebilir. Bu fonksiyonların copy versiyonlarında
parametre const l-value reference olmasına rağmen, burada artık parametreler non-const r-value reference haline dönüyor. Move constructor ve assignment
aslında mantıksal olarak basit işlemler. Aynı objeyi deep copy yapmak yerine, bu kopyalanacak objenin verilerini çalıyoruz denebilir :) Aslında shallow
copy yapıp daha sonrasında kaynak objeyi sıfırlamak gibi bir şey olarak nitelendirilebilir. Burada bu fonksiyonları yazarken noexcept anahtar sözcüğünü
es geçmemek önemli, fonksiyonların exception yollamayacağını özellikle belirtir. Bu fonksiyonlar tanımlandıklarında, ve de construction veya assignment
için r-value kullanıldığında çağrılırlar. Bunlar da tabii genelde literal veya geçici objeler olurlar. Derleyici de aşağıdaki şartların hepsi sağlanırsa
implicit olarak move assignment ve move constructor oluşturur. Bu implicit olarak tanımlanan fonksiyonlar da aslında memberwise transfer işlemi yapar.
1. Kullanıcı tarafından tanımlanmış copy constructor veya copy assignment yok
2. Kullanıcı tarafından tanımlanmış move constructor veya move assignment yok
3. Kullanıcı tarafından tanımlanmış destructor yok
Mmove fonksiyonları, üzerlerinde işlem yapılan tüm objeleri geçerli bir halde bırakmalı. Çünkü bir obje scope dışına çıktığında destructor çağrılır, bu
durumda da o objenin içerisindeki tahsis edilen bellek sisteme geri verilir. Eğer bu objenin içindeki bir pointer, başka bir objenin içindeki pointer ile
aynı yeri gösteriyorsa sıkıntı olur. Bu arada bazı durumlarda, eğer geri dönüş türü olarak auto belirlenmişse, bu objeler ne kadar l-value olsalar da 
transfer (move) işlemi içerisine girebilirler. Bu sayede zaten silinecek bir bölgeyi kopyalamak yerine sadece sahipliği transfer edilebilir. 
Bazı move işleminin dahil edildiği sınıflarda copy assignment ve constructor delete edilerek bu fonksiyonlara hiç girilmemesinden emin olunabilir. 
Bunlar da şu ifadelerle gerçekleştirilir -> Auto_ptr5(const Auto_ptr5& a) = delete; Auto_ptr5& operator=(const Auto_ptr5& a) = delete;
Aynı zamanda move assignment ve move constructor da silinebilir. Zaten copy constructor'u silersek derleyici kendiliğinden move constructor da oluşturmaz.
Bu durumda ne istediğimizi ve beklediğimizi belirtmek biraz önemli, buna göre de işlemleri gerçekleştirmemiz gerekli. 
'The rule of 5' veya '5 kuralı' olarak bilinen kural aslında burada önemli. Bu kural der ki, move cons. ve asg. copy cons. ve asg. ile destructor'dan biri
tanımlanmış veya silinmişse, geri bu 5'linin hepsi kullanıcı tarafından tanımlanmalı veya silinmeli. Aslında çok iyi bir kural denebilir, direkt bizim
amacımız neyse bunu derleyiciye aktarmamıza yardımcı oluyor. 
Kolaya kaçma adına move cons. ve asg.'yi std::swap ile tanımlamaya çalışmak sıkıntılı olabilir, çünkü swap da move işleminin gerçekleştirilebileceği 
objelerde move cons. ve asg.'yi kullanır. Ancak burada sonsuz bir yineleme sorunu olabilir. Bunu engelleme adına eğer bu şekilde bir tanımlama yapılmak
isteniyorsa kendi swap fonksiyonumuzu içinde move cons. ve asg. olmadan tanımlayıp onu mantıklı iyi olabilir. Ben her türlü uzak durmak iyi derim :)
Copy tarafında kullandığım kodları kopyalayıp biraz ekleme yapalım :)
*/


#include <iostream>


class Coordinates{
private:
    int* m_x{};
    int m_y{};
public:
    // 2 farklı constructor tanımı
    Coordinates() : m_x{new int{}} {std::cout << "Default cons. çağrıldı" << std::endl;}
    Coordinates(int x, int y):m_x{new int{x}},m_y{y}{std::cout << "Parametreli cons. çağrıldı" << std::endl;}
    
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
        std::cout << "copy cons. çağrıldı" << std::endl;
        deepCopy(source);
    }

    // copy assignment. ilk self-assignment olup olmadığına baktık sonra kopyaladık
    Coordinates& operator=(const Coordinates& source){
        std::cout << "copy asg. çağrıldı" << std::endl;
        if(this != &source)
            deepCopy(source);
        return *this;
    }

    // Move constructor
    Coordinates(Coordinates&& source) noexcept : m_x{source.m_x}, m_y{source.m_y}{
        std::cout << "move cons. çağrıldı" << std::endl;
        source.m_x = nullptr;
    }

    // move assignment
    Coordinates& operator=(Coordinates&& source) noexcept {
        std::cout << "move asg. çağrıldı" << std::endl;
        if(this == &source)
            return *this;
        delete m_x;
        m_y = source.m_y;
        m_x = source.m_x;
        source.m_x = nullptr; 
        return *this;
    }

};

int main(){
    // Değişkenlerin tanımlanması
    Coordinates co1(3,9);
    Coordinates co2(2,4);
    // Değişken bilgilerinin ilk olarak yazdırılması
    co1.print();
    co1.printAdr();
    co2.print();
    co2.printAdr();
    co2 = co1;
    co2.print();
    co2.printAdr();
    std::cout << "Buradan itibaren move ile alakalı kısım başlıyor!" << std::endl;
    // Move assignment çağrılır
    co2 = Coordinates{5,7};
    co2.print();
    co2.printAdr();
    // Bir de move constructor çağıralım
    // Aslında aşağıda move cons. çağrılacağı düşünülse de bu gerçekleşmez. Coordinates{10,20}; geçici bir obje olduğundan dolayı Copy Ellision ve de 
    // RVO (Return Value Optimization) devreye girer. Bu optimizasyondan dolayı derleyici move constructor'u çağırmak yerine temporary nesneyi doğrudan 
    // co3 içinde oluşturabilir. Eğer copy elision veya RVO kullanılıyorsa, move constructor çağrılmaz diyebiliriz. 
    Coordinates co3 = Coordinates{10,20};
    co3.print();
    co3.printAdr();    

    // Bu std::move konusunu az sonra göreceğiz. Move constructor'u zorla çalıştırıp fonksiyonu bi denedim :)
    Coordinates co4{std::move(co1)};
    co4.print();
    co4.printAdr();   
    return 0; 
}






