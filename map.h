#ifndef map_H_INCLUDED
#define map_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "entite.h"

typedef struct {
SDL_Surface *map ;
SDL_Rect map_pos;


SDL_Surface *mini_entite;
SDL_Rect pos_entite_map;

}map ;


void initialiser_map (map *m,SDL_Surface *screen) ;
void entite_map(map *m, Entite *e);
void affiche_map(map *m, SDL_Surface *screen, Entite *e);
void mise_a_jour_map(map *m , SDL_Surface *screen, Entite *e);




#endif
