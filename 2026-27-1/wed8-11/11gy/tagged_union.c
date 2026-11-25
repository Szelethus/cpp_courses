#include <stdio.h>

struct Point {
  int x;
  int y;
};

typedef struct Point Point;

enum Tag {
  act_i,
  act_charptr,
  act_point
};

union Data {
  int i;
  char *charptr;
  Point point;
};

struct TaggedUnion {
  enum Tag tag;
  union Data data;
};

typedef struct TaggedUnion TaggedUnion;

void printUnion(TaggedUnion tg) {
  switch(tg.tag) {
    case act_i:
      printf("%d", tg.data.i);
      break;
    case act_charptr:
      printf("%s", tg.data.charptr);
      break;
    case act_point:
      printf("(%d, %d)", tg.data.point.x,
                         tg.data.point.y);
      break;
  }
}

int main() {
  TaggedUnion tg;

  Point p = {3, 4};
  tg.data.point = p;
  tg.tag = act_point;

  printUnion(tg);
}
