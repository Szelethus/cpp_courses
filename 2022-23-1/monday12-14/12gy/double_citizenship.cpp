#include <iostream>

class Citizen {
protected:
  std::string passport;
  std::string tax_number;
  std::string social_security;
};

class SlovakianCitizen : public Citizen {
public:
};

class HungarianCitizen : public Citizen {
public:
};

struct Bela : public SlovakianCitizen, public HungarianCitizen {
  void print() {
    std::cout << SlovakianCitizen::passport;
  }
};

int main() {
  Bela b;
}
