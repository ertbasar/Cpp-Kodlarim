/* Sınıflar aynı zamanda kendi içlerinde tanımlanan sınıflara da izin verirler. Burada genel olarak nested olan sınıfı olabildiğince en yukarıya yazmak iyidir.
Burada forward declaration yapılamaz. Full tanımı gerçekleştirmek önemli.
*/

#include <iostream>

class OuterClass {
public:
    // Nested sınıf
    class InnerClass {
    public:
        void innerMethod() {
            std::cout << "Inner class method called." << std::endl;
        }
    };

    void outerMethod() {
        std::cout << "Outer class method called." << std::endl;
    }
};

int main() {
    // Outer sınıfın bir nesnesini oluşturuyoruz
    OuterClass outer;
    outer.outerMethod();

    // Inner sınıfın bir nesnesini oluşturuyoruz
    OuterClass::InnerClass inner;
    inner.innerMethod();

    return 0;
}
