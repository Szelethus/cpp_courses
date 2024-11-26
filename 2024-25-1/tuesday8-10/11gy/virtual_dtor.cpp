struct Int {
  int i;

  virtual void foo() {}

  Int(int i) : i(i) {}

  virtual ~Int() {}
};

struct IntPtr : public Int {
  int *ptr;

  IntPtr(int i) : Int(i), ptr(new int{i}) {}

  ~IntPtr() {
    delete ptr;
  }
};

int main() {
  Int *ptr = new IntPtr{0};

  delete ptr;
}
