#include <stdio.h>

#include "report_generator.h"
#include "word_analyser.h"

int main(void)
{
    FILE *input = fopen("input.txt", "r");

    if (input == NULL) {
        perror("Cannot open input.txt");
        return 1;
    }

    int characters = countCharacters(input);
    int words = countWords(input);
    int lines = countLines(input);
    int vowels = countVowels(input);
    fclose(input);

    writeReport(stdout, characters, words, lines, vowels);

    FILE *output = fopen("report.txt", "w");
    if (output == NULL) {
        perror("Cannot create report.txt");
        return 1;
    }

    writeReport(output, characters, words, lines, vowels);
    fclose(output);
    printf("\nReport saved to report.txt\n");

    return 0;
}