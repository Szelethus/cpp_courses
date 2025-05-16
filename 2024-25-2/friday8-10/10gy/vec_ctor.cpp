#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec1 = {1,2,3,4,5};
  std::vector<int> vec2;

  vec2.push_back(1);
  vec2.push_back(2);
  vec2.push_back(3);
  vec2.push_back(4);
  vec2.push_back(5);

  std::vector<int> vec3{5};

  vec3[0] = 1;
  vec3[1] = 2;
  vec3[2] = 3;
  vec3[3] = 4;
  vec3[4] = 5;
}
