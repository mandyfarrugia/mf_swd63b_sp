double calculate_bmi(double weight_in_kg, double height_in_metres) {
    if(weight_in_kg <= 0 || height_in_metres <= 0)
        return 0;
    if(weight_in_kg > __DBL_MAX__ || height_in_metres > __DBL_MAX__)
        return 0;

    return weight_in_kg / (height_in_metres * height_in_metres);
}