all: main.o word_analyser.o report_generator.o
	@gcc main.o word_analyser.o report_generator.o -o analyser
	
main.o: main.c
	@gcc -Wall -Wextra -c main.c

word_analyser.o: word_analyser.c word_analyser.h
	@gcc -Wall -Wextra -c word_analyser.c

report_generator.o: report_generator.c report_generator.h
	@gcc -Wall -Wextra -c report_generator.c

run: all
	@./analyser

clean:
	@rm *.o -f report.txt analyser

rebuild: clean all