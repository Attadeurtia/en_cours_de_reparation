SDL_PollEvent(&event);
 
switch(event.type)
{
       case SDL_MOUSEBUTTONDOWN:
             x=event.button.x;  //récupération de la position de la souris
             y=event.button.y;
 
             if (x>abscisse_image_gauche && x<abscisse_image_droite && y>ordonnee_image_haut && y<ordonnee_image_bas)
             {
                   //La tu fais ce que tu veux
             }
             break;
}