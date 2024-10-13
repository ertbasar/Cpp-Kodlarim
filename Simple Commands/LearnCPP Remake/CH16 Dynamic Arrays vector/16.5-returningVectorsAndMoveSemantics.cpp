/* Bir vektörü fonksiyona gönderirken, referansı ile göndeririz çünkü 'pahalı' bir kopyasının oluşmasını istemeyiz. Burada geri dönüş değerinin referans ile
değil de değer ile geri döndürüleceğini söyleyince şaşırılabilir. Ancak burada copy semantics dediğimiz bir şey devreye girer. Bu terim objelerin kopyalarının
nasıl oluşturulacağıyla alakalı kuraların belirlenmesi denebilir. Burada copy semantics'i destekleyen bir tür var dediğimiz zaman bu türün kopyalama 
işleminin tanımlandığını söyleyebiliriz. Örnek olarak sınıf tiplerinde bu işlem copy constructorlarla implemente edilir. 
Bir verinin sahipliği başka bir objeye transfer edildiği zaman biz bu işleme move işlemi deriz. Bu işlem genel olarak 'ucuz' bir işlem denebilir. Burada
da move semantics devreye girer ve tanımlı olduğu obje türlerinde diğer objeye taşınma işlemini gerçekleştirir. Burada move semantics işlemi tetiklendiğinde,
taşınabillir olan veriler taşınır, taşınamayanlar ise kopyalanır. Burada verilerin taşınabilmesi eğer gerçekleştirilebiliyorsa kopyalanmasından çok daha
efektif ve verimli denebilir. Normalde, herhangi bir obje, aynı türden bir objeyle init edildiğinde veya assign edildiğinde copy semantics devreye girer.
Ancak aşağıdaki 3 koşul sağlandığında move semantics tetiklenir:
1- Objenin türü move semanticsi desteklemeli
2- Init edilen veya assign edilen obje r-value olmalı
3- Assign edilen obje tam haliyle assign edilmeli
Çoğu tür aslında move smeanticsi desteklemez ancak vektör gibi konteynırlar ve string gibi bazı sınıflar şu an destekler.
Burada son dikkat edilecek şey, return by value'nun r-value döndürmesinden ötürü move semantics işlemlerini gerçekleştirmemize hem olanak sağlaması hem de
çok daha 'ucuz' şekilde işlemi gerçekleştirmemize olanak tanır. (Değerler yine pass bt (const) reference ile gönderilmeli)
*/

