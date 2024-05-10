/* Cpp'de C'de olduğu gibi pointer (işaretçiler) bulunmaktadır. Pointerlar değer olarak içlerinde bellek adresi bulunduran objelerdir. Burada iki karakter
çok önemli, bunlar da: & ->  adres operatörü
1. tür isminden sonra kullanınca lvalue referansı olur
2. iki adet binary context arasında bitwise and operatörü olur
3. bir ifadeden önce kullanıldığında onun adresini verir
Bir değişkenin sadece adresinin elimizde bulunması da bize pek yararı olan bir şey değildir. Burada devreye dereference operatörü olan * girer
* operatörü bir adresin içerisindeki değeri bize sağlar. Zaten genel olarak bizim ihtiyacımız da odur.
Normal değişkenler gibi pointerlar da default olarak init edilmezler, bizim etmemiz gerekir. Diğer türlü bu pointera wild pointer denir ve içinde çöp 
bulundurup beklenmeyen davranışlar gösterebilir. Bu yüzden pointerları her zaman bilinen bir değere init etmek gereklidir.
Pointerlar adres tuttuğundan ötürü bir şeye eşitmele veya init ederken ona göre bir adresle bu işlemi yapmak gerekir.
Pointerlarla iki şekilde assignment yapabiliriz.
1. pointerın gösterdiği yeri değiştirmek -> yeni bir adres eşitlemesi
2. gösterdiği yerin değiştirilmesi -> dereference edilen yere yeni bir değer eşitlemesi
Dangling (kararsız diyeceğim bundan sonra) referanslar gibi pointerlarda da eğer gösterdiği yer artık mevcut değilse sorun çıkabilir 
*/

#include <iostream>


int main(){
    int x{4};
    int* ptr; // init ama çöp adres tutuyor olabilir
    int* ptr2{}; // boş pointer initi
    int* ptr3{&x}; // x'in adresini tutan prt initi

    // x'in değeri ve adresi yazıldı
    std::cout << x << std::endl;
    std::cout << &x << std::endl;

    // sırayla ptrlerin içinde bulundurdukları adresler yazılıyor
    std::cout << ptr << std::endl;
    std::cout << ptr2 << std::endl;
    std::cout << ptr3 << std::endl;

    // sırayla ptrlerin gösterdiği adreslerdeki değerler yazdırılıyor
    std::cout << *ptr << std::endl;
    // std::cout << *ptr2 << std::endl; // nullptr olduğundan hata verir
    std::cout << "**ptr2 es geçildi**" << std::endl;
    std::cout << *ptr3 << std::endl;

    return 0;
}