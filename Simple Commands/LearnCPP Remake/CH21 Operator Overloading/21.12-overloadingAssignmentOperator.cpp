/* Kopyalama operatörü operator=, bir objenin bilgilerinin başka bir hali hazırda bulunan objeye aktarılması işlemini yapmamızı sağlayan operatördür. 
Aslında amacı copy constructor'a benzer, ikisi de bir objeye başka bir objenin bilgilerini kopyalar, ancak buradaki temel fark copy constructor'un yeni
bir obje init etmesiyken, copy assignment'ın zaten bulunan bir objeye bilgileri kopyalaması. Member fonksiyon olarak overload edilir. İlginç olsa da C++
self-assignment yani kendi kendine kopyalamaya izin verir, ancak bu işlem özellikle dinamik bellek tahsisi yapılan durumlarda çok tehlikeli olabilir.
Diğer operator overload durumları yerine, derleyici aslında kendiliğinden bir operator= overload oluşturur. Burada memberwise eşitlemeler yapar. Diğer
constructor ve operatörler gibi bu işlemleri '= delete' kullanarak veya private tanımlayarak engelleyebilir veya kendi tanımlamalarımızı yapabiliriz. 
memberwise copy -> Her sınıf elemanının teker teker kopyalanması
*/

#include <iostream>

class Coordinates{
private:
    int m_x{};
    int m_y{};
public:
    Coordinates() = default; 
    Coordinates(int x, int y):m_x{x},m_y{y}{}
    void print(){
        std::cout << "x: " << m_x << std::endl; 
        std::cout << "y: " << m_y << std::endl; 
    }
    // get çağrılırken genelde const obje kullanma durumu olduğundan eklemesi yapıldı
    int getX() const{
        return m_x;
    }
    int getY() const{
        return m_y;
    }
    void setX(int x){
        m_x = x;
    }
    void setY(int y){
        m_y = y;
    }

    // operator= overload işlemi
    Coordinates& operator=(const Coordinates& coord){
        // ilk olarak self-assignment olup olmadığı kontrol edilir.
        if(this == &coord)
            return *this;

        // sırayla kopyalama işlemleri yapılır
        m_y = coord.m_y;
        m_x = coord.m_x;

        // en sonunda *this döndürürüz ki zincirleme işlemler de yapılabilsin
        return *this;
    }

    // Eğer bu işlemi engellemek istersek
    //Coordinates& operator=(const Coordinates& coord) = delete; // kopyalamayla assignment'ı engeller
};

int main(){
    Coordinates co1(3,9);
    Coordinates co2(2,4);

    co2 = co1;
    co2.print(); // x = 3 ve y = 9 bekleriz ve de bu sonucu görürüz

    return 0; 
}