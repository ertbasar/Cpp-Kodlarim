/* Referanslarda olduğu gibi normal pointerlarla da const kullanımı hata verir. Bunun için pointer to const denen const olmayan ponter'ın constant değeri 
gösterdiği yapıyı kullanırız. Tanımını yapmak için değişken türünün öncesine const yazmak yeterlidir. Burada const olan kısım pointerın kendisi değil 
gösterdiği yer olduğundan dolayı farklı bir adrese pointerı assign edebiliriz ancak pointerın gösterdiği yerin değerini değiştiremeyiz.
Bunun dışında pointerın kendisini de const yapabiliriz. Buna const pointer denir ve bu sefer tür tipinden sonra const yazmak gereklidir.
Aynı zamanda const pointer to a const value şeklinde ikisinin de beraber kullanıldığı bir yapı da oluşturulabilir.
/*
A const before asterix is associated with the type being pointed to
A const after asterix is associated with partner itself
*/

#include <iostream> 

int main(){
    const int x{7};
    const int y{5};
    const int* ptr{};
    int z{34};
    ptr = &x;
    std::cout << *ptr << std::endl;
    //*prt = 34; // Hata verir. Gösterdiği yeri değiştiremeyiz.

    // Görüldüğü üzere farklı bir const değerin adresine assign edebiliyoruz.
    ptr = &y;
    std::cout << *ptr << std::endl;
    
    // Aynı const olmayan bir yeri de reference to const gibi gösterebilir
    ptr = &z;
    std::cout << *ptr << std::endl;

    // Const pointer
    int a{23};
    int b{55};
    int* const ptr2{&a};
    std::cout << *ptr2 << std::endl;
    // ptr2 = &b; // Hata verir ancak aşağıdaki gibi gösterdiği yerin değerini değiştirebiliriz
    *ptr2 = b;
    std::cout << *ptr2 << std::endl;

    // Const pointer to a const value
    int c{345};
    const int* const ptr3{&c};
    std::cout << *ptr3 << std::endl;
    // ptr3 = &a; // Hata verir
    // *ptr3 = a; // Hata verir
    return 0;
}