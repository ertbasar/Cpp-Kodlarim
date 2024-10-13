/* Programcılıkta stack denilen alan LIFO mantığıyla çalışan elementlerin giriş çıkış yaptığı bir yığındır. Push ve pop adında temel iki operatörle beraber
çalışır.
Vektörde reserve() üye fonksiyonu kapasiteyi değiştirir ancak boyutu değiştirmez. 
Vektörde push_back() ve emplace_back() iki adet eleman ekleme fonksiyonudur. Eğer varolan bir objeyi ekleyeceksek puch_back, geçici bir obje
eklenecekse de emplace_back() tercih edilmelidir. Bu biraz da emplace_back'in sahip olduğu explicit constructor kullanabilme yeteneğidir.
Aşağıdaki örnekte incelemeler yapılabilir. Bu sefer kendim yazmadım LearnCPP'den kopyaladım, yorumlarımı kattım
*/

#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class Foo
{
private:
    std::string m_a{};
    int m_b{};

public:
    Foo(std::string_view a, int b)
        : m_a { a }, m_b { b }
        {}

    explicit Foo(int b)
        : m_a {}, m_b { b }
        {};
};

int main()
{
	std::vector<Foo> stack{};

	// Zaten elimizde obje varsa, push_back ve emplace_back aynı verimlilikte
	Foo f{"asd", 2};
	stack.push_back(f);    // bunu tercih etmek daha iyi
	stack.emplace_back(f);

	// Ekleme için geçici obje kullanılacaksa emplace_back kullanılmalı
	// stack.push_back({ "a", 2 }); // geçici bir obje oluşturup vektöre kopyalar
	stack.emplace_back("a", 2);  // argümanları direkt vektörün içine gönderip orada oluşturulmasını sağlar (herhangi bir kopyalama işlemi yok)

	// push_back explicit constructorlarda çalışmaz, emplace_back çalışır 
	// stack.push_back({ 2 }); // explicit constructor olduğundan çalışmaz
	stack.emplace_back(2);

	return 0;
}