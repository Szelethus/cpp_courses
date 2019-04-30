#include <iostream>

template <class T>
void swap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <int N>
void f() {
	std::cout << N << '\n';
}

int main() {
	int a = 5, b = 6;
	swap(a, b);

	double d1 = 5.6, d2 = 9.3;
	
	swap(d1, d2);
	
	f<20>();
}