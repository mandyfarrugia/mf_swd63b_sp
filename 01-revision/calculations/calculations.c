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

int main(int argc, char** argv) {
    int first_number, second_number = 0;
    int check_value = 0;

    do {
        printf("Enter the first number: ");
        check_value = scanf("%d", &first_number);
    } while(check_value != 1);

    do {
        printf("Enter the second number: ");
        check_value = scanf("%d", &second_number);
    } while(check_value != 1);
    
    printf("Sum: %d\n", sum(first_number, second_number));
    printf("Average: %d\n", sum(first_number, second_number));
    printf("Sum: %d\n", sum(first_number, second_number));
}