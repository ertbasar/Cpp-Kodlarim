/* Çoğu array türünün önemli bir limiti vardır. O da tanımlandıkları sırada boyutlarının bilinmesi gerekliliğidir, ayrıca sonradan da değiştirilemezler. 
Bunlara fixed-size arrayler diyebiliriz. Ancak vektörler dinamik arraylerdir ve boyutları sonradan değişebilir. Vektörü özel kılan da budur. Vektörün
resize üye fonksiyonu kullanılarak boyutu değiştirilebilir, bu sayede normalde olan elemanları korunurken yeni elemanları da 0 ile value init olur.
Aynı zamanda daha küçük bir boyuta da resize edilebilirler. Kapasite ise vektörün bellek üzerinde ayırdığı alanı belirtir, boyut ise kaç tane elemanı
olduğunu. Kapasiteyi de capacity() üye fonksiyonuyla alabiliriz. Burada vektör kapasitesini değiştirdiğinde bu işleme reallocation denir. Resmi olarak şöyle
i. vektör yeni istenen kapasitede bir bölgeyi bellekten ayırır
ii. eski bellek alanındaki veriler kopyalanır (eğer mümkünse taşınır)
iii. yeni kapasite ve boyut değerleri vektöre atanır
Aslında vektör yeniden boyutlanıdırılmış gibi gözükse de gerçekte olan şey belleğin değiştirilmesidir denebilir. Buradaki kopyalama işlemleri pahalı 
olduğundan olabildiğince gereksiz işlemden kaçınmak en iyisidir. 
Vektör indisleme boyuta göredir, kapasiteye göre değil. Vektörü resize ederken boyutunu kısaltmak kapasitesini değiştirmez. Bu sorunu çözmek için
shrink_to_fit() üye fonksiyonu kullanarak kapasiteyi boyuta eşleme yapabiliriz.
*/

#include <iostream> 
#include <vector>

int main(){
    // Vektör tanımı ve sonrasında kapasite ve boyut sorguları
    std::vector v1{1,2,3,4,5,6,7,8};
    std::cout << "Vektörün kapasitesi: " << v1.capacity() << std::endl;
    std::cout << "Vektörün boyutu: " << v1.size() << std::endl;

    // Sonuna eleman ekledikten sonra yeniden aynı sorgular
    v1.push_back(9);
    std::cout << "Vektörün kapasitesi: " << v1.capacity() << std::endl;
    std::cout << "Vektörün boyutu: " << v1.size() << std::endl;

    // Kapasitenin boyuta eşleme yapılması
    v1.shrink_to_fit();
    std::cout << "Vektörün kapasitesi: " << v1.capacity() << std::endl;
    std::cout << "Vektörün boyutu: " << v1.size() << std::endl;

    return 0;
}