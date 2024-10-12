/* Konteynır sınıf objelerine uzunluklarını size üye fonksiyonuyla sorabiliriz ancak bu fonksiyonlar unsigned size_type (std::size_t) döndürürler.
Bu yüzden bazı yerlerde sıkıntı çıkabilir. Bunun önüne geçebilmek adına C++20'de std::ssize non-member fonksiyonu tanıtıldı. Bu sayede artık geridönüşü 
signed bir veri tipiyle alıyoruz. 
operator[]'ın sınır denetimi yapmadığını söylemiştir. Bunun yerine at member fonksiyonu kullanabiliriz.
*/

#include <iostream>
#include <vector>


int main(){
    std::vector v1{1,2,3,4,5,6};
    // member fonksiyonla size çekimi
    std::cout << v1.size() << std::endl;
    // non-member fonksiyonla size çekimi, derleyicide sıkıntı olmamasına rağmen vs code hata olarak algıladığından aşağıdaki satırı yoruma aldım
    // std::cout << std::ssize(v1) << std::endl;
    // sınır denetimi denemesi, runtime hata verdirir, abort olur
    std::cout << v1.at(12) << std::endl;
    return 0;
}