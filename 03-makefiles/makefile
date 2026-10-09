#Simple makefile to build, clean, and run our main.c program.

#To call each target, in terminal, write make all, or make run, or make clean.
#But if you call make on its own, it will run the first target which traditionally is the build/all target.

#Ideally, the first target is called all as the most common task is to build all the projects at once.
all: main

#Here, main will be built only if the executable file is older than the source code.
#The make tool uses the timestamp of the two files to decide if execution of the GCC command is necessary or not.
#main target depends on main.c, this prevents unnecessarily building for nothing (timestamps are compared)
#You can use @echo to print messages on the console. Place @ in front of the GCC command to turn echo off for the command.
main: main.c
	@echo Building...
	@gcc -Wall main.c -o main
	@echo Done...

#run target depends on main target.
run: main
	./main

clean:
	@echo Deleting files...
	@rm -f main
	@echo Done...

#Non-GCC commands must be in the same line as the target.
rebuild: clean all