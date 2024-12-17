/* ellipsis aslında ne kadar parametre göndereceğimizin tam olarak belli olmadığı fonksiyonlardır. Genel olarak uzak durulması önerilir. 
Buradaki en büyük tehlike, derleyicinin parametre sayısını yeterince check etmemesinden kaynaklı yanlış kullanımlarda istenmeyen sonuçların çıkabilmesi.
*/

#include <iostream>
// kaç parametre geleceği ve de sonrasında belirli olmayan kısım için ...
int avg(int count, ...){
    int sum = 0;
    // Buradaki gönderilen parametrelere va_list ile erişeceğiz. Tanımı aşağıdaki gibi
    std::va_list list;

    // va_start listeyi ile başlatıyoruz, burada ilk argüman init edilecek liste, ikinci argüman ise son ellipsis olmayan parametre oluyor
    va_start(list, count);
    
    // tüm ellipsis üyelerini sırayla dönüp sum'a ekliyoruz
    for (int arg{ 0 }; arg < count; ++arg)
    {
        // ellipsis içinden verileri va_arg ile alıyoruz. Burada ilk parametre kullandığımız liste, ikinci parametre ise hangi türden veri alacağımız
         sum += va_arg(list, int);
    }

    // va_end ile kullandığımız listenin silme işlemi gerçekleşiyor
    va_end(list);

    return sum / count;
}

int main(){

    // ilk baştaki 5 ile kaç adet parametre göndereceğimizi belirttik
    std::cout << avg(5, 1, 2, 3, 4, 5) ;

    return 0;
}