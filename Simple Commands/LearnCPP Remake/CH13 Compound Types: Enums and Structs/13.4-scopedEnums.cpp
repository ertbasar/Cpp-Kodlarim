/* Aslına bakarsak scoped ve unscoped enums arasında çok da bir fark yok. Çalışma şekilleri de benzer ancak aralarında iki temel fark bulunmakta. 
1. Implicit olarak integer'a dönüştürülmezler. Bu yüzden explicit cast yapmak gerekebilir.
2. Sadece o enum'un scope'unda erişilebilirler. 
Unscope enum oluşturmak için enum class kullanırız onun dışındaki her şey aynıdır. Bu kullanım namespacelere benzerdir.
Kullanımı unscoped olanlara göre biraz daha çetrefillidir denebilir.
*/

#include <iostream> 

// Enum class tanımı
enum class Color{red, blue, green};

int main(){
    Color x{Color::red};

    // std::cout << Color::red << std::endl; // Hata verir. cout Color'u nasıl yazdıracağını bilemez.
    std::cout << static_cast<int>(x) << std::endl; // Implicit olarak işe yarar hale getirdik

    return 0;
}