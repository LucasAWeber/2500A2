noStringsAttached: main.o weberLucasA2.o
	gcc -Wall main.o weberLucasA2.o -o bin/noStringsAttached

main.o: src/main.c include/weberLucasA2.h
	gcc -Wall -std=c99 -c src/main.c

weberLucasA2.o: src/weberLucasA2.c include/weberLucasA2.h
	gcc -Wall -std=c99 -c src/weberLucasA2.c

clean:
	rm *.o bin/noStringsAttached