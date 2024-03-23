/* C++'ta tüm identifierlar belirsizliğe yer vermeyecek şekilde tanımlanmalıdır. Aksi halde naming collision olabilir.
Namespaceler ise farklı bir scope bölgesi tanımlayarak aynı isimde de olsalar farklı değişken yaratmamız vs.ye yardımcı olur. 
Namespacelerde sadece tanım ve tanımlamalar yazılabilir
*/
#include <iostream>
//namespace tanımı bu şekilde yapılır
namespace deneme{
    int c{4};
    void cout(int x){
        std::cout << x;
    }

}

int main(){
    int b{8};
    deneme::cout(b);
    std::cout << "\n";
    deneme::cout(deneme::c);

    return 0;
}

