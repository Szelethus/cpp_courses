#include <stdio.h>

struct Point {
  int x, y;
};

enum Tag {
  act_i,
  act_charptr,
  act_point
};

union Data {
  int i;
  char *charptr;
  struct Point point;
};

struct TaggedUnion {
  enum Tag tag;
  union Data data;
};

void printData(struct TaggedUnion tg) {
  switch (tg.tag) {
    case act_i:
      printf("%d\n", tg.data.i);
      break;
    case act_charptr:
      printf("%s\n", tg.data.charptr);
      break;
    case act_point:
      printf("(%d, %d)\n", tg.data.point.x, tg.data.point.y);
      break;
  }
}

int main() {
  struct TaggedUnion tg; 

  struct Point p = {.x = 2, .y = 3};
  tg.data.point = p;
  tg.tag = act_point;
  
  printData(tg);
}
