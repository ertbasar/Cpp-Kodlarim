/* Direkt isimsiz bir namespace tanımlayabiliriz. En büyük yararlarından biri bu namespace içindekilerin sadece internal linke sahip olması denebilir.
Ayrıca inline namespaceler de kullanabiliriz. Normal namespace'ler, bir namespace içerisinde tanımlanan isimlerin, dış namespace'e tamamen dahil edilmesini 
sağlar. Yani, normal bir namespace içinde tanımlanan bir ismin, dış namespace'te kullanılabilmesi için namespace'in kendisiyle birlikte kullanılması gerekir.
Inline namespace'ler ise, iç namespace'in içeriğinin, dış namespace'e tamamen dahil edilmesini sağlar. Yani, inline bir namespace içinde tanımlanan isimler, 
dış namespace'te doğrudan kullanılabilir hale gelir. Örneği aşağıda. Aynı zamanda versiyonlama çalışmaları veya deneme çalışmalarında da kullanılabilir
Son olarak da bir namespace hem inline hem de isimsiz olabilir. Denemeler yaparken işi kolaylaştırır :)
*/
#include <iostream>

namespace // isimsiz namespace oluşturduk
{
    void fonk()
    {
        std::cout << "deneme" << std::endl;
    }
}
namespace A {
    inline namespace B {
        int x{27}; // şu an direkt A::x olarak kullanılabilecek duruma geldi
    }
}

int main()
{
    fonk(); //direkt bu şekilde çağırabiliriz
    std::cout << A::x << std::endl;

    return 0;
}