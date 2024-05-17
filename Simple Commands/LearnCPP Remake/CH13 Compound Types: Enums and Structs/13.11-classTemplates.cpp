/* Nasıl fonksiyonlarda şablon kullanımı varsa aynı kullanım sınıflarda da geçerlidir. Hatta kullanım biraz daha zorunlu gibi düşünülebilir çünkü class
overload gibi bir kavram bulunmamaktadır. Burda ya her tür için ayrı sınıf belirlenmeli ya da şablonlar kullanılmalıdır.
Fonksiyon şablonlarında olduğu gibi sınıf şablonlarını da header dosyalarında belirtiriz.
Aşağıda birkaç pair örneği var sık kullanıldığından <utility> altında std::pair adında bir sınıf şablonu da bulunur
*/

#include <iostream>
#include <utility>
// Tek şablonlu struct 
template <typename T> 
struct Pair{
    T x{};
    T y{};
};

template <typename T>
void printPair(Pair<T>& p){
    std::cout << p.x << std::endl;
    std::cout << p.y << std::endl;
}

// Birden fazla şablonlu da yapılabilirdi
template <typename T, typename U>
struct Pair2{
    T x{};
    U y{};
};
// Aşağıdaki gibi Pair2'yi şablon olarak verirsek hem farklı şablona sahip yapılarla hem de farklı türlerle çalışabilir hale getiririz
template <typename Pair2>
void PrintPair2(Pair2& p){
    std::cout << p.x << std::endl;
    std::cout << p.y << std::endl;
}
// pair örneği
template <typename T, typename U>
void printPair3(std::pair<T,U>& p){
    std::cout << p.first << " " << p.second << std::endl;
}

int main(){

    Pair2<int, int> a{1, 22};
    PrintPair2(a);

    std::pair<int, double> b{1, 2.3};
    printPair3(b);
    return 0;
}