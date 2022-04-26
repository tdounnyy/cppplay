#include <stdio.h>

const char *TEST_FILE = "/Users/duanyufei/temp/j.json";

void log(const char *msg) {
  printf("%s", msg);
}

int main(int argc, char *argv[]) {
  FILE *f = fopen(TEST_FILE, "r");
  if (f==NULL) {
    log("open file fail");
  } else {
    log("open success");
  }

  char c;
  while ((c = fgetc(f))!=EOF) {
    printf("%c", c);
  }

  fclose(f);
  return 0;
}