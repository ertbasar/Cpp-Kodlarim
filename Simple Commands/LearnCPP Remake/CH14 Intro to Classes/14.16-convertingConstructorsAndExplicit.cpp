/* Kendiliğinden dönüşüm yapabilen constructorlara converting constructor denir. Default olarak zaten tüm constructorlar convertingdir. Burada dönüşümler
gerçekleşirken istenmeyen dönüşümler gerçekleşebilir. Bu yüzden bu kullanımın çalışmasına olabildiğince izin vermemek lazım. 
Bu dönüşümleri engelleme adına explicit kelimesini fonksiyondan önce kullanabiliriz. Burada nota değer iki durum var: 1- copy init ve copy list ile 
kullanılamaz 2- implicit conversionları engeller.
Burada önemli olan 3 durum var
1- explicit olmalalı: copy ve move constructorlar. zaten conversiona gerek yok
2- genelde explicit yapılmayanlar: parametre almayan default constructorlar, birden fazla argüman alan constructorlar
3- explicit yapılması genelde gerekenler: tek bir argüman alan constructorlar (Burada amaç yanlış bir veri türüne dönüştürülüp istenenden farklı bir şey olması)
*/


#include <iostream>

class Foo{
    int m_id;
    std::string m_name;
    public:
    Foo(int id, std::string_view name): m_id{id}, m_name{name}{std::cout << "Bir Foo objesi oluşturuldu" << std::endl;}
    
    // Tek argüman alan bir adet explicit constructor
    explicit Foo(int id): m_id{id}{std::cout << "Bir Foo objesi explicit constructorla oluşturuldu" << std::endl;}
    
    //Copy constructor tanımlanması. 
    Foo(const Foo& foo):m_id{foo.m_id}, m_name{foo.m_name}{std::cout << "Bir Foo objesi kopyalanarak oluşturuldu" << std::endl;}
    
    void print(){std::cout << "Objenin \nID: " << m_id << "\nObjenin Adı: " << m_name << std::endl;}
};


int main(){
    Foo doo{23};
    // Foo goo{'string'};
    doo.print();
    // goo.print();
    return 0;
}