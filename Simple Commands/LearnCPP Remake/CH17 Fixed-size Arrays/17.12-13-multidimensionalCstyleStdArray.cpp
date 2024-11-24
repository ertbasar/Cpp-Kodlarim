/* Arrayler tabii ki çok boyutlu yapılabilir. C-style kısmı zaten çok bariz, farklı inir örnekleri LearnCpp'de de var incelenebilir.
Ancak kısım std::array'e geldiğinde işler o kadar da basit olmuyor. std::array tek boyutlu olarak tasarlandığından dolayı 2D ve sonrası için herhangi
bir hazır sınıf şablonu yok. Bu yüzden std::array içinde std::array tanımlamamız gerekmekte. Burada tanım sırasında bazı temel şeyleri not etmeliyiz:
iki tane süslü parantez kullanmamız gerekli
syntax sıkıntılı ve okuması da zor
array boyutlarının sırası değişmiş durumda ancak indexleme aynı şekilde
fonksiyona gönderme işi de aynı şekilde

Burada alias kullanımı işi rahatlatabilir. Buna göre daha basit bir şekilde tanımlama işlemleri gerçekleştirilebilir.
std::array ile size() kullanırsak da bize ilk boyutun değerini verir. İkincisi için arr[0].size() kullanabilirsin. Beklenmeyen davranışlar gerçekleşmemesi
adına bazı şablon işlemler tanımlanabilir.

Bazı durumlarda birden fazla boyutlu arrayleri düzleştirmek, üzerinde yapılacak işlemleri kolaylaştırabilir. Row*Col sayısınca elemana sahip olmuş olur.
Bu durumda C++23'le beraber gelen std::mdspan işe fazlasıyla yarayabilir. Burada mdspan çok boyutlu bir matris gibi view etmemizi sağlar. İstediğimiz
sayıda boyutu buradaki mdspan ile inceleyebiliriz. Önemli olan tek şey mdspan'e array verisinin ilk pointerının vermek gerekli. Burada c-style array
kullanabiliriz ya da std::array'in data() üye fonksiyonunu kullanabiliriz. 
Bunun dışında C++23 te de operator[] içinde birden fazla indis kullanımı yapabiliriz. Bu sayede [row,col] = [row][col] olur

*/

#include <iostream>
#include <array>
#include <functional>
// Şablon haline getirme en iyi çözüm gibi bu durumda
template <typename T, std::size_t Row, std::size_t Col>
using Array2d = std::array<std::array<T, Col>, Row>;

int main(){
    // 2D C-style array. Satır satır tanımlama, tanımlanmayan yerde 0 init edilir
    int arr2D[3][5]{
        {1,2,3,4,5},
        {6,7,8},
        {9,10,11,12}
    };

    // 2D std::array. Fazladan {}'e dikkat
    std::array <std::array<int,4>,3> arr{{
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    }};

    // Alias ile kullanım
    Array2d<int, 3, 4> arr2{{
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 }}};

    // mdspan örneği. C++23 olmadığından bende çalışmadı elbet :) 
    /*
    std::array<int, 9> arr3{1,2,3,4,5,6,7,8,9};
    std::mdspan mdView{arr3.data(), 3,3};
    */
    return 0;
}