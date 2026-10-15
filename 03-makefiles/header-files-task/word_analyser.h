/* This is called a header file guard. This technique makes sure that even though you have multiple includes in your code from different files,
 * the header file will be included only once to avoid multiple definitions of types/functions. */

#ifndef WORD_ANALYSER_H_INCLUDED
#define WORD_ANALYSER_H_INCLUDED
    struct person {
        int personId;
    };

    int isVowel(int ch);
    int countCharacters(FILE *file);
    int countWords(FILE *file);
    int countLines(FILE *file);
    int countVowels(FILE *file);
#endif