#include <iostream>

struct Storage {
  Storage() {
    std::cout << "Storage created\n";
  }

  virtual ~Storage() {
    std::cout << "Storage destroyed\n";
  }
};

struct IntStorage : public Storage {
  int *ptr;

  IntStorage(int i) : ptr(new int{i}) {
    std::cout << "IntStorage created\n";
  }

  ~IntStorage() {
    delete ptr;
    std::cout << "IntStorage destroyed\n";
  }
};


int main() {
  Storage *ptr = new IntStorage(5);
  delete ptr;
}
