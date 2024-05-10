/* Cpp'de null pointer kavramı bir şeyin hiçbir değerinin olmadığını belirtmek için kullanılır. Pointer null'u gösterdiğinde de ise bu pointer'ın herhangi
bir şeyi göstermediğini düşünebiliriz. 
nullptr -> nasıl true ve false gibi boolean değerler varsa nullptr için de buna benzer bir şey diyebiliriz. init yaparken, assign ederken, fonksiyona null 
pointer göndermek isterken ve koşul denemelerinde kullanılabilir. 
Bir pointer ya valid bir objenin adresini göstermeli ya da nullptr olmalı. Eski bazı kullanımlarda nullptr yerine 0 veya NULL kullanımı görülebilir.
Eğer pointerların ekstra özellikleri gerekmiyorsa referansları pointerlara göre tercih etmek daha iyidir
*/

#include <iostream>

int main(){
    int* c{}; // nullptr üretmenin en basit yolu
    std::cout << c << std::endl;
    if(c == nullptr)
        std::cout << "Harbiden nullptrmiş :)" << std::endl;
    return 0;
}