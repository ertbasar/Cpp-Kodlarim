/* Cpp'de tür çıkarımları auto kelimesi kullanılarak sağlanır. Burada derleyici hangi türü seçeceğini objeye verilen ilk değere göre seçer. Bu yüzden ilk
başta değer verilmesi zorunludur. 
constexpr auto z{2}; gibi bir kullanımla constexpr yapabilirsin.
string ile beraber olacaksa auto a{"goo"s} veya {"goo"sv} gibi bir kullanım yapman gerekir.
Fonksiyonlarda return değeri olarak yazılabilir ancak derleyicinin emin olmadığı durumlarda hata alınabilir. Prototip kullanımı da gereksiz olur tamamen
yukarıda tanımlanır. Bunun yerine normal kullanım tercih etmek daha iyi olur.
Parametre olarak C++20 ile geldi ancak o da fonksiyon şablonları kavramında işe yarar
*/
#include <iostream>
//Aşağıdaki şekilde de bir kullanım vardır. fonksiyon isimlerini aynı hizaya getirme amacıyla yapılabilecek bir işlemdir.
auto add(int x, int y) -> int{return x + y;};
auto divide(double x, double y) -> double;
int main(){
    auto i{13};
    auto d{3.2};

    std::cout << add(3, 5) << std::endl;
    std::cout << divide(3, 5) << std::endl;
    return 0;
}

double divide(double x, double y){
    return x/y;
}