/* Bir önceki yaptığımız örnekteki olduğu gibi private üyelere eşitleme de yapabiliriz ancak daha iyi bir yöntem var.
Burada aşağıdaki kullanımı yapmak eşitlemektense daha iyi. 
Dikkat edilmesi gereken şeylerden biri init listteki değişkenlerin sırasının tanımlandığı sırada kullanılması gerektiği.
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
    // Constructor tanımı, bu sefer member list init kullanıyoruz. (Yapılması gereken)
    Foo(std::string_view name, int id): m_name{name}, m_id{id}
    {
        std::cout << "Bir adet Foo objesi oluşturuldu." << std::endl;
    }
};

int main(){
    Foo goo{"Ertugrul", 55}; // Belirlenen sırayla değerlerin verilmesi
    goo.print();
    const Foo loo{"Görkem", 53};
    loo.print();
    return 0;
}