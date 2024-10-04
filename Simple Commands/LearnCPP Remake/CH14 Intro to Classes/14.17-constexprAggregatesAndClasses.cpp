/* non-member fonksiyonlar gibi member fonksiyonlar da constexpr yapılabilir. Bu da derleyiciye fonksiyonun run-time veya compile-time zamanında
değerlendirilebileceğini belirtir. Burada üye fonksiyona gönderilen argümanın da constexpr olması önemli.
Bu arada objeler de tanımlanırken constexpr yapılabilir. Ancak bu constructorun kullanılmadığı durumlar için yani daha çok structların kullanıldığı 
zaman için denebilir. Ancak class için de geçerli olmasını istersek de verileri publice geçirmemiz gerekir, bu da aslında sınıf kullanmamızın amacını
ortadan kaldırır.
Ayrıca constructorlarımızı da constexpr yapabiliriz. Bu sayede compile-time'da işlem görebilir
*/

// Aşağıdakini direkt LearnCPP'den çevirdim. Bu sefer fazla uğraşmak istemedim
#include <iostream>

struct Pair // Pair aggregate oldu
{
    int m_x {};
    int m_y {};

    // fonksiyon constexpr yapıldı
    constexpr int greater() const
    {
        return (m_x > m_y  ? m_x : m_y);
    }
};

class Pair2
{
private:
    int m_x {};
    int m_y {};

public:
    constexpr Pair2(int x, int y): m_x { x }, m_y { y } {} // constexpr constructor yapıldı

    constexpr int greater() const // fonksiyonu da constexpr yaptık
    {
        return (m_x > m_y  ? m_x : m_y);
    }
};

int main()
{
    constexpr Pair p { 5, 6 };       // now constexpr
    std::cout << p.greater() << std::endl;        // p.greater() evaluates at runtime or compile-time

    constexpr int g { p.greater() }; // p.greater() must evaluate at compile-time
    std::cout << g << std::endl;

    constexpr Pair2 p1 { 5, 6 };
    std::cout << p1.greater() << std::endl;

    constexpr int g1 { p1.greater() };
    std::cout << g1;
    return 0;
}