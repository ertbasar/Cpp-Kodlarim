/* Cpp'de enumeration ya da kısaca enumlar değeri belli bir sembolik sabitlerle belli olan compound data türüdür (Temel türler kullanılarak oluşturulan
yeni tür). Cpp iki tür enum destekler, scoped ve unscoped. Burada enumlar program-defined tür olduğundan dolayı kullanmadan önce iyi bir şekilde tanımlanması
gerekir, aksi taktirde hata alınabilir. Unscoped enumlar aşağıdaki örneğindeki gibi tanımlanır. Enumlar isimlendirilmek zorunda değillerdir, ancak bundan
kaçınılmalıdır ve isimlendirirken büyük harfle başlamak iyi bir yöntemdir, elemanlarını isimlendirirken de küçük harfle başlayabiliriz. Unscoped enumlarda 
özellikle iki enum tipinde de aynı isimde bir tanımlama varsa hata alınır bu yüzden ya dikkat edilmeli ya da farklı namecpaceler kullanılmalı.

Enumlar temel sayı sabitleridir. Burada enum tanımladığımız zaman listedeki sırasına göre sayılar artan bir şekide değer alırlar. 
Enumları yazdırmak için switch-case vs de kullanılabilir. Üstüne << operatörünü overload etmek de mantıklı olabilir örneği learncpp-de 12.3'te var.
*/

#include <iostream>
// Enum tanımı, blue'da olduğu gibi aradan da sayı verebiliriz
enum Color{red, blue = 7, green };

int main(){
    int tshirt{red}; // 0'a eşitleyecek
    int jean{blue}; // 7'ye eşitleyecek
    int shoes{green}; // 8'e eşitleyecek
    std::cout << "His tshirt color-ID is " << tshirt << std::endl;
    std::cout << "His jean color-ID is " << jean << std::endl;
    std::cout << "His shoe color-ID is " << shoes << std::endl;

    return 0;
}