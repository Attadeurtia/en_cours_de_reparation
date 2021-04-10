#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>
#include <SDL_image.h>

#include "admin_SDL.h"
#include "jeu.h"
#include "fenetre.h"





void fenetre(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_Surface* icon = NULL;
    SDL_Texture* texture = NULL;

    


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


}

