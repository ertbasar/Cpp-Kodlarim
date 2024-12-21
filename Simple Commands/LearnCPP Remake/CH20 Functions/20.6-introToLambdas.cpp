/* Lambda ifadeleri, bir fonksiyonun içerisinde başka bir isimsiz fonksiyon tanımlamamıza olanak sağlar. Burada nesting işlemi yapılıyor denebilir, bu da
namespace isimlendirme kirliliğini engeller ve bir fonksiyonun kullanım yerine en yakın yerde tanımlanabilmesini sağlar. Syntax'i biraz karışık:
[capture clause](parameters) -> return type
{statements}
- capture clause boş da olabilir. capture: dışarıdaki değişkenleri yakalama ve kendi içerisinde kullanma oluyor, değer, ref veya bulunan tüm değişkenleri
yakalama gibi farklı özelliklere sahiptir
- parametre listesi de gerek yoksa boş kalabilir
- return type opsiyonel, yoksa auto varmış gibi davranılır
- lambda ifadelerinin isimleri olmadığından belirtmeye gerek yok
Lambda fonksiyonları tek bir satıra yazmak bazen zor olabilir. Burada nasıl değişken tanımlıyorsak bu şekilde bir lambda değişkeni tanımlayıp sonrasında
kullanımını gerçekleştirebiliriz. Bu da okunabilirliği arttırır. Aynı zamanda birden fazla kez kullanılacak lambda ifadelerinde de işe yarar.
Lambda ifadesinin bir değişkende tutarken, türünü auto olarak vermek en iyisidir, çünkü her lambda farklı bir tür olduğundan dolayı auto türün derleyici
tarafından ayarlanmasını sağlar. Burada lambda ifadesini bir fonksiyona argüman olarak yollarken de eğer C++20 ve sonrası ise auto kullanılabilir, ancak
diğer türde kullanımlarda ya şablon bazlı kullanım yapmak, ya std::function kullanmak, ya da eğer lambdada capture yoksa fonksiyon işaretçisi kullanmak
gereklidir. 
Lambda içerisinde auto parametresine sahip olduğunda, derleyici tarafından bu çağrılarda nasıl bir parametre olacağı belirlenir. Burada da lambdalar farklı
türlerde parametrelerle çalışabileceğinden ötürü auto parametresine sahip lambdalara generic lambda denir. 
C++17'den itibaren lambdalar, gerekli koşullara göre kendiliğinden constexpr ifadeler haline dönerler. Burada iki tane şart vardır: Capture yok veya tüm
capturelar constexpr. Lambda tarafından çağrılan fonksiyonlar constexpr olmalı. C++23 itibariyle çoğu algoritma ve matematiksel fonksiyonlar constexpr 
olmadığından dolayı burada sıkıntı çıkarabilir. 
Generic lambdalardan resolve edilen her bir fonksiyon için derleyici yeni ve farklı bir lambda yaratır.
Return değerinde deduce olacaksa, lambdanın kendisi içerideki return ifadesine göre belirlenir. Bunun için de lambda içerisindeli tüm return ifadeleri
aynı türde olmalıdır. Burada iki adet seçenek bulunmakta: Static cast kullanımı ve de explicit olarak return type verilip derleyicinin cast etmesi.
Çoğu sık yapılan işlem için kendi lambdamızı yazmamıza gerek yok, zaten STL içerisinde çoğu <functional> headerı altında bulunmakta. Sadece internet
üzerinden böyle bir fonksiyon olup olmadığını araştırmak yeterli olacaktır.

Özet olarak aslında normal fonksiyonlardan çok bir farkı yok, ancak bazı şeyleri daha sadeleştirmesi adına, birden fazla kullanılma olasılığı düşük olan
fonksiyonları lambda ifadesine getirmek fazlasıyla mantıklı gibi. Lokal olacak kullanımlarda da işi kolaylaştırır.
*/

#include <iostream>


int main(){
    // herhangi bir capture, parametre ve dönüş türü belirlenmemiş lambda. en basic yazımı. 
    // []{}; // Bir işe yaramadığından warning verir, bu yüzden yorum satırına aldım

    // aşağıdaki şekilde kullanımda nesne, ostream'e doğrudan yazdırılamadığından bir tür bool dönüşümü gerçekleştirir ve de bu yüzden 1 döndürür
    std::cout << []{return 5;} << std::endl;
    
    // aşağıdaki kullanımda ise lambda'yı çağırdık denebilir, bu yüzden 5 yazdırır. Kullanımı da pek böyle olmaz zaten
    std::cout << []{return 5;}() << std::endl;
    
    // tanımlamalar, burada elemanları multiplier değeriyle çarpacağız
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    int multiplier = 3;

    // normal bir fonksiyon multiplier değerine erişemezdi, ya global bir değişken yapmamız ya da parametre olarak gönderilmeliydi. şimdi kendisi çekti.
    auto multiply = [multiplier](int x) { return x * multiplier; };

    for (int num : numbers) {
        std::cout << multiply(num) << " "; // lambda ifadesi değişkeni üzerinden numbers vektörü içerisindeki elemanlara sırayla işlem yaptık
    }
    std::cout << "\n" ;

    // bir de generic ve daha uzun bir lambda yazalım
    auto printer = [](auto x){
        for (auto a: x)
            std::cout << a << " ";
    };
    
    printer(numbers);
    std::cout << "\n" ;

    // Char listesi gönderelim
    printer(std::initializer_list<char>{'a', 'b', 'c'});


    
    return 0;
}