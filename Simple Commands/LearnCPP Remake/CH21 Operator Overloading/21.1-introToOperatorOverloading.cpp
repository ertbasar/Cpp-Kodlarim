/* C++ içerisinde operatörler aslında fonksiyon olarak yerleştirilmişlerdir. Burada overload işlemi yaparak bu operatörlerin kendi istediğimiz işlemleri
yapmalarını sağlayabiliriz. Derleyici, aslında bu işlemleri önceden bildiğinden de kaynaklı olarak, bize daha okunabilir şekilde işlemleri gerçekleştire-
bileceğimiz bir yapı sunar. Örnek olarak x+y dediğimiz zaman derleyici bunu operator+(x,y) olarak kendiliğinden dönüştürür. Burada derleyici resolve
yaparken ilk olarak kendiliğinden bir tanım var mı diye bir inceler, eğer yoksa hata döndürür. Ancak program-typed operatör işlemleri tanımlanmışsa, 
derleyici fonksiyon overload resolution algoritmasını çalıştırır ve uygun bir eşleşme olup olamayacağını inceler. Eğer bu süreçte de yoksa hata döner.
Burada bazı limitler olabilir:
1. Neredeyse her operatör overload edilebilir ancak bazıları edilemez. Bunlardan bir kısmı -> '?:', 'sizeof', '::', '.', '.*', typeid and casting operators.
2. Sadece zaten bulunan operatörler overload edilebilirler. Yeni bir operatör oluşturulamaz
3. Operatörle beraber kullanılan operandlardan en az bir tanesinin user-defined tür olması gerekli
4. Operand sayısını değiştirmek mümkün değildir
Operator overload ederken gerçek kullanımlarına olabildiğince yakın işlemlerle overload etmek en iyisi olur. Eğer bu sağlanamıyorsa normal bir fonksiyon
kullanmak daha iyi olabilir. 

*/