/* Burası aslında 13.13'te incelediğimiz konuya teorik olarak çok benzer. O yüzden teorik olarak sıkmayacağım pratik önemli. Hemen
basit bir örnekle pekiştirelim ve aradan çıkaralım.
*/

#include <iostream>
// Klasik şablon tanımı, T türünde değişken belirlemesi
template <typename T>
class Pair{
    T m_first{};
    T m_second{};
    public:
    Pair(T x, T y): m_first{x}, m_second{y}{}
    void print(){
        std::cout << m_first << " " << m_second << std::endl;
    }
};

int main(){
    Pair p{12,24}; // CTAD kullanıyoruz Pair<int> oluyor kendiliğinden
    p.print();

    return 0;
}