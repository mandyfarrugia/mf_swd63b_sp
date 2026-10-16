#ifndef VALUE_CONVERTER_H_INCLUDED
#define VALUE_CONVERTER_H_INCLUDED
    typedef enum {
        VALUE_CONVERSION_FAILURE = 0,
        VALUE_CONVERSION_SUCCESS = 1
    } ValueConversionResult;

    ValueConversionResult convert_str_to_double(const char* argument, double* dbl_result);
#endif