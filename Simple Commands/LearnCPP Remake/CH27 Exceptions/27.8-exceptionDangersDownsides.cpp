/* Exceptionlar bazı durumlarda ne kadar yararlı olsalar da bazı dezavantajları da olabilir. Sırayla bakalım
1. Exception olduğunda gerekli temizlik işlemlerinin yapılmaması
2. Destructor içinde kesinlikle kullanılmamalı. Program hata verir
3. Ekstra kod yazımı gerektirdiğinden ve bazı kontrolleri gerçekleştirdiğinden dosya boyutunu arttırır ve performansı çok az etkilese de düşürür. 
Exception handling aşağıdaki durumların hepsi gerçekleştiğinde dizayn edilmeli:
1. Bu hata çok sık karşılaşılmayan bir hataysa
2. Hata çok büyükse ve program çalışmaya devam edemiyorsa
3. Hata, karşılaşılan ilk yerde yönetilemiyorsa
4. Return kodu veya başka iyi bir alternatif yoksa
*/