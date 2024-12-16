/* Cpp 3 farklı bellek ayrımı (allocation) destekler. Şimdiye kadar da bunlardan 2 tanesini dolaylı olarak da olsa gördük. 
1. Statik bellek ayrımı -> Statik ve global değişkenler için yapılır. Bu türdeki değişkenlerin ayrımı programın başından sonuna kadar yapılır.
2. Otomatik bellek ayrımı -> Fonksiyon parametreleri ve lokal değişkenlerde yapılır. İlgili blok içine girildiğinde ayrım yapılır sonrasında bloktan
çıkıldığında ise geri teslim edilir.
3. Dinamik bellek ayrımı da bu bölümün konusu:
Çoğu değişken bellekte stack denilen yerde tutulur, ancak bu stack içerisindeki bellek miktarı oldukça düşüktür. Burada bellek aşımı gerçekleşirse stack
overflow gerçekleşir ve burada da büyük ihtimalle işletim sistemi devreye girip programı kapatır.
Bu problem de dinamik bellek ayrımı yapılarak çözülür. Bu, programların işletim sisteminden bir bellek bölümünü istemesi gibi düşünülebilir. Burada işletim
sistemi, heap adı verilen çok daha büyük bir havuzdan bellek ataması gerçekleştirir. Modern makinelerde bu heap denilen kısım GB'lerce olabilir.
Burada dinamik olarak bir değişkeni tanımlamak istediğimizde, sadece 'new int' anahtar sözcüğünü kullanmamız yeterlidir. Bu komut, işletim sisteminden
int boyutunca bir bellek isteminde bulunur. Daha sonrasında bu belleği kullanarak bir obje oluşturulup, bu objenin adresini gösteren bir pointer döner.
Genellikle bunları da kendi pointer değişkenimize atayarak işlemleri gerçekleştiririz. >> int* ptr{new int}; *ptr = 7; //gibi işlemler gerçekleştirilir.
Burada heap tarafında kullanılan değişkenler aslında stack'e göre genellikle daha yavaş diyebiliriz. Stack'teki veriyi derleyici zaten bildiğinden direkt
olarak veriyi çekebiliyor ancak heap'te ilk olarak adresi alıp sonrasında veriye erişim gerçekleşiyor gibi düşünebiliriz. 
Direkt veya uniform init ile de init edilebilir. >> int* ptr1{new int(3)}; int* ptr2{new int{5}}; // gibi
Önemli olan konulardan biri de, işimiz biten dinamik değişkenlerin kapladığı alanı işletim sistemine geri vermektir denebilir. Burada bu işlemi özellikle
bizim yapmamız gerekir, aksi taktirde bellek sızıntısı gerçekleşebilir. Tek bir değişken için aşağıdaki kullanım yapılabilir:
delete ptr; ptr = nullptr; // Burada değişkenin kullandığı alanı işletim sistemine geri verdik ve nullptr göstermesini sağladık. nullptr kısmı da önemli
çünkü değişken ayrılmamış bir bellek bölgesine işaret ederse tanımlanmamış davranışlar gerçekleşebilir. Derefere etmek veya yeniden silmek de farklı 
yanlış sonuçlara gebe olabilir. Nadir de olsa işletim sisteminde  uygun bir bellek bölümü olmayabilir. 
Null pointerlar bellek ayrımı sırasında da yardımcı olabilir >> if(!ptr) ptr = new int; // gibi
Dinamik olarak ayrılmış bellek, biz söylemediğimiz ya da program kapatılmadığı taktirde ayrılmaya decam eder. Ancak bu belleğin adresini tutan pointerlar
genelde lokal değişkenler olduklarından dolayı, farklı scope sorunları ortaya çıkabilir. Örnek olarak >> void doSmt(){int* ptr{new int{}}}; 
kodunda bellek ayrılmasına rağmen hiç işletim sistemine geri verilmiyor. Pointer değişkeni fonksiyon sonunda normal bir değişken gibi ömrünün sonuna 
gelmesine rağmen ayrılmış bellek geri sisteme verilmediğinden dolayı program bu belleğin adresini kaybediyor, bu durumda bellek sızıntısı gerçekleşiyor. 
Program fazladan bellek kullanmış oluyor ve belki de diğer programlara yeteri kadar bellek kalmıyor. İşletim sistemi bu belleği ancak ve ancak program
kapatıldığında kendine geri alabilir. Bellek sızıntısı farklı birçok şekilde olabilir, sadece bu örnek bazında değildir. Farklı bir örnek ise ptr'nin
ayrılan kısmı delete edilmeden farklı bir adrese eşitlenmesi olabilir.

*/

#include <iostream>

int main(){
    // Bellekten bir int'lik boyutta yer ayrımı
    int* ptr1 = new int;
    *ptr1 = 15;
    std::cout << "ptr'nin adresi: " << ptr1 << std::endl; // benim bilgisayarımda çalıştırınca sırayla 0x13de05f30 ve 0x143e05f30 adresleri geldi
    std::cout << "ptr'nin değeri: " << *ptr1 << std::endl;
    delete ptr1; 
    std::cout << "ptr'nin adresi: " << ptr1 << std::endl; // yukarıdaki adresle aynısı çünkü aynı yeri gösteriyor, delete işlemi gerekli
    std::cout << "ptr'nin değeri: " << *ptr1 << std::endl; // 0 değeri geliyor beklendiği üzere
    ptr1 = nullptr; 
    std::cout << "ptr'nin adresi: " << ptr1 << std::endl; // 0x0 beklendiği üzere
    //std::cout << "ptr'nin değeri: " << *ptr1 << std::endl; // segmentasyon hatası çünkü göstereceği bir yer yok
    ptr1 = new int{12}; 
    std::cout << "ptr'nin adresi: " << ptr1 << std::endl; // yeniden bir değer verdik, aynısı olabilir, başkası olabilir o anki duruma göre
    std::cout << "ptr'nin değeri: " << *ptr1 << std::endl; // 12 değeri geliyor beklendiği üzere

    if(ptr1) // Belleği geri verme komutu
        delete ptr1;
    ptr1 = nullptr;

    // Sızıntıdan korunmak için delete kullanım örneği
    int val = 23;
    int* ptr2 = new int{323};
    // ptr2 = &val; // bu kullanımda önceki ayrılan kısım sızıntı haline dönüşür
    std::cout << "ptr2'nin adresi: " << ptr2 << std::endl; 
    std::cout << "ptr2'nin değeri: " << *ptr2 << std::endl; // 323

    delete ptr2;
    ptr2 = &val;
    std::cout << "ptr2'nin adresi: " << ptr2 << std::endl; // farklı bir adres çünkü bu sefer val'i gösteriyor
    std::cout << "ptr2'nin değeri: " << *ptr2 << std::endl; // 23 değeri geliyor beklendiği üzere

    return 0;
}