#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "value_converter.h"

ValueConversionResult convert_str_to_double(const char* argument, double* dbl_result) {
    if(!argument || !dbl_result) {
        return 0;
    }

    char* end_pointer = NULL; //Indicates where strtod stops parsing.

    errno = 0;
    double conversion_result = strtod(argument, &end_pointer);

    //If the end_pointer and argument both point to the same address, then conversion was unsuccessful.
    if(end_pointer == argument) {
        return VALUE_CONVERSION_FAILURE;
    }

    //If input is successful, then the value referenced by the pointer should be a null terminator.
    if(*end_pointer != '\0') {
        return VALUE_CONVERSION_FAILURE;
    }

    if(errno == ERANGE || !isfinite(conversion_result)) {
        return VALUE_CONVERSION_FAILURE;
    }

    *dbl_result = conversion_result;

    return VALUE_CONVERSION_SUCCESS;
}