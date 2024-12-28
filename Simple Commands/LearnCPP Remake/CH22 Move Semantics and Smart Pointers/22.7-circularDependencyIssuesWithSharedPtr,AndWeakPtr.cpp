/* shared_ptr'nin birden fazla smart pointerla beraber aynı kaynağa işaret edebileceğini gördük. Bu durum bazen problemlere yol açabilir. Dairesel 
referans dediğimiz kavram, Bir grup nesne veya referans, birbirini işaret ederek bir döngü oluşturur. Sonuç olarak, son nesne tekrar ilk nesneyi 
işaret eder ve bu bir referans döngüsü oluşturmasıdır. Birbirini işaret eden iki nesneyi düşünelim, burada döngüsel referanslar, bellekteki nesnelerin 
serbest bırakılmasını engelleyebilir. Özellikle akıllı işaretçilerle (e.g., std::shared_ptr) çalışıyorsanız, bu bir bellek sızıntısına yol açabilir.
Döngü, programın çalışmasını zorlaştırabilir, çünkü referans zincirini takip etmek karmaşık hale gelir. Bu problemi çözmek adına da weak_ptr tanımlanmış.
Buradaki weak_ptr bir gözlemci denebilir, başka bir pointerla beraber aynı objeyi gösterebilir, gözlemleyip erişebilir, ancak sahip olarak 
değerlendirilmez. weak_ptr objeleri direkt olarak kullanılabilir objeler değillerdir çünkü operator->'e sahip değiller. Kullanabilmek için öncelikle
lock() üye fonksiyonunu kullanmak gerekir. Herhangi bir weak_ptr'nin geçerli olup olmadığına da expired() üye fonksiyonuyla bakılabilir.
*/

#include <iostream> 

#include <memory>
#include <utility>

// işlemlerde kullanmak amacıyla basit bir sınıf tanımlayalım
class Coordinates{
private:
    int m_x{};
    int m_y{};
public:
    Coordinates(){
    std::cout << "Coordinates objesi default cons. ile oluşturuldu." << std::endl;
    }; 
    Coordinates(int x, int y):m_x{x},m_y{y}{
        std::cout << "Coordinates objesi paramtreli cons. ile oluşturuldu." << std::endl;
    }
    ~Coordinates(){std::cout << "Coordinates objesi parçalandı" << std::endl;}
    friend Coordinates operator+(const Coordinates& c1, const Coordinates& c2);
    void print(){
        std::cout << "x: " << m_x << std::endl; 
        std::cout << "y: " << m_y << std::endl; 
    }
    int getX() const{
        return m_x;
    }
    void setX(int x){
        m_x = x;
    }
};

int main(){
    Coordinates* co1{new Coordinates{1,3}};

    // ilk olarak bir shared_ptr oluşturalım
    std::shared_ptr<Coordinates> sharedCo{co1};

    std::weak_ptr<Coordinates> weakCo = sharedCo;

    // weak_ptr'ın durumu kontrol ediliyor
    if (weakCo.expired()) {
        std::cout << "Kaynak bitmiş gitmiş!" << std::endl;
    } else {
        std::cout << "Resource halen hayatta!" << std::endl;
    }

    // weak_ptr üzerinden shared_ptr oluşturmak için lock() kullanımı
    if (auto lockedCo = weakCo.lock()) { // lock başarılıysa shared_ptr döner
        lockedCo->print();
    } else {
        std::cout << "Böyle bir lock işlemi yapılamaz!" << std::endl;
    }

    // shared_ptr'ın serbest bırakılması
    sharedCo.reset();

    // weak_ptr'ın durumu tekrar kontrol ediliyor
    if (weakCo.expired()) {
        std::cout << "Kaynak bitmiş gitmiş!" << std::endl;
    } else {
        std::cout << "Resource halen hayatta!" << std::endl;
    }
    return 0;
}