/* Cpp'de standart kütüphane tarafından sağlanan türlerin çoğu sınıf tipidir ve bu sınıf tipinin kopyalanmasının pahalı bir işlem olduğunu std::string'de 
olduğu gibi belirtmiştik. Bu yüzden verileri bir yere gönderirken pass by value yerine pass by reference olarak göndermek daha mantıklıdır. Bu işlemi
yaparken fonksiyon parametresi olarak referans bir tip belirleriz ve bu fonksiyona uygun bir argümanı göndeririz. Referans da bir alias gibi davrandığından
ötürü herhangi bir copy işlemi olmaz. Sadece eğer const göndermek istiyorsak pass by const lvalue ref ile yapmamız gerekli onun anlatımı da aşağıda :)

Ayrıca eğer gönderilen obje fonksiyonun içerisinde değiştirilmeyecekse pass by const lvalue reference ile işlemleri gerçekleştirmek / parametreyi belirlemek
daha iyi olur. Ayrıca const değerleri yollamamıza da yardımcı olur. 
Classlar genelde kopyalanmaları çok pahalı olduğundan genelde const ref ile gönderilirler
*/

#include <iostream>

void printStr(std::string& str){
    std::cout << str << std::endl;
}
void printInt(int& x){
    std::cout << x << std::endl;
}

void printConstStr(const std::string& str){
    std::cout << str << std::endl;
}
void printConstInt(const int& x){
    std::cout << x << std::endl;
}
// Aslında bir string için en iyi gönderim şekli böyle denebilir
void printConstStrView(std::string_view deneme){
    std::cout << deneme << std::endl;
}
int main(){
    std::string a{"deneme123"};
    int x{12};
    const int y{23};

    printStr(a);
    printInt(x);
    // printInt(y); // Hata verir. pass by ref. ile const olmaz, pass by const ref ile olur o da aşağıda

    printConstInt(x);
    printConstInt(y);
    printConstStr(a);
    printConstStrView("Asd123");
    return 0;
}