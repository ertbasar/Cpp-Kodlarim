/* C++'daki dosya giriş çıkış işlemleri de normal konsol işlemlerine fazlasıyla benzerdir diyebiliriz. fstream header dosyasını include etmemiz gerekli.
Daha sonrasında ise işlem bittiğinde close() fonksiyonu ile beraber dosyayı kapatabilir veya lokal değişkenin scope'dan çıkmasını bekleyebiliriz.
Dosyadan veri alırken her kelimede alta geçmesin diye getline() kullanılabilir.
Dosya objelerini oluştururken ikinci bir parametre vererek opsiyonel ekstra işlemleri belirtebiliriz. Buna mod denir ve birkaç farklı flagden oluşur:
app, ate, binary, trunk gibi
*/

#include <iostream>
#include <fstream>
#include <string>

int main(){
    // Çıkış için ofstream kullanıyoruz
    std::ofstream outf{"Sample.txt"};
    outf << "Line 1\n" << "Line 2\n";
    // Giriş öncesi kapama yaptık
    outf.close();

    // Giriş için ifstream
    std::ifstream inf{"Sample.txt"};
    // Dosyada okunacak bir şey var mı kontrolü
    std::string strInput{};
    while (inf >> strInput)
        std::cout << strInput << '\n';
    // Yukarıdaki durumda her yeni kısmı yeni bir satıra yazar ve bunu istemeyiz. O yüzden bir de getline yapalım
    inf.close();
    std::cout << "******" << std::endl;
    std::ifstream inf1{"Sample.txt"};
    std::string strInput1{};
    // Getline ile satır satır yazmayı başarırız
    while (std::getline(inf1, strInput1))
	    std::cout << strInput1 << '\n';
    return 0;
}

