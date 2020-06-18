/**
* @file main.c
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
void  main(SDL_Surface *ecran)
{
    charac pers;

    SDL_Event event;
    int continuer=1,i=0;

    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO); //initialisation
    ecran=SDL_SetVideoMode(900, 700, 32,SDL_HWSURFACE);//afficher la fenetre

  int j=0;
    image img;
    pers=init_perso();
    pers=init_perso1();
    pers=init_perso2();
    pers=init_perso3();
    img=init_img("bgg.png",0,130);

    SDL_EnableKeyRepeat(100,100); /*Activation de la répétition des touches  100 ms */

    while (continuer)
    {   

         SDL_PollEvent(&event);
       switch(event.type)
          {
            case SDL_QUIT:
            continuer= 0;
            break;
          }
            i=input(&pers,i,&continuer,&j);
	  
            /*pers.positionChar.x+=10;
            i++;*/
           printf("%d\n",j);
            if (i==5)
            {
            i=0;
            }
             SDL_Delay(100);
             display(ecran,img);
            display_perso(ecran,pers,i,pers.positionChar,j);
            SDL_Flip(ecran);
           
        
  }    


   
}





