/* Nasıl fonksiyon parametrelerinin bazı durumlarda kopyalama işlemlerinin pahalı olduğundan behsettiysek benzer bir durum fonksiyon geri dönüşlerinde de
yaşanabilir. Özellikle sınıf tipinde return by reference kullanımını tercih edebiliriz. Burada return by reference olunca return olan objeye bağlı olan bir
referans döndürülüyor ve return değerinin kopyasının oluşturulmasını engelliyor. 
Buradaki en dikkat edilmesi gereken şey objenin yaşam ömrünün fonksiyondan fazla olmasının gerekliliği. Yoksa dangling duruma düşer.
Yani non-static olan veya geçici değişkenleri return by reference ile kullanmamak lazım. 
Bunu genişletip non-const static değişkenleri kullanma da diyebiliriz. Aynı veriyi başka yerde çağırıp değerini değiştirince ortaya bazı sorunlar çıkabilir.

Return by address de neredeyse aynısı, sadece referans yerine bir pointer dönüyor
*/

#include <iostream>
// Basit bir örnek
int& returnByReference(int& num) {
    return num;
}

// Bu fonksiyon büyük olan argümanın adresini geri döndürüyor
int& max(int& x, int& y){
    return (x > y) ? x : y;
}

int* returnByAddress(int* num) {
    *num = 2123;
    return num;
}

int main(){
    int x{15};
    returnByReference(x) = 25;
    std::cout << x << std::endl;

    int a{23};
    int b{55};

    max(a, b) = 1; // Büyük olan sayının değeri 1 olarak güncelleniyor.
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    int y{10};
    int* ptr{&y};
    returnByAddress(ptr);
    std::cout << *ptr << std::endl;
    std::cout << y << std::endl;

    return 0;
}