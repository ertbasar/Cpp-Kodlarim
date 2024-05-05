/* Genel olarak bir değerden başka bir değer üretme sürecine tür dönüşümü denir. İki şekilde gerçekleşir bunlar implicit (derleyicinin gerçekleştirdiği) ve 
explicit (programcının komutları ile) Cpp'deki çoğu tür dönüşümü de aslında implicit olur denebilir.
Tür dönüşümü tetiklenince derleyici bu dönüşümü yapıp yapamayacağına bakar, olumsuz durumda hata verir
Ayrıca direct list init ile tür dönüşümünü implicit olarak yapmaz, hata verir
*/

#include <iostream>

void print(double d){ //Gelen değeri double çevirecek
    std::cout << d << std::endl;
}

int main(){
    double d{3};
    // int a{3.5}; // hata
    double division{4/3.0};
    print(4.0f);
    return 0;
}