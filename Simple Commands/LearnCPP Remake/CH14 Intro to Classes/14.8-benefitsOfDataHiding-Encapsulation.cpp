/* Fonksiyonları olabildiğince non-member yapmak iyi olabilir. Burada direkt set ve get'i üye yapma demekten ziyade üye yaptığın bir fonksiyonda private
üyelere direkt erişmekten kaçın diyor. 
Kod başkalarıyla da paylaşılabileceğinden ve de diğer kişiler direkt olarak arayüzle ilgilenebileceğinden dolayı sıralama public, protected, private.
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
        m_id = id;
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
};

// Sınıf arayüzünde değil
void printName(const Foo& foo){
        std::cout << foo.getName() << std::endl;
}

int main()
{
	Foo goo{}; 

	goo.setName("Ert");

	printName(goo);
	return 0;
}