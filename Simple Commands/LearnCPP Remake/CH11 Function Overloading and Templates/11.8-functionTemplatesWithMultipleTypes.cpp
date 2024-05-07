/* Bazi durumlarda, (max(2, 3.5) cagrimi gibi) iki farkli turde degisken gonderildiginden hata alinabilir. Bunu engellemek icin 
3 farkli yola basvurabiliriz. 
1- static cast kullanarak tur donusumu
2- sablona explicit olarak tur gecirilmesi (onceki bolumde gosterdigim gibi)
3- sablonda birden fazla sablon elemani kullanilmasi
fonksiyon geridonuslerinde de C++20'den itibaren auto kullanabildigimizden orada donuse gore return tipini kendisi ayarlar
*/
#include <iostream>

template <typename T> // Bu yapinin scope'u sonraki fonksiyon veya sinif tanimlanana kadardir.
T max(T x, T y){
    return (x < y) ? y : x;
}
// 3. yontem, birden fazla sablon elemaninin oldugu sablon
template <typename T, typename U> // Bu yapinin scope'u sonraki fonksiyon veya sinif tanimlanana kadardir.
auto max(T x, U y){
    return (x < y) ? y : x;
}

int main(){
	std::cout << max(static_cast<int>(1.2), 2) << std::endl; // 1. yontem
	
	std::cout << max<int>(1.2,5) << std::endl; // 2. yontem
	
	std::cout << max(1.9,232); // 3. yontem
	
	return 0;
}
