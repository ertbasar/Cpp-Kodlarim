/* Aslına bakarsak burada çok ekstra bir şey yok değinmemiz gereken. 16.2'de yazdırma örneğine bakılabilir basit bir döngü örneği için.
Burada sıkıntı indis kullanımında gerçekleşebilir çünkü indis ve uzunlukta kullanılan tür olan std::size_t aslında unsigned bir değer. Bundan ötürü
özellikle geriye doğru giden döngülerde bazı istenmeyen durumlar gerçekleşebilir. Bunun önüne geçmek adına iki adet yöntem bulunmakta
1- Range based for loops
2- iterators
Bu iki konuyu önümüzdeki bölümlerde inceleyeceğiz :)
*/