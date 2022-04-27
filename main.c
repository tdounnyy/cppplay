#include <stdio.h>

const char *TEST_FILE = "/Users/duanyufei/temp/test.py";
const char *TARGET_FILE = "/Users/duanyufei/temp/test2.py";

void log(const char *msg) {
  printf("%s", msg);
}

void copy(char *inputfile, char *outputfile) {
  FILE *infile = fopen(inputfile, "r");
  FILE *outfile = fopen(outputfile, "w");
  if (infile == NULL) {
    log("open file fail");
  } else {
    log("open success");
  }

  char c;
  while ((c = fgetc(infile)) != EOF) {
    printf("%c", c);
    fputc(c, outfile);
  }

  fclose(infile);
  fclose(outfile);
}

int main(int argc, char *argv[]) {
  copy(TEST_FILE, TARGET_FILE);
}