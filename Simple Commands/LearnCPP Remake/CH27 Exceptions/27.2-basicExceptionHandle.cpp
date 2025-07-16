/* Exception handling mekanizması hataların nerede veya nasıl olduğunu anlamakta bize yardımcı olur. 3 adet keyword ile bu mekanizma oluşturulur:
throw, try, catch

Burada throw, sıkıntılı bir durumun gerçekleştiğini belirten bir sinyal yollamaya yarar. Çok basit bir kullanımı vardır, throw keyword'ünden sonra 
istenen türden bir veri türünü ve değerini kullan. Örnek olarak:
throw -1; throw MyException("Fatal Error"); throw dx; throw "Error";

Exception'u throw etmek bu işin sadece basit bir kısmı diyebiliriz. Burada ilk olarak try keyword'ü ile beraber bir adet 'deneme' bloğu ayarlarız. Bu blok
bir gözlemci gibi davranır ve bu blok içerisinde herhangi bir throw atıldı mı ona bakar. Ancak nasıl handle edileceğiyle alakalı bir işlemde bulunmaz. 
Örnek bir kullanım olarak
try{ // Exception throw edebilecek bazı ifadeler
    throw -1;
}

Son olarak, bu exceptionları handle etmek, catch bloklarının işidir diyebiliriz. Örnek kullanım olarak:
catch(int x){ // Bu kısımda exception handle edilir
    std::cerr << "Exception caught with value: " << x << std::endl;    
}

try ve catch blokları beraber çalışırlar, try bloğu sorunu tespit eder ve soruna uygun türdeki catch bloğuna yönlendirir. Ayrıca, try bloklarından sonra
bir veya birden fazla catch bloğu takiben bulunmalıdır. 

catch bloğu parametreleri fonksiyon parametreleri gibi çalışır. Burada genel olarak caught by value gibi bir durum olsa da eğer temel bir tür yakalanmayacaksa
caught by ref. olarak da bir tasarlama yapılabilir. Ayrıca, eğer parametre catch bloğun içerisinde kullanılmayacaksa değişken adı yerine bir şey yazılmadan
sadece veri türü ile devam edilebilir. 
catch(double){std::cerr << "Exception caught.." std::endl;}

Exception catch ederken vs. tür dönüşümleri gerçekleştirilmez.

Temel özet olarak, çalışan program bir exception fırlattığında en yakın try bloğu bitişine bakarak sonrasında o türde exceptionu handle edebilecek bir 
catch bloğu olup olmadığına bakar, olması durumunda bu catch bloğunun en üstünden itibaren ifadeleri çalıştırmaya başlar. Eğer uygun bir catch bloğu 
bulamazsa ise program runtime exception hatasıyla çalışmayı sonlandırır. Burada programın implicit tür dönüşümü ile catch bloğuna exceptionu uydurmaya
çalışmayacağını hatırlatmak gerekir. Sadece türetilmiş sınıfın baz sınıflara doğru tür dönüşümleri belki gerçekleşebilir.

Eğer bir exception, bir catch bloğuna yönlendirildiyse, bu catch bloğu boş olsa bile bu exception handle edilmiş sayılır. Catch bloklarının exception
geldiğinde genel olarak yaptığı 4 temel işlev vardır:
1. Hatayı yazdır ve fonksiyona devam et
2. Bir hata kodu döndür
3. Başka bir exception throwla
4. Fatal hataları yakal ve programı güvenli şekilde sonlandır
*/

#include <iostream>


int main(){
    double x{};
    std::cout << "Lütfen pozitif bir sayı giriniz: ";
    std::cin >> x; 
    // deneme bloğunu tanımladık
    try
    {
        if(x < 0.0) // içerisinde bir deneme yapıyoruz ve eğer buna uymuyorsa throw yapıyoruz
            throw "Cannot take sqrt of negative number";
        std::cout << "sqrt is " << sqrt(x) << std::endl; // throw yoksa buradan devam
    }
    catch(const char* exception)
    {
        std::cerr << "Error: " << exception << std::endl; // throwa göre hatayı yazdırıyoruz
    }

    return 0;
}

