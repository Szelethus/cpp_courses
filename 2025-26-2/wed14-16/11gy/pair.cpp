#include <string>

template <class T, class R>
struct pair {
  T first;
  R second;
};

int main() {
  pair<std::string, int> p{"alma", 4};
}
