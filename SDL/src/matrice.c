#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>
#include <SDL_image.h>

#include "admin_SDL.h"
#include "jeu.h"
#include "fenetre.h"

//gcc src/matrice.c -o bin/matrice -I include -L lib -lmingw32 -lSDL2main -lSDL2 -mwindows



int main(int argc, char* argv[])
{

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    //Lancement SDL
    SDL_initialisation();

    fenetre(window, renderer);

    afficher_personnage(window, renderer);

    SDL_RenderPresent(renderer);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;

}
