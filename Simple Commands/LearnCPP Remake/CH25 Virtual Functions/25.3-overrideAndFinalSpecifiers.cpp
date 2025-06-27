/* Önceki konuda da belirttiğimiz gibi override'lar sadece türetilen ve baz sınıftaki fonksiyonların imzalarının aynı olmasına bağlıdır. 
Burada işimizi override keywordu kolaylaştırabilir. 
Eğer override keywordu bir adet sana fonksiyonda kullanılırsa, derleyiciye bu fonksiyonun bir adet override olduğunu dikte etmiş oluruz, ve bu sayede 
bu fonksiyonun override işlemi gerçekleştireceğinden emin oluruz. Çünkü eğer override olarak işaretlenen fonksiyon override yapmazsa, derleyici 
hata verir ve program çalışmaz. 
En iyi kullanım -> Baz sınıftaki fonksiyonun önüne virtual, türetilen sınıflarda ise override kelimesinin yazılması olur. Zaten bir fonksiyon
baz sınıf içerisinde sanal olarak işaretlenmişse, türetilen sınıflarda da otomatik olarak sanal olur. 
---
Bazı durumlarda bir sanal fonksiyonun override edilmesini istemeyebiliriz. Bu durumlarda final keywordu kullanılarak o fonksiyonun bir daha
override edilmesinin önüne geçilebilir. 
---
Özel bir durum ile return türü farklı olarak override yapılabilir. Bu covariant return types ile açıklanır. Gerekirse bakılabilir. 
*/


#include <iostream> 
#include <string>
#include <string_view>

class A{
    public:
    virtual std::string_view getName() const {return "A";} // sanal fonksiyon tanımlanması
};

class B: public A{
    public:
    // Bazda virtual, burada override, ayrıca daha fazla override edilememesi için final
    std::string_view getName() const override final{return "B";}
};

class C: public B{
    public:
    // Öncekinde final olarak verdiğimizden ötürü burada override yapılamaz. Hata verir
    // virtual std::string_view getName() const {return "C";}
};

int main(){
    C c{};
    A& a{c};
    std::cout << a.getName() << std::endl; // Sonucun C çıkmasını bekliyoruz. A üzerinden çağrılsa da sanal fonksiyon olduğundan en türetilmiş sınıfa kadar resolution yapılacak.
    B b{};
    A a2{b};
    std::cout << a2.getName() << std::endl; // Sonucun A çıkmasını bekliyoruz çünkü ref veya pointer olarak tanımlanmayan bir a2 var elimizde 

    return 0;
}