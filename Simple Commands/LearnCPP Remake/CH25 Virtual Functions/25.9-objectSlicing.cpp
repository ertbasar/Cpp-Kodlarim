/* Şimdiye kadar türetilen objeyi baz objenin referansına atama yoluyla çalıştık. Peki direkt olarak tüertilen objeyi baz objeye assign edersek ne olur?
Burada türetilmiş obje hem türetilmiş hem de baz kısımlara sahip olduğundan dolayı baz kısım assign edilirken türetilmiş kesim 'sliced' olur yani
kırpılır. Yanlış kullanımda beklenmeyen sonuçlar olabilir dikkat edmek gerekli. Genel olarak özellikle fonksiyonlarda pass by ref yerine pass by value
kullanıldığında yaşanmakta diyebiliriz bu sorun için. Vektörlerde de vektör elementleri assignable olması gerektiğinden ve de referanslar yeniden
atanamadığından dolayı ref değil pointer kullanımı gerekli olur -> std::vector<Base*> v{} şeklinde
Bir de Frankenobject sorunu bulunmakta. Aşağıdaki örneğe bakarsak sonda kalan objenin bir kısmı d1 bir kısmı ise d2 kalabilir.
Derived d1{5}; Derived d2{3};
Base& b{d2};
b = d1;
*/