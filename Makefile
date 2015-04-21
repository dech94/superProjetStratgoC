joueur: joueur.o
	gcc -g -std=c99 joueur.o -o joueur
arbitre: arbitre.o
	gcc -g -std=c99 arbitre.o -o arbitre
joueur.o : joueur.c joueur.h
	gcc -c -Wall -g joueur.h joueur.c -std=c99
arbitre.o : arbitre.c arbitre.h
	gcc -c -Wall -g arbitre.h arbitre.c -std=c99
clean:
	rm -f *.o
