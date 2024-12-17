/* Programın genel olarak farklı segmentler denilen ayrı ayrı bölgelerde bellek kullanımı gerçekleştirir. Bunlar:
1. code segmenti -> Derlenmiş programın bellek üzerinde olduğu yer. Bu segment genel olarak read-only olur
2. bss segment -> zero-initialized global ve statik değişkenlerin saklandığı yer
3. data segment -> init edilmiş global ve statik verilerin saklandığı yer
4. heap -> dinamik olarak bellek ayrılan değişkenlerin saklandığı yer
5. stack -> fonksiyon parametreleri, lokal değişkenler, ve diğer fonksiyonlarla ilgili bilgilerin saklandığı bölüm

Heap dinamik olarak ayrılan belleklerin izini tutar. Burada new operatörü ile bellek ayırabilir ve de bize pointer döndürerek bu alanı saklamamıza yardımcı
olur. Burada arka planda ne işlemlerin gerçekleştiğini bilmemize gerek yoktur. Delete işlemi gerçekleştiğinde de bu bellek heap'e geri verilir ve de 
ileriki zamanlarda yeniden ayrılabilecek konuma getirilir. Burada pointerı silmek, değişkeni de silmek anlamına gelmiyor. Burada sadece o bellek bölümü
işletim sistemine geri veriliyor. 

Stack veya call stack olarak geçen bölüm ise programın başından o ana kadar tüm aktif fonksiyonların izini sürer ve bu süre içerisinde fonksiyon 
parametreleri ve de lokal değişkeşkenlerin bellek ayrım işlemlerini gerçekleştirir. Stack veri yapısı olarak implemente edilmiştir ve de temel olarak
bir konteynır yapısına benzese de çok daha kısıtlı erişim ve değişim fonksiyonlarına sahiptir. Stack içindeki operasyonlar:
1. Sıradaki objeye bakış (top veya peak ile)
2. Sıradaki objeyi stackten çekme (pop ile)
3. Sıraya yeni bir obje ekleme (push ile)
Genel olarak stack için LIFO (Last In First Out) yapısında diyebiliriz. Yani son push edilen obje ilk pop ile geri verilir.
Stack limitli bir boyuta sahip olduğundan ötürü belli bir miktarda bilgiyi saklayabilir. Fazla yükleme yapılması durumunda stack overflow gerçekleşebilir.
*/