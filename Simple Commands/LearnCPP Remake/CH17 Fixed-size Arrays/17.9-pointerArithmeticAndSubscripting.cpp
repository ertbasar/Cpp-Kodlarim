/* Pointer aritmetiği, bazı temel matematikssel işlemleri pointer üzerinden yapmamıza ve yeni bir pointer adresi elde etmemize izin verir. 
Örnek olarak ptr+1, bir sonraki objenin bellekteki yerini gösterir. operator[] da bu aritmetiği kullanarak işlemlerini gerçekleştirir. 
*/

#include <iostream>

int main(){
    int arr[]{9, 7, 5, 3, 1};
    int* ptr = arr;
    std::cout << ptr[1] << std::endl;
    std::cout << ptr[-1] << std::endl; // Pointer kullanımında sınır denetimi elbette yok

    return 0;
}