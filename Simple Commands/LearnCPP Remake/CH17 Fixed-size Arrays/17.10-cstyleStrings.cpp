/* C-style stringler aslına bakarsak elemanları (const) char olan c-style arrayler diyebiliriz. Init ederken uzunluğunu derleyiciye bırakmak mantıklıdır.
Burada da array decay olur ancak yine uzunluk kaybolur. Bir de yazdırma işleminde cout null terminator'u görene kadar yazdırma işlemini gerçekleştirir.
Burada en sıkıntılı durumlardan biri stringi init yaparken normal kullanım yapabilirsin ancak sonrasında herhangi bir operatörle stringe eşitleme işlemi
yapılamaz, teker teker elemanlarını değiştirme işlemini gerçekleştirmek gerekir. 
C'den kalma bazı fonksiyonları da <cstring> headerı altında kullanabilirsin
Zaten spesifik bir neden olmadığı sürece std::string tercih edilmeli.
*/

#include <iostream>

int main(){

    const char str[]{"Ben Ertugrul"};
    std::cout << str << std::endl;
    std::cout << str[2] << std::endl;

    return 0;
}