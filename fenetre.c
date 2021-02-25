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

    
    window = SDL_CreateWindow("Ma première application SDL2",  //nom de la fenetre 
                        SDL_WINDOWPOS_UNDEFINED,    //position en x
                        SDL_WINDOWPOS_UNDEFINED,    //position en y
                        SDL_WINDOW_RESIZABLE,       //taille en largeur 
                        SDL_WINDOW_RESIZABLE,       //taille en hauteur
                        SDL_WINDOW_SHOWN);          //option
    SDL_Delay(3000);
    SDL_DestroyWindow(window);
    
    SDL_Quit();
 
    return EXIT_SUCCESS;
}


/*
void pause()
{
    int continuer = 1;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}
*/