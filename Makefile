ex02: main.o utils.o encode.o
	gcc main.o utils.o encode.o -o ex02
main.o: main.c
	gcc -Wall -Wextra -Wpedantic -std=c11 -c main.c -o main.o
utils.o: utils.c
	gcc -Wall -Wextra -Wpedantic -std=c11 -c utils.c -o utils.o
encode.o: encode.c
	gcc -Wall -Wextra -Wpedantic -std=c11 -c encode.c -o encode.o
clear:
	rm ex02 *.o
