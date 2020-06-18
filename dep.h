#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
/**
* @struct charc
* @brief struct personnage
*/
typedef struct image
{ 
	SDL_Rect position;
        SDL_Surface* background;
}image;

typedef struct charac

{

	SDL_Surface *personage[5];
	SDL_Surface *personage1[5];
        SDL_Surface *personage2[5];	
        SDL_Surface *personage3[5];	
        SDL_Rect positionChar;

}charac;

image init_img(char nomimage[100],int x,int y);
void display(SDL_Surface *ecran,image img);
charac init_perso();
void display_perso(SDL_Surface *ecran,charac pers,int i,SDL_Rect positionChar,int j);
int input(charac *pers,int i,int *continuer,int *j);
charac init_perso1();
charac init_perso2();
charac init_perso3();




#endif
