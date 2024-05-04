/* External bir erişimi olan değişken tanımlandığı veya diğer dosyalarda kullanılabilir. Bu onu aslında tam anlamda global yapar diyebiliriz.
Fonksiyonlarda otomatik olarak external link tanımlıdır, sadece kullanılacağı dosyada önceden deklare edilmesi gerekir.
Başka bir dosyada tanımlanmış external global değişkeni kullanmak için yine önceden deklare etmek gerekir bu da extern kelimesi yardımıyla gerçekleşir.
Burada dikkat edilmesi gereken şey non-const bir değişkenin tanımı yapılırken extern kelimesi kullanılmamalı. Bu o değişkenin başka bir dosyadan geldiğini
düşünmesine neden olur. 
constexpr türündeki değişkenlere de extern keyworduyle external link verilebilse de, complile-time'da değerlerinin diğer dosya tarafından da bilinmesi 
gerektiğinden forward deklare edilemezler. Bu yüzden bu tür durumlarda const kullanmak gereklidir.
Burada birkaç örnek vermek iyi olur diye düşünüyorum:
int g_x{3}; // değişkenin tanımı
extern int g_x; // forward declaration
extern const int g_y{1}; // değişken tanımı, const int zorunlu tutar
extern const int g_y; // forward declaration
Son olarak da aslında 7.8'in konusu ancak burada değinmek yeterli olur, const olmayan global değişkenleri kullanmak çok sıkıntı çıkarabilir. Herhangi bir 
fonksiyon vs içerisinde değiştirlmesi durumunda öngörülemez hatalar doğurabilir. Kullanılması gerektiğinde namespaceler altında kullanmak iyi olur.
*/


#include <iostream>

extern int ext_var;
extern const int ext_const_var;

int main() {
    std::cout << ext_var << " " << ext_const_var << std::endl;
    return 0;
}
