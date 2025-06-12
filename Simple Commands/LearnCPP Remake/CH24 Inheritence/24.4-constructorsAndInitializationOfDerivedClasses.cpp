/* Türetilmiş sınıfları init ederken baz sınıfların da istediğimiz şekilde init edilmesini isteriz. Önceki örnekte bu yoktu ki zaten tüm değişkenler
public olarak tanımlanmıştı. Bu sefer private değişkenler kullanalım ve baz sınıfın init edilmesini sağlayalım. Bunu yapmak için de türetilmiş sınıfın
kendi constructor'ında baz sınıfın constructor'ını çağırmamız gerekir. Bu, türetilmiş sınıfın constructor'ında bir parametre olarak baz sınıfın 
constructor'ına gerekli argümanları geçerek yapılır. 
Constructorlar sadece kendi alt/üst sınıflarıyla iletişime geçebileceğinden ötürü zincirde dikkat edilmeli. 
Destructorlar çağrıldığında da constructorların tam tersi şekilde en türetilmiş sınıftan başlayarak bu işlemler yapılır. Burada önemli olan kısım
eğer baz sınıfın virtual fonksiyonu varsa destructoru da virtual olmalıdır (İleride incelenecek). Eğer belirtme yapılmazsa default constructor
kullanılır. 
*/

#include <iostream>

class Person{
    private:
    std::string m_name{};
    int m_age{};
    public:
    Person(std::string_view name = " ", int age = 0) : m_name{name}, m_age{age} {
        std::cout << "Person objesi oluşturuldu. Yaş: " << this->getAge() << "\n";
    }
    std::string_view getName() {return m_name;}
    int getAge() {return m_age;}
};


class Employee : public Person{
    private:
    int m_salary{};
    long m_ID{};
    public:
    // Görüldüğü üzere baz sınıfın constructoru da türetilen sınıftan çağrıldı
    Employee(int salary = 0, long ID = 0, std::string_view name = " ", int age = 0) : Person{name, age}, m_salary{salary}, m_ID{ID} {
        std::cout << "Employee objesi oluşturuldu. İsim: " << this->getName() << "\n";
    }
};

int main() {
    
    Employee e{15, 23, "Ertugrul", 26};
    return 0;
}
