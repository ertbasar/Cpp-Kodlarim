#include <iostream>

template <typename T>
struct Triad
{
	T first {};
	T second {};
	T third {};
};

// If using C++17, we need to provide a deduction guide (not required in C++20)
// A Triad with three arguments of the same type should deduce to a Triad<T>
//template <typename T>
//Triad(T, T, T) -> Triad<T>;

template <typename T>
void print(const Triad<T>& t)
{
	std::cout << '[' << t.first << ", " << t.second << ", " << t.third << ']';
}

int main()
{
	Triad<double> t1{ 1, 2, 3 }; // <double> kısmı olmasa yukardakı deductıon guıde kullanmak gerekırdi
	print<double>(t1);

	Triad<double> t2{ 1.2, 3.4, 5.6 };
	print<double>(t2);

	return 0;
}