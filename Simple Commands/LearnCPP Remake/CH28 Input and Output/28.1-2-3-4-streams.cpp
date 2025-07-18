/* Stream veya akış, bir bit bölümünün sıralı olarak erişilmesi gibi düşünülebilir. Input ve output olarak 2 ayrı stream türü vardır. Zaten bazı standart
bildiğimiz streamler: cin, cerr, clog...
operator>> ile giriş akışından verileri okuyabiliriz. Burada stringleri okurken karşılaştığımız en temel problem, girişin overflow olmasıdır. Bunu 
manipulator denen objeleri kullanabiliriz. En temel bizim de bildiğimiz endl'dir. Yeni satıra geçer ve buffer'ı temizler. Bazı manipulatörlerin sitede
örnekleri var, bakılabilir. 
operator<< ile verileri çıkış akışına ekleyebiliriz. Burada da çıkış formatını değiştirmek adına 2 farklı yöntem devreye giriyor. Flag ve manipülatörler.
Flagleri açıp kapanabilen boolean değişkenler gibi düşünebiliriz. setf() ve unsetf() fonksiyonlarıyla beraber aktif ve deaktif edilir. Burada bir flag
açılırken, aynı grupta olan flagler kapatılmaz. Bu yüzden manipülatörlerle çalışmak daha kolay diyebiliriz. 
Sitede veya internette bol bol flag ve manipülatör görülebilir. 
*/


#include <iostream>



int main(){
    int x{23};
    double d{2.3};
    
    // Flag kullanımı
    std::cout << x << std::endl;
    std::cout.setf(std::ios::showpos); // Pozitif sayılarda '+' ile belirtmeyi açıyoruz 
    std::cout << x << std::endl;
    std::cout.unsetf(std::ios::showpos); // Pozitif sayılarda '+' ile belirtmeyi kapatıyoruz 
    std::cout << x << std::endl;

    // Manipülatör kullanımı
    std::cout << 30 << std::endl;
    std::cout << std::hex << 30 << std::endl; // 16'lık düzende yazıyoruz.
    std::cout << std::dec << 30 << std::endl; // 10'luk düzene geri getirdik
    
    return 0;
}