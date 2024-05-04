/* stringlerin init veya copy işlemlerinin init ve copy işlemlerinin pahalı işlemler olduklarını belirtmiştik. bundan dolayı c++17 ile beraber
<string_view> headerıyla gelen std::string_view tanıtıldı. Bu obje zaten bulunan stringe bir referans gibi read-only bir erişim sağlar. Bu
sayede fonksiyon parametresi gibi yerlerde kullanımı ile daha verimli bir program yazımı yapılır. 
Fazlasıyla esnek bir yapı olduğundan dolayı c-style string ve std::stringlerle init edilebilir veya argüman olarak alabilir.
stringin aksine constexpr ile kullanılabilir ve constexpr return değeri olarak fonksiyonlarda c-style string döndürülebilir.
.remove_suffix(1) veya .remove_prefix(1) gibi eklerle de önden veya arkadan gösterdiği alan kırpılabilir, stringi değiştirmez

*/

#include <iostream>
#include <string_view>

//Bir string_view parametre alıp yazdıran fonksiyon
void printString(std::string_view str_view) {
    std::cout << str_view << std::endl;
}

int main() {
    std::string str = "Merhaba, dunya!";
    //std::string str'yi gösteren view 
    std::string_view view{str};
    
    printString(view);
    //string'i değiştirelim
    str = "Hello, world!";
    //içeriği değişecek
    printString(view);
    //onden bir çıkardık
    view.remove_prefix(1);
    printString(view);

    //stringi değiştirmemize rağmen önden bir karakter kısacak
    str = "selam dunya";
    printString(view);

    //view'a deneme yazdım ve artık c-style bir stringi gösterecek
    view = "deneme";
    printString(view);

    //yeniden eski str'yi refere edelim, normal bir şekilde kırpmadan gösterecek
    view = str;
    printString(view);
    return 0;
}
