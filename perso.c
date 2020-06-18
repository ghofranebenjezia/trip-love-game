
/**
* @file perso.c
* @brief personnage
* @author med mustapha bouchmel
* @version 0.1
* @date July 07 2020
*
* integrated program for personnage
*
*/
#include "dep.h"
#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
/**
* @brief affichage personnage 
* @return integer
*/
image init_img(char nomimage[100],int x,int y)
{
image img;
img.background=IMG_Load(nomimage);//load image
img.position.x=x;//position x de bg
img.position.y=y;//position y de bg
return img;
}

void display(SDL_Surface *ecran,image img)
{
SDL_BlitSurface(img.background,NULL,ecran,&img.position);//afficher l image

}
int input(charac* pers,int i,int *continuer,int *j)
{ 
SDL_Event event;
    SDL_WaitEvent(&event);
        switch(event.type)
        {
          
            case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
             
                case SDLK_RIGHT:
               *j=0;
                pers->positionChar.x +=30;
                i++;
                
                break;

                case SDLK_LEFT:
               *j=1;
                pers->positionChar.x -=30;
                i++;
                break;
                  
               case SDLK_v:
                *j=0;
               pers->positionChar.x+=60;

                i++;
                break;
               case SDLK_UP:
              *j=2;
               pers->positionChar.x+=30;
                i++;
                break;
                case SDLK_DOWN:
              *j=3;
               pers->positionChar.x+=30;

                i++;
                break;
           }
           break;             
        
        }
return i;
}


charac init_perso()
{

    charac pers;
    pers.personage[0] = IMG_Load("6.png");
    pers.personage[1] = IMG_Load("7.png");
    pers.personage[2] = IMG_Load("8.png");
    pers.personage[3] = IMG_Load("9.png");
    pers.personage[4] = IMG_Load("10.png");

    pers.positionChar.x = 0;
    pers.positionChar.y = 400; 

  return pers;

}  

void display_perso(SDL_Surface *ecran ,charac pers,int i,SDL_Rect positionChar,int j)
{
    if (j==0)
SDL_BlitSurface(pers.personage[i],NULL,ecran,&positionChar);
 if (j==1)
SDL_BlitSurface(pers.personage1[i],NULL,ecran,&positionChar);
else if (j==2)
SDL_BlitSurface(pers.personage2[i],NULL,ecran,&positionChar); 
else if (j==3)
SDL_BlitSurface(pers.personage3[i],NULL,ecran,&positionChar); 
}

charac init_perso1()
{

    charac pers;
    pers.personage1[0] = IMG_Load("1.png");
    pers.personage1[1] = IMG_Load("2.png");
    pers.personage1[2] = IMG_Load("3.png");
    pers.personage1[3] = IMG_Load("4.png");
    pers.personage1[4] = IMG_Load("5.png"); 


     pers.positionChar.x = 0;
    pers.positionChar.y = 400; 

  return pers;

}  

charac init_perso2()
{

    charac pers;
    pers.personage2[0] = IMG_Load("11.png");
    pers.personage2[1] = IMG_Load("12.png");
    pers.personage2[2] = IMG_Load("13.png");
    pers.personage2[3] = IMG_Load("14.png");
    pers.personage2[4] = IMG_Load("15.png"); 


     pers.positionChar.x = 0;
     pers.positionChar.y = 400; 

return pers;

}  

charac init_perso3()
{

    charac pers;
    pers.personage3[0] = IMG_Load("16.png");
    pers.personage3[1] = IMG_Load("17.png");
    pers.personage3[2] = IMG_Load("18.png");
    pers.personage3[3] = IMG_Load("19.png");
    pers.personage3[4] = IMG_Load("20.png"); 


     pers.positionChar.x = 0;
     pers.positionChar.y = 400; 

return pers;

}  

