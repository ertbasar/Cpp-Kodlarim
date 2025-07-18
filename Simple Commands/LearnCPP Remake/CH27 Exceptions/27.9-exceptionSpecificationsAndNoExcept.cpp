/* C++'da fonksiyonlar ya potansiyel thrower ya da non-thrower olarak sınıflandırılırlar. Non-throwing denilen fonksiyonlar dışarıya görülecek bir şekilde
exception fırlatmayacağını garanti eden fonksiyonlardır. noexcept keywordu kullanılarak tanımlama işlemi gerçekleştirilebilir. 
void doSmt() noexcept {};
Yeniden hatırlatmak gerekir ki, noexcept kullanımı fonksiyon içerisinde exception işlemlerinin gerçekleşmeyeceğini garanti etmiyor. Garanti ettiği şey
bu exception'un kendi içerisinde handle edileceği ve dışarıya bir etkisinin olmayacağı. Eğer bu noexcept fonksiyonun içinde yönetilememe durumu olursa
std::terminate çağrılır. 
Türlerine göre fonksiyonlar:
1. Kendiliğinden non-throwing: default, move ve copy constructor ve assignmentlar, karşılaştırma operatörleri
2. Potansiyel throwing: Normal fonksiyonlar, kullanıcı tarafından yazılan constructorlar ve kullanıcı tarafından yazılan operatörler
Noexcept operatör olarak da ifadelerin içlerinde kullanılabilirler. Derleyicinin exception gelir veya gelmez düşüncesine göre true veya false döndürür.
Statik olarak derleme zamanında tahmin ederek yapılan bir işlemdir. 
Best Practice:
- Move constructor, assignment ve swap fonksiyonlarını noexcept yap
- Copy constructor ve assignmentlar yapılabildiğinde noexcept
- Diğer fonksiyonlarda da no-fail veya no-throw garantisi için noexcept kullan
*/