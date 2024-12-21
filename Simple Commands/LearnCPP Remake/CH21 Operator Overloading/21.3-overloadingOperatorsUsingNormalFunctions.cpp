/* Normal fonksiyonlar yerine friend kullanımı private kısımda bulunan verilere direkt olarak erişim konusunda işimizi kolaylaştırdığından dolayı daha
uygun olur. Ancak böyle bir erişime ihtiyacımız yoksa normal fonksiyon olarak da yazabiliriz. Burada kullanımda çok fark olmuyor, sadece prototip
yazma konusunda farklılık olur. Eğer friend olursa .h dosyasında sınıfın içinde tanımlandığında prototip olarak sayılır, ancak normal fonksiyonda
normal olarak belirtmek gerekiyor. Eğer çok karmaşık ekstra işlemlere sebep olmayacaksa işlemleri friend değil de normal olarak tanımlamak daha iyi olur.
Az önce yazdığım örneğin aynısını bu sefer normal bir fonksiyon olarak yazacağım.
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
};


Coordinates operator+(const Coordinates& c1, const Coordinates& c2){
    Coordinates c3;
    c3.setX(c1.getX() + c2.getX());
    c3.setY(c1.getY() + c2.getY());
    return c3;
}

int main(){
    Coordinates co1(3,9);
    Coordinates co2(2,4);
    Coordinates co3{co1 + co2};
    co3.print();
    return 0;
}