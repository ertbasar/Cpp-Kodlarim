/* İteratörler bir konteynır yapısı içerisinde gezinmek için oluşturulmuş objelerdir denebilir. Burada konteynırın elemanlarına erişim sağlarlar. En basit
iteratör olarak da aslında pointerları gösterebiliriz (pointer aritmetiği ile beraber saklanan veriye erişim sağlanır). Kullanımı çok yaygın bir operasyon
olduğundan ötürü çoğu standart kütüphane fonksiyonu da direkt olarak begin ve end fonksiyonlarıyla erişime destek sağlar. Burada numerik karşılaştırmalar
yaparken operator<  yerine =! kullanırız ancak iteratörlerde durumun tam tersi olduğunu hatırlatmakta fayda var. Karşılaştırmalar =! ile yapılmalı.
Begin ve end üye fonksiyonlarına sahip tüm türlerde range based looplar kullanılabilir. Zaten arka planda da aynı işlem gerçekleşir.
Pointer ve ref.lerde de olduğu üzere adres değişimi veya yok edilme olduğunda danglling iterator durumu oluşabilir. Geri init yapmak bazı sorunlardan
sakınmamıza yardımcı olabilir. 
Aslında modern kullanımda range based kullanım nispeten daha iyi diyebiliriz
*/

#include <iostream>
#include <vector>

int main() {
    
    std::vector numbers = {10, 20, 30, 40, 50};

    // İteratör kullanarak elemanları yazdır. Tanımda syntax biraz karmaşık olablilir
    std::cout << "Vektör elemanları (iteratör):" << std::endl;
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) { // For içinde =! kullanımıına dikkat
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Modern C++ (C++11 ve sonrası) ile range-based for döngüsü
    std::cout << "Vektör elemanları (range-based for):" << std::endl;
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Başlangıca aldık
    auto it{numbers.begin()};
    it++; // Bir ileriyi gösterip yazdırdık. Pointer aritmetiğine çok benzer
    std::cout << *it;
    return 0;
}




