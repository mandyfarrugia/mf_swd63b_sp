#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

struct Person {
    char* name;
    char* surname;
    int age;
    char* nationality;
} typedef Person;

int main(int argc, char** argv) {
    Person* person_1 = (Person*)malloc(1 * sizeof(Person));
    (*person_1).name = (char*)malloc(MAX * sizeof(char));
    (*person_1).surname = (char*)malloc(MAX * sizeof(char));
    (*person_1).nationality = (char*)malloc(MAX * sizeof(char));

    strcpy((*person_1).name, "Mandy");
    strcpy((*person_1).surname, "Farrugia");
    (*person_1).age = 24;
    strcpy((*person_1).nationality, "Maltese");

    printf("%s %s, %d, %s\n", (*person_1).name, (*person_1).surname, (*person_1).age, (*person_1).nationality);

    return 0;
}