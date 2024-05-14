/* Cpp'de bir yapı veya sınıfın içerisinde yine benzer bir yapı veya sınıf tanımlanabilir. Bu iki şekilde yapılabilir:
1. Bir tür tanımlamak ve onu daha sonra tanımlanan bir türün içerisinde kullanmak
2. Bir türün içerisinde farklı bir tür tanımlamak
Genel olarak yapıların kendilerine sahip olmalarını isteriz.
Bunun dışında C'de olduğu gibi yapılarda padding olabilir (hizalama) Yani yapının toplam boyutu ile kapladığı alan değişebilir
Üyelere erişimde de eğer üye normalse . ile işaretçiyse -> ile ulaşılır.
*/
#include <iostream>

//Çok dümenden bir örnek yapalım
struct Employee{
    int id{};
    int age{};
    int* ptr{};
};
struct Company{
    Employee a{};
    int deneme;
};

// İçeride tanımlamak
struct Company2{
    struct Employee2{
        int id{};
        int age{};
    };
    int deneme{};
};
int main(){
    Employee ert{1, 25, nullptr};
    // yapı değişkeni normal olunca değerine . ile pointer olunca ise -> ile ulaşılır. 
    ert.id = 3;
    ert.ptr = &ert.id;
    Employee tempEmp{2, 53, nullptr}; 
    // Bir adet yapı işaretçisi oluşturup tempEmp'e işaret ettirelim
    Employee* alp{&tempEmp};
    // İşaretçi içerisinden değişiklikleri yapalım
    alp->age = 53;
    alp->id = 2;
    // ptr'ye id'nin adresini verelim
    alp->ptr = &alp->id;
    std::cout << ert.ptr << " " << *(ert.ptr) << std::endl;
    std::cout << alp->ptr << " " << *(alp->ptr) << std::endl;
    return 0;
}