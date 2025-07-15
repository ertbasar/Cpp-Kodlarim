/* Operator<<'ı sanal olarak yapamayız. Bu yüzden baz sınıfın referansını kullanarak oluşturulmuş sınıf objeleri operator<< kullanarak overload edilemez.
Bu yüzden iki adet farklı çözüm yolu vardır. Siteden bakılabilir çok fazla içerisine girmeyeceğim bu konunun. Ama temel olarak şunu diyebiliriz ki
operator<<'ı overload etmek için ya her sınıf için ayrı ayrı overload etmemiz gerekir ya da bir fonksiyon tanımlayıp bu fonksiyonu her sınıf için 
çağırmamız gerekir.
*/