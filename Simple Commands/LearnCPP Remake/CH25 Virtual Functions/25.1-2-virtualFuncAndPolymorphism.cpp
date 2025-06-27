/* 
25.1 pointers, references to the base class of derived objects
Sanal fonksiyonlar ve çok biçimliliğe geçmeden önce, türetilmiş ve baz sınıfların pointer ve referans ile farklı bir ilişkisinden bahsetmek gerekir. 
Bir türetilmiş sınıf objesi oluşturulduğu zaman, bu obje baz sınıfın da özelliklerini içerir. Bu durum sayesinde de C++ bizim baz sınıfı pointer veya referansı
üzerinden türetilmiş sınıfın objesini kullanabilmemize olanak tanır. Aşağıdaki örneklere bakabiliriz. 
Derived derived{5};
Derived& rDerived{derived};
Derived* pDerived{derived};
Base&    rBase{derived}; // rBase bir l-ref diyebiliriz
Base*    pBase{derived}; 
Şimdi yukarıdaki örnekleri incelersek zaten Derived üzerinden oluşturulan objeler şimdiye kadar gördüklerimiz. Base üzerinden oluşturulan objeler ise derived objesinin
Base sınıfı özelliklerine erişmeyi sağlar, Derived sınıfının özelliklerini göremez. 
Bu kullanımın 2 adet temel nedeni bulunmakta: 
1- Benzer özelliklere sahip olan türetilmiş sınıfların baz sınıf üzerinden bu ref/prt ile erişilebilmesini sağlamak ve ekstra kod yazımını engellemek. 
2- Arrayler tek türde eleman tuttuklarından dolayı burada bazı objeleri tek türe indirerek beraber saklamak. 
-----
25.2 virtual functions and polymporphism 
Sanal bir fonksiyon, özel bir üye fonksiyon türüdür ve çağrıldığında, referans verilen ya da işaret edilen nesnenin gerçek (en türetilmiş) türüne ait olan en son versiyonu çalıştırılır.
Türetilmiş fonksiyon sadece ve sadece baz ile aynı imzaya (isim, parametreler, const turu ve return turu) sahipse override fonksiyon olarak nitelendirilir. 
Bir fonksiyonu sanal yapmak için 'virtual' keywordunu kullanmak yeterli. Bazı durumlarda eğer destructor'u sanal yapmazsak derleyici hata verebilir. Bu durumda
sadece virtual kelimesini eklemek yine yeterli olur. 
Not: Sanal fonksiyon resolution sadece referans veya pointer üzerinden çalışır. Eğer Baz sınıfın normal bir objesi olarak tanımlanırsa slice işlemi olabilir 
ve Baz sınıfın özellikleri kullanılır. Yani istenen işleme ulaşılamaz. 
Polymorphism de çok biçimlilik olarak çevrilebilir. Bu da bir varlığın birden çok formda iş görebileceğini belirler. 2 farklı türü vardır: 
1- Compile-time: Derleyici tarafından resolve edilir. Fonksiyon overload, şablon resolution gibi işlemlerde olur. 
2- Runtime: Çalışma zamanında bu resolve işlemi gerçekleşir. Sanal fonksiyonlar örnektir. 
Eğer bir fonksiyon virtual olarak işaretlenirse, türetilmiş sınıflarındaki tüm eşleşen fonksiyonlar da sanal olarak işlenir. (virtual keyword kullanmasak bile)
Sanal fonksiyonları constructor veya destructor içinden çağırmak sıkıntılı sonuçları doğurabileceğinden dolayı kaçınmak gerekli :) 
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
    virtual std::string_view getName() const {return "B";}
};

class C: public B{
    public:
    virtual std::string_view getName() const {return "C";}
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