#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("argc: %d", argc);
    printf("\n");
    for (int i = 0; i< argc; i++) {
        printf("arg:%s\n", argv[i]);
    }
    // char* name = "felix";
    // printf("name = %s\n", name);
    return 0;
}