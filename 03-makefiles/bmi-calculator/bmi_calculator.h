#ifndef BMI_CALCULATOR_H_INCLUDED
#define BMI_CALCULATOR_H_INCLUDED
    typedef enum {
        BMI_CALCULATION_FAILURE = 0,
        BMI_CALCULATION_SUCCESS = 1
    } BmiCalculatorResult;

    BmiCalculatorResult calculate_bmi(double weight_in_kg, double height_in_metres, double* bmi_calculation);
#endif