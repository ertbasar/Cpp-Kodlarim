/* Bazı durumlarda baz sınıfı gösteren bir pointera sahipken türetilmiş sınıfın içerisindeki bir bilgiye erişmeyi isteyebiliriz. Bu tür durumlarda dynamic
cast denilen operatör kullanılır ve baz sınıf pointerı türetilmiş sınıf pointerına dönüştürülür. Buna downcasting denir. Örneğini aşağıda verelim. 

int main(){
Base* b{getObject(true)}; // Burada bir adet türetilmiş sınıf oluşturduğumuzu varsayalım 
Derived* d{dynamic_cast<Derived*>(b)}; // dönüştürme işlemi gerçekleştirildi
cout << d->getName();
delete b;
return 0;}

Bazı durumlarda mesela b'nin türetilmiş objeyi göstermediği durumlarda dynamic_cast bize nullptr döndürür. Bunun dışında eğer private veya protected
kısımlara da tabii ki erişim olmaz. 
*/