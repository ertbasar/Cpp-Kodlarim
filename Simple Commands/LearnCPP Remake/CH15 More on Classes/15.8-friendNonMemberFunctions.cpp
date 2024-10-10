/* Sınıfın tanımı içerisinde bir friend deklarasyonu yaparak başka bir sınıf veya fonksiyonun arkadaş olduğunu belirtebiliriz. C++'da bu arkadaşlık
arkadaş olunan diğer sınıfın tüm private ve protected verilerine erişebilme imkanı sunar. Bu friend fonksiyonları üye fonksiyonlar gibi sınıf tanımının
içerisinde de tanımlayabiliriz. Ayrıca bir üye fonksiyon birden fazla sınıfa aynı anda arkadaş olabilir. Burada sadece iki sınıfı kullanırken bir sınıf tanımlanmadan
diğeri tanımlanacağından dolayı sınıf forward declare edilmeli -> class Hum; gibi. 
Bir friend fonksiyon elemanlara direk erişmek yerine olabildiğince arayüzü kullanarak işlemleri gerçekleştirmeli. Bu ileride yapılacak değişiklikleri 
minimize etme adına iyi bir alışkanlık olur. Hatta bu yüzden fonksiyonları olabildiğince non-friend yapmamız iyi olur.
*/

#include <iostream>

class Accumulator
{
private:
    int m_value { 0 };

public:
    void add(int value) { m_value += value; }

    // arkadaş sınıf tanımı. non-member
    friend void print(const Accumulator& accumulator);
    // arkadaş sınıf tanımı. yine non-member ancak tanımı içeride
    friend void print2(const Accumulator accumulator){
        std::cout << accumulator.m_value << std::endl; // arkadaş olduğundan veriye direkt erişimi bulunmakta
    }
};

void print(const Accumulator& accumulator)
{
    std::cout << accumulator.m_value << std::endl; // arkadaş olduğundan veriye direkt erişimi bulunmakta
}

// Şimdi de 2 farklı sınıfın aynı anda kullanıldığı friend fonksiyon yazalım (LearnCPP'den aldım)

class Humidity; // Sınıfı forward deklare ediyoruz

class Temperature
{
private:
    int m_temp { 0 };
public:
    explicit Temperature(int temp) : m_temp { temp } { }

    friend void printWeather(const Temperature& temperature, const Humidity& humidity); // yukarıdaki sınıf forward deklaresini bu satır için yaptık
};

class Humidity
{
private:
    int m_humidity { 0 };
public:
    explicit Humidity(int humidity) : m_humidity { humidity } {  }

    friend void printWeather(const Temperature& temperature, const Humidity& humidity); // bura için yapmadık çünkü buraya kadar iki sınıf da tanımlı
};

void printWeather(const Temperature& temperature, const Humidity& humidity)
{
    std::cout << "The temperature is " << temperature.m_temp <<
       " and the humidity is " << humidity.m_humidity << '\n';
}


int main()
{
    // Tek sınıflı örnek
    Accumulator acc{};
    acc.add(5);
    print(acc);
    acc.add(5);
    print(acc);   

    // İki sınıflı örnek
    Humidity hum { 10 };
    Temperature temp { 12 };
    printWeather(temp, hum);
    return 0;
}