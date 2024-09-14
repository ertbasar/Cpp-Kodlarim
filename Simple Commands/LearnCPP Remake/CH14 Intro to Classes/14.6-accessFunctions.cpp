/* Erişim fonksiyonları, basit public üye fonksiyonlarıdır. İşleri tamamen private olan verilerin getirilmesi veya  değiştirilmesidir. Bu işlemin direkt 
olarak değişken üzerinden erişmememizi sağlarlar. getter ve setter olarak 2 türü vardır denebilir ve getterlar genelde -bir değişim de gerçekleştirmeyeceğinden
ötürü ve de const objeler tarafından da erişilebilmesi için- const olarak tanımlanırlar.
Getterlar ayrıca read-only erişim sağlamaları gerektiğinden ya by value (sınıf pahalı değilse) ya da by const lvalue reference ile geri dönüş yapmalıdırlar.
*/

#include <iostream>
class Foo{
    int m_id{};
    public:
    // Getter
    int getID()const {
        return m_id;
    }
    // Setter
    void setID(int a){
        m_id = a;
    }
    // print fonksiyonu
    void printID(){
        std::cout << m_id << std::endl;
    }
};


int main(){
    Foo goo;
    // goo.m_id = 321; // hata verir çünkü erişim yok. private bir üye
    goo.setID(55); // Bu şekilde set ediyoruz
    std::cout << "goo'nun id'si: " << goo.getID() << std::endl; // Bu şekilde get edebiliriz
    
    goo.printID(); // ya da direkt fonksiyon üzerinden işlemleri gerçekleştirebiliriz
    
    return 0;
}




