#gcc src/matrice.c -o bin/matrice -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -mwindows

FLAGS = -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -mwindows

all: bin/prog

bin/prog: obj/matrice.o obj/admin_SDL.o obj/jeu.o
	gcc obj/matrice.o obj/admin_SDL.o -o bin/prog $(FLAGS)

obj/admin_SDL.o: src/admin_SDL.c src/admin_SDL.h src/jeu.h
	gcc src/admin_SDL.c -c -o obj/admin_SDL.o $(FLAGS)

obj/matrice.o: src/matrice.c src/admin_SDL.h src/jeu.h
	gcc src/matrice.c -c -o obj/matrice.o $(FLAGS)

obj/jeu.o: src/jeu.c src/admin_SDL.h src/jeu.h
	gcc src/jeu.c -c -o obj/jeu.o $(FLAGS)


clean: 
	rm obj/*.o
	rm bin/prog