/* Exceptionlar üye fonksiyonlar ve de operator overload işlemlerinde çok yararlılar. 
Constructorlar da ayrıca faydalı oldukları ayrı bir alan diyebiliriz. Burada eğer constructor bir nedenden dolayı hata alırsa, bu objenin yaratılma
işlemi yarıda bırakılır, ve o ana kadar oluşturulmuş değişkenler silinip parçalanır. Ancak destructor çağrılmayacağından dolayı eğer burada bir bellek 
ayrımı yapılmışsa bu bellekte sızıntı oluşabilir. Buradaki temizlik için 2 adet farklı yol kullanılabilir:
1. Hata alınabilecek kısmı try bloğu içerisine ekle, ve uygun catch bloğu içerisinde bu temizlik işlemlerini gerçekleştir.
2. Bellek ayrımlarını constructor değil de değişken tanımlarında gerçekleştir, bu sayede değişkenler parçalanırken silme işlemi gerçekleşir. (Constructor
içerisinde allocate olursa destructor gerektiğinden silme işlemi olmayabilir.)

Exception sınıfı kavramı, normal bir sınıfın sadece exception fırlatırken kullanılmasını sağlayan sınıftır diyebiliriz.  Bu tür sınıfları kullanarak 
exception'un açıklamasını yazdırabiliriz. 

Exception'u handle edecek handlerların sınıf exceptionlarını catch by ref yapması daha iyi olur. Hatırlatmış olalım

Türetilmiş sınıfların handler catch blokları baz sınıflardan daha önce yazılmalı ki baz sınıfa ref. gösterme gibi algılanıp erkenden işlenmesin. 

Standart kütüphane içerisindeki çoğu sınıf ve operatörler exceptionları std::exception adındaki exception sınıfı üzerinden fırlatırlar. Küçük bir 
exception sınıfı olmakla beraber diğer exception sınıflarına baz bir sınıf olmak için yazılmıştır. Kendi exception sınıflarımızda da bu sınıf üzerinden 
kendi kullanımlarımızı override edebiliriz. 

Bir exception fırlatıldığı zaman derleyici bu exception objesinin bir kopyasını belirli olmayan bir alana (exceptionlar için ayrılmış) kopyalar.
Bu şekilde stack kaç kez geri sarılmış olursa olsun exception objesine bir zarar gelmez. 
*/

#include <iostream>

// Örnek olarak bir exception sınıfı
class ArrayException{
    private:
    std::string m_error{};
    public:
    ArrayException(std::string_view error):m_error{error}{}
    const std::string& getError() const {return m_error;}
    const char* what() const noexcept override { return m_error.c_str(); } // what() üye fonksiyonu da override edebiliriz
};

class Foo{
    public:
    Foo(){
        try
        {
            // Burada işlemler oluyor
        }
        catch(const std::exception& e) // std::exception sınıf objesi geliyor 
        {
            std::cerr << e.what() << '\n'; // what üye fonksiyonu ile exception yazdırılıyor. C-style bir değer döndürür 
        }
        
    }
}


