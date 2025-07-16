/* Exception yönetimiyle alakalı en iyi özelliklerden biri de throw ifadelerinin direkt olarak try bloğunun içinde handle edilmesinin zorunlu olmaması 
diyebiliriz. Bunun yerine throw ifadeleri herhangi bir yerde kullanılabilir, ve bu exceptionlar çağrıldıkları try bloğundan veya onu da çağıran try
bloğundan handle edilebilirler. 
Bir exception fırlatıldığı zaman program ilk olarak bu exception'un o fonksiyon içerisinde hemen handle edilip edilemeyeceğine bakar. Eğer şu an bulunan
fonksiyon bu exception'u handle edebilecek durumdaysa handle edilir. Eğer durum böyle değilse, program bir sonraki adım olarak bu fonksiyonu çağıran 
fonksiyona bakar ve burada bir handle edilebilme durumu olup olmadığına bakar. Burada önemli olan konu, çağıran fonksiyonun da yine bir try bloğu içerisinde
olup olmadığına bakılmasıdır, eğer durum böyle değilse uygun bir catch bloğuna yönlendirme işlemi olmaz ve bu sefer de bir üst çağıran fonksiyona bakılır. 
Bu süreç, exceptionu handle edebilecek bir catch bloğunu bulana kadar veya hiçbir uygun catch bloğu bulunamayana kadar devam eder. 
Eğer uygun bir catch bloğu bulunursa program bu catch bloğunun en üstüne kadar stack üzerinde geri sarar ve bu işlem sırasında arada kalan fonksiyonlardaki
lokal değişkenler silinir. Bu sayede de bazı gerekli destructorların çağrıldığını söyleyebiliriz ki bu iyi bir şeydir. Ancak eğer uygun bir catch blok
bulunamazsa, bu işlemin gerçekleşeceğinin bir garantisi yoktur. 
Bu stack üzerinden geri sarma işlemine 'stack unwinding' denir.

*/