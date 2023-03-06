#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

std::vector<int> generateVector();

struct GreaterThan3 {
  bool operator()(int i) {
    return i > 3;
  }
};

struct Pol {
  virtual void a();
};

struct OrderByMod7 {
  bool operator()(int a, int b) {
    return (a % 7) < (b % 7);
  }
};

int main() {
  std::vector<int> vec = generateVector();

  // (1a) STL algoritmus segítségével keressük meg az első olyan elemet vec-ben,
  // amelynek az értéke 3nál nagyobb!

  std::vector<int>::iterator it = find_if(vec.begin(), vec.end(), GreaterThan3{});
  
  // (1b) Töröljük ki a vectorból ezt, és a rákövetkező elemet is!

  it = vec.erase(it);
  vec.erase(it);

  // (2) Írjunk egy polimorfikus osztályt!
  
  // (3) Írjunk egy int-eket tartalmazó halmazt STL konténer segítségével,
  // mely a 7 szerinti maradék szerint rendez!

  std::set<int, OrderByMod7> s;

  // (4) Mi a különbség az std::remove_if és az std::stable_partition között?
}
