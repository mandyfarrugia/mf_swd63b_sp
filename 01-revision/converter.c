#include <stdio.h> //for input and output operations.
#include <stdlib.h> //for memory management using malloc.
#include <ctype.h> //specifically for handling characters.
#include <string.h> //for copying strings from one place to another.

#define MAX 50

//design a function that accepts a dynamic string and converts it to uppercase.
char* converter(char* s) {
	if(*s == '\0') {
		printf("Please pass in a proper string!\n");
		return NULL;
	}

	size_t word_length = strlen(s);
	char* letter_in_uppercase = (char*)malloc((word_length + 1) * sizeof(char));
	memset(letter_in_uppercase, '\0', sizeof(letter_in_uppercase));

	//hint: use toupper function which requires <ctype.h>.
	//you can alternatively XOR the 6th bit.
	for(int index = 0; index < strlen(s); index++) {
		*(letter_in_uppercase + index) = *(s + index) ^ (1 << 5);
	}

	*(letter_in_uppercase + word_length) = '\0';

	return letter_in_uppercase;
}

int main(int argc, char** argv) {
	//fopen is a function used to read files in C, returns a file pointer.
	FILE* file_ptr = fopen("words.txt", "r"); //takes two arguments - file path and file handling mode

	//if file pointer is null, exit the program gracefully instead of risking crashes when handling null pointers.
	if(!file_ptr) {
		printf("Cannot open file!\n");
		return -1;
	} else {
		int count = 0;

		//loop through text files using a while loop because you are unsure as to how many elements are present.
		char* word = malloc(MAX * sizeof(char));
		
		//omitting == 1 causes an infinite loop, a value of 1 indicates a successful read.
		while(fscanf(file_ptr, "%49s", word) == 1) {
			count++;
			printf("%s - %d\n", word, count);
		}

		char** words_list = (char**)malloc(count * sizeof(char*));

		for(int index = 0; index < count; index++) {
			*(words_list + index) = (char*)malloc(MAX * sizeof(char));
		}

		fseek(file_ptr, 0, SEEK_SET);

		int index = 0;
		while(fscanf(file_ptr, "%49s", word) == 1) {
			*(words_list + index) = (char*)realloc(*(words_list + index), strlen(word) * sizeof(char));
			char* uppercase_word = converter(word);
			strcpy(*(words_list + index), uppercase_word);
			free(uppercase_word);
			index++;
		}

		fclose(file_ptr);

		FILE* file_write_ptr = fopen("uppercase_output.txt", "w");
		for(int index = 0; index < count; index++) {
			if(index < count) {
				fprintf(file_write_ptr, "%s%s", *(words_list + index), (index < count - 1) ? "\n" : "");
			}
		}

		fclose(file_write_ptr);

		for(int index = 0; index < count; index++) {
			printf("%s\n", *(words_list + index));
		}

		for(int index = 0; index < count; index++) {
			free(*(words_list + index));
		}

		free(words_list);
	}
}