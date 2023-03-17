#include <iostream>

bool isAdmin(std::string name) {
  if (name != "pityu") {
    std::cout << "YOU ARE NOT THE ADMIN!!\n";
    return false;
  }
  return true;
}
