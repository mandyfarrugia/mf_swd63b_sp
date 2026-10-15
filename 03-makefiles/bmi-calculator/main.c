#include <stdio.h>
#include <stdlib.h>
#include "bmi_calculator.h"
#include "bmi_status.h"

double convert_str_to_double(char* argument) {
    char* end_pointer = NULL; //Indicates where strtod stops parsing.

    double conversion_result = strtod(argument, &end_pointer);

    //If the end_pointer and argument both point to the same address, then conversion was unsuccessful.
    if(end_pointer == argument) {
        return 0;
    }

    //If input is successful, then the value referenced by the pointer should be a null terminator.
    if(*end_pointer != '\0') {
        return 0;
    }

    return conversion_result;
}

int main(int argc, char** argv) {
    if(argc != 3) {
        fprintf(stderr, "Usage: %s <weight_in_kilograms> <height_in_metres>\n", *(argv + 0));
        return EXIT_FAILURE;
    }

    double weight_in_kg = convert_str_to_double(*(argv + 1));
    if(weight_in_kg == 0) {
        fprintf(stderr, "Weight is not in correct format!\n");
        return EXIT_FAILURE;
    }

    printf("%f\n", weight_in_kg);

    double height_in_metres = convert_str_to_double(*(argv + 2));

    if(height_in_metres == 0) {
        fprintf(stderr, "Height is not in correct format!\n");
        return EXIT_FAILURE;
    }

    printf("%f\n", height_in_metres);

    double bmi_calculated = calculate_bmi(weight_in_kg, height_in_metres);
    if(bmi_calculated == 0) {
        fprintf(stderr, "Could not calculate BMI, try again!\n");
        return EXIT_FAILURE;
    }

    char* bmi_result = generate_status_from_bmi(bmi_calculated);
    if(bmi_result == NULL) {
        fprintf(stderr, "Could not generate result from BMI calculation, try again!\n");
        return EXIT_FAILURE;
    }

    fprintf(stdout, "BMI (Body Mass Index): %.2f\nResult: You are %s.\n", bmi_calculated, bmi_result);

    return EXIT_SUCCESS;
}