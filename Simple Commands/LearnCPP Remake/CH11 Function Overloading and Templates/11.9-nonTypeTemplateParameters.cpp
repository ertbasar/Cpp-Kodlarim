/* Tur olmayan sablon parametreleri aslinda iceriye sabit degerleri gondermemiz gerektiginde lazim olur.
C++20 itibariyle fonksiyon parametreleri constexpr olamiyor ve de static_assert bizden const bir ifade istiyor. Assert de 
kullanilabilir ancak biz run-time degil compile-time tercih ederiz.
Bu non-type sablon argumanlarini derleyici gordugu zaman kendiliginden tur donusumu gerceklesebilir. Bu bazi durumlarda belirsizlik
ve hataya neden olabilir.
C++17den itibaren tip olmayan sablon parametrelerinde auto kelimesini kullanabiliyoruz. 

*/


#include <iostream>

template <int N>
void print(){
	std::cout << N << std::endl;
}
/* Fonksiyonun asagidaki gibi cagrildigini goren derleyici
template <>
void print<3>{std::cout << 3 << std::endl;}
gibi bir fonksiyon olusturur
*/

int main(){
	
	print<3>();
	
	
	return 0;
}
