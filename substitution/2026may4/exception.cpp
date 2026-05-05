#include <iostream>
#include <vector>

int main() {
  try {
    std::vector<int> v = {1,2,3,4,5};
    
    v.at(50000);

  } catch(std::exception &e) {
    std::cout << e.what() << '\n';
  } catch (int i) {
    std::cout << "caught " << i << '\n';
  }  catch (...) {
    std::cout << "Caught an exception\n";
  }
}
