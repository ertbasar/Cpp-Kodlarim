/* Pass by address kullandığımız zaman bir obje yerine o objenin adresini pointer ile göndermiş oluruz. Fonksiyondaki parametreye bu pointer'ın gösterdiği
değer değil pointer'ın tuttuğu adres gönderilir. 
Burada eğer spesifik bir nedenimiz yoksa pass by reference'ı tercih etmemiz daha iyi olur. Bunun nedenleri:
1. Fonksiyon çağrımı yaparken adreslerle uğraşmak yerine direkt olarak kendi adını kullanmamız
2. Pass by reference geçersiz bellek erişimlerini önlemeye yardımcı olur
3. Daha verimli olabilir çünkü referanslar adreslere göre daha hafif bir veri yapısına sahiptir. 

*/
#include <iostream>

void printByValue(int value){
    std::cout << value << std::endl;
}

void printByReference(const int& value){
    std::cout << value << std::endl;
}

void printByAddress(const int* ptr){
    std::cout << *ptr << std::endl;
}
int main(){
    int a1{23};
    int a2{25};
    int a3{27};

    printByValue(a1);
    printByReference(a2);
    printByAddress(&a3);
    return 0;
}