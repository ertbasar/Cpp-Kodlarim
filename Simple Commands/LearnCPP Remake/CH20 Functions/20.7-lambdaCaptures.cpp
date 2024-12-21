/* Lambda ifadeleri, kendi içlerinde bulunmayan objelerden sadece statik olanları ve de constexpr olanlara erişebilirler. Bunu değiştirmek için capture
denilen bir özel bir liste kullanılır. Bu listedeki elemanlara defaultta const olarak davranırlar ancak (mutable kullanımıyla beraber)? listeye referans 
gönderimi sayesinde lambda ifadesini gönderilen listedeki elemanları değiştirebilir hale getirebiliriz. İçeride kullanılacak değişkenleri caption alanına
ekle çıkar yapmak sıkıntılı olabilir. Burada otomatik olarak oluşturulan ve default captures denen olay bize lambda içerisinde kullanılan her şeyi 
otomatik olarak listeye alır veya çıkarır.
[=] -> value için | [&] -> referans için kullanılabilir
Burada beraber kullanımlar da olabilir. Mesela [&, armor] -> her şey ref ile armor value ile. Bazen de capture alanında yeni bir değişken tanımlarız 
[userArea{genislik*uzunluk}] gibi. Sadece türü belli olan ve değeri short sınırlarında olan değişkenlerde yap. 
Lambdalar birer obje olduklarından dolayı o anki durumlarıyla kopyalanabilirler.
Mutable lambda kullanımı tehlikeli olduğundan kaçınmak gerekir.
Örnek için bu sefer çok uğraşmak istemedim bu sefer chatgpt'ye yazdırdım
*/

#include <iostream>
#include <vector>

int main() {
    int x = 10;
    int y = 20;

    // 1. Hiçbir şeyi yakalamayan lambda
    auto noCapture = []() {
        std::cout << "Hiçbir şey yakalanmadı!" << std::endl;
    };
    noCapture();

    // 2. Değer kopyalayarak yakalama ([x])
    auto captureByValue = [x]() {
        std::cout << "x (değer olarak yakalandı): " << x << std::endl;
    };
    captureByValue();

    // 3. Referans ile yakalama ([&x])
    auto captureByReference = [&x]() {
        x += 5; // x'in değeri değişir
        std::cout << "x (referans ile yakalandı ve değiştirildi): " << x << std::endl;
    };
    captureByReference();
    std::cout << "x'in ana fonksiyondaki yeni değeri: " << x << std::endl;

    // 4. Tüm değişkenleri değer olarak yakalama ([=])
    auto captureAllByValue = [=]() {
        std::cout << "x (değer olarak yakalandı): " << x << ", y: " << y << std::endl;
        // x ve y burada sadece okunabilir, değiştirilemez
    };
    captureAllByValue();

    // 5. Tüm değişkenleri referans ile yakalama ([&])
    auto captureAllByReference = [&]() {
        x += 10; // x değiştirilebilir
        y += 10; // y değiştirilebilir
        std::cout << "x ve y (referans ile yakalandı): " << x << ", " << y << std::endl;
    };
    captureAllByReference();
    std::cout << "x ve y'nin ana fonksiyondaki yeni değerleri: " << x << ", " << y << std::endl;

    // 6. Karma yakalama ([x, &y])
    auto mixedCapture = [x, &y]() {
        // x kopyalanmıştır, değiştirilemez
        // y referans ile yakalanmıştır, değiştirilebilir
        // x += 10; // Derleme hatası
        y += 10;
        std::cout << "x (değer olarak): " << x << ", y (referans olarak): " << y << std::endl;
    };
    mixedCapture();
    std::cout << "y'nin ana fonksiyondaki yeni değeri: " << y << std::endl;

    return 0;
}
