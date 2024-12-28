/* C++11'le beraber gelen std::move, bir argümanı alıp, onu r-value reference'a çeviren, ve bu sayede move semantics'i aktif etmemize yarayan bir standart
kütüphane fonksiyonudur. <utility> altında bulunur. Konteynır yapılarla beraber kullanılabilir olması da fazlasıyla işe yarar bir özelliktir. Bunun örneği
aşağıda olur. std::move kullanımı aslında derleyiciye bu değişkenin içerisindeki değerlerin artık kullanımına pek de ihtiyaç olmadığını belirtir, bu 
yüzden bir obje bu şekilde transfer edildikten sonra bu objeyle alakalı özellikle de içinde barındırdıklarıyla alakalı pek de bir düşünce içinde 
bulunmamak önemli denebilir. std::move bir dizide sıralama yaptığımız (sort) veya bir smart pointer'dan diğerine bilgileri transfer ettiğimiz
durumlarda da işe yarar. Az önceki örneği baz alaraktan kodu daha da geliştirelim :)
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
    std::cout << "Buradan itibaren std::move ile alakalı kısım başlıyor!" << std::endl;  


    // Aslında aşağıda move cons. çağrılacağı düşünülse de bu gerçekleşmez. Coordinates{10,20}; geçici bir obje olduğundan dolayı Copy Ellision ve de 
    // RVO (Return Value Optimization) devreye girer. Bu optimizasyondan dolayı derleyici move constructor'u çağırmak yerine temporary nesneyi doğrudan 
    // co3 içinde oluşturabilir. Eğer copy elision veya RVO kullanılıyorsa, move constructor çağrılmaz diyebiliriz. 
    Coordinates co3{Coordinates{10,20}};
    co3.print();
    co3.printAdr();   

    // std::move ile geçici objenin ilk olarak rref'e dönüştürülmesi ve sonrasında move constructor'un kullanımı denebilir ancak burada da ilk olarak
    // Coordinates{10,20} kısmı için parametreli cons. çağrılır, sonrasında std::move ile rref'e döndürülür ve son olarak transfer işlemi yapılır
    Coordinates co4{std::move(Coordinates{12,24})};
    co4.print();
    co4.printAdr();   

    // std::move ile l-value'nin rref'e dönüştürülmesi ve de move işlemine hazır hale getirilmesi
    Coordinates co5{std::move(co3)};
    co5.print(); // Değerler co3 ile aynı
    co5.printAdr(); // Yukarıdaki co3 yazımı ile m_x adresi aynı (bellek tahsisi yapılmıştı), m_y adresi farklı olur.  
    return 0; 
}
