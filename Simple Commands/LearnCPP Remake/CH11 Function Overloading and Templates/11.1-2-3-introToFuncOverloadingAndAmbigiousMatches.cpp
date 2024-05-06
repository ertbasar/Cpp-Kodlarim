/* Foksiyon overload aynı isme sahip olan farklı fonksiyonların yaratılmasına olanak tanır. Bunu sadece farklı parametre türlerini alan fonksiyonlar 
tanımlayarak yapabiliriz. 
Overload edilmiş bir fonksiyon çağrıldığı zaman derleyici bu çağrıyı bir uygun olan bir overload ile eşleştirmeye çalışır. Buna da overload resolution denir.
----
Bir başka yaklaşım da overload differentiationdır. Eğer fonksioynlar düzgün bir şekilde ayrıştırılamazsa derleyici hata verebilir. Burada;
1. Parametre sayısı ile ayrışım yapılabilir
2. Parametre tipleriyle ayrışım yapılabilir
3. Return türü ile ayrışım yapılamaz
typedef, type aliasları veya const expression ile ayrışma olmaz
----
Differentiated overload yazmak işin yarısı denebilir. Fonksiyon çağrıldığında ona uygun bir fonksiyon bulmak da derleyici tarafından yapılan işin diğer yarısı.
Burası da overload resolution kısmı olmakta. Eğer derleyici birden fazla uygun olabilecek şey bulursa o da ambigious match olabilir. Bu durumda hata alınır.
*/

#include <iostream>
// F1
int topla(int x, int y, int z){
    return x + y + z;
}
// F2
int topla(int x, int y){
    return x + y;
}
// F3
double topla(int x, double y){
    return x + y;
}
//F1 ile F2 ve F3 arasında parametre sayısı ayrışımı
//F2 ve F3 arasında ise parametre türü ayrışımı olmasına rağmen return türüyle alakalı bir ayrışım yoktur.

int main(){
    std::cout << topla(1, 3.2) << std::endl;
    std::cout << topla(1,2,3) << std::endl;
    std::cout << topla(1.0, 3.2) << std::endl; // Implicit type conversion
    std::cout << topla(1,4) << std::endl;


    return 0;
}