#include <stdio.h>
#include <string.h>

struct Login {
  char name[5];
  // Whether the user has admin access.
  char isAdmin;
};

int main(void) {
  struct Login login = {0};

  printf("Provide a login name: ");
  scanf("%s", login.name);

  if (strcmp(login.name, "pityu") == 0) {
    login.isAdmin = 1;
  }

  printf("Admin?: %d\n", login.isAdmin != 0);
  return 0;
}
