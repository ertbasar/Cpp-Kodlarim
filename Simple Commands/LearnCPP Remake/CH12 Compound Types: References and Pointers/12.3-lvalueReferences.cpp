/* Cpp'de referanslar onceden tanimlanmis bir objenin aliasidir denebilir. Referans uzerinde yapilan islemler gosterdigi/refere
ettigi objenin uzerinde de yapilmis olur. Aslinda referanslar gosterdigi objeyle tamamen aynidir diyebiliriz. Tanimi asagida.
referanslar bir kere tanimlandiktan sonra baska objeyi refere edemezler bu yuzden init etmek zorunlu
Referanslar Cpp'de obje olarak gecmezler, bu yuzden bellekte herhangi bir alan kaplamazlar. Bundan dolayi hem bazi yerlerde
kullanilamazlar hem de bazi yerlerde kullanimlari islerimizi cok kolaylastirir.
*/
#include <iostream>

int main(){
	int x{5};
	int y{23};
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
	return 0;
}
