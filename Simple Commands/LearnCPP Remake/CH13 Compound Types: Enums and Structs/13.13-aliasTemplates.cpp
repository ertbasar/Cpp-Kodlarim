/* Sınıf şablonlarında da alias ile bilinen bir tipin yerine başka bir şey kullanabiliriz. Kullanımı biraz daha farklı

*/

template <typename T> 
struct Pair{
    T first{};
    T second{};
};

template <typename T> 
using Coord = Pair <T>;

template <typename T>
void print(const Coord<T>& c){
    // ...
}