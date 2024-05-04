/* C++17 ile beraber koşulun sabit bir değer olduğu durumlara özel compile-time'da değerlendirilecek if statementları geldi.
Burada eğer constexpr if statementının true olduğu düşünülürse direkt o if statement yerine oradaki true state karşılığı veya tam tersi geçirilir.
Kullanımı aşağıda
*/
#include <iostream>

int main(){
    constexpr double gravity{9.8};

    if constexpr(gravity == 9.8){
        std::cout << "Yerçekimi değeri doğru";
    }

    return 0;
}