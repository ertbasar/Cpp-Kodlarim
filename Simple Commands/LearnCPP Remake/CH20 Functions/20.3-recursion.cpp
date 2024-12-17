/* Recursion bir fonksiyonun geri kendisini çağırması olarak tanımlanabilir. Burada kendi kendini sonsuza kadar çağırmaması için bazı koşul
kodları koymak gerekebilir. Aşağıda basit bir faktöriyel işlemi gerçekleştireyim.
*/

#include <iostream>

int faktoriyel(int x){
    if(x > 1) // Koşul kısmı, burada x = 1'i görene kadar aslında gidecek ve sonrasında sırayla geri döndürecek. 5*4*3*2*1 yerine 1*2*3*4*5 gibi debebilir.
        return x * faktoriyel(x-1);
    return 1;
}


int main(){

    std::cout << faktoriyel(5) << std::endl;



    return 0;
}