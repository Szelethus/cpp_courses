
struct Int{
  int i;
};

struct Float {
  float f;

  Float(float f) : f(f) {}

  explicit Float(Int i) : f(i.i) {}
};

int main() {
  Int i{4};

  Float f{6};

  f = static_cast<Float>(i);
}
