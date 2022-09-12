#include "shapes.hpp"
#include "shapes.hpp"

#include <iostream>

#define CHECK_EQUAL(a, b) \
  { \
    const auto va = (a); \
    const auto vb = (b); \
    if (va != vb) \
    { \
      std::cerr \
        << "\n" __FILE__ ":" << __LINE__ << ": expected\n" \
        << "  " #a " == " #b "\n" \
        << "but\n" \
        << "  " << va << " != " << vb << "\n" \
        << "\n"; \
      return mark; \
    } \
  }

int test_code()
{
  int mark = 1;
  
  rectangle r1(10, 20);
  const rectangle r2(4, 3);

  CHECK_EQUAL(r1.area(), 200);
  CHECK_EQUAL(r2.area(), 12);

  square s1(3);
  const square s2(4);

  CHECK_EQUAL(s1.area(), 9);
  CHECK_EQUAL(s2.area(), 16);

  mark = 2;

  shape* sh1 = &r1;
  CHECK_EQUAL(sh1->area(), r1.area());

  const shape* sh2 = &s2;
  CHECK_EQUAL(sh2->area(), s2.area());

  class test_shape : public shape
  {
  public:
    explicit test_shape(int& counter) : counter_(&counter) {}

    ~test_shape() { ++*counter_; }

    int area() const { return 0; }

    shape *clone() const
    {
      return new test_shape(*this);
    }
  private:
    int* counter_;
  };

  int destructed_times = 0;
  shape* sh3 = new test_shape(destructed_times);
  delete sh3;

  CHECK_EQUAL(destructed_times, 1);

  mark = 3;
  {
    shape_group g1;

    g1.add(r1);
    CHECK_EQUAL(g1.area(), r1.area());

    g1.add(s2);
    CHECK_EQUAL(g1.area(), r1.area() + s2.area());

    g1.add(test_shape(destructed_times));
    CHECK_EQUAL(destructed_times, 2);
  }
  CHECK_EQUAL(destructed_times, 3);

  mark = 4;
  shape_group g2;
  g2.add(r1);
  g2.add(r2);
  g2.add(test_shape(destructed_times));

  shape_group g3(g2);

  CHECK_EQUAL(destructed_times, 4);
  g3 = g2;
  CHECK_EQUAL(destructed_times, 5);

  g2.add(g3);

  mark = 5;
  return mark;
}

int main()
{
  const int mark = test_code();
  std::cout << "Your mark is " << mark << std::endl;
}

