#include "background.h"

void init_back1(background *bg){
bg->image_back=IMG_Load("images/bg1.jpg");

bg->pos_back.w=4289;
bg->pos_back.h=400;

bg->camera.x=0;
bg->camera.y=0;
bg->camera.w=800;
bg->camera.h=400;

}

void init_back2(background *bg){
bg->image_back=IMG_Load("images/bg2.jpg");

bg->pos_back.w=3217;
bg->pos_back.h=400;

bg->camera.x=0;
bg->camera.y=-400;
bg->camera.w=800;
bg->camera.h=700;

}

void afficher_back(background bg,SDL_Surface *screen){
SDL_BlitSurface(bg.image_back,&bg.camera,screen,NULL);
}

void scroll_right1 (background *bg, Entite *E){
if(bg->camera.x+bg->camera.w<bg->pos_back.w){
bg->camera.x+=5;
E->posmax_st-=5;
E->posmin_st-=5;
E->posfond.x-=5;
}
}

void scroll_left1 (background *bg, Entite *E){
if (bg->camera.x>0){
bg->camera.x-=5;
E->posmax_st+=5;
E->posmin_st+=5;
E->posfond.x+=5;
}
}

void scroll_right2 (background *bg){
if(bg->camera.x+bg->camera.w<bg->pos_back.w){
bg->camera.x+=5;
}
}

void scroll_left2 (background *bg){
if (bg->camera.x>0){
bg->camera.x-=5;
}
}
