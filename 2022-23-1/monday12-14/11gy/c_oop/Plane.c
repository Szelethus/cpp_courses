#include "Plane.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Plane {
  int ID;
  int wingspan;
  char brand[50];
};

struct Plane *mallocPlane(int ID, int wingspan, char *brand) {
  struct Plane *plane = malloc(sizeof(struct Plane));
  plane->ID = ID;
  plane->wingspan = wingspan;
  strcpy(plane->brand, brand);
  return plane;
}

void freePlane(struct Plane *plane) {
  free(plane);
}

int getWingSpan(const struct Plane *plane) {
  return plane->wingspan;
}

const char *getBrand(const struct Plane *plane) {
  return plane->brand;
}
