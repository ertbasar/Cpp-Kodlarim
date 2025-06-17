/* Bazen baz sınıfa erişimimiz olmasına rağmen bir özellik eklemek isteriz ancak baz sınıfı değiştirmek istemeyiz, veya direkt olarak değişim için bir iznimiz olmayabilir. Bu tür durumlarda 
yapılabilecek en iyi şeylerden birisi kendi türetilmiş sınıfımızı oluşturmak ve de buraya o özelliği eklemek olabilir. Bu sayede baz sınıfı da değiştirmemiş oluruz. 
*/

#include <iostream>
class Base{
    protected:
    int m_value{};
    public:
    Base(int value): m_value{value} {}
};

class Derived : public Base{
    public:
    Derived(int value): Base(value) {}
    int getValue(){
        return m_value;
    }
};

int main(){
    Derived d(12);
    std::cout << d.getValue();
    return 0;
}