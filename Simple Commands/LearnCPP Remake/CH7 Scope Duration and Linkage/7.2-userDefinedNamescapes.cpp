/* C++ ile kendimize namespace yaratabiliriz. Bazı şeyleri aynı isimle tanımlamak istediğimiz zaman vs. çok işimize yarar.
Aynı namespacele alakalı çalışmalar farklı dosyalar içerisinde yapılabilir ancak yapılması önerilmez. Hatta bu şekilde kendi fonksiyonlarımızı
std namespace'e bile ekleyebiliriz. Ayrıca namespaceler birbirlerinin içlerinde de tanımlanabilirler. Bu tür durumlarda işlemin daha az 
çetrefilli olması adına namespace Moo = Foo::Goo; gibi tanımlamalar yapılıp Moo ile erişim sağlanabilir.
*/
#include <iostream>
namespace Foo{
    int a{5};
    void asd(){
        std::cout << "Buradayım" << std::endl;
    }
    namespace Goo{
        int a{7};
        void asd(){
            std::cout << "Aynı zamanda buradayım da" << std::endl;
    }
    }
}
int main(){

    Foo::asd();
    std::cout << Foo::a << std::endl;
    Foo::Goo::asd();
    std::cout << Foo::Goo::a;


    return 0;
}