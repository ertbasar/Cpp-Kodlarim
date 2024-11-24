/* Vektörler, fixed-size arraylere göre biraz daha az performanslıdırlar. Bunu çoğu kullanımda zaten fark etmeyiz. Vektör aynı zamanda constexpr kullanımı
pek desteklemez, bu yüzden constexpr arraylere ihtiyacımız olduğunda std::array kullanmamız gerekir. <array> headerında bulunur ve tanımı vektore benzer:
std::array <int, 5> a{]; // array of 5 ints
Burada arrayin uzunluğu const bir ifade olmalıdır. non-const değişkenler ve run-time değişkenleri uzunluk için kullanılamaz.
std::array aggregate'tır. Bu yüzden constructoru yoktur, aggregate init ile tanımlaması yapılır. Eğer değer verilmeyecekse süslü parantezler kafi.
const veya constexpr olabilirler. eğer const olmayacaksa vectör kullanımı daha iyi olabilir. C++17'den itibaren CTAD kullanılabilir. Ancak CTAD kısmi 
olarak C++20'den sonra gelmiş olsa da çok pahalı bir işlem olduğundan dolayı çok kullanılmaz. 
Elemanlara erişim [] ile olur ancak o da sınır kontrolü işlemi yapmaz. Bu yüzden kullanım sırasında dikkat etmek gerekir.

bir array'in uzunluğu size_t türündedir. size() üye fonksiyonu kullanılabilir. Array'in uzunluğu constexpr olduğundan ona göre bir constexpr değer
döndürür. at() üye fonksiyonuyla sınır kontrolü yapılan bir dönüş alınabilir, get() de benzer şekilde kullanılabilir. 
*/

#include <iostream>
#include <array>

int main(){

    std::array<int, 8> arr1{1,2,3,4,5,6,7,8}; // 8 tane int elemanla array
    // Normal for veya range-based for kullanılabilir
    for(const auto& num : arr1)
        std::cout << num << ' ';
    std::cout << std::endl;     

    for(int i = 0; i < static_cast<int>(arr1.size()); i++)
        std::cout << arr1[i] << ' ';
    std::cout << std::endl;     
    std::cout << arr1.size() << std::endl;

    //CTAD
    std::array arr2{10,20,30}; // <int, 3> olarak alır

    return 0;
}

