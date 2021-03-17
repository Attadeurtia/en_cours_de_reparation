#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include "admin_SDL.h"

//gcc src/matrice.c -o bin/matrice -I include -L lib -lmingw32 -lSDL2main -lSDL2 -mwindows



int main(int argc, char* argv[])
{

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Surface* icon = NULL;
    SDL_Texture* texture = NULL;
    SDL_Texture* sdltexture = NULL;
    SDL_Surface* screen = NULL;

    //Lancement SDL
    SDL_initialisation();



    window = SDL_CreateWindow("[EN COURS] DE REP@RATION", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);

    if (window == NULL)
        SDL_ExitWithError("Impossible de creer la fenêtre");

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL) {
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de creer le rendu");
    }

    

    icon = SDL_LoadBMP("src/La bAAnane.bmp");
    SDL_SetWindowIcon(window, icon);

    if (icon == NULL) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de charger l'image");
    }


    texture = SDL_CreateTextureFromSurface(renderer, icon);
    SDL_FreeSurface(icon);

    if (texture == NULL) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de creer l'icone");
    }






   /* screen = SDL_CreateRGBSurface(0, 400, 400, 32,255,255,255,255);



    if (screen == NULL) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de creer la surface");
    }
    

    sdltexture = SDL_CreateTextureFromSurface(renderer, screen);
    SDL_FreeSurface(screen);

    if (sdltexture == NULL) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de creer la texture");
    }

    */



    SDL_RenderPresent(renderer);

    SDL_bool program_launched = SDL_TRUE;

    while (program_launched) {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                program_launched = SDL_FALSE;
                break;

            default:
                break;
            }
        }
    }


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;

}
