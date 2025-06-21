/* C++'ta kalıtımla alınan üyelerin erişimleri türetilmiş sınıf içerisinden değiştirilebilir (Tabii ki türetilmiş sınıfın bu üyeye erişimi olmalı. 
Zaten private erişimde olan bir üyenin türetilmiş bir sınıfta da erişimi yok.) 
Benzer şekilde bir fonksiyona erişim tamamen de kesilebilir. Buradaki tek püf noktası, bir fonksiyonun tüm overloadlarıyla beraber veya hiçbiri olacak
şekilde erişimden kesebiliriz. 
Türetilmiş sınıfta o üye fonskiyonu delete de edebiliriz (Access specifier'i değiştirmeden). Bu sayede türetilmiş obje üzerinden bu fonksiyon çağrılamaz. 

*/

#include <iostream>

class Base{
    private:
    int m_value{};
    int m_x{12};
    protected:
    int getValue() const {return m_value;}
    public:
    Base(int value) : m_value{value} {std::cout << "Base objesi oluşturuldu" << std::endl;}
    int getX() const {return m_x;}
};

class Derived : public Base{
    public:
    Derived(int value): Base (value) {std::cout << "Derived objesi oluşturuldu" << std::endl;}
    using Base::getValue;
    int getX() const = delete;
    private:
    // using Base::getX; // Bu şekilde de erişimden uzaklaştırabilirdik. 
};

int main(){
    Derived d(5);
    std::cout << d.getValue() << std::endl; 
    // std::cout << d.getX() << std::endl; // Hata verir çünkü delete ettik  

    return 0;
}