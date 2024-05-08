/* Cpp'de cok farkli tiplemeler vardir ve bunlardan biri de rvalue ve lvalue kavramlaridir. 
lvalue -> islemin sol tarafinda bulunabilecek degerler. bir ifadeyi olusturan ve bellekte tanimlanmis nesneyi temsil eder
rvalue -> islemin sag tarafinda bulunabilecek degerler. bir ifadenin degerini temsil eder
eger bir ifadenin rvalue mi yoksa lvalue mi oldugunu belirleyemiyorsan adresini & operatoruyle almaya calis. rvalueler adressizdir


*/
#include <iostream>

int main(){
	
	int x = 5; // Burada x lvalue, 5 ise rvalue
	int y = x; // Burada x rvalue, y ise lvalue
	std::cout << &x << std::endl;
	
	
	
	return 0;
}
