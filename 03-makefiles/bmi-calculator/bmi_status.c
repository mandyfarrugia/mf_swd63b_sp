#include <stddef.h>
#include <math.h>

const char* generate_status_from_bmi(double bmi_result) {
    if(!isfinite(bmi_result) || bmi_result <= 0) {
        return NULL;
    }
    if(bmi_result < 18.5) {
        return "Underweight";
    } else if(bmi_result < 25.0) {
        return "Normal";
    } else if(bmi_result < 30.0) {
        return "Overweight";
    } else {
        return "Obese";
    }
}