/* Cpp'de explicit dediğimiz bizim tetiklediğimiz 5 farklı tür dönüşümü vardır. Bunlar: 
1. C-style -> () operatörü kullanılarak, basit gibi görünebilir ancak istenmeyen castleri kullanabilir
2. static -> CH4'te incelenmişti. En kullanılması gereken cast türü, compile-time'da da kontrolleri yapar
3. const
4. dynamic 
5. reinterperet 
*/
#include <iostream>
#include <iomanip>

int main() {
    std::cout << (int)5 << std::endl;
    float y{1231335.232421};
    std::cout << static_cast<int>(5.5) << std::endl;
    std::cout << static_cast<int>(y) << std::endl;


    return 0;
}
