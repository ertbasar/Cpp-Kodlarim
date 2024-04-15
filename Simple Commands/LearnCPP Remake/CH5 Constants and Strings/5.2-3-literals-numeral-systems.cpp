/* 1- Cpp'de sabit kullanırken kullanım durumumuza göre sayıları 3L veya 4.0f gibi tanımladığımız olur. f dışındakiker genelde kullanılmaz da zaten
2- değişkenlere değer verirken bazı önekler sayesinde farklı sayı sistemlerini kullanarak o şekilde değerlendirebiliriz. çıkışı da benzer
istiyorsak i/o manipülasyonu şart.
*/
#include <iostream>

int main(){
    float x = 4.01F;
    long  y = 12L;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    int a{012};
    int b{0x12};
    int c{0b10111};
    std::cout << a << std::endl;
    std::cout<<std::hex;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    return 0;
}