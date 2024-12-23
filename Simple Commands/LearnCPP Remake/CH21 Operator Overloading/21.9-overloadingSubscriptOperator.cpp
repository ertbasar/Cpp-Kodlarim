/* En iyi member fonksiyon olarak tanımlanır. Dönüş türü de referanstır. Çünkü operator[]'ın kullanım şeklinde sonucunun l-value olabilmesi için bir
referans döndürmesi gerekir. Referanslar her zaman l-value olarak kabul edilir, çünkü bellek adresine işaret ederler ve bu da atama işlemi için gereklidir.
Burada const objeler için yeniden bir overload işlemi yapmamız gereklidir. Ayrıca index validasyonu önemli olabilir, normalde olmadığından dolayı bizim
overload işlemi yaptığımız durumlarda bunu  kontrol etmemiz yararlı olabilir. Bu arada operator[] kesinlikle bir objeye işaret etmelidir, eğer bir nesneye
işaret edilen bir pointer üzerinden çağırıyorsanız, önce pointer'ı dereference etmeniz gerekir. Son olarak da operator[] istenen her türden değişken 
üzerinden overload edilebilir. Aşağıda da bir vektöre sahip olan bir sınıf için bunu yapacağım :)
*/

#include <iostream>
#include <vector>
class Vec{
private:
    std::vector<int> a{1,2,3,4,5};
public:
    int& operator[](int index){
        return a[index];
    }
};



int main(){
    Vec v1;
    std::cout << v1[2] << std::endl;



    return 0; 
}
