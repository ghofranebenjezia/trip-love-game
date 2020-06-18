#include "stat.h"
void init_vie(vie_perso* v){
    v->police_vie=TTF_OpenFont("font.ttf",30);

    v->texte_vie=NULL;

        v->pos_texte_vie.x=480;
        v->pos_texte_vie.y=50;

}
void init_score(score_perso* s){
    s->police_score=TTF_OpenFont("font.ttf",30);

    s->texte_score=NULL;

    s->pos_texte_score.x=280;
    s->pos_texte_score.y=50;

}

void init_chrono(chrono_perso* c){
    c->police_chrono=TTF_OpenFont("font.ttf",30);

    c->texte_chrono=NULL;
    c->pos_texte_chrono.x=600;
    c->pos_texte_chrono.y=50;

    c->temps_init=50;
}

void afficher_score(personnage* p,SDL_Surface* screen,score_perso* s)
{SDL_Color couleur_score={255,255,255};
char char_score[50];
  sprintf(char_score,"score : %04d",p->score);

  s->texte_score=TTF_RenderText_Solid(s->police_score,char_score,couleur_score);
  SDL_BlitSurface(s->texte_score,NULL,screen,&s->pos_texte_score);

}


void afficher_vie(personnage* p,SDL_Surface* screen,vie_perso* v)
{SDL_Color couleur_vie={255,255,255};
  char char_vie[50];
  sprintf(char_vie,"vie x%02d",p->vie);

  v->texte_vie=TTF_RenderText_Solid(v->police_vie,char_vie,couleur_vie);
  SDL_BlitSurface(v->texte_vie,NULL,screen,&v->pos_texte_vie);
}

void afficher_vie_score(personnage *p, SDL_Surface *screen, score_perso *s, vie_perso *v, chrono_perso *c){
afficher_vie(p,screen,v);
afficher_score(p,screen,s);
afficher_chrono(screen,c);
}

void afficher_chrono(SDL_Surface* screen,chrono_perso* c)
{ SDL_Color couleur_chrono={255,255,255};
  char char_chrono[50];
  c->temps_restant= c->temps_init-(float)SDL_GetTicks()/1000;
  sprintf(char_chrono,"Timer : %0.2f",c->temps_restant);
  c->texte_chrono=TTF_RenderText_Solid(c->police_chrono,char_chrono,couleur_chrono);
  SDL_BlitSurface(c->texte_chrono,NULL,screen,&c->pos_texte_chrono);
}

void gestion_vie(personnage *p, Entite *e){
  if (e->col)//il y a collision avec perso
  p->vie--;

}

int fin_jeu(personnage p,chrono_perso *c){
//return 1 si jeu est fini ( soit gagné soit perdu) | return 0 si je joue encore
if(p.vie<=0 || p.score<=0 || c->temps_restant<=0) {
  return 1;
}
  return 0;
}
