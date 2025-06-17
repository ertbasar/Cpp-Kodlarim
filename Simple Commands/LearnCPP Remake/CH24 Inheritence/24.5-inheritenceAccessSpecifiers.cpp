/* Şimdiye kadar public ve private erişim belirleyicilerini görmüştük. Bir diğeri ise protected. Erişim belirleyicisi protected altında olan üyeler, kendi sınıf objelerine, friend'lere ve de
türetilmiş fonksiyonların erişimlerine açıktır, ancak sınıfın dışarısına açık değillerdir. Genel olarak üyeleri private yapmak daha iyi denebilir ancak eğer private üyelerin erişiminde kullanılacak
arayüzün geliştirilmesi komplike olacaksa protected yapılabilir. 
3 farklı türde kalıtım şekli ve de 3 farklı türde de erişim şekli olduğundan dolayı 9 kombinasyon olur. Buradaki kombinasyonlara göre erişimde değişiklikler olabilir. Genel olarak incelersek: 
- public: Anlaması en kolayı, erişim baz sınıftakiyle aynı kalır. 
- protected: public ve de protected üyelerin erişimi protected, private ise private kalır
- private: tüm baz sınıfı üyeleri private olarak alınır. Bu yüzden üye baz sınıfta public bile olsa main fonksiyonda erişilemez. 
*/

class Base{
    int m_private{12};
    protected:
    int m_protected{24};
    public: 
    int m_public{36};
};

class Derived: public Base{
    public:
    Derived(){
        // m_private = 1; // Erişemez
        m_protected = 2; // Erişebilir
        m_public = 3;
    }
};

int main(){
    Base b;
    b.m_public = 15;
    // b.m_private = 211; // Hata
    // b.m_protected = 12; // Hata

    return 0;
}