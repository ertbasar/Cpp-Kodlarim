/* If statementların tersine olarak switch case olduğunda expression sadece bir kez değerlendirilmiş olur.
caselerden biri bittiğinde isteğe bağlı olarak yazılan [[fallthrough]] return veya break olmadan warning vermeden alttaki case'e geçiş yapar
switch case ile değişken tanımlayabilir veya değer verebilirsiniz ancak init edemezsiniz (birazcık saçma olsa da)
*/
#include <iostream> 

int main(){
    constexpr int a{5};
    switch (a)
    {
    case 2:

        break;
    case 5:
        int x;
        x = 5;
        break;
    default:
        std::cout << x; // hata vermez çünkü scope içi
        break;
    }
    // std::cout << x; // hata verir çünkü scope dışı
    return 0;
}