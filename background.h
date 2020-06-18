#ifndef background_H_INCLUDED
#define background_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#include "entite.h"

typedef struct {
SDL_Surface *image_back;
SDL_Rect pos_back;
SDL_Rect camera;
} background;

void init_back1(background *bg);
void init_back2(background *bg);
void afficher_back(background bg,SDL_Surface *screen);
void scroll_right1 (background *bg, Entite *E);
void scroll_left1 (background *bg, Entite *E);
void scroll_right2 (background *bg);
void scroll_left2 (background *bg);


#endif
