#include <iostream>

// Şablon struct tanımı
template<typename T>
struct Pair {
    T first{};
    T second{};
};

// Şablon fonksiyon tanımı
template<typename T>
void printPair(const Pair<T>& p) {
    std::cout << "(" << p.first << ", " << p.second << ")" << std::endl;
}

int main() {
    // int türünde Pair yapısı oluşturma
    Pair<int> intPair{10, 20};
    // double türünde Pair yapısı oluşturma
    Pair<double> doublePair{3.14, 2.718};
    
    // Pair yapılarını yazdırma
    std::cout << "Integer Pair: ";
    printPair(intPair);
    std::cout << "Double Pair: ";
    printPair(doublePair);
    
    return 0;
}
