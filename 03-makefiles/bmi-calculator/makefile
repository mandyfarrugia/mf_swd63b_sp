all: bmi_analyser

bmi_analyser: main.o bmi_calculator.o bmi_status.o value_converter.o
	@gcc -Wall -Wextra main.o bmi_calculator.o bmi_status.o value_converter.o -o bmi_analyser

main.o: main.c
	@gcc -Wall -Wextra -c main.c -o main.o

bmi_calculator.o: bmi_calculator.c bmi_calculator.h
	@gcc -Wall -Wextra -c bmi_calculator.c -o bmi_calculator.o

bmi_status.o: bmi_status.c bmi_status.h
	@gcc -Wall -Wextra -c bmi_status.c -o bmi_status.o

value_converter.o: value_converter.c value_converter.h
	@gcc -Wall -Wextra -c value_converter.c -o value_converter.o

run: bmi_analyser
	@./bmi_analyser $(WEIGHT) $(HEIGHT) $(OUTPUT_FILE)

clean:
	@rm *.o -f bmi_analyser

rebuild: clean all