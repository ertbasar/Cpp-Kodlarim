/* C'de şimdiye kadar kullandığımız değişkenler veya sabitler C-style string olarak geçer. Bunlar yerine std::string kullanımı önemli.
Bu aslında bir sınıf tipidir ve <string> headerında bulundan std::string, diğer değişkenler gibi kullanılabilir. 
şu anda constexpr ile bir kullanımı yoktur.
stringler init edilirken stringin bir kopyası kullanılır ve bu nispeten 'pahalı' diyebileceğimiz bir işlemdir. Bu yüzden fonksiyonlara gönderirken
mümkünse pass by value kullanılmamalıdır. returnler için de benzer bir sorun bulunmaktadır.
*/
#include <iostream> 
//#include <string> //kütüphane eklenmesi tam olarak gerekmeyebilir, iostreamde olabilir ben yoruma alınca da çalıştı

int main(){
    char isim1[10] = "Ertugrul"; //C-style string
    std::string isim2{"Ertugrul"};
    std::cout << isim1 << std::endl;
    std::cout << isim2 << std::endl;
    std::string deneme{};
    //std::cin >> deneme;
    std::getline(std::cin >> std::ws, deneme);//enter girilene kadarki kısmı almak için bir i/o manipülasyonu yapmak gerekir, yukarıdaki gibi olmaz
    std::cout << deneme << std::endl;


    return 0;
}