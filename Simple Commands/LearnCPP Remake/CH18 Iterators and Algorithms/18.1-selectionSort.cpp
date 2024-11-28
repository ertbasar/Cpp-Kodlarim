/* Cpp'de işimizi kolaylaştırmak adına çok sayıda önceden tanımlanmış fonksiyon vardır. Bu fonksiyonlardan biri de <algorithm> altındaki std::sort
fonksiyonudur. Sıralama işlemi çok sık yapılan bir işlem olduğundan standart olarak yazılmıştır. Bununla beraber <utility> altında da std::swap
gibi fonksiyonlar bulunmakta. Burada herhangi bir kendi fonksiyonunu yazmadan önce internet üzerinde benzer bir fonksiyonun yazılıp yazılmadığına 
bakmak iyi olacaktır

*/

#include <iostream>
#include <array>
#include <algorithm>

int main(){
    std::array arr{12,23,14,12,55, 2, 45, 21, 23};
    for(const auto& num: arr)
        std::cout << num << " ";
    std::cout << std::endl;
    
    // sort kullanımı. neresinden neresine sort yapılacağı belirtilir
    std::sort(arr.begin(), arr.end());
    for(const auto& num: arr)
        std::cout << num << " ";


    return 0;
}