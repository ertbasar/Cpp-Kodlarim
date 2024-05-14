/* Bir yapı da sonuçta normal değişken gibi olduğundan dolayı onu fonksiyonlara pass by reference ile gönderebilir veya return olarak alabiliriz. 
Bunun dışında Fraction f1{getFraction()}; gibi verilerin alınıp bir yapıya eklendiği gibi durumlarda da return value olarak Fraction verilmelidir

*/
#include <iostream>

struct Point{
    int x{};
    int y{};
};

void printPoint(Point& p){
    std::cout << "x:" << p.x << " y:" << p.y << std::endl;
}
// İki yapıyı alıp değişkenlerini toplayıp yapı olarak döndüren bir fonksiyon
Point addPoints(Point& p1, Point& p2){
    Point temp{};
    temp.x = p1.x + p2.x;
    temp.y = p1.y + p2.y;
    return temp;
}


int main(){
    Point p1{1, 4};
    Point p2{23, 55};

    std::cout << "Point 1 Info" << std::endl;
    printPoint(p1);

    std::cout << "Point 2 Info" << std::endl;
    printPoint(p2);

    // İki yapıyı fonksiyon yardımıyla toplayarak yeni bir yapı oluşturduk
    Point p3{addPoints(p1, p2)};
    std::cout << "Point 3 Info" << std::endl;
    printPoint(p3);

    return 0;
}