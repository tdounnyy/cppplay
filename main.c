#include <stdio.h>
#include <string.h>

typedef struct {
  unsigned int id;
  unsigned int age;
  char name[30];
} Person;

void printPersion(const Person *p) {
  printf("id:%d\n", (*p).id);
  printf("age:%d\n", (*p).age);
  printf("name:%s\n", (*p).name);

}
int main(int argc, char *argv[]) {

  char c;
  while ((c = getchar()) != EOF) {
    printf("putchar\n");
    putchar(c);
  }

  // printf("argc: %d", argc);
  // printf("\n");

  // Person peter = { 123, 35, "Peter"};

  // printPersion(&peter);
  return 0;
}