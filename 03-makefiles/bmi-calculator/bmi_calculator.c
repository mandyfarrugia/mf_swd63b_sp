#include <math.h>
#include "bmi_calculator.h"

BmiCalculatorResult calculate_bmi(double weight_in_kg, double height_in_metres, double* bmi_calculation) {
    if(!bmi_calculation) {
        return BMI_CALCULATION_FAILURE;
    }

    if(!isfinite(weight_in_kg) || !isfinite(height_in_metres)) {
        return BMI_CALCULATION_FAILURE;
    }

    if(weight_in_kg < 0.5 || weight_in_kg > 500) {
        return BMI_CALCULATION_FAILURE;
    }

    if(height_in_metres < 1.0 || height_in_metres > 2.72) {
        return BMI_CALCULATION_FAILURE;
    }

    double squared_height = height_in_metres * height_in_metres;

    if(!isfinite(squared_height) || squared_height <= 0) {
        return BMI_CALCULATION_FAILURE;
    }

    double calculation = weight_in_kg / squared_height;

    if(!isfinite(calculation) || calculation <= 0) {
        return BMI_CALCULATION_FAILURE;
    }

    *bmi_calculation = calculation;
    return BMI_CALCULATION_SUCCESS;
}