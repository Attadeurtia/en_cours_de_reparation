#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>

void SDL_ExitWithError(const char *message)
{
    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}

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
      /*window =*/ SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer);          //option

      //if(SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer) != 0)
        //SDL_ExitWithError("Impossible de creer la denetre et le rendu");

      SDL_Rect rectangle;
      rectangle.x = 300;
      rectangle.y = 300;
      rectangle.w = 200;
      rectangle.h = 120;

      if(SDL_SetRenderDrawColor(renderer, 255, 255, 12, SDL_ALPHA_OPAQUE) != 0)
            SDL_ExitWithError("Impossible de changer la couleur");

      if(SDL_RenderDrawRect(renderer, &rectangle) != 0)      //SDL_RenderFillRect dessine un rectangle rempli
            SDL_ExitWithError("Impossible de dessiner un rectangle");



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
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);  
    SDL_Quit();

    return EXIT_SUCCESS;
}