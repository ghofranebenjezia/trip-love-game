#include "perso.h"


int nb_image_par_ligne_spritesheet = 15,
nb_ligne_spritesheet=4;
void initialiser_animation_perso(SDL_Rect *clip)
{

  //init width and height
for (int j=0; j<nb_image_par_ligne_spritesheet*nb_ligne_spritesheet;j++){
  clip[j].w = 100;
  clip[j].h = 100;
}


    //vers droite : ligne 1
    clip[0].x = 0;
    clip[0].y = 0;

    int i = 1;
    for (i = 1; i < nb_image_par_ligne_spritesheet; i++)
    {

        clip[i].x = clip[i-1].w + clip[i-1].x;
        clip[i].y = 0;
    }

    //vers gauche : ligne 2
    clip[15].x = 0;
    clip[15].y = clip[0].y+clip[0].h;

    i = 16;
    for (i = 16; i < (2 * nb_image_par_ligne_spritesheet); i++)
    {
        clip[i].x = clip[i - 1].x + clip[i].w;
        clip[i].y =  clip[0].y+clip[0].h;
    }
    //stable right : ligne 3
    clip[30].x = 0;
    clip[30].y =  clip[15].y+clip[15].h;
    i = 31;
    for (i = 31; i < (3 * nb_image_par_ligne_spritesheet); i++)
    {
        clip[i].x = clip[i - 1].x + clip[i].w;
        clip[i].y =  clip[15].y+clip[15].h;
    }

    //stable right : ligne 4
    clip[45].x = 0;
    clip[45].y =  clip[30].y+clip[30].h;

    i = 46;
    for (i = 46; i < (4 * nb_image_par_ligne_spritesheet); i++)
    {
        clip[i].x = clip[i - 1].x + clip[i].w;
        clip[i].y = clip[30].y+clip[30].h;
    }
}

void initialiser_perso(personnage *p){
  p->pos_perso.x=10;
  p->pos_perso.y=300;
  p->pos_perso.h=100;
  p->pos_perso.w=100;

  p->image_perso=IMG_Load("src/run.png");
  p->vitesse_perso=3;
    p->vitesse_max_perso=15;

  p->stable=1;
  p->direction=0;
  p->jump=1; //1-> peut sauter | 0-> ne peut pas sauter

  p->comp_tab_animation_perso=30;
  initialiser_animation_perso(p->animation_perso);

  p->vie=3;
  p->score=500;

  p->acc=0;
  p->acceleration=0;

}

void afficher_perso(personnage *p, SDL_Surface *screen){
  SDL_BlitSurface(p->image_perso,&p->animation_perso[p->comp_tab_animation_perso],screen,&p->pos_perso);
}

void avancer_perso(personnage *p,Uint32 dt){
  acceleration(p,dt);
  p->direction=0;
  p->stable=0;
  if (p->pos_perso.x+p->pos_perso.w<800)
p->pos_perso.x+=p->vitesse_perso;
p->pos_perso_relative.x+=p->vitesse_perso;

animation_perso_mvt_droite(p);
}

void reculer_perso_souris(personnage *p, int pos_souris_x,Uint32 dt){
acceleration(p,dt);
  p->direction=1;
    p->stable=0;
p->pos_perso.x-=p->vitesse_perso;
p->pos_perso_relative.x-=p->vitesse_perso;

animation_perso_mvt_gauche(p);

}

void avancer_perso_souris(personnage *p, int pos_souris_x,Uint32 dt){
acceleration(p,dt);
  p->direction=0;
  p->stable=0;
  if (p->pos_perso.x+p->pos_perso.w<800)
p->pos_perso.x+=p->vitesse_perso;
p->pos_perso_relative.x+=p->vitesse_perso;

animation_perso_mvt_droite(p);
}


void reculer_perso(personnage *p,Uint32 dt){
  acceleration(p,dt);
  p->direction=1;
    p->stable=0;
p->pos_perso.x-=p->vitesse_perso;
p->pos_perso_relative.x-=p->vitesse_perso;

animation_perso_mvt_gauche(p);
}

void animation_perso_stable(personnage *p){

  p->comp_tab_animation_perso++;

  //regarder droite
if (!p->direction)
{
  if(p->comp_tab_animation_perso < 30 || p->comp_tab_animation_perso>44)
  p->comp_tab_animation_perso=30;
}

  //regarder gauche
if(p->direction){
  if(p->comp_tab_animation_perso < 45 || p->comp_tab_animation_perso>59)
  p->comp_tab_animation_perso=45;
}



}

void animation_perso_mvt_droite(personnage *p){
    p->comp_tab_animation_perso++;

  if(p->comp_tab_animation_perso < 0 || p->comp_tab_animation_perso>14)
  p->comp_tab_animation_perso=0;
}

void animation_perso_mvt_gauche(personnage *p){
  p->comp_tab_animation_perso++;

if(p->comp_tab_animation_perso < 15 || p->comp_tab_animation_perso>29)
p->comp_tab_animation_perso=15;
}

void acceleration(personnage *p,Uint32 dt){
  if (p->acceleration%2==0) {
 p->acc=0;
     p->vitesse_perso=3;
   }
 if(p->acceleration%2==1)
 {
   if(p->vitesse_perso<p->vitesse_max_perso)
 {
 p->acc+=0.000001;
   p->vitesse_perso+=0.5*p->acc*dt*dt+p->vitesse_perso*dt/1000;
 }
 }
}

void jump_perso(personnage *p){
 if(p->jump){
  p->pos_perso_relative.y-=100;
  p->pos_perso.y-=100;
}
}
