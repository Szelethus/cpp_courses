#include <iostream>

int main() {
  int age;
  char startLetter;

  std::cout << "Please give me your age: ";
  std::cin >> age;

  std::cout << "Please give me your name: ";
  std::cin >> startLetter;

  std::cout << "name: " << startLetter << " age: " << age << '\n';

  // if (startLetter == 'a') {
  //   std::cout << "a a kezdőbetű";
  // } else {
  //   std::cout << "a nem a kezdőbetű";
  // }

  //if (startLetter == 'a') {
  //  std::cout << "magánhangzó!";
  //} else if (startLetter == 'e') {
  //  std::cout << "magánhangzó!";
  //} else if (startLetter == 'i') {
  //  std::cout << "magánhangzó!";
  //} else if (startLetter == 'u') {
  //  std::cout << "magánhangzó!";
  //} else if (startLetter == 'o') {
  //  std::cout << "magánhangzó!";
  //} else {
  //  std::cout << "mássalhangzó!";
  //}

  if (startLetter == 'a') {
    std::cout << "magánhangzó!";
  } else if (startLetter == 'e') {
    std::cout << "magánhangzó!";
  } else if (startLetter == 'i') {
    std::cout << "magánhangzó!";
  } else if (startLetter == 'u') {
    std::cout << "magánhangzó!";
  } else if (startLetter == 'o') {
    std::cout << "magánhangzó!";
  } else {
    std::cout << "mássalhangzó!";
  }

  std::cout << '\n';
}
