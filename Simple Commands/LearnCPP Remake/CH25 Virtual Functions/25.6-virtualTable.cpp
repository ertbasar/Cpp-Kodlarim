/* Sanal fonksiyonlar kullanıldığı zaman, C++ derleyicisi sahneye vtable adında gizli bir yapı ortaya çıkarır. Bu vtable, sınıfın sanal
fonksiyonlarının adreslerini (pointerlarını) tutan bir tablodur. Her bir sınıfın kendi vtable'ı vardır. Her nesne, kendi içinde
bir vptr (virtual pointer) barındırır ve bu pointer da vtable'ı işaret eder. 

Aşağıdaki örnekte sırayla şunlar olur.
1- Base sınıfı içerisinde bir vtable oluşturulur ve show fonksiyonunun adresi vtable'a eklenir. 
2- Derived sınıfı da kendi vtable'ını oluşturur ve Derived::show() fonksiyonunun adresini koyar.
3- ptr->show() dediğimizde de
3.1- ptr'nin vptr'si, Derived'in vtable'ını gösterir
3.2- vtable üzerinden Derived::show adresi bulunur
3.3- Sonuç: Derived show yazılır
Bu mekanizma sayesinde runtime polymorphism sağlanır.
*/


#include <iostream> 
#include <string>

class Base{
    public:
    virtual void show(){
        std::cout << "Base show" << std::endl;
    } 
};

class Derived: public Base{
    public:
    void show() override {
        std::cout << "Derived show" << std::endl;  
    }
};

int main(){
    Base *ptr = new Derived();
    ptr->show();
    return 0;
}