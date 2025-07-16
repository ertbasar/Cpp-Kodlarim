/* Herhangi uygun bir catch bloğu bulunamadığında std::terminate() çağrılır ve program sonlandırılır. Bu tür durumlarda stack geri satabilir veya 
sarmayabilir, bundan daha önce bahsetmiştik. Burada da lokal değişkenlerin parçalaması gerçekleşmeyebileceğinden dolayı herhangi bir temizleme işlemi
olmayabilir. Bu da pek istenen bir şey değildir. 
Catch-all handler ise normal catch bloğu gibi çalışan, sadece operator... kullanarak her türlü exception'u handle edebilecek durumdaki bloklardır. catch
bloklarını sıraladığımız zaman en altta bulunması lazım. Genel olarak da zaten içleri boş bırakılırlar, amaçları stack geri sarma işleminin gerçekleşmesini
sağlamak ve gerekli temizliklerin yapıldığından emin olmaktır. Pek hata handle işlemi gerçekleştirmezler. 

catch(double x){...}
catch(...){...} // catch all handler

*/