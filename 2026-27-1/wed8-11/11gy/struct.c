#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Point {
  int x;
  int y;
};

typedef struct Point Point;

Point getRandPoint() {
  Point ret;
  ret.x = rand() % 100;
  ret.y = rand() % 100;
  return ret;
}

void printPoint(const Point *p) {
  printf("(%d, %d)\n", (*p).x, p->y);
}

int main() {
  srand(time(NULL));
  for (int i = 0; i < 20; ++i) {
    struct Point point1 = getRandPoint();
    printPoint(&point1);
  }

  Point point2 = {3, 4};
  Point point3 = {.x = 7, .y = 8};
}
