/* 3 farklı şekilde operatörler overload edilebilir. 
1. Member function
2. Friend function
3. Normal function
Burada overload işlemini sıralama ve türlere göre tekrar tekrar tanımlamak gerekebilir. Cents(4)+6 ile 6+Cents(4) aynı değildir.
*/

#include <iostream>

class Coordinates{
private:
    int m_x{};
    int m_y{};
public:
    Coordinates() = default; 
    Coordinates(int x, int y):m_x{x},m_y{y}{}
    friend Coordinates operator+(const Coordinates& c1, const Coordinates& c2);
    void print(){
        std::cout << "x: " << m_x << std::endl; 
        std::cout << "y: " << m_y << std::endl; 
    }
};

Coordinates operator+(const Coordinates& c1, const Coordinates& c2){
    Coordinates c3;
    c3.m_x = c1.m_x + c2.m_x;
    c3.m_y = c1.m_y + c2.m_y;
    return c3;
}

int main(){
    Coordinates co1(1,2);
    Coordinates co2(2,4);
    Coordinates co3{co1 + co2};
    co3.print();
    return 0;
}