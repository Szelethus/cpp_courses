#include <iostream>

class Storage {
public:
  Storage() {
    std::cout << "Storage created!\n";
  }
  virtual ~Storage() {
    std::cout << "Storage destructed!\n";
  }
};

class IntStorage : public Storage {
  int *ptr;
public:
  IntStorage(int i) : ptr(new int{i}) {
    std::cout << "IntStorage created!\n";
  }
  ~IntStorage() {
    delete ptr;
    std::cout << "IntStorage destructed!\n";
  }
};

int main() {
  Storage *sptr = new IntStorage{6};
  delete sptr;
}
