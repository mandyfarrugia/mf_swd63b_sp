all: main.o bmi_calculator.o bmi_status.o
	gcc -Wall -Wextra main.o bmi_calculator.o bmi_status.o -o bmi_analyser

main.o: main.c
	gcc -Wall -Wextra -c main.c

bmi_calculator.o: bmi_calculator.c bmi_calculator.h
	gcc -Wall -Wextra -c bmi_calculator.c

bmi_status.o: bmi_status.c bmi_status.h
	gcc -Wall -Wextra -c bmi_status.c

run: all
	./bmi_analyser $(WEIGHT) $(HEIGHT)

clean:
	rm *.o -f bmi_analysis

rebuild: clean all