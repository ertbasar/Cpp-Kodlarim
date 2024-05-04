/* Static lokal değişkenler yaratıldığı andan program sonlanana kadar bellekte yer tutan değişkenlerdir. Scope dışına çıksa da değerini korur.
Ne kadar bazı yerlerde yeniden init ediliyor gibi gözükse de bir kere init edilirler ve tanım noktasına bir kez daha gelince sanki tanım işlemi yokmuş gibi
davranırlar. 
statik yerel değişkenler aynı zamanda const veya constexpr de yapılabilir. Değerinin sabit kalması istendiğinde her seferinde yeni bir değişken init 
etmemek için kullanılabilir.
statik yerel değişkenlerin internal linkage'ı vardır ve tanımlarken init yapmak önemlidir çünkü o satıra bir daha gelse de tanım yapmayacaktır.
*/

#include <iostream>

int ogrenci_sayi_arttir(){
    static int ogrenci_sayi{10};
    return ++ogrenci_sayi;
}

int main(){

    std::cout << ogrenci_sayi_arttir() << std::endl;
    std::cout << ogrenci_sayi_arttir() << std::endl;
    std::cout << ogrenci_sayi_arttir() << std::endl;

    return 0;
}