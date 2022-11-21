#include "Plane.h"
#include <stdio.h>

int main() {
  struct Plane *plane = mallocPlane(0xDEADBEED, 200, "Boeing");
  printf("Plane has a wingspan of %i meters and a brand of %s\n",
         getWingSpan(plane), getBrand(plane));
  //plane->wingspan = 200;
  freePlane(plane);
}
