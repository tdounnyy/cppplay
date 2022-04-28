#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

const char *TEST_FILE = "/Users/duanyufei";

enum FILE_TYPE { REG_FILE, DIR, OTHER, UNKNOWN };

typedef struct {
  char *path;
  char *owner;
  char *group;
  enum FILE_TYPE type;
  int attr;
  long size;
} FILE_RECORD;

void log(const char *msg) {
  printf("%s", msg);
}

//FILE_RECORD * get_files(const char *path) {
//  return NULL;
//}

FILE_RECORD read_record(const char *path) {
  FILE_RECORD r = {path, "unknown_owner", "unknown_group", UNKNOWN, -1, -1};
  struct stat path_stat;
  stat(path, &path_stat);
  if (S_ISREG(path_stat.st_mode)) {
    r.type = REG_FILE;
  } else if (S_ISDIR(path_stat.st_mode)) {
    r.type = DIR;
  } else {
    r.type = OTHER;
  }
  return r;
}

char *format(const FILE_RECORD *record) {
  char *split = "\t\t";
  int split_len = strlen(split);
  int length1 = strlen(record->path);
  int length2 = strlen(record->owner);
  int length3 = strlen(record->group);

  char type[10];
  switch (record->type) {
    case REG_FILE:strcpy(type, "file");
      break;
    case DIR:strcpy(type, "dir");
      break;
    case OTHER:strcpy(type, "other");
      break;
    default:strcpy(type, "unknown_type");
  }
  int length4 = strlen(type);

  char *result = malloc(length1 + length2 + length3 + length4 + split_len*3 + 1);
  memset(result, 0, strlen(result));

  memcpy(result, record->path, length1);
//  result[length1] = split;
  memcpy(result + length1, split, split_len);
  memcpy(result + length1 + split_len, record->owner, length2);
//  result[length1 + length2 + split_len] = split;
  memcpy(result + length1 + length2 + split_len, split, split_len);
  memcpy(result + length1 + length2 + split_len*2, record->group, length3);
//  result[length1 + length2 + length3 + split_len*2] = split;
  memcpy(result + length1 + length2 + length3 + split_len*2, split, split_len);
  memcpy(result + length1 + length2 + length3 + split_len*3, type, length4);
  return result;
}

int main(int argc, char *argv[]) {

  FILE_RECORD r = read_record(TEST_FILE);
  char *str_record = format(&r);
  log(str_record);

  return 0;
}