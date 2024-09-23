#include <iostream>

int main() {
	int k = 6;
	
	const int *const ptr = &k;
	
	int c = 8;
	
	std::cout << k << '\n';
	
	int *r = nullptr;
}
