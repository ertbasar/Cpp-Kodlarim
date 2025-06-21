/* Bir sınıfın aynı anda iki adet sınıftan kalıtım yoluyla bazı şeyleri elde etmesi de mümkündür. Zaten kullanımı basit ancak birkaç ekstra terim
işin içine giriyor diyebiliriz. 
mix-in class: Başka bir sınıfa ekstra özellik veya davranış kazandırmak için kullanılan küçük yardımcı sınıflardır. Kendi başlarına init bir anlamları
pek yoktur. Genellikle de çoklu kalıtım ile beraber kullanılır. Buradaki örneği direkt LearnCPP'den çekeceğim güzel bir örnek, açıklamasını da kendim
yaparım. 
Tekli kalıtımın bir gelişmiş versiyonu gibi algılansa da aslında ileride çok sayıda komplikasyona neden olabilir. Bu yüzden alternatif bir yöntem 
olduğu sürece kaçınılması işe yarayabilir. 
*/

#include <string>
#include <string_view>

class Person
{
private:
    std::string m_name{};
    int m_age{};

public:
    Person(std::string_view name, int age)
        : m_name{ name }, m_age{ age }
    {
    }

    const std::string& getName() const { return m_name; }
    int getAge() const { return m_age; }
};

class Employee
{
private:
    std::string m_employer{};
    double m_wage{};

public:
    Employee(std::string_view employer, double wage)
        : m_employer{ employer }, m_wage{ wage }
    {
    }

    const std::string& getEmployer() const { return m_employer; }
    double getWage() const { return m_wage; }
};

// Teacher sınıfı hem Person hem de Employee sınıflarından çoklu kalıtımı gerçekleştiriyor
class Teacher : public Person, public Employee
{
private:
    int m_teachesGrade{};

public:
    // Tabii ki constructor da biraz büyüdü :)
    Teacher(std::string_view name, int age, std::string_view employer, double wage, int teachesGrade)
        : Person{ name, age }, Employee{ employer, wage }, m_teachesGrade{ teachesGrade }
    {
    }
};

// ----------------

struct Point2D
{
	int x{};
	int y{};
};

class Box // mixin Box sınıfı
{
public:
	void setTopLeft(Point2D point) { m_topLeft = point; }
	void setBottomRight(Point2D point) { m_bottomRight = point; }
private:
	Point2D m_topLeft{};
	Point2D m_bottomRight{};
};

class Label // mixin Label sınıfı
{
public:
	void setText(const std::string_view str) { m_text = str; }
	void setFontSize(int fontSize) { m_fontSize = fontSize; }
private:
	std::string m_text{};
	int m_fontSize{};
};

class Tooltip // mixin Tooltip sınıfı
{
public:
	void setText(const std::string_view str) { m_text = str; }
private:
	std::string m_text{};
};

// Button sınıfı diğer mix-in sınıflarının özelliklerini kalıtımla beraber aldı. Kendi bir özelliği yok
class Button : public Box, public Label, public Tooltip {}; 

int main()
{
    Teacher t{ "Mary", 45, "Boo", 14.3, 8 };
    
    Button button{};
	button.Box::setTopLeft({ 1, 1 });
	button.Box::setBottomRight({ 10, 10 });
	button.Label::setText("Submit");
	button.Label::setFontSize(6);
	button.Tooltip::setText("Submit the form to the server");

    return 0;
}