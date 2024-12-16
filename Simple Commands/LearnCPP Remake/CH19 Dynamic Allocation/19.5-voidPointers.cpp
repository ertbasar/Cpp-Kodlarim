/* Void (veya generic) pointerlar, aslında özel tipte bir pointer türü denebilir. Bu pointerlar herhangi bir türdeki objeye işaret edebilirler. 
Yalnız şöyle bir durum var ki, neye işaret ettiklerini bilmediklerinden ötürü herhangi bir şekilde derefere işlemi de gerçekleştiremezler. İşlem yapmadan
önce başka bir pointer türüne cast edilmesi gerekir. nullptr'ye eşitlenebilirler. 
Hangi türü gösterdiğini bilmediğinden, eğer o pointer silinecekse ilk önce gerçek türüne cast edilmesi gerekir. Benzer sorunlar pointer aritmetiğinde de 
bulunur çünkü başta da dediğimiz gibi void pointerlar hangi türden objeyi işaret ettiklerini bilmezler.
Eğer spesifik bir neden yoksa kullanmaktan kaçınmak iyidir.
*/

#include <iostream>

int main(){
    int val;
    val = 23;
    void* ptr{&val};
    // std::cout << *ptr << std::endl; // hata verir, ne gösterecek ki?
    std::cout << static_cast<int*>(ptr) << std::endl; // int olarak işaret ettiği adresi döner
    // Eğer veriye erişmek istersek bu şekilde cast yapmamız gerekli
    int* intPtr{static_cast<int*>(ptr)};
    std::cout << *intPtr << std::endl; // 23 değerini görürüz

    return 0;
}