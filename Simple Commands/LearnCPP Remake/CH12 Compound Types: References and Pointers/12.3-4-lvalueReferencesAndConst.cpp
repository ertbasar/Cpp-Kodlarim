/* lvalue references
Cpp'de referanslar onceden tanimlanmis bir objenin aliasidir denebilir. Referans uzerinde yapilan islemler gosterdigi/refere
ettigi objenin uzerinde de yapilmis olur. Aslinda referanslar gosterdigi objeyle tamamen aynidir diyebiliriz. Tanimi asagida.
referanslar bir kere tanimlandiktan sonra baska objeyi refere edemezler bu yuzden init etmek zorunlu
Referanslar Cpp'de obje olarak gecmezler, bu yuzden bellekte herhangi bir alan kaplamazlar. Bundan dolayi hem bazi yerlerde
kullanilamazlar hem de bazi yerlerde kullanimlari islerimizi cok kolaylastirir.

lvalue references to const
Ayrica const objelere normal tanimla refere islemi yapamayiz. Burada lvalue references to const denilen farkli bir tanimlama
islemi yapilmasi gerekir. Ayrica bu sekilde non-const degerleri de refere edebiliriz. Refere edilen objenin degeri degistirilmeyecekse
kullanimi iyi olur. 
const lvalue referanslarini ayni zamanda rvaluelerle de kullanabiliriz.
Bir const lvalue referansi gecici bir objeye baglandiginda o objenin yasam omru referansi esleyecek sekilde uzatilir.
const oldugu gibi constexpr lvalue referanslari da tanimlayabiliriz ancak bunu yapmak icin refere edilen degiskenin static
bir omre sahip olmasi gerektiginden kullanimi pek yoktur denebilr.

*/
#include <iostream>

int main(){
	int x{5};
	int y{23};
	const int z{34};
	int& ref{x}; // x yerine kullanilabilecek lvalue referansi, derleyici gozunden &'i nereye koydugumuz fark etmiyor ancak
	// &ref yerine int& kullanimi daha iyi olur.
	
	std::cout << x << std::endl;
	std::cout << ref << std::endl;
	//&ref = y; // Bu sekilde refere edilen yeri degistiremeyiz
	ref = y; // Bu sekilde y'nin degerini ref'e atabiliriz
	ref = 55;
	
	std::cout << ref << std::endl; 
	std::cout << y << std::endl;
	std::cout << x << std::endl;
	
	//int& ref2{z}; //const objelere bu sekilde bir referans tanimlayamayiz
	// Dogru kullanim asagidaki gibidir.
	const int& ref2{z}; 
	std::cout << ref2 << std::endl;
	const int& ref3{8};
	std::cout << ref3 << std::endl;
	return 0;
}
