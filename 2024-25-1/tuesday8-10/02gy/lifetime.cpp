#include <iostream>

int i = 9;

namespace detail {
int k;
}

int main() {
	int i = 6;
	for (int i = 0; i < 1; ++i) {
		std::cout << ::i << '\n';
	}
	
	detail::k = i;
}
