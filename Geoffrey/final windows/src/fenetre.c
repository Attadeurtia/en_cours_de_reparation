#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>
#include <SDL_image.h>

#include "admin_SDL.h"
#include "jeu.h"
#include "fenetre.h"
#include "menu.h"





void fenetre(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_Surface* icon = NULL;
    SDL_Texture* texture = NULL;

    int toutsepassebien = 1;

    


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

    /*if (toutsepassebien) {
        SDL_Rect rectangle;
        // départ / arrivé
        rectangle.x = 25;
        rectangle.y = 25;
        rectangle.w = 50;
        rectangle.h = 50;
        if (SDL_SetRenderDrawColor(renderer, 00, 80, 00, SDL_ALPHA_OPAQUE) != 0)
            SDL_ExitWithError("Impossible de changer la couleur");
        if (SDL_RenderFillRect(renderer, &rectangle) != 0)      //SDL_RenderFillRect dessine un rectangle rempli / SDL_RenderDrawRect fais juste les contours
            SDL_ExitWithError("Impossible de dessiner un rectangle");

        rectangle.x = 25;
        rectangle.y = 375;
        rectangle.w = 50;
        rectangle.h = 50;
        if (SDL_SetRenderDrawColor(renderer, 255, 00, 00, SDL_ALPHA_OPAQUE) != 0)
            SDL_ExitWithError("Impossible de changer la couleur");
        if (SDL_RenderFillRect(renderer, &rectangle) != 0)      //SDL_RenderFillRect dessine un rectangle rempli / SDL_RenderDrawRect fais juste les contours
            SDL_ExitWithError("Impossible de dessiner un rectangle");
        SDL_RenderPresent(renderer);




        //murs
        rectangle.x = 100;
        rectangle.y = 0;
        rectangle.w = 50;
        rectangle.h = 200;
        if (SDL_SetRenderDrawColor(renderer, 80, 80, 80, SDL_ALPHA_OPAQUE) != 0)
            SDL_ExitWithError("Impossible de changer la couleur");
        if (SDL_RenderFillRect(renderer, &rectangle) != 0)      //SDL_RenderFillRect dessine un rectangle rempli / SDL_RenderDrawRect fais juste les contours
            SDL_ExitWithError("Impossible de dessiner un rectangle");
        SDL_RenderPresent(renderer);

        rectangle.x = 0;
        rectangle.y = 300;
        rectangle.w = 500;
        rectangle.h = 50;
        if (SDL_SetRenderDrawColor(renderer, 80, 80, 80, SDL_ALPHA_OPAQUE) != 0)
            SDL_ExitWithError("Impossible de changer la couleur");
        if (SDL_RenderFillRect(renderer, &rectangle) != 0)      //SDL_RenderFillRect dessine un rectangle rempli / SDL_RenderDrawRect fais juste les contours
            SDL_ExitWithError("Impossible de dessiner un rectangle");
        SDL_RenderPresent(renderer);

        rectangle.x = 600;
        rectangle.y = 300;
        rectangle.w = 250;
        rectangle.h = 50;
        if (SDL_SetRenderDrawColor(renderer, 80, 80, 80, SDL_ALPHA_OPAQUE) != 0)
            SDL_ExitWithError("Impossible de changer la couleur");
        if (SDL_RenderFillRect(renderer, &rectangle) != 0)      //SDL_RenderFillRect dessine un rectangle rempli / SDL_RenderDrawRect fais juste les contours
            SDL_ExitWithError("Impossible de dessiner un rectangle");
        SDL_RenderPresent(renderer);

        rectangle.x = 450;
        rectangle.y = 100;
        rectangle.w = 50;
        rectangle.h = 200;
        if (SDL_SetRenderDrawColor(renderer, 80, 80, 80, SDL_ALPHA_OPAQUE) != 0)
            SDL_ExitWithError("Impossible de changer la couleur");
        if (SDL_RenderFillRect(renderer, &rectangle) != 0)      //SDL_RenderFillRect dessine un rectangle rempli / SDL_RenderDrawRect fais juste les contours
            SDL_ExitWithError("Impossible de dessiner un rectangle");
        SDL_RenderPresent(renderer);

        // miroirs
        if (SDL_SetRenderDrawColor(renderer, 255, 192, 203, SDL_ALPHA_OPAQUE) != 0)
            SDL_ExitWithError("Impossible de changer la couleur");
        if (SDL_RenderDrawLine(renderer, 25, 225, 75, 275) != 0)
            SDL_ExitWithError("Impossible de dessiner une ligne");
        if (SDL_RenderDrawLine(renderer, 425, 225, 375, 275) != 0)
            SDL_ExitWithError("Impossible de dessiner une ligne");
        if (SDL_RenderDrawLine(renderer, 425, 25, 375, 75) != 0)
            SDL_ExitWithError("Impossible de dessiner une ligne");
        if (SDL_RenderDrawLine(renderer, 525, 25, 575, 75) != 0)
            SDL_ExitWithError("Impossible de dessiner une ligne");
        if (SDL_RenderDrawLine(renderer, 575, 375, 525, 425) != 0)
            SDL_ExitWithError("Impossible de dessiner une ligne");
        SDL_RenderPresent(renderer);
    }*/


}

