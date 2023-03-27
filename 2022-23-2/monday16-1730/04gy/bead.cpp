#include <iostream>
#include <vector>

int heappop(std::vector<int> &heap);

int main() {
  std::vector<int> heap = {5, 4, 2, 3, 0, 1};

  while (!heap.empty()) {
    int i = heappop(heap), expected = heap.size();
    std::cout << "Popped value: " << i << '\n';
    if (i != expected) {
      std::cout << "Error: expected value was " << expected << "!\n";
      std::cout << "Remaining heap contents:";
      for (int elt : heap) {
        std::cout << elt << " ";
      }
      std::cout << '\n';
      break;
    }
  }
}
