#include <stdio.h>

char* generate_status_from_bmi(double bmi_result) {
    if(bmi_result < 18.5) {
        return "Underweight";
    } else if(bmi_result >= 18.5 && bmi_result <= 24.9) {
        return "Normal";
    } else if(bmi_result >= 25 && bmi_result <= 29.9) {
        return "Overweight";
    } else if(bmi_result >= 30) {
        return "Obese";
    }

    return NULL;
}