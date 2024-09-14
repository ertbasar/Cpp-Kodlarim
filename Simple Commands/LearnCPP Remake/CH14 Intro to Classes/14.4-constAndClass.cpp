/* const objeler non-const üye fonksiyonlarla çalışmayı reddedebilirler. bu yüzden const üye fonksiyonlar da kullanılır.
Bu const üye fonksiyonlar, objeyi değiştirmeyeceklerini veya üye olmayan bir fonksiyonu çağırmayacaklarını vaat eden fonksiyonlardır.
hem const hem de non-const objeler tarafından çağrılabilirler. Bu yüzden eğer objede değişiklik olmayacaksa (getter gibi) const tercih edilmeli
Pek kullanılmasa da const ve non-const olmak üzere overload etmek mümkündür.
14.3'teki örneğin benzerini yazacak olursak
*/

#include <iostream>
class Foo{
    public: // Buna sonra değinecegiz
    int id{15};
    // Burada üye fonksiyon tanımını yapıyoruz.
    void print(){
        std::cout << id << std::endl;
    }
    void print() const {
        std::cout << id << std::endl;
    }
    void print2() const {
        std::cout << id << std::endl;
    }
};


int main(){
    Foo goo;
    const Foo doo;
    goo.print();
    doo.print(); //Eğer const olarak overload etmeseydim hata verir ve calismazdi
    goo.print2(); // non-const objeler de const üye fonksiyonlarla çalışabilirler

    return 0;
}
