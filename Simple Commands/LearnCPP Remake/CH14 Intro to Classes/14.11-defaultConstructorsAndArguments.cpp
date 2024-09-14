/* Default constructorlar objeyi tanımlarken hiçbir parametre vermediğimiz zamanlarda çağrılırlar. 
Constructorlar aslında birer fonksiyon olduklarından ötürü overload edilebilirler Farklı sayıda ve tanımda constructor oluşturabiliriz
Eğer biz kendimiz oluşturmazsak, derleyici bizim yerimize public default constructor oluşturur
Bu yüzden sadece gerçekten bir amaca uygunsa kendimiz default constructor yazalım
Fonksiyonlara benzer şekilde default argümanları olan constructorlar da yazılabilir.
*/

#include <iostream>
#include <string>
class Foo{
    std::string m_name{};
    int m_id;
    public:
    // print fonksiyonumuz
    void print() const{
        std::cout << "ID: " << m_id << std::endl;
        std::cout << "Name: " << m_name << std::endl;
    }
    Foo(std::string_view name, int id): m_name{name}, m_id{id}
    {
        std::cout << "Bir adet Foo objesi oluşturuldu." << std::endl;
    }

    //Default constructor, parametresi yok görüldüğü üzere.
    Foo(): m_name{"Tanımlanmamış"}, m_id{0} // initte default argümanlar verdik. vermezsek bazı random değerler atanabilir
    {
        std::cout << "Bir adet default Foo objesi oluşturuldu." << std::endl;
    }

    // Kendi yazdığımız default constructor derleyicinin yazdığıyla aynı olacaksa aşağıdaki belirtmeyi yapmak iyidir (boş bodyli bizim yazdığımızdansa) 
    //Foo () = default; // Redeclare diyeceğinden yoruma aldım

    // Default argümanı ola constructor
    Foo(int x): m_name{"Tanımlanmamış"}, m_id{x} // initte default argümanlar verdik. vermezsek bazı random değerler atanabilir
    {
        std::cout << "Bir adet default argümanlı Foo objesi oluşturuldu." << std::endl;
    }
};

int main(){
    Foo goo{"Ertugrul", 55}; // Belirlenen sırayla değerlerin verilmesi
    goo.print();

    const Foo loo{}; // Default constructor çağrılması
    loo.print();

    Foo coo{30}; // Default argümanı olab constructorun çağrılması
    coo.print();
    return 0;
}