/* Cpp'de 'using' kelimesi tanımlanmış başka bir şeye daha kolay bir şekilde erişmemizi sağlar. Derleyici bu alias'ı gördüğü zaman yerine gerçek adını 
yerleştirir. 
Typedef de benzer mantığa hizmet eden daha eski bir yöntemdir.

*/
#include <iostream>
// Aşağıdaki kullanımla beraber direkt olarak Deneme a; gibi değişken tanımlayabiliriz. yoksa struct _Deneme a; ile de yapabiliriz
typedef struct _Deneme{
    int a;
} Deneme; 
struct _Deneme2{
    int b;
};
// Benzerinin alias ile yapılması
using Deneme2 = struct _Deneme2;
int main(){
    using Foo = long;
    Deneme a;
    Deneme2 b;
    // Aslında az önceki kısmı C ile karıştırdım sanırım. struct _Deneme yerine sadece _Deneme yazarak da struct oluşturabıliriz
    _Deneme asd;

    return 0;
}