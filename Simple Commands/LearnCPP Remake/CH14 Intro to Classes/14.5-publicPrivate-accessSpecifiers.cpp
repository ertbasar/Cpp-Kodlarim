/* Bir sınıfın içindeki her üye değişken veya fonksiyonun bir erişim seviyesi vardır. Cpp'de üç farklı erişim seviyesi bulunmakta: public, private, protected
public: dışarıdan erişim var
private: dışarıdan erişim yok
Burada üyeler varsayılan olarak private gelirler. 
Üyelere erişim gerektiği zaman derleyici kontrol eder, eğer erişim hakkı yoksa derleyici hatası verir.
Cpp'de private değişkenlerin önüne 'm_' koyulması gibi bir kullanım da bulunmakta.
Erişim seviyeleri obje değil de sınıf bazlı olduğundan dolayı bir üye fonksiyon diğer objenin private değerlerine erişebilir.
*/

// Yine önceki örneğimizle devam edelim :)

#include <iostream>
class Foo{
    int m_id{25};
    public:
    int id{15};
    // Burada üye fonksiyon tanımını yapıyoruz.
    void printID(){
        std::cout << id << std::endl;
    }
    
};


int main(){
    Foo goo;
    goo.id = 23;
    // goo.m_id = 321; // hata verir çünkü erişim yok. private bir üye
    goo.printID();
    
    return 0;
}