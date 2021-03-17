#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
  
int main(int argc, char *argv[])
{

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) == -1) // Démarrage de la SDL. Si erreur :
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); // Écriture de l'erreur
        exit(EXIT_FAILURE); // On quitte le programme
    }

    //création de la fenêtre
    window = SDL_CreateWindow("Ma première application SDL2",  //nom de la fenetre 
                        SDL_WINDOWPOS_UNDEFINED,    //position en x
                        SDL_WINDOWPOS_UNDEFINED,    //position en y
                        800,       //taille en largeur 
                        600,       //taille en hauteur
                        SDL_WINDOW_SHOWN);          //option


    //initialisation des variables 
    
    int fullscreen = SDL_SetWindowFullscreen(window,0);     //variable pour mettre en fullscreen
    SDL_bool program_lauched = SDL_TRUE;    //variable pour bloquer la boucle infini
    
    //tant que l'on ne change pas "program_lauched" le programme est executer, sinon, on le ferme proprement
    while (program_lauched)
    {
        SDL_Event event;    //variable qui vérifie ce qui se passe
        while (SDL_PollEvent(&event)) // Récupération des actions de l'utilisateur
        {
            switch(event.type)
            {
                case SDL_QUIT: // Clic sur la croix
                    program_lauched = SDL_FALSE; //changement de "program_lauched"
                    break;
                case SDL_MOUSEBUTTONDOWN: // Relâchement d'un clique 
                    printf("Clic en %dx /%dy\n", event.button.x, event.button.y);
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

