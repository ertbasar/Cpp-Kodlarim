/*Aslında fonksiyon yazmakta sorun yok basit bir işlem ancak eğer fonksiyon parametrelerini değiştirirsek ve sonrasında çağırırken fazladan bir argüman 
gelmesini istemiyorsak ne yapmamız gerektiğiyle alakalı bir dosya oluşturmak istedim. Bunun için fonksiyon tanımını yaparken sadece değişkenin tipini 
yazıp bir şey vermemek yeterlidir. Aşağıdaki örnekte de fazlasıyla açıklayıcı olacağını düşünmekteyim.
*/
#include <iostream> 

int foo(int a, int, int b){

    std::cout << a << " " << b << std::endl;
    return 0;
}

int main(){

    foo(2, 3, 6);



    return 0;
}