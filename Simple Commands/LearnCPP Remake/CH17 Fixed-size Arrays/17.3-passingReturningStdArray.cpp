/* Array objeleri de fonksiyonlara diğer herhangi bir obje gibi gönderilebilir. Burada std::array gönderdiğimizde pahalı bir kopyası oluşuyor denebilir.
Bu yüzden genellikle pass by (const) ref. ile kullanılırlar. Burada fonksiyona gönderim sağlarken objenin element türü ve de element sayısı da bilgi 
olarak gönderildiğinden ötürü fonksiyonda bunu özellikle belirtmemiz gereklidir. CTAD şimdilik fonksiyon parameterelerinde çalışmamaktadır. Ancak bunun
yerine biz de şablon bir fonksiyon oluşturup onu kullanabiliriz. Bununla beraber gerekli yerlerde static_assert kullanarak sınır denetimi sayesinde
herhangi bir problem oluşmasının önüne geçebiliriz. 
Burada return kısmı vectorlerden farklı çünkü arrayler move capable olmadığından ötürü bu şekilde return etmek array'in kopyasının alınmasını gerektirir.
Çok büyük olmayan arraylerde bu pek sorun teşkil etmese de arrayleri non-const ref. ile gönderip fonksiyonun içinde değişiklik yapılabilir.

*/


#include <iostream>
#include <array>

// Elemanların hepsini yazdıran fonksiyon. Eleman türünden bağımsız bir çalışma şekli var
template<typename T, std::size_t N>
void printArr(const std::array<T, N>& arr){
    for(const auto& num: arr)
        std::cout << num << ' ';
    std::cout << std::endl;
}

// Int türünden elemanların hepsini birer arttıran fonksiyon
template<std::size_t N>
void incArr(std::array<int, N>& arr){
    for(int& num: arr)
        ++num;
}

int main(){

    std::array arr1{1,2,3,4,5};
    printArr(arr1);
    incArr(arr1);
    printArr(arr1);
    std::array arr2{'e', 'r', 't', 'b', 'a', 's', 'a', 'r'};
    printArr(arr2);
    // incArr(arr2); // Hata verir çünkü int değil char
    return 0;
}