#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include "admin_SDL.h"
#include "jeu.h"

//gcc src/matrice.c -o bin/matrice -I include -L lib -lmingw32 -lSDL2main -lSDL2 -mwindows



int main(int argc, char* argv[])
{

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Surface* icon = NULL;
    SDL_Texture* texture = NULL;
    SDL_Texture* pers_text = NULL;
    SDL_Surface* pers_img = NULL;

    int height = 800;
    int width = 450;

    //Lancement SDL
    SDL_initialisation();



    window = SDL_CreateWindow("[EN COURS] DE REP@RATION", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height, width, 0);

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

    
    

    

    SDL_Rect rectangle;
    rectangle.x = 0;
    rectangle.y = 0;
    rectangle.w = 800;
    rectangle.h = 450;


    if (SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur");

    if (SDL_RenderFillRect(renderer, &rectangle) != 0)      
        SDL_ExitWithError("Impossible de dessiner un rectangle");


    pers_img = IMG_Load("src/morty_robot_png.png");

    if (pers_img == NULL) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de charger l'image");
    }


    pers_text = SDL_CreateTextureFromSurface(renderer, pers_img);
    SDL_FreeSurface(pers_img);

    if (pers_text == NULL) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de creer l'icone");
    }

    SDL_Rect rectangle_pers;

    if (SDL_QueryTexture(pers_text, NULL, NULL, &rectangle_pers.w, &rectangle_pers.h) != 0)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de creer le rectangle");
    }

    rectangle_pers.x = (800 - rectangle_pers.w) / 2;
    rectangle_pers.y = (450 - rectangle_pers.w) / 2;

    if (SDL_RenderCopy(renderer, pers_text, NULL, &rectangle_pers) != 0)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible d'afficher la texture");
    }

    



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
