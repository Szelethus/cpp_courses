#include <vector>
#include <algorithm>

struct IsSecond3 {
  bool firstFound = false;

  bool operator()(int i) {
    if (i == 3) {
      if (!firstFound) {
        firstFound = true;
        return false;
      }
      return true;
    }
    return false;
  }
};

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5, 3};
  std::vector<int>::iterator it = find_if(v.begin(), v.end(),
                                               IsSecond3{});

  if (it == v.end())
    return -1;

}
