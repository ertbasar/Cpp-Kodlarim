/* Fonksiyon try blokları exception yakalamanın veya kontrolün bir blok içerisinde değil de tüm fonksiyon içerisinde gerçekleşmesini sağlar diyebiliriz. 
Try kelimesinden fonksiyonun sonuna kadar try bloğu olarak kabul edilir. 
Constructor'da member init list verdiğimiz zaman bir exception yakalanacaksa kullanımı çok mantıklı olur. 
Burada önemli olan noktalardan biri ise eğer bu try bloğu constructor içinde yapılacaksa ya yeni bir exception göndermeli veya aynısını rethrow yapmalı.
Kendi başına exceptionları handle etme gibi bir yetkisi yok. Return ifadeleri de mümkün olmadığından bloğun sonuna geldiği zaman rethrow yapar. 
Bu yüzden fonksiyon seviyesindeki catch bloğunun sonuna gelmeden kendimiz throw edersek daha iyi olur. 
Fonksiyon catch blokları hem baz hem de türeyen sınıftaki exceptionları yakalayabilir.
Örneği direkt siteden aldım bu sefer
*/


#include <iostream>

class A
{
private:
	int m_x;
public:
	A(int x) : m_x{x}
	{
		if (x <= 0)
			throw 1; // Exception fırlatımı
	}
};

class B : public A
{
public:
	B(int x) try : A{x} // try keyword'ü bu şekilde ekleniyor
	{
        if (x <= 3) // Aynı fırlatma işlemi burada da gerçekleşebilir
		throw 1;

	}
	catch (...) 
	{
                // member initializer list veya constructor body'sindeki exceptionlar buraya düşer
                std::cerr << "Exception caught\n";

                throw; // rethrow işlemi, kendisi direkt handle edemez demiştik
	}
};

int main()
{
	try
	{
		B b{2};
	}
	catch (int)
	{
		std::cout << "Oops\n";
	}
}