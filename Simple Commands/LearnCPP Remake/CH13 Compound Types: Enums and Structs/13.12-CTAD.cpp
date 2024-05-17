/* CTAD = Class Template Argument Deduction C++17'den itibaren bir objeyi şablon sınıftan init ederken derleyici o objenin init edildiği şekle göre auto
olarak deduce edebilir. Burada önemli olan kısım bu şekilde init ederken argüman listesi vermememiz gerektiğidir. 
CTAD fonksiyon parametreleriyle çalışmaz, adı üstünde argüman deduction :p

*/

#include <iostream>
#include <utility>



int main(){
    //ya tam olarak belirtmek ya da hiç belirtmemek gerekli
    std::pair <int, int> p1{3,5};
    std::pair p2{3,5};
    //std::pair <> p3{3,5};
    //std::pair <int> p4{3,5};


    return 0;
}