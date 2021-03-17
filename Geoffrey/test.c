#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>

int const longueur_fenetre = 800;
int const largeur_fenetre = 450;


  
int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) == -1) // Démarrage de la SDL. Si erreur :
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); // Écriture de l'erreur
        exit(EXIT_FAILURE); // On quitte le programme
    }

    if (TTF_Init() < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
        return EXIT_FAILURE;
    }

    //création de la fenêtre
    window = SDL_CreateWindow("Ma première application SDL2",  //nom de la fenetre 
                        SDL_WINDOWPOS_UNDEFINED,    //position en x
                        SDL_WINDOWPOS_UNDEFINED,    //position en y
                        longueur_fenetre,       //taille en largeur 
                        largeur_fenetre,       //taille en hauteur
                        SDL_WINDOW_SHOWN);          //option
    if(NULL == window)
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
  
  
  //Eccrire ton code 
  
    TTF_Font* font = TTF_OpenFont("Miglia.ttf", 18); // Crée un police avec la police "ariali.ttf" et de taille 18 pixels

    if (font == 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());

    }
    SDL_Color black = {0,255,0};

    SDL_Surface* text = TTF_RenderText_Blended(font, "Hello, World", black);// Crée un surface qui contient le texte

    if (text == 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, text); // Crée la texture qu'on va afficher a partir de la surface

    if (texture == 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
    }

    SDL_Rect position;

    SDL_QueryTexture(texture, 0, 0, &position.w, &position.h); // Récupere la dimension de la texture

    // Centre la texture sur l'écran
    position.x = longueur_fenetre / 2 - position.w / 2;
    position.y = largeur_fenetre / 2 - position.h / 2;


    // Libération des resource de la police et de la surface qui contient le texte
    SDL_FreeSurface(text);
    TTF_CloseFont(font);
  
  
  
  
  

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
                default:
                    break;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 
        SDL_RenderClear(renderer);  

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderCopy(renderer, texture, 0, &position);

        SDL_RenderPresent(renderer); 
    }

    //on quitte proprement le programme
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);  
    SDL_DestroyTexture(texture);
    TTF_Quit();
    SDL_Quit();

    return EXIT_SUCCESS;
}
