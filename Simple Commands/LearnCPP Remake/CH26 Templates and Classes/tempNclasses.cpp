/* Şablon ve sınıflar kısmını tek bir dosyada halledebilirim diye düşündüm. Sırayla açıklamaları yapmaya çalışayım. 
26.1 Template classes
Eğer şablon sınıfı içerisindeki bir üye fonksiyonu sınıf tanımı dışında tanımlayacaksak, bu fonksiyon tanımı da sınıf tanımı ile beraber header dosyasında
olmalı. Header değil de cpp dosyasında tanımlanırsa, her cpp dosyası ayrı ayrı derlendiğinden dolayı hata alınabilir. 
26.2 Template non-type parameters 
Burada parametre kısmında sabit bir değer kullanırken olur gibi anlatabiliriz. Örneği aşağıda olur.
26.3 Function/Class template specialization
Şablonun normal davranışını override etmek istediğimizde kullanırız. Eğer tüm türler override edilmişse de full specialization olarak geçer. Sınıflar
kısmi özelleştirmeyi desteklerken, fonksiyonlarda partial specialization yoktur, full olmalıdır. 
Burada özelleştirme yapmadan önce şablon tanımının yapılmış olması gerekir. Yine tahmin edileceği üzere, özelleştirmedeki ile şablondaki yapının/imzanın
aynı olması gerekli. 
Delete kullanımı yapılabilir. Bu sayede o kullanımın önüne geçilir. 
Genel olarak bu özelleştirme yerine düz override tarzı kullanım daha iyi olur. 
*/

#include <iostream>


// 26.2
template<typename T, int size>
class StaticArray{
    T m_array[size]{};
};

// 26.3
template<typename T>
void print(const T& t){std::cout << t << std::endl;}
// Şablonun override'ı gibi düşünebiliriz. 
template<>
void print<double>(const double& d){std::cout << std::scientific << d << std::endl;}
// Aşağıdaki gibi override etmeyi tercih ederiz. Ekstra şablon vs uğraşmaya gerek kalmaz ve de imzaların tutmasına gerek duyulmaz. 
void print(double d){std::cout << std::scientific << d << std::endl;}

int main(){
    // 26.2
    // 12 elemanlı dizi
    StaticArray<int, 12> intArray;

    return 0;
}
