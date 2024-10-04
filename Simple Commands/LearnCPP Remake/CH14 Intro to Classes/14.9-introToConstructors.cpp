/* Sınıf değişkenlerini tanımlarken aggregate init yapabiliriz ancak bu verileri private kısma çektiğimizde -ki öyle olmasını isteriz- bunu yapamayız çünkü
bu üyelere erişim kısmında sıkıntı yaşarız. Burada devreye constructor girer. Constructorlar obje tanımlanırken çağrılan özel üye fonksiyonlardır. 
İsimleri sınıfın adı ile aynıdır ve return türleri yoktur. Eğer gerekirse conversion yapma yetileri vardır. 
Objeyi init etmesi gerektiğinden const olamaz, ancak const objelerle kullanılabilir. (İlk olarak init edilip sonradan const olacağından sorun oluşturmaz)
Constructorlar tanımlama işleminde kullanılma amacıyla oluşturulmuşlardır. Setterlar ise bir objenin bir elemmanını değiştirme amaçlı
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
    // Constructor tanımı
    Foo(std::string_view name, int id){
        m_name = name;
        m_id = id;
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