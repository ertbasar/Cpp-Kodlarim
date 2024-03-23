/*Çok da fazla dosyaya ayırmaya gerek olmadığından dolayı bu bölümü tek dosyada inceleyim dedim.
İlk olarak double ve float sayılardaki precisionu, daha sonrasında ise static_cast operatörünün özelliklerine bakacağız
Araya birkaç şey daha karışabilir tabii :)
*/
#include <iostream>
#include <iomanip>

int main() {
    int x{7};
    // sizeof operatörü kullanımı
    std::cout << sizeof(x) << std::endl;

    // float ve double precision deneme
    float y{123133.232421};
    double z{2323.232421323234};
    std::cout << y << std::endl;
    std::cout << z << std::endl;
    // std::cout için daha fazla ondalık basamak görüntülemek için setprecision kullanımı
    std::cout << std::setprecision(10);
    std::cout << y << std::endl;
    std::cout << z << std::endl;
    // boolean zaten klasik bir şekilde takılır diyelim :)
    bool b1{};// false ile init eder
    // char da klasik
    char c1{'a'};
    char c2{97};// bu kullanımı yapmasak daha iyi olur diyebiliriz. 
    //static_cast tür değişimlerinde kullanılır. daha detaylı ileride inceleyeceğiz ancak bu zaten en iyi metot denebilir 
    std::cout << static_cast<int>(5.5) << std::endl;
    std::cout << static_cast<int>(y) << std::endl;


    return 0;
}
