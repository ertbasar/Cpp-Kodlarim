/* unique_ptr'nin aksine shared_ptr, tek bir kaynağa sahip olmak ve yönetmek yerine birden fazla smart pointer'ın bir kaynağı yönetmesi durumunda 
kullanılacak obje türüne olan ihtiyacı çözmek için tanımlanır. Yani birden fazla shared_ptr'nin aynı kaynağa işaret etmesi normal olan bir şeydir. 
Shared pointerlar kendi içlerinde o kaynağa işaret eden kaç tane pointer olduğunu da tutarlar. En az bir shared_ptr bir kaynağa işaret ettiği sürece
o kaynağa tahsis edilen bellek sisteme geri verilmez. <memory> altında bulunur ve unique_ptr üzerinden oluşturulabilir, burada unique_ptr'nin içindeki
bilgiler shared_ptr'ye transfer edilir. C++17'ye kadar dizileri yönetemezken C++20'den itibaren dizileri destekler. Eğer aynı kaynağa işaret edecek
ikinci bir shared_ptr tanımlanacaksa, bunun direkt kaynak üzerinden değil de hali hazırda bulunan bir shared_pointer üzerinden tanımlanması önemli!
Bu sayede birbirlerinden haberleri olur ve de aynı kaynağın iki defa delete edilmesi (biri programın ortasında) engellenmiş olur.
make_unique gibi burada da make_shared() olarak bir fonksiyon bulunmakta ve shared_ptr oluştururken bu fonksiyon kullanılarak oluşturulmalı. Shared
pointerlar aynı kaynağı idare eden birden fazla smart pointer'a ihtiyaç duyulan durumlar için dizayn edilmiştir. Son shared_ptr de parçalandıktan sonra
işaret edilen kaynak da parçalanacaktır. 
Burada unique_ptr'nin aksine shared_ptr içinde iki adet pointer tutar, biri yönetilen objeyi, diğeri ise bazı başka bilgileri (kaç tane shared_ptr'nin 
bu kaynağa işaret ettiği gibi) bilgileri tutar. Bu alanı daha optimize tutabilmek için make_shared ile oluşturmak daha iyi olur. 
reset üye fonksiyonuyla deletevari bir işlem de yapılabilir
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

    // 1. yol -> std::shared_ptr<obje_türü> değişken_ismi{eşitlencek ptr}
    std::shared_ptr<Coordinates> ptr1{co1};

    // 2. yol -> auto değişken_adı{std::make_shared<obje_türü>(varsa init değeri)}
    auto ptr2{std::make_shared<Coordinates>(2,4)};

    // Aynı yeri gösterecek başka bir pointer istediğimizde, shared_pointer üzerinden bunu tanımlayacağız
    auto ptr3{ptr2};
    
    // aynı dönüşü bekliyoruz
    ptr2->print();
    ptr3->print();

    // m_x'i değiştirelim
    ptr3->setX(23);

    // aynı dönüşü bekliyoruz, x = 23
    ptr2->print();
    ptr3->print();
    {
        auto ptr4{ptr3};
        ptr4->print();
    }
    return 0;
}