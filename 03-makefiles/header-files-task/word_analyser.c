#include <stdio.h>
#include <ctype.h>

int isVowel(int ch)
{
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' ||
           ch == 'o' || ch == 'u';
}

int countCharacters(FILE *file)
{
    int count = 0;
    rewind(file);
    while (fgetc(file) != EOF) {
        count++;
    }
    return count;
}

int countWords(FILE *file)
{
    int ch, count = 0, insideWord = 0;
    rewind(file);
    while ((ch = fgetc(file)) != EOF) {
        if (isspace(ch)) {
            insideWord = 0;
        } else if (!insideWord) {
            count++;
            insideWord = 1;
        }
    }
    return count;
}

int countLines(FILE *file)
{
    int ch, count = 0, lastCharacter = EOF;
    rewind(file);
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            count++;
        }
        lastCharacter = ch;
    }
    /* Count a final line that has no newline. */
    if (lastCharacter != EOF && lastCharacter != '\n') {
        count++;
    }
    return count;
}

int countVowels(FILE *file)
{
    int ch, count = 0;
    rewind(file);
    while ((ch = fgetc(file)) != EOF) {
        if (isVowel(ch)) {
            count++;
        }
    }
    return count;
}