/*
1- constexpr fonksiyonlar return değeri compile-time'da hesaplanma ihtimali olan fonksiyonlardır. return tipi önüne constexpr yazılır
2- consteval fonksiyonlar ise C++20'de gelen ve compile-time'da hesaplanmayı zorunlu kılan fonksiyonlardır. Yoksa hata verir 
Bu iki fonksiyona verilen parametrelerin türleri de aslında bu işlemin run-time mı yoksa compile-time mı olacağını belirtir. 
constexpr ile normal değişkenler de çalışırken consteval ile yalnızca constexpr veya sabit değerlerle çalışır
Ayrıca constexpr ve consteval fonksiyonlar inline fonksiyonlar olduklarından kullanıldıkları her cpp dosyasında tanımlanmalıdırlar
Bunun yerine header dosyasında tanımlayıp include edilir
*/

#include <iostream>

constexpr int fonk_expr(int x, int y){
    return x > y ? x : y;
}



consteval int fonk_eval(int x, int y){
    return x > y ? x : y;
}



int main(){
    constexpr int g{fonk_expr(2,3)};
    std::cout << g << std::endl;

    constexpr int z{fonk_eval(4,5)};
    std::cout << z << std::endl;

    constexpr int c{3};
    std::cout << fonk_eval(c,8) << std::endl; //sıkıntı yok, constexpr ve sabitle çalışır 

    int d{10};
    //std::cout << fonk_eval(d,8) << std::endl; // run-time'da çalışacağından dolayı hata verir
    
    return 0;
}


