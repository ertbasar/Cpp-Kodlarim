/* Fixes-array'lerin aksine dinamik olarak belleği ayrılan arrayler runtime içerisinde boyutlarını belirleme imkanını bize sunarlar. Burada artık 
new ve delete yerine new[] ve delete[] kullanımı vardır diyebiliriz. 
Burada yeni bir boyuta geçirmek istediğimizde direkt olarak resize edemiyoruz. Yeni bir alan alıp oraya kopyalama işlemi gerçekleştirilebilir.
Zaten fixed-size array dediklerimize çok benzerler, sadece bellek ayrımı run-time'da gerçekleşebilir.
Eğer resize işlemi olacaksa en iyisi vektör kullanmak.
*/

#include <iostream>

int main(){
    // 23 int ayrımı
    constexpr int val{23};
    int* ptr1 = new int[val];

    // sisteme geri veriş
    delete[] ptr1;

    return 0;
}