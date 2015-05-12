arbitre: arbitre.o
	gcc -g -std=c99 arbitre.o -o arbitre
arbitre.o : arbitre.c arbitre.h 
	gcc -c -Wall -g arbitre.h arbitre.c -std=c99
clean:
	rm -f *.o
