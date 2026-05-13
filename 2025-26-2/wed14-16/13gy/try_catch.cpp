#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

int main() {
  std::vector<int> v{1,2,3,4,5,6};

  try {
    std::cout << v.at(100) << '\n';
  } catch (std::exception &e) {
    std::cout << e.what() << '\n';
  } catch (int i) {
    std::cout << "Caught an int\n";
  } catch (...) {
    std::cout << "Caught an exception\n";
  }
}
