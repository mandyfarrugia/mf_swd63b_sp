#include <stdio.h>
#include <stdlib.h>

#define MAX_THRESHOLD 10

void flush_buffer() {
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

int get_maximum_number(int* array, int array_length) {
    int first_element_of_array = *(array + 0);
    int maximum_number = first_element_of_array;

    for(int index = 0; index < array_length; index++) {
        int current_element = *(array + index);

        if(current_element > maximum_number) {
            maximum_number = current_element;
        }
    }

    return maximum_number;
}

int seek_integer_input(char* message) {
    int check_value = 0;
    int number = 0;

    do {
        printf("%s", message);
        check_value = scanf("%d", &number);

        if(check_value < 1) {
            printf("Invalid input!\n");
            flush_buffer();
        }
    } while(check_value < 1);

    return number;
}

int main(int argc, char** argv) {
    int* numbers_array = (int*)malloc(MAX_THRESHOLD * sizeof(int));

    if(numbers_array == NULL) {
        printf("Unfortunately, memory allocation has failed!\n");
        return -1;
    }

    for(int index = 0; index < MAX_THRESHOLD; index++) {
        *(numbers_array + index) = seek_integer_input("Enter a number: ");
    }

    int maximum_value = get_maximum_number(numbers_array, MAX_THRESHOLD);
    printf("The largest value from the array in memory location %p is %d.\n", &numbers_array, maximum_value);

    free(numbers_array);
    return 0;
}