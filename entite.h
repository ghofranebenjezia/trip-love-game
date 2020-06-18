#ifndef GG_H_INCLUDED
#define GG_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "time.h"

/**
* @struct entite
* @brief struct de l'entite
*/


typedef struct Entite
{

SDL_Surface* imagefond; /*!<surface*/
SDL_Rect posfond;/*!crectangel*/
SDL_Rect tab_anim[5];
int frame;
int direction;
int posmin,posmax;
int posmin_st,posmax_st;
int col;
} Entite ;

typedef struct {
int vie;
int score;
} personnage;


void initEntite(Entite *E);
void affichEntite(Entite E, SDL_Surface* ecran);
void animer(Entite *E);
void deplacer(Entite *E);
//void collisionBB(charac P,Entite E);
void update_min_max(Entite *E);
#endif
