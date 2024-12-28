/* C++11'den önce, sadece bir türde referans türü bulunmaktaydı ve ona da sadece reference deniliyordu. C++11'le beraber bu referansa l-value referance
denilmeye başlandı. L-refler sadece değiştirilebilir olan l-valuelarla init edilebilir. Bir de lref to const var tabii, o da hem değiştirilebilir, hem
değiştirilemeyen l-valuelarla, hem de r-valuelarla init edilebilirler. Bu çok yararlı bir şey çünkü herhangi bir türden argümanı kopyalama yapmadan
fonksiyonlara göndermemize yararlar. 
C++11 ise farklı bir referans türünü daha bize sundu: r-value reference. Bu referanslar sadece r-valuelarla init edilmek üzere tasarlanmış referanslardır.
İki ampersand kullanımı ile yapılır-> int x{4}; int& lref{x}; int&& rref{5}; olarak en temel tanımlamaları gösterebiliriz. Rreflerin temelde 2 yararı:
1. init edildikleri objelerin yaşam sürelerini gerekli olan durumlarda rreflerin yaşam süresine kadar uzatır
2. r-value'nın değiştirilebilmesini sağlar. Aşağıdaki yazıda Fraction{3,5} bir r-value oluyor.
Örnek olarak auto&& rref{Fraction{3,5}};'i ele alalım. Normalde rref burada geçici bir Fraction objesini gösterme durumundayken, yani bu ifade bittikten
sonra scope dışına çıkacakken, rref olması sayesinde bu blok içerisinde yaşamaya devam edecek. Literal bir değer, doğrudan değiştirilemeyen bir sabit 
olduğundan, derleyici bu literalden geçici (temporary) bir nesne oluşturur. R-value referansı da bu geçici nesneyi referans alır, yani doğrudan literal 
değeri değil, onun temel alındığı geçici bir nesneyi işaret eder. Bu nedenle, geçici nesne üzerinde değişiklik yapmak mümkündür, ancak bu değişiklik 
literal değeri etkilemez.
Rrefler daha çok fonksiyon parametrelerinde kullanılırlar. Fonksiyon overload işlemlerinde l-value ve r-value kullanımı arasındaki bazı farklılıkları 
kullanmak istediğimizde işe yararlar. 
rref değişkenleri de aslında birer l-valuedur. Objenin türü ve de değer kategorileri biraz birbirinden ayrı kavramlar diyebiliriz. Mesela aşağıdaki kod 
snippet'ı fun(const int& lref)'ı çağırır -> int &&ref{5}; fun(ref); Çünkü ifadede rvalue değil, lvalue değişkeni kullandık. örneği aşağıda olacak. ref 
yerine fun(5) göndersek fun(int&& ref) çağrılacaktı.
rrefleri de nasıl lrefleri fonksiyon return değeri yapmamamız lazımsa yine yapmamalıyız. Çoğu durumda objenin scope dışına kalmasından ötürü dangling ref. 
dönüşü olabilir. Bu da beklenmeyen davranışlara yol açabilir. 
*/

#include <iostream> 

class Coordinates{
private:
    int m_x{};
    int m_y{};
public:
    // Constructorlar
    Coordinates() = default; 
    Coordinates(int x, int y):m_x{x},m_y{y}{}


    friend std::ostream& operator<<(std::ostream& out, const Coordinates& c){
        out << "Coordinates \nx: " << c.m_x << " y: " << c.m_y;
        return out;
    }
};

void refFunc(auto& x){
    std::cout << "lrefFunc çağrıldı" << std::endl;
}
void refFunc(auto&& x){
    std::cout << "rrefFunc çağrıldı" << std::endl;
}

int main(){
    int x{4}; 
    int& lref{x}; 
    // int&& rref{x}; // Hata, sağ tarafta l-value bulunmakta
    int&& rref{23}; 
    Coordinates co1(3,9);
    std::cout << "x: " << x << " lref: " << lref << " rref: " << rref << std::endl;
    // Yukarıdaki değişkenin rref olarak ayarlanması
    Coordinates&& rrefCo1{Coordinates{3,9}};

    // Aşağıdaki kullanım çalışmaz, çünkü sağ tarafında lvalue olur
    // Coordinates&& rrefCo11{co1};

    // Aşağıdaki ifade, universal referans oluşturur. Universal referans, tür çıkarımı sayesinde hem l-value hem de r-value ile çalışabilir. Derleyici, 
    // co1 bir l-value olduğundan, rrefCo11'in türünü Coordinates& (bir l-value referansı) olarak çıkarır. Eğer co1 bir r-value olsaydı, tür Coordinates&& 
    // olurdu. Universal referanslar bu esnekliği sağlar, bu yüzden bu kullanım çalışır. Kullanımı biraz riskli olabilir gibi.
    auto&& rrefCo11{co1};

    // print işlemlerini gerçekleştireceğiz
    std::cout << co1 << std::endl;
    std::cout << rrefCo1 << std::endl;
    std::cout << rrefCo11 << std::endl;
    
    // sırayla aşağıdaki fonksiyonları çağıralım ve de yanlarına beklediğimiz davranışları not düşeyim 
    refFunc(lref); // argüman zaten direkt lvalue, o yüzden lref çağrılır
    refFunc(rref); // argüman ne kadar rref olsa da, o da bir lvalue değişken olduğundan dolayı lref çağrılır
    refFunc(23); // argüman r-value olduğundan dolayı rref çağrılır
    refFunc(Coordinates{}); // argüman yine bir r-value obje. rref çağrılır

    return 0;
}