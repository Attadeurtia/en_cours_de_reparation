#gcc src/matrice.c -o bin/matrice -I include -L lib -lmingw32 -lSDL2main -lSDL2 -mwindows

FLAGS = -I include -L lib -lmingw32 -lSDL2main -lSDL2 -mwindows

all: bin/prog

bin/prog: obj/matrice.o obj/admin_SDL.o
	gcc obj/matrice.o obj/admin_SDL.o -o bin/prog $(FLAGS)

obj/admin_SDL.o: src/admin_SDL.c src/admin_SDL.h
	gcc src/admin_SDL.c -c -o obj/admin_SDL.o $(FLAGS)

obj/matrice.o: src/matrice.c src/admin_SDL.h
	gcc src/matrice.c -c -o obj/matrice.o $(FLAGS)


clean: 
	rm obj/*.o
	rm bin/prog