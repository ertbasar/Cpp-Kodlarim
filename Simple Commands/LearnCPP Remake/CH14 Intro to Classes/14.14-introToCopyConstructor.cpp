/* Copy constructorlar, zaten olan bir objeyi kopyalayarak üzerinden yeni bir obje oluşturmak istediğimizde kullanabileceğimizde kullandığımız fonksiyonlardır.
Zaten biz özellikle belirtmesek bile derleyici otomatik olarak bu işlemi gerçekleştirir. Ancak kendimiz de tanımlayabiliriz.
Copy constructorların kopyalama dışında pek de bir işi olmamalı ve de gerekli olmadıkça kendimiz yazmamıza gerek yok.
Eğer kendi copy constructorumuzu yazacaksak gelen obje const ref ile alınmalı.
*/

#include <iostream>

class Foo{
    int m_id;
    std::string m_name;
    public:
    Foo(int id, std::string_view name): m_id{id}, m_name{name}{std::cout << "Bir Foo objesi oluşturuldu" << std::endl;}
    
    //Copy constructor tanımlanması. 
    Foo(const Foo& foo):m_id{foo.m_id}, m_name{foo.m_name}{std::cout << "Bir Foo objesi kopyalanarak oluşturuldu" << std::endl;}
    
    void print(){std::cout << "Objenin \nID: " << m_id << "\nObjenin Adı: " << m_name << std::endl;}

    // Eğer copy işleminin gerçekleşmesini istemiyorsak
    //Foo(const Foo& foo) = delete;

    // Eğer derleyicinin oluşturacağını kullanacaksak
    //Foo(const Foo& foo) = default;
};


int main(){
    Foo doo{23, "Ertugrul"};
    doo.print();
    Foo goo{doo};
    goo.print();
    return 0;
}