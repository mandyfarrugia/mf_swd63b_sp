#include <stdio.h>

void introduce(char* message) {
    printf("%s\n", message);
}

void introduce(int num) {
    printf("Number %d\n", num);
}