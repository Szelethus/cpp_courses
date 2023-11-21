#include <iostream>
#include <vector>

template <class UnaryPred>
int find(const std::vector<int> &v, UnaryPred pred) {
  for (int i = 0; i < v.size(); ++i) {
    if (pred(v[i]))
      return i;
  }
  return -1;
}

// Funktor
struct IsSecond3 {
  bool isSecond = false;

  bool operator()(int i) {
    if (i == 3) {
      if (isSecond)
        return true;
      isSecond = true;
    }
    return false;
  }
};

// bool is3(int i) { return i == 3; }
// 
// bool isSecond3(int i) {
//   static bool isSecond = false;
//   if (i == 3) {
//     if (isSecond) {
//       isSecond = false;
//       return true;
//     }
//     isSecond = true;
//   }
//   return false;
// }

int main() {
  std::vector<int> v = {1,2,3,4,5,3};
  std::cout << find(v, IsSecond3()) << '\n';
}
