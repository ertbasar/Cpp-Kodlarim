/* Ne zaman bir sınıf objesi oluştursak, her objenin kendine özel kopyalanmış değişkenleri olur. Burada istersek static keywordunu kullanarak bu sınıfın
her objesinin paylaştığı bir değişken yaratabiliriz. static üye değişkenlere nasıl sınıf objeleri üzerinden normal bir şekilde erişebiliyor olsak da bu 
değişkenler aslında hiçbir obje olmasa da bulunmaktadırlar. Program başladığında yaratılırlar ve sonlandığında parçalanırlar. Yani yaşam ömürleri herhangi
bir sınıf objesine bağımlı değildir. Aslında bu static üye değişkenlere bir sınıf scope'u altında yaşayan global değişkenler diyebiliriz. 
Static üye değişkeni sınıf içinde deklare ettiğimizde aslında prototiğleme veya forward declaration yapmış gibi oluruz. Bu yüzden bu değişkenleri explicit
olarak sınıf tanımının dışında define etmemiz gerekir.
Sınıfı header'da tanımladıysak bu değişken genelde cpp'de tanımlanır. Sınıf eğer cpp'de tanımlandıysa da hemen sınıfın altında tanımlanır. Bu statik üyeleri
headerda tanımlamamak gerekli. Birden fazla dosyada #include edilirse sıkıntı çıkarabilir.
Eğer bundan kaçınmak istiyorsak da değişkeni ya const ya da inline yapmamız gerekli. Bu sayede sınıf tanımı içerisinde init edebiliriz.
Kullanım alanların biri herkese unique id verirken kullanım.
*/

#include <iostream>

class Smt{
    public:
    static int s_val;
};

int Smt::s_val{23};

int main(){
    Smt foo{};
    std::cout << foo.s_val << std::endl;
    ++foo.s_val;
    std::cout << foo.s_val << std::endl;
    Smt goo;
    std::cout << goo.s_val << std::endl;
    return 0;
}