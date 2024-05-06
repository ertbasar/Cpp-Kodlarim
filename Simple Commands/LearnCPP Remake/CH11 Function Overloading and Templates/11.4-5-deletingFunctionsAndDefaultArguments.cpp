/* Bazen fonksiyon overload yapmamamıza rağmen derleyici imlicit type conversion yapıp fonksiyonu çalıştırabilir. Bunu engellemek için fonksiyon bazı türlerden
silinebilir/çıkarılabilir. Örnek aşağıda
= delete'in anlamı bu yoktur demektense daha çok bunu görmezden gel gibidir. 
Bir sürü fonksiyonu delete etmek yapılabilir bir şey olsa da biraz da gereksiz olabilir. Bunun için daha iyi bir örnek aşağıda
Default argümanlar ise fonksiyon parametresi olarak verilen sabitlerdir, eğer çağrılırken bir argüman yollanmazsa default argüman kullanılır. Bu yüzden 
default argümanlar en sağda kullanılmalıdır.
*/

#include <iostream>
void print(int x){
    std::cout << x << std::endl;
}
// Aşağıdaki kullanım ile burada implicit type conversion yapıp onları kullanması engellendi
void print(char) = delete;
void print(bool) = delete;

// Fonksiyon şablonları görmedik ancak toplu delete için yöntem
void printInt(int x){
    std::cout << x << std::endl;
}
template <typename T>
void printInt(T x) = delete;
// en sağda default argüman kullanıldı
void addPrint(int x, int y = 5){
    std::cout << x + y << std::endl;
}
int main(){
    print(97);
    //print('a'); // hata verir
    //print(true); // hata verir

    printInt(12);
    //printInt(12.2); // hata verir
    
    addPrint(3);
    addPrint(3, 10);


    return 0;
}