/* reference_wrapper için bir sınıf şablonudur ve bir referansı kapsüllemeye (wrap) yarar diyebiliriz. Genellikle referanslar normalde konteynerlerde 
saklanamadığından, referansları STL konteynerlerinde saklamak veya referanslar üzerinde çalışırken kopyalama semantiğinden kaçınmak için kullanılır.
Burada birkaç kullanım şekli var:
operator= refere edilen objenin değerini değiştirir
std::reference_wrapper<T> tutulan elemant türünü T& yapar
get() T&'yu elde etmek için kullanılabilir
Bunun dışında std::ref ve std::cref ile de kullanımı var ancak kısa yoldan kullanımı gibi çok bir ekstrası yok denebilir
Özetle bunun amacı referansları STL konteynerlerinde güvenle saklamak.
*/

#include <iostream>
#include <array>


int main(){
    int a{10};
    int b{20};
    int c{30};
    int d{40};
    std::array<std::reference_wrapper<int>, 3> arr{a,b,c};
    arr[1].get() = 5;
    std::cout << arr[1] << std::endl;
    arr[1] = d;
    std::cout << arr[1];
    return 0;
}