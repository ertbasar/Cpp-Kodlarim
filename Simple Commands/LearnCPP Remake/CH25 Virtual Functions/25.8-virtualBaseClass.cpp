/* Diamond diagram probleminden 24.9'da bahsetmiştik. Burada en baz sınıfın iki kez oluşturulması problemi yaşanıyordu. Burada da bizim yardım çağrımıza
sanal baz sınıf cevap veriyor. Burada baz sınıfı paylaşmak için türetilen sınıfın kalıtım listesinde bu baz sınıfın adının öncesinde virtual keywordunu
kullanmak yeterli olacaktır. Bu sayede de tek bir baz sınıf olacak ve kalıtım ağacında ortak olarak kullanılacaktır.

*/

class Base{};

class D1: virtual public Base{};
class D2: virtual public Base{};

class DD1: public D1, public D2{};

int main(){return 0;}