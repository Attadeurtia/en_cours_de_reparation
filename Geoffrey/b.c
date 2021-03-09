// Inclure la bibliothèque SDL
#include <SDL2/SDL.h>   


// Inclusion des bibliothèque standard C++ 

// Définition des constante 
template<typename T>
constexpr T WIDTHSCREEN{ 800 };

template<typename T>
constexpr T HEIGHTSCREEN{ 600 };

template<typename T>
constexpr T TOTAL_POINTS{ 5000 };

// Prototype
void draw_rectangle_fill(SDL_Renderer* renderer, const SDL_Rect& rectangle, const SDL_Color& color);
void draw_rectangle_not_fill(SDL_Renderer* renderer, const SDL_Rect& rectangle, const SDL_Color& color);

int main(int argc, char* argv[])
{
    // Chargement du module vidéo de la SDL 
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    // Ressource : Fenêtre et rendu 
    SDL_Window* pWindow{ nullptr };
    SDL_Renderer* pRenderer{ nullptr };

    // Création d'une fenêtre, en 800x600, et visible
    if (SDL_CreateWindowAndRenderer(WIDTHSCREEN<unsigned int>, HEIGHTSCREEN<unsigned int>, SDL_WINDOW_SHOWN, &pWindow, &pRenderer) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }


    SDL_Event events;
    bool isOpen{ true };


    SDL_Rect rectangle1{20, 20, 100, 50};


    // Game loop
    while (isOpen)
    {
        // Input 
        while (SDL_PollEvent(&events))
        {
            switch (events.type)
            {
            case SDL_QUIT:
                isOpen = false;
                break;
            }
        }


        // Rendering
        SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255); // Choisir la couleur noir  
        SDL_RenderClear(pRenderer); // Colorier en noir toutes la fenêtre 

        draw_rectangle_not_fill(pRenderer, rectangle1, SDL_Color{ 0, 0, 255, 255 });

        SDL_RenderPresent(pRenderer); // Mise à jour de la fenêtre 
    }

    // Libération des ressource en mémoire
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    SDL_Quit();

    return EXIT_SUCCESS;
}

// Implementation 

void draw_rectangle_fill(SDL_Renderer* renderer, const SDL_Rect& rectangle, const SDL_Color& color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    for (auto y = rectangle.y; y < rectangle.y + rectangle.h; y++)
    {
        for (auto x = rectangle.x; x < rectangle.x + rectangle.w; x++)
        {
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }
}
void draw_rectangle_not_fill(SDL_Renderer* renderer, const SDL_Rect& rectangle, const SDL_Color& color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    for (auto y = rectangle.y; y < rectangle.y + rectangle.h; y++)
    {
        for (auto x = rectangle.x; x < rectangle.x + rectangle.w; x++)
        {
            if(x == rectangle.x)
                SDL_RenderDrawPoint(renderer, x, y);
            if(x == rectangle.x + rectangle.w - 1)
                SDL_RenderDrawPoint(renderer, x, y);
            if(y == rectangle.y)
                SDL_RenderDrawPoint(renderer, x, y);
            if(y == rectangle.y + rectangle.h - 1)
                SDL_RenderDrawPoint(renderer, x, y);
        }
    }
}