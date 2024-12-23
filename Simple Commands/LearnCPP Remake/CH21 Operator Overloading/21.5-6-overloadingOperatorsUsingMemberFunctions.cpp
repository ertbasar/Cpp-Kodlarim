/* Friend fonksiyonlara çok benzer, sadece artık üzerinden işlem yapılan objeyi kullanırken farklılık oluyor. Burada üye olarak yapılması ve yapılmaması
daha iyi olan operatörler var. 
Member -> '=', '[]', '()', '->'
non-member -> '<<' tipik olarak sol tarafı sınıf olmayan veya bizim değiştiremediğimiz bir sınıf (ostream) olduğunda non-member yaparız
Ayrıca operator! diğer operatörlerden biraz farklıdır. Sadece tek operand üzerinden işlemler gerçekleştirdiğinden ötürü member olarak implemente edilir.
*/


#include <iostream>

class Coordinates{
private:
    int m_x{};
    int m_y{};
public:
    Coordinates() = default; 
    Coordinates(int x, int y):m_x{x},m_y{y}{}
    Coordinates operator+(const Coordinates& c1);
    void print(){
        std::cout << "x: " << m_x << std::endl; 
        std::cout << "y: " << m_y << std::endl; 
    }
    // koordinatları -1 ile çarpan şekilde overload ettim
    Coordinates operator!(){
        m_x = -m_x;
        m_y = -m_y; 
        return *this;
    }
};

// üye fonksiyon olduğundan dolayı tek bir parametre alır. Dönerken de üzerinde işlem yapılan obje döndürülür. 
Coordinates Coordinates::operator+(const Coordinates& c1){
    m_x = c1.m_x + m_x;
    m_y = c1.m_y + m_y;
    return *this;
}

int main(){
    Coordinates co1(1,2);
    Coordinates co2(2,4);
    Coordinates co3{co1 + co2};
    co3.print();
    
    // koordinatları -1 ile çarptım
    co2 = !co2;
    co2.print();
    return 0;
}