/* C++ ne kadar otomatik olarak bir constructor sağlasa da, eğer kalıtımla uğraşıyorsak destructorları sanal yapmamız önemli. Çok
basit bir şekilde aşağıdakini yapsak bile yeterli.
virtual ~Base() = default;
Eğer bir sınıf üzerinden kalıtım yapılacağını biliyorsak o sınıfın destructorunu public ve virtual yapmak lazım. Eğer kalıtım istenmiyorsa da 
final ile belirtmek ve baştan böyle bir işe girişilemeyeceğini belirtmek iyi olur. 
--
Bazı durumlarda bir fonksiyonun sanallaştırılmasını es geçmek isteriz. Bu tür durumlarda scope resolution operatoru ile baz sınıf
çağrılabilir ve baz sınıfın fonksiyonu kullanılabilir. 

*/


#include <iostream> 
#include <string>
#include <string_view>

class A{
    public:
    virtual std::string_view getName() const {return "A";} // sanal fonksiyon tanımlanması
    virtual ~A() = default;
};

class B: public A{
    public:
    // Bazda virtual, burada override
    std::string_view getName() const override final{return "B";}
};


int main(){
    B b{};
    std::cout << b.A::getName() << std::endl;
    return 0;
}