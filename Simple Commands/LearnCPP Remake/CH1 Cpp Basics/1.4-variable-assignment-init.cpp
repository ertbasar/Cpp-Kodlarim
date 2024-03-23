/* şöyle ki ben bu konuları tekrar etmeye başlamadan önce değişken tanımlama yaparken sanki C dilinde yazıyormuş gibi default int veya copy init denilen tarzlarda 
değişken tanımlaması yapıyordum. Ancak modern C++ programlarken bunlardan ziyade value init veya direct list init kullanmanın daha iyi olduğunu öğrendim. Aslında
bu kod dosyasının oluşturulma nedeni bu kadar basit. List init yapmanın en büyük yararı köşeli parantezin içinde o yapılan init işlemine uygun bir değeri zorunlu 
tutmasıdır.
*/
#include <iostream>

int main(){
    int a; //default init
    int b = 5; //copy init
    int c{}; //value init
    int d{6}; //direct list init
    //ayrıca aşağıdaki ikili de bulunmakta ama en gereksizleri bunlar herhalde benim için
    int e(7); //direct init
    int f = {10}; //copy list init

    // int g{4.7}; // hata
    return 0;
}