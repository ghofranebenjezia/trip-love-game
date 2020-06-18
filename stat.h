#ifndef stat_H_INCLUDED
#define stat_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "string.h"


#include "entite.h"

typedef struct
{
  //creation police/font du texte
  TTF_Font *police_vie;
  //creation couleur du texte

  //creation texte vie
  SDL_Surface *texte_vie;
  TTF_Font *font;
  SDL_Rect pos_texte_vie;

} vie_perso;


typedef struct
{
  //creation police/font du texte
  TTF_Font *police_score;
  //creation couleur du texte

  //creation texte score
  SDL_Surface *texte_score;

  SDL_Rect pos_texte_score;

} score_perso;

typedef struct
{
  //creation police/font du texte
  TTF_Font* police_chrono;

 //val initiale chrono
 float temps_restant;
  float temps_init;

  //creation texte vie
  SDL_Surface *texte_chrono;
  SDL_Rect pos_texte_chrono;

} chrono_perso;

void init_vie(vie_perso* v);
void init_score(score_perso *s);
void  init_chrono(chrono_perso* c);
void afficher_score(personnage *p, SDL_Surface *screen, score_perso *s);
void afficher_vie(personnage *p, SDL_Surface *screen, vie_perso *v);
void afficher_vie_score(personnage *p, SDL_Surface *screen, score_perso *s, vie_perso *v, chrono_perso *c);
void afficher_chrono(SDL_Surface* screen,chrono_perso* c);
void gestion_vie(personnage *p, Entite *e);
int fin_jeu(personnage p,chrono_perso *c);

#endif
