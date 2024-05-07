/* Sablon fonksiyon cagrimi yaparken normal fonksiyondan biraz daha farkli bir durum soz konusudur. Burada acili parantezlerle 
tur belirtmek iyi fikir olur cunku ayri tiplerde arguman kullanirsak ve bunlar icin yeteri sayida sablon kullanimi yaratmamissak
burada kafasi karisir ve hata verebilir. Bu sekilde kullanim bizi saglama alir
Sablon fonksiyonlari farkli dosyalarda beraber kullanmak istersek linker error vermemesi adina forward declaration yapmak 
yerine header icinde eklememiz gerekir.
*/

#include <iostream>

template <typename T> // Bu yapinin scope'u sonraki fonksiyon veya sinif tanimlanana kadardir.
T max(T x, T y){
    return (x < y) ? y : x;
}

int main(){

	std::cout << max<int>(1,2) << std::endl; 
	std::cout << max<int>(1.2,5); 
	// std::cout << max(1.2,5); // hata verir. cunku iki ayri tipte arguman kullandik
	
    return 0;
}
