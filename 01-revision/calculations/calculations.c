#include <stdio.h>

#define SQUARE(number) ((number) * (number))

double sum_of_squares(int first_number, int second_number) {
    return SQUARE(first_number) + SQUARE(second_number);
}

double average(int first_number, int second_number) {
    return (first_number + second_number) / 2;
}

int sum(int first_number, int second_number) {
    return first_number + second_number;
}

void flush_buffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) { };
}

int seek_integer_input(char* message) {
    int number = 0;
    int check_value = 0;

    do {
        printf("%s", message);
        check_value = scanf("%d", &number);

        if(check_value < 1 || number < 0) {
            printf("Invalid input!\n");
            flush_buffer();
        }
    } while(check_value < 1 || number < 0);

    return number;
}

int main(int argc, char** argv) {
    signed int first_number, second_number = 0;
    int check_value = 0;

    first_number = seek_integer_input("Enter the first number: ");
    second_number = seek_integer_input("Enter the second number: ");
    
    printf("Sum: %d\n", sum(first_number, second_number));
    printf("Average: %.2f\n", average(first_number, second_number));
    printf("Sum of squares: %.2f\n", sum_of_squares(first_number, second_number));

    return 0;
}