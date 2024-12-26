/* Önceki derslerde şablon fonksiyonlar ve sınıflar bulunduğundan bahsetmiştik. Bazen kullandığımız sınıf ve içindeki değişkenler şablon kullanılarak
farklı veri türlerinde oluşturulabilirler. Bu yüzden overload işlemleri de aynı şekilde şablonlaştırılabilir. LearnCPP'de çok daha farklı ve güzel 
örnekler var, incelenebilirler. Aşağıdaki örneği de oradan aldım.
*/

#include <iostream>

class Cents
{
private:
    int m_cents {};
public:
    Cents(int cents): m_cents { cents }{}

    // Gelen iki objeden hangisinin elemanı büyükse ona göre 1 veya 0 döndürüyor
    friend bool operator< (const Cents& c1, const Cents& c2){
        return (c1.m_cents < c2.m_cents);
    }

    friend std::ostream& operator<< (std::ostream& ostr, const Cents& c){
        ostr << c.m_cents;
        return ostr;
    }
};

// x ve y'den hangisinin daha büyük olduğunu anlamak için operator<'a başvuruyor. Gelen 1 veya 0 sonucuna göre de y veya x'i döndürüyor
template <typename T>
const T& max(const T& x, const T& y){
    return (x < y) ? y : x;
}

int main()
{
    Cents nickel{ 5 };
    Cents dime { 10 };

    Cents bigger { max(nickel, dime) };
    std::cout << bigger << " is bigger\n";

    return 0;
}