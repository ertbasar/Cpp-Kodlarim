/* Aynı fonksiyonu her değişken türüne göre yazıp overload etmekle uğraşmamak için şablon kullanımı yapabiliriz. Bu şablonlar Cpp'de fonksiyon veya sınıfların
farklı değişken veya veri türleriyle çalışabilmesi için dizayn edilmiştir. Bir kere bu şablon oluşturulduktan sonra derleyici bu fonksiyon üzerinden istediği
kadar overload fonksiyonu veya sınıfı oluşturabilir. 

*/

#include <iostream>

template <typename T> // Bu yapının scope'u sonraki fonksiyon veya sınıf tanımlanana kadardır.
T max(T x, T y){
    return (x < y) ? y : x;
}

int main(){


    return 0;
}