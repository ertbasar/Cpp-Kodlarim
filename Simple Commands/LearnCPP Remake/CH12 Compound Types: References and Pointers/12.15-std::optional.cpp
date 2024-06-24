/* std::optional, C++17 ile tanıtılan bir şablon sınıftır ve isteğe bağlı değerlerin yönetimini sağlar. Bu sınıf, bir değerin var olup olmadığına bakar 
ve eğer varsa o değeri temsil eder. Biraz alışılagelmişin dışında bir türdür. Pointerlara kullanım olarak benzetilebilir ancak tabii ki kullanım amaçları
çok çok farklıdır. Gemini ve LearnCpp'deki kodlarla beğendiğim bir karışımı aşağıda örnekledim.
*/
#include <optional>
#include <iostream>

// Opsiyonel olarak int döndüren bir fonksiyon
std::optional<int> doIntDivision(int x, int y)
{
    if (y == 0)
        return {}; // std::nullopt de döndürebilir
    return x / y;
}

// Örnek olarak ID alan ve kontrol işlemini yapan fonksiyon. Default değişken belirledik ki kendimizi sağlama aldık
void printIDNumber(std::optional<const int> id = std::nullopt) 
{
    if (id)
        std::cout << "ID numaranız" << *id << ".\n";
    else
        std::cout << "ID numaranız hatalı!!\n";
}

int main() {
    std::optional<int> x; // T türünde bir değeri tutabilen bir optional nesnesi

    // Değeri atama
    x = 10; // x'e 10 değerini atar

    // Değer kontrolü
    if (x.has_value()) { // x bir değere sahipse
        std::cout << "x: " << x.value() << std::endl; // Değeri yazdır
    } else {
        std::cout << "x boş" << std::endl;
    }

    // Değeri alma, burada aslında pointera benzer durumu gerçekleştirmiş olduk. 
    int y = *x; // x'in değerini y'ye atadı (eğer varsa)

    std::optional<int> result1 { doIntDivision(20, 5) }; // Direkt sonucu atacak
    if (result1) // eğer fonk istenen bir değer döndürürse
        std::cout << "Sonuç 1: " << *result1 << '\n'; 
    else // döndürmezse
        std::cout << "Sonuç 1: Hata!!\n";

    std::optional<int> result2 { doIntDivision(5, 0) }; // Şimdi de istenen cevabı vermeyecek bir değişken oluşturalım
    // Aslında aşağıdaki işlemleri fonksiyonel hale getirsek iyi olur. onu da yukarıda kendim yapayım
    if (result2)
        std::cout << "Sonuç 2: " << *result2 << '\n';
    else
        std::cout << "Sonuç 2: Hata!!\n";
    return 0;
}
