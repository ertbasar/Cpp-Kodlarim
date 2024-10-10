/* Sınıflar uzadıkça ve daha karmaşık hale gelmeye başladıkça her şeyi aynı yerde tutmak sınıfı yönetmeyi zorlaştırabilir. Bu yüzden üye fonksiyonları
non-member fonksiyonlar gibi sınıf tanımının dışında tanımlayabiliriz. Sınıfların, fonksiyonlardan farklı olarak, kullanılmadan önce derleyici tarafından
tüm tanımının görülmesi gerekir. Bu yüzden sınıflar genel olarak header dosylarında, üye fonksiyonlar ise farklı bir derlenebilir cpp dosyasında 
tanımlanırlar. Bu sayede aynı sınıfı kullanmak isteyen dosyaların header'ı #include etmesi yeterli olur. Eğer fonksiyon kısaysa (get-set gibi) tanımı
header dosyasında yapılabilir. 
sınıf tanımının dışında olan fonksiyonlar inline yapılmak isteniyorsa özellikle inline keywordu kullanılmalı
*/


#include "Foo.hpp"
#include <iostream>

int main(){

    Foo foo;
    foo.print();

    return 0;
}