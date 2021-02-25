/*
    //GNU/Linux et MacOS
        > gcc main.c $(sdl2-config --cflags --libs) -o prog
        > gcc *.c $(sdl2-config --cflags --libs) -o prog
    //Windows
        > gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
        > gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -mwindows

    //Flags
        SDL_RENDERER_SOFTWARE
        SDL_RENDERER_ACCELRATED
        SDL_RENDERER_PRESENTVSYNC
        SDL_RENDERER_TARGETTEXTURE


    //Création fenêtre
        window = SDL_CreateWindow("Première fenêtre SDL 2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);

        if(window == NULL)
            SDL_ExitWithError("Creation fenetre echouee");

    //Creation d'un rendu 
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

        if(renderer == NULL) 
        {
          SDL_ExitWithError("Creation rendu echouee");
        }

    //Permet d'effacer tous les rendus
        if (SDL_RenderClear(renderer) != 0)
        {
            SDL_ExitWithError("effacement rendu echoue");
        }

*/
#include <stdio.h>
#include <stdlib.h>
#include "SDL.h"

void SDL_ExitWithError(const char *message);

int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    //Lancement SDL
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        SDL_ExitWithError("Initialisation SDL");

    //Création fenêtre + rendu
    if(SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer) != 0)
        SDL_ExitWithError("Impossible de creer la denetre et le rendu");

    //if(SDL_SetWindowFullscreen(window, SDL_TRUE) < 0)
       // SDL_ExitWithError("Erreur lors du passage en mode plein ecran");
        
    /*------------------------------------------------------------*/
    if(SDL_SetRenderDrawColor(renderer, 112, 168, 237, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur");

    if(SDL_RenderDrawPoint(renderer, 400, 300) != 0)
        SDL_ExitWithError("Impossible de dessiner un point");

    if(SDL_RenderDrawLine(renderer, 50, 50, 500, 500) != 0)
        SDL_ExitWithError("Impossible de dessiner une ligne");

    SDL_Rect rectangle;
    rectangle.x = 300;
    rectangle.y = 300;
    rectangle.w = 200;
    rectangle.h = 120;

    if(SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur");

    if(SDL_RenderDrawRect(renderer, &rectangle) != 0)      //SDL_RenderFillRect dessine un rectangle rempli
        SDL_ExitWithError("Impossible de dessiner un rectangle");



    SDL_RenderPresent(renderer);
    SDL_Delay(10000);
    /*------------------------------------------------------------*/

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return EXIT_SUCCESS;
}

void SDL_ExitWithError(const char *message)
{
    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}
