/* Türetilmiş sınıf objesi üzerinden bir fonksiyon çağrıldığı zaman derleyici ilk olarak o isimde bir fonksiyonun türetilmiş sınıfta olup olmadığını inceler. Eğer varsa, oradaki overload
edilmiş fonksiyonların resolution işlemi gerçekleştirilip en uygun olanı seçilir. Eğer bu şekilde uygun bir eşleşme bulunamazsa kalıtım zincirindeki bir üst sınıfa geçilip orada inceleme
yapılır. 
Bazı durumlarda, türetilmiş sınıfın içerisinde tamamen yeniden fonksiyon tasarlamak yerine sadece bazı değişiklikler yapmayı isteyebiliriz. Bu tür durumlarda türetilmiş fonksiyon
içerisinden baz sınıftaki fonksiyonu çağırma yöntemini seçebiliriz. 
Burada resolution işlemi yapılırken tam olarak istenen fonksiyona resolution olmaması durumunda beklenmedik şeyler olabilir. Bunun için de dikkat et. 
Türetilmiş sınıf içerisinde resolution gerçekleşmeden direkt olarak baz sınıf fonksiyonlarının bakılmasını istersen de bir yöntem var o da aşağıda :)
*/

#include <iostream>
class Base{
    protected:
    int m_value{};
    public:
    Base(int value): m_value{value} {}
    int getValue(){ 
        return m_value;
    }
};

class Derived : public Base{
    public:
    Derived(int value): Base(value) {}
    void getValue(){ 
        // Bu şekilde ana sınıfı çağırdık ve onun yapacaklarının dışında özellik ekleme şansı kazandık
        Base::getValue();
        std::cout << "Türetilmiş sınıftan çağrıldı" << std::endl;
    }
    // Dümenden bir overload yapalım sanki resolution yapacakmış gibi :p
    double getValue(int x){ 
        return static_cast<double>(m_value);
    }
};

class Derived2 : public Base{
    public:
    Derived2(int value): Base(value) {}
    // Aşağıdakini kullanarak direkt olarak Base sınıfının getValue fonksiyonlarını kullanacak hale getirdik
    using Base::getValue;
};

int main(){
    Derived d(12);
    std::cout << d.getValue(12) << "\n";
    d.getValue();
    Derived2 d2{23};
    // Direkt olarak baz sınıfın fonksiyonu kullanılacak
    std::cout << d2.getValue() << "\n";
    return 0;
}