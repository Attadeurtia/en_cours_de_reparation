#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>

int const longueur_fenetre = 800;
int const largeur_fenetre = 450;
  
int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
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
                        SDL_WINDOW_SHOWN /*| SDL_WINDOW_RESIZABLE*/);          //option
    if(NULL == window)
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(NULL == renderer)
    {
        fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    
    /* C’est à partir de maintenant que ça se passe. */
    if(0 != SDL_SetRenderDrawColor(renderer, 127, 127, 127, 127))
    {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    
    if(0 != SDL_RenderClear(renderer))
    {
        fprintf(stderr, "Erreur SDL_SetRenderDrawColor : %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }


    //SDL_Rect rectangle1 = {0, 200, 100, 100}; //modèle rectangles 
   
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); //couleurs rouge
    SDL_Rect rectangle;
    rectangle.x = (longueur_fenetre/2*1.3); 
    rectangle.y = (largeur_fenetre/3*2);
    rectangle.w = 100;
    rectangle.h = 50;

    SDL_Rect rectangle2;
    rectangle2.x = (longueur_fenetre/2/1.4);
    rectangle2.y = (largeur_fenetre/3*2);
    rectangle2.w = 100;
    rectangle2.h = 50;
    
    SDL_RenderFillRect(renderer, &rectangle);
    SDL_RenderFillRect(renderer, &rectangle2);

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
                    if (x>rectangle.x && x<(rectangle.x+rectangle.w) && y>rectangle.y && y<(rectangle.y+rectangle.h))
                    {
                        printf("bravo ! \n"); // detection du clique dans le carré
                    }
                    if (x>rectangle2.x && x<(rectangle2.x+rectangle2.w) && y>rectangle2.y && y<(rectangle2.y+rectangle2.h))
                    {
                        printf("bravo2 ! \n"); // detection du clique dans le carré
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

    //on quitte proprement le programme
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);  
    SDL_Quit();

    return EXIT_SUCCESS;
}