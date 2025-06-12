/* C++'da inheritence (kalıtım) konusu aslında OOP kavramının en temel ögelerinden biridir. Composition tarafında bir objenin içinde diğer
objeleri oluşturaak kullanmak yerine burada direkt olarak başka bir objenin özelliklerini kendi içine yansıtarak almak gibi düşünülebilir.
Burada kalıtımı yapılan sınıfa base veya parent class denirken oluşturulan yeni sınıfa ise child veya derived class diyebiliriz. 
Burada çok katlı kalıtım yapabiliriz. Bunu yaparken ilk olarak en baz sınıftan en türetilmiş sınıfa kadar sırayla oluşturulur. 

Aşağıda basit bir kalıtım kullanımı yapalım. (Private değişkeni şimdilik kullanmayacağım)
*/

#include <iostream>

class Person{
    public:
    std::string m_name{};
    int m_age{};
};

// Basit bir kalıtım gösterimi. Sınıf adından sonra : koyup public vs. olarak diğer sınıfın ismini yazıyoruz (İleride değinilecek)
class Employee : public Person{
    public:
    int m_salary{};
    long m_ID{};
};

// Şu an Supervisor sınıfı hem Employee, hem de onun kalıtımını gerçekleştirdiği Person sınıfının özelliklerine sahip oldu.
// Bu tür zincirleme kullanımlarla beraber genel ve yeniden kullanılabilir temel sınıflar tanımlayıp işimizi kolaylaştırabiliriz.
class Supervisor : public Employee{
    public:
    int m_teamID{};
};

int main(){

    Supervisor s{};
    // Görüldüğü üzere en temel sınıf olan Person sınıfına ait kalıtımı en alttaki Supervisor sınıfının bir objesinde kullanabildik.
    s.m_age = 45;
    s.m_ID = 2123;
    s.m_name = "Ertugrul";

    std::cout << s.m_age << " " << s.m_ID << " " << s.m_name << "/n";
    return 0;
}


