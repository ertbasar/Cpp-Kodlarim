/*Eğer çoklu dosya kullanımı yapılacaksa işler birazcık farklı işliyor. Bu dosya ve add.cpp adlı dosyanın bulunduğunu ve bu dosyaların birbriyle iliştiğini
düşünelim. Bu dosyaları ilk başta direkt VS Code üzerinden CodeRunner ile çalıştırmayı denersem direkt hata alırım. Çünkü derleme işlemine add.cpp'yi almamış
olur. Xcode kullansam bir sıkıntı olmaz ancak şu an da ben onu kullanmak istemiyorum. Bu yüzden en mantıklısı terminal üzerinden derleme almak. Bunun için
bir örnek komut -> g++ -std=c++20 main.cpp add.cpp -o deneme
Şimdi böyle bir denemenin benzerini şu anda da yapacağım. Burada önemli olan şeylerden birisi de başka bir dosyada tanımlanan fonksiyonu burada kullanacaksak
bu fonksiyonların prototiplerini de burada tanımlamamız gerekir. (forward declaration)
*/
#include <iostream>

int add(int, int);

int main(){
    int x{3};
    int y{5};

    std::cout<< add(3,5);

    return 0;
}

