/* Şimdiye kadar overload edilen parametrelerde sadece operand türü hakkında çalışma yapmıştık. Parantezde ise hem operand türü hem de sayısı hakkında
overload yapılabilir. Burada 2 önemli durum var: Birincisi parantez operatörünün member olmalı, ikincisi ise yine fonksiyon çağrılırken kullanılabileceği.
operator() genelde functor denilen, fonksiyon gibi hareket eden sınıflarda overload edilir. Burada functor'un fonksiyona göre avantajı, verileri kendi
değişkenlerinde saklayabilmesi olur denebilir.
Aşağıdaki örneği direkt LearnCPP'den aldım uğraşmadım
*/

#include <iostream>
#include <cassert> 

class Matrix
{
private:
    double m_data[4][4]{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

public:
    double& operator()(int row, int col);
    double operator()(int row, int col) const;
    void operator()();
};

// matristeki elemanı dönen fonksiyon
double& Matrix::operator()(int row, int col)
{
    assert(row >= 0 && row < 4);
    assert(col >= 0 && col < 4);

    return m_data[row][col];
}

// const versiyon
double Matrix::operator()(int row, int col) const
{
    assert(row >= 0 && row < 4);
    assert(col >= 0 && col < 4);

    return m_data[row][col];
}

// tüm elemanları 0.0'a döndüren fonksiyon
void Matrix::operator()()
{
    for (int row{ 0 }; row < 4; ++row)
    {
        for (int col{ 0 }; col < 4; ++col)
        {
            m_data[row][col] = 0.0;
        }
    }
}



int main(){

    Matrix a;
    std::cout << a(1,3) << std::endl;


    return 0;
}
