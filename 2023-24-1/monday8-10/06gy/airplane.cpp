#include <iostream>

class Airplane {
  std::string name;
  int id;

public:
  static int instances;

  Airplane(std::string name) : name(name), id(instances++) {
    std::cout << "Plane '" << name << "' (id: " << id << ") created\n";
  }

  std::string getName() { return name; }
};

int Airplane::instances = 0;

class AirTrafficManager {
  Airplane *planes[3];

public:
  void populate_planes() {
    planes[0] = new Airplane("B737");
    planes[1] = new Airplane("F16");
    planes[2] = new Airplane("B787");
  }

  ~AirTrafficManager() {
    delete planes[0];
    delete planes[1];
    delete planes[2];
  }
};
