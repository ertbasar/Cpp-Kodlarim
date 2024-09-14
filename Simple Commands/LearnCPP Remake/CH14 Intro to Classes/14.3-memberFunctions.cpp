/* Üye değişkenler gibi üye fonksiyonlar da bulunmakta. Tanımlamaları dışarda yapılsa bile sınıfın içinde deklare edilmeliler. 
Üye fonksiyonlarda fonksiyonu kullanılan objeyi özellikle göndermemize gerek yok. 
Üye fonksiyon veya değişkenler istenen sıralamayla yazılabilirler. Normalde Cpp yukarıdan aşağıya doğru derlese de burada o şekilde olmaz
Eğer sınıfta üye değişken yoksa, sınıfı namespace olarak değiştirmek mantıklı olabilir
*/
#include <iostream>
class Foo{
    public: // Buna sonra değinecegiz
    int id{15};
    // Burada üye fonksiyon tanımını yapıyoruz.
    void print(){
        std::cout << id << std::endl;
    }
    // İçeride tanımlamamıza gerek yok. Tanımı aşağıda yaptım
    void print2();
};

// Dışarıda tanım
void Foo::print2(){
    std::cout << id << std::endl;
}

// Üye olmayan bır fonksiyonun kullanımı. Ekstradan bir referans kullanımı da oldu
void print(const Foo& a){
    std::cout << a.id << std::endl;
}

int main(){
    Foo goo;
    goo.print();
    print(goo);
    return 0;
}
