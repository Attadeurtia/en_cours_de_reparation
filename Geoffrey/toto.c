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
    //SDL_Color orange = {255, 127, 40, 255};

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
    if(0 != SDL_SetRenderDrawColor(renderer, 127, 127, 127, 127)) //couleurs grise
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

    // Définition des deux Point 
    SDL_Point pointA;
    pointA.x = 300;
    pointA.y = 200;

    SDL_Point pointB;
    pointB.x = 350;
    pointB.y = 250;

    //SDL_RenderClear(renderer);  

    //SDL_RenderDrawLine(renderer, pointA.x, pointA.y, pointB.x, pointB.y);

    SDL_RenderFillRect(renderer, &rectangle);
    SDL_RenderFillRect(renderer, &rectangle2);

    SDL_RenderDrawLine(renderer, pointA.x, pointA.y, pointB.x, pointB.y);

//    SDL_RenderPresent(renderer);

    
    //initialisation des variables 
    SDL_Event event;    //variable qui vérifie ce qui se passe
    int fullscreen = SDL_SetWindowFullscreen(window,0);     //variable pour mettre en fullscreen
    SDL_bool program_lauched = SDL_TRUE;    //variable pour bloquer la boucle infini
    int x=0, y=0;
    char clavier;
    //tant que l'on ne change pas "program_lauched" le programme est executer, sinon, on le ferme proprement
    
    void tata(){
        
            SDL_Surface* pSprite = SDL_LoadBMP("./source/Abstract8789_rectangle.bmp");
            if ( pSprite )
            {
                SDL_Texture* pTexture = SDL_CreateTextureFromSurface(renderer,pSprite); // Préparation du sprite
                if ( pTexture )
                {
                    SDL_Rect dest = { 640/2 - pSprite->w/2,480/2 - pSprite->h/2, pSprite->w, pSprite->h};
                    SDL_RenderCopy(renderer,pTexture,NULL,&dest); // Copie du sprite grâce au SDL_Renderer
                    
                    SDL_RenderPresent(renderer); // Affichage
                    //SDL_Delay(3000); /* Attendre trois secondes, que l'utilisateur voit la fenêtre */
                    
                    SDL_DestroyTexture(pTexture); // Libération de la mémoire associée à la texture
                    SDL_RenderClear(renderer);
                }
                else
                {
                    fprintf(stdout,"Échec de création de la texture (%s)\n",SDL_GetError());
                }
                
                SDL_FreeSurface(pSprite); // Libération de la ressource occupée par le sprite
            }
            else
            {
                fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
            }
            
            SDL_DestroyRenderer(renderer); // Libération de la mémoire du SDL_Renderer
        }
        
    
    
    
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
                        program_lauched = SDL_FALSE;
                    }
                    if (x>rectangle2.x && x<(rectangle2.x+rectangle2.w) && y>rectangle2.y && y<(rectangle2.y+rectangle2.h))
                    {
                        printf("bravo ! \n"); // detection du clique dans le carré
                    }
                    if (event.button.button == SDL_BUTTON_LEFT)  {
                        printf("clique gauche ! \n");
                    }else if (event.button.button == SDL_BUTTON_MIDDLE){
                        printf("clique molette ! \n");
                    }else
                        printf("clique droit ! \n");               
                    break;
                case SDL_KEYDOWN: // Relâchement d'un clique
                    clavier = event.key.keysym.sym;
                    SDL_Log("+key");
                    printf("la touche %s est enclanché \n",SDL_GetKeyName(event.key.keysym.sym));
                    
                    //if(event.key.keysym.scancode != SDL_GetScancodeFromKey(event.key.keysym.sym))
                    printf("Physical %s key \n",
                    SDL_GetScancodeName(event.key.keysym.scancode));
                    //SDL_GetKeyName(event.key.keysym.sym)

                    if (event.key.keysym.scancode == SDL_SCANCODE_W){// Regarde si le keycode w est enfoncé (la touche W sous un azerty)
                        SDL_Log("Keycode W"); // Affiche un message
                        pointA.x =+ 10;
                        pointA.y =+ 10;

                        pointB.x =+10;
                        pointB.y =+ 10;
                        tata();
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

