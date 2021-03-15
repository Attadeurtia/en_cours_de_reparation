//vérifie que la SDL fonctionne correctement et donne la version installé 
#include <stdio.h>
#include <SDL.h>

int main(int argc, char **argv){
	SDL_version nb;
	SDL_VERSION(&nb);
	printf("vous avez la SDL %d.%d.%d !\n", nb.major, nb.minor, nb.patch);
	return 0;
}
