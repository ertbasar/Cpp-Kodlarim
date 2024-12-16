/* Destructorlar özel bir sınıf fonksiyonudur ve o sınıfın objesinin parçalandığı zaman, veya o sınıfın dinamik olarak oluşturulmuş bir objesi delete
anahtar sözcüğü kullanılarak silindiğinde çağrılırlar. Burada destructor, obje tamamen parçalanmadan önce son temizlik işlemlerini gerçekleştirebilir.
RAII(Resource Acquisition Is Initialization) tekniği, sınıf objelerinin yaşam ömrünün constructor ve destructorlarla beraber otomatik olarak 
belirlenmesi gibi düşünülebilir. Manuel (önceki yaptığımız new ve delete gibi) veya daha otomatik (unique_ptr ve shared_ptr) olarak iki şekilde
yapılabilir. 

*/

#include <iostream>

class IntArray{
    int* m_array{};
    int m_length{};
    public:
    IntArray(int length): m_length{length}
    {
        m_array = new int[length];
        std::cout << length << " uzunluğunda bir obje oluştu" << std::endl; 
    }
    ~IntArray(){
        std::cout << m_length << " uzunluğunda obje parçalandı" << std::endl;
        delete[] m_array;}
};

int main(){
    IntArray asd(123); 

    IntArray* ptr1 = new IntArray(256);
    delete ptr1; // pointer değişkeni olduğundan ve kendi allocationumuz olduğundan kendimiz serbest bırakmalıyız, yoksa leak olur

    // asd değişkeninde kendiliğinden delete edecek
    return 0;
}