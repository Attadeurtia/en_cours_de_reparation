#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>
#include <SDL_image.h>

#include "admin_SDL.h"
#include "jeu.h"
#include "fenetre.h"
#include "menu.h"

void menu(SDL_Window* window, SDL_Renderer* renderer){

    int const longueur_fenetre = 800;
    int const largeur_fenetre = 450;

    SDL_Surface* bouton_restart = NULL;
    SDL_Texture* bouton_restart_texture = NULL;

    SDL_Texture* bouton_quit2 = NULL;
    SDL_Surface* bouton_quit = NULL;

    SDL_Rect rectangle_pers;
    rectangle_pers.x = 1;
    rectangle_pers.y = 1;


    SDL_Surface* fond = SDL_LoadBMP("./image/fond.bmp");
    SDL_Texture* fond_Texture = SDL_CreateTextureFromSurface(renderer,fond);

    SDL_Rect fenetre_surface = { 0,0,longueur_fenetre , largeur_fenetre };

    SDL_RenderCopy(renderer,fond_Texture,NULL,&fenetre_surface); // Copie du sprite grâce au SDL_Renderer
    

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); //couleurs rouge

    // initialisation des rectangle
    
    SDL_Rect rectangle_restart;
    rectangle_restart.x = (longueur_fenetre/2/1.5); 
    rectangle_restart.y = (largeur_fenetre/3*2);
    rectangle_restart.w = 100;
    rectangle_restart.h = 50;

    SDL_Rect rectangle_quit;
    rectangle_quit.x = (longueur_fenetre/2*1);
    rectangle_quit.y = (largeur_fenetre/3*2);
    rectangle_quit.w = 100;
    rectangle_quit.h = 50;
    
    SDL_RenderFillRect(renderer, &rectangle_restart);
    SDL_RenderFillRect(renderer, &rectangle_quit);


    bouton_restart = SDL_LoadBMP("./image/restart.bmp"); //chargement de l'image du bouton restart

    if (bouton_restart == NULL) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de charger l'image");
    }

    bouton_restart_texture = SDL_CreateTextureFromSurface(renderer, bouton_restart);
    SDL_FreeSurface(bouton_restart);

    if (bouton_restart_texture == NULL) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de creer le bonton quitter");
    }

    if (SDL_RenderCopy(renderer, bouton_restart_texture, NULL, &rectangle_restart) != 0)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible d'afficher la texture");
    }

    bouton_quit = SDL_LoadBMP("./image/quit.bmp");       //chargement de l'image du bouton quitter       

    if (bouton_quit == NULL) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de charger l'image");
    }

    bouton_quit2 = SDL_CreateTextureFromSurface(renderer, bouton_quit);
    SDL_FreeSurface(bouton_quit);

    if (bouton_quit == NULL) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de creer le bonton quitter");
    }

    if (SDL_RenderCopy(renderer, bouton_quit2, NULL, &rectangle_quit) != 0)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible d'afficher la texture");
    }


//////////////////////////////////////////////
/*
    fenetre(window, renderer);
    
    afficher_personnage(window, renderer, rectangle_pers);
*/

    SDL_RenderPresent(renderer);


    //initialisation des variables 
    SDL_Event event;    //variable qui vérifie ce qui se passe
    int fullscreen = SDL_SetWindowFullscreen(window,0);     //variable pour mettre en fullscreen
    SDL_bool program_lauched = SDL_TRUE;    //variable pour bloquer la boucle infini
    int x=0, y=0;

    //tant que l'on ne change pas "program_lauched" le programme est executer, sinon, on le ferme proprement
    while (program_lauched)
    {
        while (SDL_PollEvent(&event)) // Récupération des actions de l'utilisateur
        {
            switch(event.type)
            {
                case SDL_QUIT: // Clic sur la croix
                    program_lauched = SDL_FALSE; //changement de "program_lauched"
                    break;
                case SDL_KEYUP: // Relâchement d'une touche
                    if (event.key.keysym.sym == SDLK_f ) // Touche f
                    {
                        // Alterne du mode plein écran au mode fenêtré
                        if ( fullscreen == 0 )
                        {
                            fullscreen = 1;
                            SDL_SetWindowFullscreen(window,SDL_WINDOW_FULLSCREEN);
                        }
                        else if ( fullscreen == 1 )
                        {
                            fullscreen = 0;
                            SDL_SetWindowFullscreen(window,0);
                        }
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN: // Relâchement d'un clique 
                    x=event.button.x;  //récupération de la position de la souris
                    y=event.button.y;
                    printf("Clic en %d /%d\n", x, y); //affichage des coordonnées souris
                    if (x>rectangle_restart.x && x<(rectangle_restart.x+rectangle_restart.w) && y>rectangle_restart.y && y<(rectangle_restart.y+rectangle_restart.h))
                    {
                        printf("bravo ! \n"); // detection du clique dans le carré
                        //////

                        while (SDL_PollEvent(&event))
                                {
                                    switch (event.type)
                                    {
                                    case SDL_KEYDOWN:
                                        deplacer(event, &rectangle_pers);
                                        fenetre(window, renderer);
                                        afficher_personnage(window, renderer, rectangle_pers);
                                        SDL_RenderPresent(renderer);
                                        break;
                                    }
                                }

                        //////
                    }
                    if (x>rectangle_quit.x && x<(rectangle_quit.x+rectangle_quit.w) && y>rectangle_quit.y && y<(rectangle_quit.y+rectangle_quit.h))
                    {
                        printf("bravo2 ! \n"); // detection du clique dans le carré
                        program_lauched = SDL_FALSE;
                    }
                    if (event.button.button == SDL_BUTTON_LEFT)  {
                        printf("clique gauche ! \n");
                    }else if (event.button.button == SDL_BUTTON_MIDDLE){
                        printf("clique molette ! \n");
                    }else
                        printf("clique droit ! \n");               
                    break;
                default:
                    break;
            }
        }
    }
}
