/* Internal linkage ile tanımlanan bir öğe, sadece tanımlandığı dosyada görülebilir ve kullanılabilir, bu da aynı isme sahip başka öğelerin 
bağımsız olarak ele alınacağı anlamına gelir.
const olmayan bir global değişkeni internal değişken yapmak için static kullanabiliriz. (Diğer türlü extern kullanılarak diğer dosyalardan erişilebilirdi) 
const ve constexpr zaten internaldır.
Fonksiyonlar da benzer şekilde static kullanılarak internal hale getirilebilir.
Diğer dosyalar tarafından kullanılmayacak fonksiyon ve değişkenleri olabildiğince internal yapmak iyi bir alışkanlık olabilir.

*/

#include <iostream>
//Aşağıdaki tanımla beraber internal oldular
static int a{4};
static int asd(){
    return 3;
}
int main(){



 

    return 0;
}