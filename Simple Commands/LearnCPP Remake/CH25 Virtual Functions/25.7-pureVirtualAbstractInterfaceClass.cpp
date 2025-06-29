/* C++ bizim farklı bir özel bir sanal fonksiyon tanımlamamıza izin verir, bu da hiç gövdesi olmayan pure virtual fonksiyonlardır. Bu fonksiyonlar sadece bir 
yer tutar, ana sınıf içerisinde bir işlevleri yoktur ve türetilen sınıfta yeniden tanımlanıp detaylandırılması zorunludur. 
Oluşturmak için fonksiyonu direkt 0'a eşitlemek yeterli. Kullanımı durumunda iki adet sonuç beliriyor. 
1. Bir veya daha fazla saf sanal fonksiyona sahip bir sınıf abstract (soyut taban) sınıfı haline gelir. Ve bu sınıflar kendi başlarına nesne oluşturamazlar. 
2. Türetilen sınıflar bu fonksiyonlara bir adet override vermek durumunda, eğer vermezse o sınıf da abstract baz sınıf haline gelir. 
Saf sanal fonksiyonlar baz sınıfa bir fonksiyonu koymak istediğimizde, ancak sadece türetilen sınıfın bu fonksiyonla alakalı bir şey yapabilmesini istediğimizde
kullanılırlar. Bu türetilen sınıfların da kendi objelerinin yaratılabilmesi için override işleminin gerçekleşmesi gerekir. Bu sayede türetilen sınıfta bu
fonksiyonun tanımlandığından emin olunur. 
Normal fonksiyonlar gibi baz sınıfın pointer/referansları üzerinden çağrılabilirler. 
İlginç bir özellik olsa da saf sanal fonksiyonları tanımlayabiliriz de. Bunun için sınıf tanımı içinde yine 0'a eşitlenmeli ve de tanımlamalar
sınıfın dışında yapılmalı. Bu yöntem baz sınıftaki fonksiyonun bir default tanıma sahip olduğu, ancak türetilmiş sınıfların da kendi tanımlamalarının zorunlu
tutulmasının istendiği durumlarda kullanılır. 
---
Interface (arayüz) sınıfı herhangi bir üye değişkeni olmayan, sadece saf sanal fonksiyonlara sahip olan sınıflardır. 
*/


#include <iostream> 
#include <string>

class Base{
    public:
    virtual int getValue() const = 0; // Bu şekilde tanımladık
    virtual int getValue2() const = 0; 

};

class Derived: public Base{
    public:
    // Aşağıdaki fonksiyonlardan birini bile tanımlamasak bize variable type 'Derived' is an abstract class hatası döndürür çünkü
    // gerekli override işlemleri yapılmadığından ötürü bu sınıf da abstract kalır
    int getValue() const override{
        return 5;
    }
    int getValue2() const override{
        return 2;
    }
};

// Saf sanal fonksiyona ek olarak dışarıda tanımlama
int Base::getValue2() const{
    return 2;
}

int main(){
    Derived d{};
    std::cout << d.getValue() << " " << std::endl;
    // Baz sınıfa da ref veya pointer ile atayabiliyoruz
    Base& b{d};
    return 0;
}