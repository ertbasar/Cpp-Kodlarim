/* Aslında her üye fonksiyonun içinde o an kullanılan objenin adresini tutan 'this' pointerı bulunur. Genel olarak kullanmayız ancak bazı kullanım alanları
bulunmakta tabii. Tüm non-static üye fonksiyonlar bu this pointerına sahiptir ve genel olarak 2 durumda kullanılır:
1- Üye fonksiyondaki bir parametre ile üye değişkenin aynı isimde olmaları.
2- Üye fonksiyonun return değerinde objenin kendisini değer olarak döndürmesine yardımcı olur. Buna method chaning denir ve örneği aşağıda olacak.
3- Sınıf objesini default haline geri döndürmek. Burada yapılacak en iyi şey reset üye fonksiyonunu tanımlayıp içinde işlemi gerçekleştirmek.
Const olmayan üye fonksiyonlarında bu this pointer const pointer to a non-const value olduğundan dolayı işaret edilen obje üzerinde değişiklik yapılabilir 
ancak gösterdiği obje değiştirilemez.
*/

#include <iostream>

// Basit bir sınıf tanımlayalım
class Foo{
    public:
    int first{};
    int second{};
    void print();
    Foo() = default;
    Foo(int x, int y):first{x}, second{y}{}
    void addValue(int first, int second);
    Foo& addValueChain(int first, int second);
    void reset(){*this = {};} // Default constructor olmadan çalışmaz
};
// Basit bir yazdırma fonksiyonu. Amacı sadece yazdırma islemi
void Foo::print(){
    std::cout << first << " " << second << std::endl;
    std::cout << this->first << " " << this->second << std::endl;
}

void Foo::addValue(int first, int second){
    this->first += first;
    this->second += second;
}

// Method chanining tanımlaması için güzel bir örnek. Burada return yaparken objenin referansını dönüyoruz ve sonraki işlemler de bu obje üzerinden yapılıyor.
Foo& Foo::addValueChain(int first, int second){
    this->first += first;
    this->second += second;
    return *this;    
}

int main(){
    Foo deneme(12,23);
    deneme.print();
    deneme.addValue(12,10);
    deneme.print();

    // Method chaining işlemi. Bazı işlemler art arda gerçekleştiriliyor. Başka basit örneği 4 işlem olabilir
    deneme.addValueChain(12,10).addValueChain(10,23);
    deneme.print();
    // deneme.addValue(12,10).addValue(12,10); // Bu satır olmaz çünkü void dönmüş oluyor ve bu bizim sınıf objemiz değil

    // reset işlemi yapıp yazdıralım
    deneme.reset();
    deneme.print();
    return 0;
}



