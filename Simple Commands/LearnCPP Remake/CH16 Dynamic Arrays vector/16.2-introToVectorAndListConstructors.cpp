/* Vektörler C++'taki dizileri implemente eden konteynır sınıflardan biridir. <vector> headerında şablon olarak tanımlanmıştır, CTAD kullanımı yapılabilir.
Bu konteynırların özel bir list constructorları vardır, sayesinde bir liste ile beraber init edebilmemizi sağlar. 
Konteynır elemanlarına genel olarak operator[] ile erişilir. Burada dikkat edilmesi gereken durum operator[] herhangi bir sınır denetimi yapmaz.
Şu an vektör veya diğer konteynırlarda genel olarak bir constexpr kullanımı yoktur. Eğer constexpr zorunluysa std::array kullanılmalı.
*/

#include <iostream>
#include <vector>
int main(){
    // Düz vektor tanımı
    std::vector<int> vec{1,23,345,65,32};
    // Boş vektör, value init yapar
    std::vector<int> vec0{};
    // CTAD ile vektör tanımı
    std::vector vec1{1,3,4,534,345};
    // Belirli sayıda elemanla init etme, 10 elemanı value init yapar
    std::vector<int> vec10(10);
    // Biraz da yazdıralım, size üye fonksiyon ile uzunluğu alıp ona göre sınırı belirledik
    for(std::size_t i = 0; i < vec1.size(); i++){
        std::cout << vec1[i] << std::endl;
    }
    // Sınır denetimi yok!
    std::cout << vec1[20] << std::endl;
    return 0;
}
