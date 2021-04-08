#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>
#include <SDL_image.h>

#include "admin_SDL.h"
#include "jeu.h"
#include "fenetre.h"

void afficher_personnage(SDL_Window* window, SDL_Renderer* renderer) {

    SDL_Texture* pers_text = NULL;
    SDL_Surface* pers_img = NULL;


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
        SDL_ExitWithError("Impossible de creer le personnage");
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
}