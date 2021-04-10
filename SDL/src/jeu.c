#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>
#include <SDL_image.h>

#include "admin_SDL.h"
#include "jeu.h"
#include "fenetre.h"

enum{HAUT, BAS, GAUCHE, DROITE};
enum{VIDE, MUR, MORTY};
SDL_Rect rectangle_pers;

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

    

    if (SDL_QueryTexture(pers_text, NULL, NULL, &rectangle_pers.w, &rectangle_pers.h) != 0)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de creer le rectangle");
    }

    rectangle_pers.x = 0;
    rectangle_pers.y = 0;

    if (SDL_RenderCopy(renderer, pers_text, NULL, &rectangle_pers) != 0)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible d'afficher la texture");
    }
}



void deplacer(SDL_Event event) {

    switch (event.key.keysym.sym) {

        case SDLK_LEFT:
            rectangle_pers.x -= 10;
            break;

        case SDLK_RIGHT:
            rectangle_pers.x += 10;
            break;

        case SDLK_UP:
            rectangle_pers.y -= 10;
            break;

        case SDLK_DOWN:
            rectangle_pers.y += 10;
             break;
    }
}