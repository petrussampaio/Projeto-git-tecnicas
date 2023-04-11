run: Functions.c Git.c Git .h
	gcc -c Git.c -o git.o
	gcc -c Functions.c -o func.o
	gcc git.o func.o -o prog.exe
	./prog.exe

clean:
	rm git.o func.o prog.exe

all: run clean