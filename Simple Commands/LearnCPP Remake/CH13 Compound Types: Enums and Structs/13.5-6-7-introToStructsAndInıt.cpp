/* Struct yani yapılar tek tür içerisinde farklı değişkenleri tanımlamamıza yarayan türdür. Burada yapıların içindeki değişkenlere üye (member) denir.
Bu üyelere de üye seçim opeartörü (member selection operator) ile . kullanılarak erişilir.
Struct tanımı yapılırken de normal değişkenler gibi default olarak init edilmezler. Bu yüzden toplu init yapmak gerekir. Örneği de tabii aşağıda :)

*/

#include <iostream>
// Basit bir struct tanımlanması
struct Employee{
    int id{};
    int age{};
    double wage{};
};

// Fonksiyonlarda olduğu gibi yapılarda da default olarak üyeye bir değer verebiliriz. Tabii özellikle init yapıldığında bu default değerlerin bi önemi kalmaz
struct Foo{
    int y{};
    int z{22};
};
int main(){
    // Tanımlama türleri
    Employee frank = {1, 32, 6000.0}; // Copy-list init
    Employee joe{2, 25, 3000.0}; // list init (preferred)
    Employee dave{3, 29}; // wage = 0
    Employee john{}; // tüm üyeler value-init 
    // Bir yapı kendisiyle aynı tür bir yapı ile de init edilebilir.
    Employee z{frank};
    std::cout << "Frank's ID is " << frank.id << std::endl;

    Foo goo{23};
    std::cout << "goo's z is " << goo.z << std::endl;

    return 0;
}
