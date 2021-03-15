#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>

int const longueur_fenetre = 800;
int const largeur_fenetre = 450;

int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_ * = NULL;
    int statut = EXIT_FAILURE;
    SDL_Color orange = {255, 127, 40, 255};

    if (SDL_Init(SDL_INIT_VIDEO) == -1) // Démarrage de la SDL. Si erreur :
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); // Écriture de l'erreur
        exit(EXIT_FAILURE); // On quitte le programme
    }

    //création de la fenêtre
    window = SDL_CreateWindow("Ma première application SDL2",  //nom de la fenetre 
                        SDL_WINDOWPOS_UNDEFINED,    //position en x
                        SDL_WINDOWPOS_UNDEFINED,    //position en y
                        longueur_fenetre,       //taille en largeur 
                        largeur_fenetre,       //taille en hauteur
                        SDL_WINDOW_RESIZABLE);          //option
    if(NULL == window)
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

     = SDL_Create(window, -1, SDL__PRESENTVSYNC);
    if(NULL == rende)
    {
        fprintf(stderr, "Erreur SDL_Create : %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    
    /* C’est à partir de maintenant que ça se passe. */
    if(0 != SDL_SetRenderDrawColor(, 127, 127, 127, 127))
    {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    
    if(0 != SDL_RenderClear())
    {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_Rect rectangle = {100, 100, 100, 100};
    SDL_Rect rectangle2 = {(((longueur_fenetre*2)/3)/2), (largeur_fenetre/10), 50, 50};

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(renderer, &rectangle);
    SDL_RenderFillRect(renderer, &rectangle2);
    SDL_RenderPresent(renderer);
        
    //initialisation des variables 
    SDL_Event event;    //variable qui vérifie ce qui se passe
    int fullscreen = SDL_SetWindowFullscreen(window,0);     //variable pour mettre en fullscreen
    SDL_bool program_lauched = SDL_TRUE;    //variable pour bloquer la boucle infini
    
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
                default:
                    break;
            }
        }
    }

    //on quitte proprement le programme
    SDL_Destroy();
    SDL_DestroyWindow(window);  
    SDL_Quit();

    return EXIT_SUCCESS;
}