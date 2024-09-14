/* Kod yazarken genel olarak yazılması gereksiz kodu azaltmaya çalışırız. Aynı zamanda da genel olarak sınıflar çok fazla sayıda overload edildiklerinden
gereksiz bazı kod yazımı ortaya çıkabilir. Burada da bir constructor üzerinden diğer constructoru kullandığımız bir temsil işlemi gerçekleşebilir.
Bu da üye init listesi kısmında constructor çağrılarak yapılır
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

    // Temsil içeren constructor. Burada ilk önce ne kadar name değişkeni main'den versek de burada ilk başka bir obje oluşturulup geri buraya gelir ve
    // init edilir
    Foo(std::string_view name): Foo{name, 0}
    {
        std::cout << "Bir adet default temsil kullanan Foo objesi oluşturuldu." << std::endl;
    }
};

int main(){
    Foo goo{"Ertugrul", 55}; // Belirlenen sırayla değerlerin verilmesi
    goo.print();

    Foo coo{30}; // Default argümanı olab constructorun çağrılması
    coo.print();

    // Aşağıdaki işlemi yapınca iki farklı constructordan mesaj yazılacak
    Foo doo{"Caner"};
    doo.print();
    return 0;
}