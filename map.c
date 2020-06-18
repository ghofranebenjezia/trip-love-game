#include "map.h"

void initialiser_map (map *m,SDL_Surface *screen)
{
m->map=IMG_Load("images/map1.jpg");
m->map_pos.x = 0;
m->map_pos.y = 0;


m->mini_entite=SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_DOUBLEBUF,10,10,32,0,0,0,0);
SDL_FillRect(m->mini_entite,NULL,SDL_MapRGB(screen->format,255,0,0));
m->pos_entite_map.x=0;
m->pos_entite_map.y=0;

}

void entite_map(map *m, Entite *e){
  m->pos_entite_map.x=e->posfond.x/10+m->map_pos.x;
    m->pos_entite_map.y=e->posfond.y/10+e->posfond.h/10+m->map_pos.y;
}

void affiche_map(map *m , SDL_Surface *screen, Entite *e){
      SDL_BlitSurface(m->map, NULL, screen,&m->map_pos);
      SDL_BlitSurface(m->mini_entite, NULL, screen,&m->pos_entite_map);

}

void mise_a_jour_map(map *m , SDL_Surface *screen, Entite *e){
  entite_map(m,e);
  affiche_map(m,screen,e);
}
