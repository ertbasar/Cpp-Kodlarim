/* Initializer listeleri bir objeyi oluştururken veya değiştirirken (overload gerekebilir) kullanılan listelerdir diyebiliriz. 
Bir dizi elemanı liste halinde fonksiyona veya sınıfa geçirmeyi sağlayan özel bir sınıftır. Süslü parantez ({}) ile yazılan değerleri 
kapsayan bir konteyner olarak düşünebiliriz.
Aynı zamanda bir derleyici initializer listesini gördüğünde onu otomatik olarak std::initializer_list objesine
dönüştürdüğünden dolayı eğer std::initializer_list'i parametre olarak alan bir adet constructor oluşturursak bu listelerle
sınıf objeleri de oluşturabiliriz. 
Burada hangi türde veri tutacağını belirtmek önemli. yine <> ile yapılır bu işlem. 
Fonksiyon parametresi olarak kullanılınca da for-each tarzıyla beraber kullanılabilir.
Bir diğer kullanımı da sınıflarda diyebiliriz. Array tarzı bir şekilde bir obje oluştururken. 
Son olarak da liste değiştirilemeyeceğinden, read-only olduğundan dolayı hatalara dikkat etmek gerekir. 
*/

#include <iostream>
#include <initializer_list>

void printList(std::initializer_list<int> list) {
    for (int val : list) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}


int main(){
    std::vector<int> vec = {1, 2, 3, 4};  // kendiliğinde initializer_list'e dönüştürüp kullanır

    printList({12,45,123,124}); 
}