/*
commande d'execution
gcc -o game  *.c -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -lSDL_gfx -lm ; ./game
*/

#include <stdio.h>
#include <stdlib.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

#include "background.h"
#include "entite.h"
#include "map.h"
#include "stat.h"





int main(int argc, char const *argv[]) {
SDL_Init(SDL_INIT_VIDEO);
TTF_Init();
//creation fenetre
SDL_Surface *screen=NULL;
screen=SDL_SetVideoMode(800,700,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

//declaration et initiliser background 1
background bg;
init_back1(&bg);

//declaration et initiliser background 2
background bg2;
init_back2(&bg2);

//declaration et init entite
Entite E;
initEntite(&E);

//declaration et initialisation mini map
map m;
initialiser_map(&m,screen);

//declaration vie et score et chrono
vie_perso val_vie;
init_vie(&val_vie);
score_perso val_score;
init_score(&val_score);
chrono_perso val_chrono;
init_chrono(&val_chrono);

personnage p;
p.vie=3;
p.score=100;

//reglage fps
Uint32 t_int,t_fin,dt;

//initialiser boucle pseudo infinie
int running=1;
SDL_Event event;
SDL_EnableKeyRepeat(200,0);

while (running) {

  if(SDL_PollEvent(&event)){
    switch (event.type) {
//boutton X rouge de la fenetre
      case SDL_QUIT:
      running=0;
      break;

//avec clavier
      case SDL_KEYDOWN:
switch (event.key.keysym.sym) {
  case SDLK_RIGHT:
scroll_right1(&bg,&E);
  break;
  case SDLK_LEFT:
scroll_left1(&bg,&E);
  break;

  case SDLK_d:
scroll_right2(&bg2);
  break;
  case SDLK_q:
scroll_left2(&bg2);
  break;

  case SDLK_v:
p.vie--;
  break;
  case SDLK_s:
p.score-=100;
  break;


}
      break;

    }

  }//fin poll event


afficher_back(bg,screen);
afficher_back(bg2,screen);

//mise a jour et affichag emini map
mise_a_jour_map(&m,screen,&E);

//mise a jour et affichage entite
animer(&E);
deplacer(&E);
affichEntite(E,screen);

//gestion_vie(&p,&E);
afficher_vie_score(&p,screen,&val_score,&val_vie,&val_chrono);

SDL_Flip(screen);

if(fin_jeu(p,&val_chrono)) //si jeu est fini
{
  running=0;
}

}//fin while
TTF_Quit();
SDL_Quit();
  return 0;
}
