/* Bazı durumlarda bir exceptionu yakalamak ancak tam olarak da handle etmemek durumunda kalırız. Bu tür durumlarda exceptionu asıl handle edileceği
yere doğru göndermek gerekli. Bir fonksiyon return code olarak geri döndürünce bunu halletmek kolaydır ancak return kodu yokken, exceptionlarla bunu
nasıl hallederiz? Burada birkaç farklı yol bulunmakta:
1. Catch bloğu üzerinden yeni bir exception fırlatmak. Stack üzerinden gerekli yere geri sarar
2. Exception objesini kullanarak yeni bir throw yapmak -> throw exception; gibi, bu da kopyalama yapacağından yanlış olur.
3. Doğru yol exceptionu rethrow yapmaktır. Yakalanan exception objesinden kopyalama yapmadan direkt olarak aynısını fırlatır. Sadece throw; kullanılır.

catch(Base& b){
    cout << "B objesi yakalandı" << endl;
    throw; // Yakalanan obje geri fırlatılır.
}


*/