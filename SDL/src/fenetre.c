#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

//gcc src/fenetre.c -o bin/fenetre -I include -L lib -lmingw32 -lSDL2main -lSDL2 -mwindows


int main(int argc, char* argv[])
{

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Surface* icon = NULL;
    SDL_Texture* texture = NULL;

    
    window = SDL_CreateWindow("[EN COURS] DE REP@RATION", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);

    if(window == NULL)
        SDL_ExitWithError("Impossible de creer la fenêtre");

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL) {
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de creer le rendu");
    }

    SDL_RenderPresent(renderer);

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

void SDL_ExitWithError(const char* message)
{
    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}