#include <iostream>

namespace outer {
int x;

namespace inner {
int y;
} // namespace inner

} // namespace outer

int main() {
  outer::x = 1;
  outer::inner::y = 1;
}
