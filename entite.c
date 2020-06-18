/**
* @file entite.c
*/

#include <stdio.h>
#include <SDL/SDL.h>
#include<SDL/SDL_mixer.h>
#include "entite.h"
#include "SDL/SDL_image.h"

/**
* @brief intitialiser l'entite E
* @param E l'entite
* @return nothing
*/

void initEntite(Entite *E)
{

E->direction=0;

E->imagefond = IMG_Load("images/sprite.png");
E->frame=0;
for(int i=0;i<5;i++){
  E->tab_anim[i].x=150*i;
  E->tab_anim[i].y=0;
  E->tab_anim[i].w=150;
  E->tab_anim[i].h=173;
}

 E->posfond.x=100;
 E->posfond.y=200;

 E->posmax=600;
 E->posmin=400;

 E->posmax_st=600;
 E->posmin_st=400;

 E->col=0;

}


/**
* @brief afficher l'entite
* @param ecran c'est l'ecran
* @param E l'entite
* @return nothing
*/



void affichEntite(Entite E, SDL_Surface* ecran)
{
 SDL_BlitSurface(E.imagefond,&E.tab_anim[E.frame],ecran,&E.posfond);
}

/**
* @brief annimer l'entite
* @param E l'entite
* @return nothing
*/

void animer(Entite *E)
{
E->frame++;
if(E->frame>4 || E->frame<0)
E->frame=0;

}


/**
* @brief deplacer l'entite
* @param E l'entite
* @return nothing
*/


void deplacer(Entite *E)
{

if(E->posfond.x >= E->posmax)
 E->direction= 0;
if(E->posfond.x <= E->posmin){
 E->direction=1;
 update_min_max(E);
}

if(E->direction == 1)
E->posfond.x+=5;
else
E->posfond.x-=5;


}

void update_min_max(Entite *E){
  E->posmax=rand()%150+E->posmax_st;
  E->posmin=E->posmax_st-rand()%150;
//  printf("min : %d\tmax : %d\n",E->posmin,E->posmax );
}



/*

void collisionBB(perso *P,Entite E)
{

//collision
if (
( E.posfond.x <= P->positionChar.x + P->positionChar.w)
|| ( E.posfond.x + E.posfond.w >= P->positionChar.x)
|| ( E.posfond.y <= P->positionChar.y + P->positionChar.h)
|| (E.posfond.y + E.posfond.h >= P->positionChar.y)
)
 E->col=0;
else
E->col=1;


}
*/
