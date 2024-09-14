/* Sınıf tanımlamaları aslında aynı yapılar gibidir. Sadece struct yerine class kullanırız ve de elemanlara erişim konusunda farklılıklar vardır.
Çoğu standart Cpp kütüphanesi de sınıflardan oluşur. std::string buna örnek olarak verilebilir.
*/

#include <iostream>

// Basit bir sınıf tanımı (hepsi private)
class Employee{
    int id{};
    std::string name;
};

int main(){


    return 0;
}
