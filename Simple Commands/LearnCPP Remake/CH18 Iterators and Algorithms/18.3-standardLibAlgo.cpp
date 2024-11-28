/* Bazı basit taskların yazımı standart kütüphanede bulunmaktadır. Bu algoritmalar genel olarak 3e ayrılırlar
Inspect -> Bir konteynırdaki veriyi izlemek için
Mutator -> Bir konteynırdaki veriyi değiştirmek için
Facilitator -> Bir konteynır içindeki veriyi kullanarak bir sonuç elde etmek için

std::find -> Bir değerin konteynır içindeki ilk bulunduğu yeri arar. begin, end ve de aranacak değeri parametre alır, bulunduğu konumun pointerını veya
o değer yoksa konteynırın sonunu gösterir.

std::count -> Kaç kere o değerle karşılaşıldığını döndürür

std::sort -> Sıralama işlemi yapar

std::for_each -> konteynır içerisindeki tüm değerlerle bir işlem gerçekleştirmek için kullanılır (doubleNumber gibi)

Burada her seferinde begin ve arr göndermek bunaltıcı olabilir. C++20'den itibaren sadece konteynırın adını gönderebiiliriz
*/