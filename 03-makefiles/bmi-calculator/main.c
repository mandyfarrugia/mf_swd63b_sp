#include "bmi_calculator.h"
#include "bmi_status.h"
#include <stdio.h>
#include <stdlib.h>
#include "value_converter.h"

int main(int argc, char** argv) {
    if(argc != 4) {
        fprintf(stderr, "Usage: %s <weight_in_kilograms> <height_in_metres> <output-file.txt>\n", *(argv + 0));
        return EXIT_FAILURE;
    }

    double weight_in_kg = 0;
    ValueConversionResult value_conversion_result = convert_str_to_double(*(argv + 1), &weight_in_kg);
    if(value_conversion_result == VALUE_CONVERSION_FAILURE) {
        fprintf(stderr, "Weight is not in correct format!\n");
        return EXIT_FAILURE;
    }

    double height_in_metres = 0;
    value_conversion_result = convert_str_to_double(*(argv + 2), &height_in_metres);
    if(value_conversion_result == VALUE_CONVERSION_FAILURE) {
        fprintf(stderr, "Height is not in correct format!\n");
        return EXIT_FAILURE;
    }

    double bmi_calculated = 0;
    BmiCalculatorResult calculation_result = calculate_bmi(weight_in_kg, height_in_metres, &bmi_calculated);

    if(calculation_result == BMI_CALCULATION_FAILURE) {
        fprintf(stderr, "Could not calculate BMI, try again!\n");
        return EXIT_FAILURE;
    }

    const char* bmi_result = generate_status_from_bmi(bmi_calculated);
    if(bmi_result == NULL) {
        fprintf(stderr, "Could not generate result from BMI calculation, try again!\n");
        return EXIT_FAILURE;
    }

    FILE* file_write_ptr = fopen(*(argv + 3), "w");
    if(!file_write_ptr) {
        fprintf(stderr, "Failed to create the file!\n");
        return EXIT_FAILURE;
    }

    fprintf(file_write_ptr, "BMI (Body Mass Index): %.2f\nResult: You are %s.\n", bmi_calculated, bmi_result);

    return EXIT_SUCCESS;
}