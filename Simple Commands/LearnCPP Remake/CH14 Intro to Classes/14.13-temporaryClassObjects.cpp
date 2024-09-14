/* Bir fonksiyonu bir obje ile bir kere kullanıp o objeyle işimiz bitecekse burada geçici obje oluşturabiliriz. Normal objeyle kullanım ve de 
2 farklı geçici obje türüyle kullanım kodu aşağıda. Burada üye olmayan fonksiyonların kullanımı kural denebilir. Üye olursa zaten obje üzerinden 
çağrılacağından konsepte aykırı.
*/

#include <iostream>
class Foo{
    // Şimdilik public olsun get set uğraşmayalım
    public: 
    int p_id{15};
    Foo() = default; // Default constructor tanımı
    // Constructor
    Foo(int id): p_id{id}
    {
        std::cout << "Bir Foo objesi oluşturuldu" << std::endl;
    }

    // Destructor, ileride bakacağız şu an objelerin geçiciliğini gösterme adına şu an ekleme yaptım
    ~Foo(){
        std::cout << p_id << " id numaralı obje çöp oldu" << std::endl;
    }
};

// Üye olmayan bır fonksiyonun kullanımı. Ekstradan bir referans kullanımı da oldu
void print(const Foo& a){
    std::cout << a.p_id << std::endl;
}

int main(){
    //Normalde obje oluşturularak kullanım
    Foo goo{23};
    print(goo);

    // geçici Foo objesi construct edip gönderme
    print(Foo{55});

    // geçici bir objenin implicit olarak Foo objesine convert edilip gönderilmesi
    print({1024});
    return 0;
}