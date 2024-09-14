/* Biliyoruz ki bazı değişkenleri kopyalaması pahalı olduğundan dolayı returnlerini referans ile yapıyoruz. Burada return edilen objenin fonskiyon return
ettikten sonra da yaşamına devam etmesi önemliydi. Burada da benzer kurala bağlı kalırsak sıkıntı yaşamayız.
Burada önemli olan başka bir şey ise dönen referansın dönen veri tipiyle aynı olmasını sağlamak. Burada boşu yere conversion yapılmasını istemeyiz. Özellikle
getter kullanırken auto ile deduce etmek mantıklı olabilir. Ancak yine de kullanımı sırasında dikkatli olunmalı. 
non-const referansları private üyelere eşitlememek önemli çünkü burada indirekt olarak veriye erişim sağlanmasına sebep olabilir.
son olarak da cosnt üye fonksiyonları non-const referansları üyelere döndürme yetisine sahip değillerdir.
*/

#include <iostream>
#include <string>

class Foo{
    int m_id{};
    std::string m_name{};
    public:
    // ID Getter
    int getID()const {
        return m_id;
    }
    // ID Setter
    void setID(int id){
        m_id = m_id;
    }
    // name Getter
    // Burada const string referansı ile geri dönüş yapıyoruz. Bu şekilde hem stringin ağırlığını taşımıyoruz hem de zaten fonksiyon bir getter ve dönüş const
    const std::string& getName() const { 
        return m_name;
    }
    // name Setter
    void setName(std::string_view name){
        m_name = name;
    }
    // print fonksiyonu
    void printID(){
        std::cout << m_id << std::endl;
    }
};

int main()
{
	Foo goo{}; 

	goo.setName("Joe");
	std::cout << goo.getName(); // Burada fonksiyonu çağırdığımızda const value string referansı dönecek

	return 0;
}








