#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include "constantes.h"

//gcc src/test.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -mwindows

void SDL_ExitWithError(const char *message);
SDL_Rect position, positionJoueur;

int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Surface *image = NULL;
    SDL_Texture *texture = NULL;

int toutsepassebien=1;


    //Lancement SDL
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        SDL_ExitWithError("Initialisation SDL");

    //Création fenêtre + rendu
    if(SDL_CreateWindowAndRenderer(800, 450, 0, &window, &renderer) != 0)
        SDL_ExitWithError("Impossible de creer la fenetre et le rendu");

    // niveau 1
    if(toutsepassebien){
    SDL_Rect rectangle;
    // départ / arrivé
    rectangle.x = 25;
    rectangle.y = 25;
    rectangle.w = 50;
    rectangle.h = 50;
    if(SDL_SetRenderDrawColor(renderer, 00, 80, 00, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur");
    if(SDL_RenderFillRect(renderer, &rectangle) != 0)      //SDL_RenderFillRect dessine un rectangle rempli / SDL_RenderDrawRect fais juste les contours
        SDL_ExitWithError("Impossible de dessiner un rectangle");

    rectangle.x = 25;
    rectangle.y = 375;
    rectangle.w = 50;
    rectangle.h = 50;
    if(SDL_SetRenderDrawColor(renderer, 255, 00, 00, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur");
    if(SDL_RenderFillRect(renderer, &rectangle) != 0)      //SDL_RenderFillRect dessine un rectangle rempli / SDL_RenderDrawRect fais juste les contours
        SDL_ExitWithError("Impossible de dessiner un rectangle");
SDL_RenderPresent(renderer);




    //murs
    rectangle.x = 100;
    rectangle.y = 0;
    rectangle.w = 50;
    rectangle.h = 200;
    if(SDL_SetRenderDrawColor(renderer, 80, 80, 80, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur");
    if(SDL_RenderFillRect(renderer, &rectangle) != 0)      //SDL_RenderFillRect dessine un rectangle rempli / SDL_RenderDrawRect fais juste les contours
        SDL_ExitWithError("Impossible de dessiner un rectangle");
SDL_RenderPresent(renderer);

    rectangle.x = 0;
    rectangle.y = 300;
    rectangle.w = 500;
    rectangle.h = 50;
    if(SDL_SetRenderDrawColor(renderer, 80, 80, 80, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur");
    if(SDL_RenderFillRect(renderer, &rectangle) != 0)      //SDL_RenderFillRect dessine un rectangle rempli / SDL_RenderDrawRect fais juste les contours
        SDL_ExitWithError("Impossible de dessiner un rectangle");
SDL_RenderPresent(renderer);

    rectangle.x = 600;
    rectangle.y = 300;
    rectangle.w = 250;
    rectangle.h = 50;
    if(SDL_SetRenderDrawColor(renderer, 80, 80, 80, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur");
    if(SDL_RenderFillRect(renderer, &rectangle) != 0)      //SDL_RenderFillRect dessine un rectangle rempli / SDL_RenderDrawRect fais juste les contours
        SDL_ExitWithError("Impossible de dessiner un rectangle");
SDL_RenderPresent(renderer);

    rectangle.x = 450;
    rectangle.y = 100;
    rectangle.w = 50;
    rectangle.h = 200;
    if(SDL_SetRenderDrawColor(renderer, 80, 80, 80, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur");
    if(SDL_RenderFillRect(renderer, &rectangle) != 0)      //SDL_RenderFillRect dessine un rectangle rempli / SDL_RenderDrawRect fais juste les contours
        SDL_ExitWithError("Impossible de dessiner un rectangle");
SDL_RenderPresent(renderer);

// miroirs
    if(SDL_SetRenderDrawColor(renderer, 255, 192, 203, SDL_ALPHA_OPAQUE) != 0)
        SDL_ExitWithError("Impossible de changer la couleur");
    if(SDL_RenderDrawLine(renderer, 25, 225, 75, 275) != 0)
        SDL_ExitWithError("Impossible de dessiner une ligne");
    if(SDL_RenderDrawLine(renderer, 425, 225, 375, 275) != 0)
        SDL_ExitWithError("Impossible de dessiner une ligne");
    if(SDL_RenderDrawLine(renderer, 425, 25, 375, 75) != 0)
        SDL_ExitWithError("Impossible de dessiner une ligne");
    if(SDL_RenderDrawLine(renderer, 525, 25, 575, 75) != 0)
        SDL_ExitWithError("Impossible de dessiner une ligne");
    if(SDL_RenderDrawLine(renderer, 575, 375, 525, 425) != 0)
        SDL_ExitWithError("Impossible de dessiner une ligne");
    SDL_RenderPresent(renderer);
    }
    



    




/*
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


*/






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