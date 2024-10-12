/* Vektörler de diğer objeler gibi fonksiyonlara gönderilirler. Pass by value işlemi kopya yarattığından genellikle pahalı bir işlem oluşmaması adına pass
by (const) reference ile göndermek daha mantıklı olur. Burada fonksiyonu olabildiğince şablonlaştırmak, farklı türlerde gelen vektörlere karşın bizim 
elimizi kuvvetlendirir. Veya C++20'den itibaren fonksiyonda argümanı auto belirtebiliriz :) İki yöntem de olur
Aşağıda 4 adet print fonksiyonu var, print3 ve print4 aslında en basit yazılacaklar. C++20 varsa zaten direkt print4 kullan
*/

#include <iostream>
#include <vector>

// Direkt pass by const reference ile yazdırma işleminin gerçekleştirilmesi
void print1(const std::vector<int>& v){
    for(std::size_t i = 0; i < v.size(); i++){
    std::cout << v[i] << std::endl;
    }
}

// Vektörün türünün şablonize edilmesi. Yukarıdaki örnek olursa int dışı herhangi bir türde çalışmaz.
template <typename T>
void print2(const std::vector<T>& v){
    for(std::size_t i = 0; i < v.size(); i++){
    std::cout << v[i] << std::endl;
    }
}

// Direkt türün şablonize edilmesi, operator[] için overload edilmiş her objede kullanılabilir
template <typename T>
void print3(const T& arr){
    for(std::size_t i = 0; i < arr.size(); i++){
    std::cout << arr[i] << std::endl;
    }
}

// Şablon vs. yok. Derleyiciye sen bu işi halledersin diyoruz
void print4(const auto& arr){
    for(std::size_t i = 0; i < arr.size(); i++){
    std::cout << arr[i] << std::endl;
    }
}

int main(){
    std::vector v1{1,2,3,4,5,6};
    print1(v1);
    print2(v1);
    print3(v1);
    print4(v1);

    return 0;
}