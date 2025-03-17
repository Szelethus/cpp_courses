#include <iostream>
#include <string>

struct Login {
  // Encode the letters of the name in an integer array.
  int letters[5];
  // Wether the user has admin access.
  int isAdmin = 0;
};

int main() {
  Login login;

  std::string name;
  std::cout << "Provide a login name: ";
  std::cin >> name;

  for (int i = 0; i < name.size(); ++i) {
    login.letters[i] = int(name[i]);
  }

  if (name == "pityu") {
    login.isAdmin = 1;
  }

  std::cout << "Admin?: " << (login.isAdmin != 0)
            << std::endl;
}
