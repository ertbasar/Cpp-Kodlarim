/* 
1- Compile-time optimizasyonu run-time'a göre çok daha iyi olduğundan ötürü, bir değişkeni eğer sabit yapabiliyorsak yapmak bizim için en iyisidir.
const kullandığımız zaman bu değişkenlerin compile-time mı yoksa run-time'da mı init edileceğini belirlemek zordur. Bu yüzden constexpr kullanarak
bu sorunu bazı yerlerde çözmeye çalışırız. 
Bir değişken const olduğu zaman değerinin init edildikten sonra değiştirilemeyeceğini, constexpr ise bir değişkenin değerinin compile-time'da
belli olması gerektiğini zorunlu kılar diyebiliriz. Kullanımı nispeten basit ve aşağıda örneği olacak
2- Koşul operatörü C ? x : y; ile C'nin değeri doğruysa x, yanlışsa y değerinin döneceği if-else benzeri yapı. constexpr durumunda init ederken
bir if-else yapısı veya fonksiyon çağrılamayacağından bu kullanılabilir
*/

#include <iostream> 

int main(){
    const int x{3};
    constexpr int y{5};
    constexpr int z{y > x ? 7 : 4};
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;


    return 0;
}