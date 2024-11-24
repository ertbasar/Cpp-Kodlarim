/* [] kullanarak tanımlanan objenin c-style array olduğunu söyleyebiliriz. Aslında std::array'e fazlasıyla benzer. Ancak CTAD kullanımı yoktur çünkü
bir sınıf şablonu değillerdir. const ve constexpr olabilir, aynı zamanda sizeof(arr)'ı da kullanılan byte sayısını çekmekte de kullanabiliriz.
Bunun dışında std::size(arr) veya ssize(arr) ile de uzunluğunu alabiliriz. Eğer C++17 öncesini kullanıyorsak da aşağıda gösterdiğim şablon kullanılabilir.

*/

#include <iostream>

// 
template <typename T, std::size_t N>
constexpr std::size_t length(const T(&)[N]) noexcept
    {return N;}

int main(){
    // Düz bir tanım
    int a[]{5,3,5}; 
    int b[10]{};
    std::cout << a[2] << std::endl; 
    std::cout << sizeof(b) << std::endl; // elemanların kapladığı |byte
    std::cout << std::ssize(a) << std::endl; // eleman sayısı
    
    std::cout << length(b) << std::endl;
    return 0;
}