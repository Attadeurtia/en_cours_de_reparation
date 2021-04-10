#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>
#include <SDL_image.h>

#include "admin_SDL.h"
#include "jeu.h"
#include "fenetre.h"

//gcc src/main.c -o bin/main -I include -L lib -lmingw32 -lSDL2main -lSDL2 -mwindows



int main(int argc, char* argv[])
{

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    //Lancement SDL
    SDL_initialisation();

    int height = 800;
    int width = 450;
    

    window = SDL_CreateWindow("[EN COURS] DE REP@RATION", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height, width, 0);

    if (window == NULL)
        SDL_ExitWithError("Impossible de creer la fenêtre");

    


    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL) {
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de creer le rendu");
    }

    fenetre(window, renderer);
    
    afficher_personnage(window, renderer);

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

            case SDL_KEYDOWN:
                deplacer(event);
                SDL_RenderPresent(renderer);
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
