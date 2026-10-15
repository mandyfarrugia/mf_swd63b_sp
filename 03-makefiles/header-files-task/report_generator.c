#include <stdio.h>
//#include "report_generator.h"

void writeReport(FILE *output, int characters, int words, int lines, int vowels)
{
    fprintf(output, "TEXT FILE REPORT\n");
    fprintf(output, "Characters: %d\n", characters);
    fprintf(output, "Words:      %d\n", words);
    fprintf(output, "Lines:      %d\n", lines);
    fprintf(output, "Vowels:     %d\n", vowels);
}