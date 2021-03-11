#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include "constantes.h"

void SDL_ExitWithError(const char *message);
SDL_Rect position, positionJoueur;

int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Surface *image = NULL;
    SDL_Texture *texture = NULL;




    //Lancement SDL
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        SDL_ExitWithError("Initialisation SDL");

    //Création fenêtre + rendu
    if(SDL_CreateWindowAndRenderer(900, 700, 0, &window, &renderer) != 0)
        SDL_ExitWithError("Impossible de creer la fenetre et le rendu");

    
    /*
    if(SDL_SetRenderDrawColor(renderer, 112, 168, 237, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur");

    if(SDL_RenderDrawLine(renderer, 50, 50, 500, 500) != 0)
        SDL_ExitWithError("Impossible de dessiner une ligne");

    SDL_Rect rectangle;
    rectangle.x = 300;
    rectangle.y = 300;
    rectangle.w = 200;
    rectangle.h = 100;

    if(SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur");

    if(SDL_RenderDrawRect(renderer, &rectangle) != 0)      //SDL_RenderFillRect dessine un rectangle rempli
        SDL_ExitWithError("Impossible de dessiner un rectangle");

    SDL_RenderPresent(renderer);
*/




    SDL_Surface *robot[4]={NULL};
    SDL_Surface *robotactuel=NULL;


    robot[BAS]= image = SDL_LoadBMP("robot1.bmp");

    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);

    robotactuel=robot[BAS];

    positionJoueur.x=3;
    positionJoueur.y=3;

    position.x=positionJoueur.x*TAILLE_BLOC;
    position.y=positionJoueur.y*TAILLE_BLOC;









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

    /*------------------------------------------------------------*/

    SDL_RenderPresent(renderer);
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