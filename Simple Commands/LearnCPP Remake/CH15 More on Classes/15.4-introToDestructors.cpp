/* Destructorlar bir objenin yaşam süresi sonunda, parçalanmadan önce, gerekli olan temizleme işlemini yapan özel fonksiyonlardır. Constructor gibi bazı
kuralları vardır:
1- Sınıf adıyla aynı isimde olacak ancak başında ~ olmalı
2- Herhangi bir argümanı yok
3- Herhangi bir geridönüş değeri yok
Bir sınıf sadece bir destructora sahip olabilir ve bizim çağırmamıza gerek yoktur. Program kendisi gerekli olan zamanda çağırır.
Eğer sınıfın özellikle bir temizleme işlemi yoksa herhangi bir destructor tanımı yapmamıza özellikle gerek yoktur. Derleyici kendisi bu destructor yazım
işlemini de gerçekleştirir. Burada dikkat edilmesi gereken şey eğer std::exit kullanılırsa destructorlar çağrılmaz. Eğer program buna bağlıysa dikkat et.
*/

#include <iostream>

class Foo{
    int m_id{};
    public:
    Foo(int x): m_id{x} {
        std::cout << this->m_id << " id'ye sahip obje oluşturuldu!" << std::endl; 
    }
    ~Foo(){
        std::cout << this->m_id << " id'ye sahip obje parçalandı!" << std::endl; 
    }
};

int main(){
    Foo foo{12};
    return 0;
}