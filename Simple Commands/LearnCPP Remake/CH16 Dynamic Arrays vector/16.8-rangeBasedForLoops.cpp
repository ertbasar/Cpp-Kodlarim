/* Array içerisinde işlemler gerçekleştirmek çok popüler olduğundan ötürü C++ for-each diyebileceğimiz bir döngü türü daha destekler. Herhangi bir indisleme
işlemi yapmadan array içerisinde gezinmemizi sağlayan bu döngü türü üzerinde işlem yapılan objenin içerisindeki tüm elemanları gezer diyebilriz. 
Burada bir objeyi bir döngüye göndermektense fonksiyona gönderiyoruz gibi de düşünülebilir. Bu yüzden o elementin kopyasıyla uğraşmak istemiyorsak 
const auto& kullanımı yapmak en mantıklısı olur. Tanımı:
for(element_declaration:array_object)
    statement;
*/

#include <iostream>
#include <vector>

int main(){
    std::vector v1{1,2,3,4,5,6};
    // elemanlarının int olduğunu belirtiyoruz ve de array içinde geziniyoruz.
    for(int num: v1)
        std::cout << num << " ";
    std::cout << std::endl;

    // Türün belirlenmesini derleyiciye bıraktık
    std::vector v2{10,20,30,40,50,60};
    for(auto num: v2)
        std::cout << num << " ";
    std::cout << std::endl;

    std::vector v3{100,200,300,400,500,600};
    // En doğru kullanım denebilir, hem const ref, hem de kendisi türü belirliyor.
    for(const auto& num : v3)
        std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}