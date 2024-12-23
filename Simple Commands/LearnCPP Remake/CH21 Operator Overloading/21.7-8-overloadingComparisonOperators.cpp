/* Karşılaştırma operatörleri binary olduklarından ve de herhangi bir şeyi değiştirmediklerinden dolayı friend fonksiyon olarak yazılırlar. 
Burada gerçekten anlam ifade eden operatör overload yapmak mantıklı olur. 
C++20'den itibaren '<=>' spaceship operatörü de tanımlandı. Bu operatör sayesinde karşılaştırma fonksiyonlarının sayısını azaltmış oluyoruz.
İleride belki bu konuya da değinirim ancak şu an değinmeyeceğiz.
Bununla beraber '++' ve '--' operatörleri için de prefix ve postfix olarak iki adet farklı işlem var. Buradaki örnek biraz zorluydu LearnCPP'den detaylı
şekilde bakılması benim basit örneğime göre çok daha makul olur.
*/

#include <iostream>


class Coordinates{
private:
    int m_x{};
    int m_y{};
public:
    Coordinates(int x, int y):m_x{x},m_y{y}{}
    void print(){
        std::cout << "x: " << m_x << std::endl; 
        std::cout << "y: " << m_y << std::endl; 
    }
    // friend olarak burada ekleyip aşağıda tanımlayalım
    friend bool operator==(Coordinates& c1, Coordinates& c2);
};

// iki noktanın eşit olup olmadığını karşılaştıran operator== overload
bool operator==(Coordinates& c1, Coordinates& c2){
        return ((c1.m_x == c2.m_x) && (c1.m_y == c2.m_y));
    }

int main(){
    Coordinates co1(1,2);
    Coordinates co2(2,4);

    // iki koordinatın birbirine eşit olup olmadığını karşılaştıralım
    if(co1 == co2)
        std::cout << "İki nokta eşit" << std::endl;
    else
        std::cout << "İki nokta eşit değil" << std::endl;
    Coordinates co3(2,4);

    if(co3 == co2)
        std::cout << "İki nokta eşit" << std::endl;
    else
        std::cout << "İki nokta eşit değil" << std::endl;

    return 0;
}