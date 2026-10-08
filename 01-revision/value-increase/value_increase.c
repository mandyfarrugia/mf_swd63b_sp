#include <stdio.h>

int main(int argc, char** argv) {
    int value = 0;

    while(1) {
        value += 10000;
        printf("Updated value: %d", value);
    }

    return 0;
}