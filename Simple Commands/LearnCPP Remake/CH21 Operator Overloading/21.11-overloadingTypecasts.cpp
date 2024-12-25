/* C++ zaten built-in dediğimiz veri türlerinin nasıl dönüştürüleceği hakkında bilgilidir, ancak user-defined türlerde nasıl dönüşüm yapacağını tam olarak
bilemez. Burada da devreye typecast overload operator devreye girer. Burada atlanmaması gereken 3 adet şey var:
1. Sınıfı int'e overload edebilmek için sınıfın altında 'operator int()' adında bir fonksiyon oluştururuz. Burada operator ile int arasındaki boşluğa dikkat
2. Herhangi bir parametreleri olmamasına rağmen gizli bir *this pointer'a sahiptir
3. Herhangi bir geridönüş türü belirtmezler. Tür dönüşümünün türü return türü olarak kullanılır.
Bu tür değişimi overload işlemini hem built-in hem de user-defined türlere yapabiliriz yani herhangi bir sınır yoktur. 
Nasıl constructorlarda farklı bir türü implicit olarak dönüştürüp kullanmasın diye explicit anahtar sözcüğünü kullanıyorsak, burada da kullanabiliriz, ki
zaten özel bir durum olmadığı taktirde explicit yapmamız daha iyi olur. Son olarak da tür dönüşümü overload'ı ile converting constructorlar aslında benzer
iki kavramdır, genel olarak converting constructor tercih edilmelidir diyebiliriz 

*/


#include <iostream>

class Coordinates{
    int m_x{};
    int m_y{};
public:
    Coordinates(int x, int y): m_x{x}, m_y{y}{};

    // int overload işlemi yapalım. Koordinatların toplamını döndürüyoruz 
    explicit operator int() const {
        return m_x + m_y; 
    }
  
};



int main(){
    Coordinates coord(2,4);
    // int value = coord; // explicit yazdığımızdan dolayı implicit tür dönüşümü engellenir. hata verir
    // std::cout << "Koordinatların toplamlarının değeri: " << coord << std::endl; // burada zaten hata verir, nasıl yazacağını bilemez
    
    // cast'i kendimiz belirtirsek artık sıkıntı olmaz
    int value2 = static_cast<int>(coord);
    std::cout << "Koordinatların toplamlarının değeri: " << value2 << std::endl;

    return 0;
}