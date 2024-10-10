/* Önceki bölümde static üye değişkenlerin sınıfa ait olmaktansa sınıfın bir objesi olduğunu ve de eğer public olarak eklendiyse de sadece scope resolution
operatorünü kullanarak erişilebilir olduğunu belirtmiştik. Private olduğu durumda ise üye fonksiyonlar ile erişilebilir. Bunun için de ilk olarak sınıfın
bir objesini oluşturmamız gerekli. Daha iyi bir çözüm bulabiliriz:
static yapılabilen tek üye türü değişkenler değillerdir, üye fonksiyonlar da static yapılabilirler ve direkt olarak scope resolution operatorünü kullanarak 
erişilebilir hale gelirler. Bu static üye fonksiyonlarda this pointer'ı yoktur çünkü herhangi bir objeye bağlı değiller. Ayrıca static her üyeye erişebilirken
non-static herhangi bir üyeye erişemezler. Çünkü bu non-static üyeler bir objeyle ilişkilendirilir. 

*/

#include <iostream>


class IDGenerator{
    private:
    static inline int s_nextID{1}; // inline olarak ekledik ki tanımını direkt yapabilelim
    public:
    static int getNextID();
};

int IDGenerator::getNextID(){return s_nextID++;} // Her seferinde return sonrası artış yapıyoruz

int main(){
    std::cout << IDGenerator::getNextID() << std::endl;
    std::cout << IDGenerator::getNextID() << std::endl;
    std::cout << IDGenerator::getNextID() << std::endl;
    return 0;
}