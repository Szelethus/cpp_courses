
#include <cstdio>

union MyUnion {
  const char *hello;
  int flag;
};

void f() {
  MyUnion u;
  u.hello = "Hello";

  printf("%s", u.hello);
  printf("%i", u.flag);
}
