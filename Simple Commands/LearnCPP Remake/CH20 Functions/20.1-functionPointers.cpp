/* Fonksiyon pointerları aslında çok benzerler, sadece değişken yerine fonksiyonlara işaret ederler. Değişkenler gibi fonksiyonlar da bellekte bir adreste
yer tutarlar. Fonksiyon çağrıldığında, program bu adrese gider ve işlemleri gerçekleştirir. Syntaxi biraz bozuk denebilir. Aşağıda örneği olur, burada
önemli olan şey, bir fonksiyon işaretçisi ancak ve ancak aynı parametre ve geridönüş türüne sahip fonksiyonlara işaret edebilir. Bu işaret edilen
fonksiyonu sanki alias kullanıyor gibi bir şekilde bu pointer ile de çağırabiliriz. nullptr olabilir o yüzden test etmek mantıklı olabilir.
Default argumanlar burada çalışmaz çünkü run-time'da çözümü gerçekleştirilir. Burada yapılabilecek en güzel kullanımlardan biri de callback fonksiyon
kullanımıdır. callback fonksiyonlar da bir fonksiyonun içerisine argüman olarak başka bir fonksiyonun gönderilmesidir. Bunun örneği de aşağıda olur.
Bu callback fonksiyonların bazılarında default parametre kullanmak mantıklı olabilir. Yukarıda olmaz dedim ancak o pointerın içinde olmaz anlamındaydı,
asıl fonksiyonda olabilir sanırım. Ayrıca kullanımın çirkimnliğini azaltmak adına type alias da kullanılabilir. Farklı bir kullanım ise <functional>
altındaki std::function kullanmaktır. std::function ile auto da kullanılabilir. dönüş türleri gizli olduğundan dikkatli olmak gerekli.
Onun örneği de olur hepsinin olur :p
*/

#include <iostream>
#include <functional>

int foo(){return 55;}
int goo(int x){return x * 2;}
int doo(){return 55;}

// Aşağıda callback örneği. Burada hangi algoritmanın fonksiyonunun kullanılmasını istiyorsak ona göre o fonksiyonu argüman olarak da göndeririz.
// Default da verdik ki kullanırken ilk düşündüğümüz neyse o kullanılsın. Fcn ptr kullanılırken default olmadığını unutma sadece yeterli
// void selSort(int* array, int size, bool(*comparisonFcn)(int,int) = ascending){} // Burada ascending de bizim type alias kullandığımız bir fonksiyon olur.

// std::function kullanımı. bool dönen ve de iki adet int alan bir fonksiyonu callback kullandık
// bool validate(int x, int y, std::function<bool(int,int)> fcn);


int main(){
    // parametre almayan ve int dönen fonksiyon pointer örneği. Eşitlemesini de direkt yaptım
    int(*fcnPtr1)(){&foo};

    // int parametre alan ve int dönen fonksiyon pointer örneği
    int(*fcnPtr2)(int){&goo};

    // Çağırırken iki farklı şekilde çağrılabilir
    // 1. yöntem
    std::cout << (*fcnPtr1)() << std::endl;
    std::cout << (*fcnPtr2)(23) << std::endl;
    // 2. yöntem. Bu direkt kullanıma çok benzer zaten
    std::cout << fcnPtr1() << std::endl;
    std::cout << fcnPtr2(12) << std::endl;
    
    // başka bir fonksiyona da sonradan bu şekilde eşitlenebilir
    fcnPtr1 = &doo;

    // auto kullanımı
    auto fcnPtr3 = &goo; 
    std::cout << fcnPtr3(34) << std::endl;

    return 0;
}