/* Projeyi daha düzenli tutmak için, OCR kuralını delmemek için vs birçok yerde header dosyaları kullanırız. Burada bazı tanımlamalar yapıp
ana kodun içerisine #include ettikten sonra içindeki tanımlamaları kullanabiliriz. 
Genel olarak
main.cpp -> headerın include edilip hemen kullanım
square.h -> prototip yazımı
square.cpp - > headerın include'u ve tanımlamalar
*/

#include <iostream>
#include "square.h"

int main(){
    int x{5};
    //Diğer dosyalarda yazılmış aldığı sayının karesini ekrana yazdıran fonksiyon
    square(5);

    return 0;
}