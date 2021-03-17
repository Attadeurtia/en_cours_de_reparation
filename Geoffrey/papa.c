#include <stdio.h>
#include <SDL.h>

SDL_Surface *ecran, *imageDeFond, *zozor;
/*
 * Fonction pour initialiser SDL
 * et les variables globales.
 */
void init(void)
{
	SDL_Init(SDL_INIT_VIDEO);
	ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
	imageDeFond = SDL_LoadBMP("lac_en_montagne.bmp");
	zozor = SDL_LoadBMP("zozor.bmp");
}

/*
 * Fonction pour être à l'écoute
 * de l'événement SDL_Quit.
 */
void input_handle(void)
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) {

		switch (event.type) {
		case SDL_QUIT:
			SDL_Quit();
			exit(0);
			break;
		}
	}
}

/*
 * La fonction qui fera l'animation
 */
void anime(void)
{
	SDL_Rect positionFond, positionZozor;
	int avanceX = 1, avanceY = 1; // Ces variables diront si zozor doit avancer ou reculer.

	positionFond.x = 0;
	positionFond.y = 0;

	positionZozor.x = 0;
	positionZozor.y = 0;

	while (1) {

		SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond); // Dessiner le fond
		SDL_BlitSurface(zozor, NULL, ecran, &positionZozor); // Dessiner zozor

		if (avanceX) {
			positionZozor.x++; // Si avance est à 1 alors on incrémente x
		} else {
			positionZozor.x--; // Sinon on décrémente x 
		}

		if (avanceY) {
			positionZozor.y++;
		} else {
			positionZozor.y--;
		}

                /* 
                 * Arrivé à l'une des extrémités, on change la valeur de avance
                 */
		if (positionZozor.x == ecran->w - zozor->w - 1)
			avanceX = 0;
		else if (positionZozor.x == 0)
			avanceX = 1;

		if (positionZozor.y == ecran->h - zozor->h - 1)
			avanceY = 0;
		else if (positionZozor.y == 0)
			avanceY = 1;

		SDL_Flip(ecran); // On affiche réellement l'image.
		input_handle(); // On appelle le gestionnaire d'évènements.
		//SDL_Delay(10);
	}
}

int main(void)
{
	init();
	anime();
	return 0;
}