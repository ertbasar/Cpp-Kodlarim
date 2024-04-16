/* Eğer mod operatörü kullanılacaksa 0 ile karşılaştırmak iyi olur (x % 12 == 0 gibi)
arttırma veya azaltma operatörü kullanılacaksa -- veya ++ yı önde kullanmak daha iyi olur
ayrıca ondalıklı sayılar arasında karşılaştırmalar problematik olabilir
<bitset> kullanarak bit bazlı tanımlama ve işlemler yapabiliriz
*/

#include <iostream>
#include <cmath>

int main(){
    int a{7};
    ++a;
    a = std::pow(a,2);//üs alımı, karesini aldık
    std::cout << a << std::endl;
    std::bitset <4> my_bitset{0b0011};
    std::cout << my_bitset << std::endl;
    return 0;
}