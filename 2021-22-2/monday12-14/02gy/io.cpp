#include <iostream>

int main() {
  int age;
  std::cout << "Please submit your age: ";
  std::cin >> age;

  char firstLetter;
  std::cout << "Please submit your name's first letter: ";
  std::cin >> firstLetter;

  std::cout << "Your age: " << age << '\n';
  std::cout << "Your name's first letter: " << firstLetter << '\n';

  switch (firstLetter) {
    case 'a': case 'e': case 'u': case 'i': case 'o':
      std::cout << "Magánhangzó!\n";
      break;
    default:
      std::cout << "Mássalhangzó!\n";
  };

  //switch (firstLetter) {
  //  case 'a':
  //    std::cout << "Magánhangzó!\n";
  //    break;
  //  case 'e':
  //    std::cout << "Magánhangzó!\n";
  //    break;
  //  case 'u':
  //    std::cout << "Magánhangzó!\n";
  //    break;
  //  case 'i':
  //    std::cout << "Magánhangzó!\n";
  //    break;
  //  case 'o':
  //    std::cout << "Magánhangzó!\n";
  //    break;
  //  default:
  //    std::cout << "Mássalhangzó!\n";
  //};

  // && <--- 'és' operátor
  // || <--- 'vagy' operátor
  //if (firstLetter == 'a' || firstLetter == 'e' || firstLetter == 'u' ||
  //    firstLetter == 'i' || firstLetter == 'o') {
  //  std::cout << "Magánhangzó!\n";
  //} else {
  //  std::cout << "Mássalhangzó!\n";
  //}

  // if (firstLetter == 'a') {
  //   std::cout << "Magánhangzó!\n";
  // } else if (firstLetter == 'e') {
  //   std::cout << "Magánhangzó!\n";
  // } else if (firstLetter == 'u') {
  //   std::cout << "Magánhangzó!\n";
  // } else if (firstLetter == 'i') {
  //   std::cout << "Magánhangzó!\n";
  // } else if (firstLetter == 'o') {
  //   std::cout << "Magánhangzó!\n";
  // } else {
  //   std::cout << "Mássalhangzó!\n";
  // }
}
