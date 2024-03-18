#include <iostream>
#include <vector>

int main() {
  std::vector<int> v;

  v.push_back(5);
  v.push_back(6);
  v.push_back(7);
  v.push_back(7);
  v.push_back(7);


  //for (int i = 0; i < v.size(); ++i) {
  //  std::cout << v[i] << '\n';
  //}

  std::vector<int> vi2;

  vi2.resize(10);

  for (int i = 0; i < vi2.size() + 10; ++i) {
    vi2.at(i) = i;

    std::cout << vi2[i] << '\n';
  }

}
