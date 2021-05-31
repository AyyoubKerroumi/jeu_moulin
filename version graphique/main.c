#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"
#include <SDL2/SDL.h>
struct carre {
   SDL_Rect rect;
   Uint32 couleur;
};

SDL_Event event;

int main(int argc, char **argv)
{
    int p[24];
    for(int i=0;i<24;i++)
        p[i]=1;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *image = NULL,*J=NULL,*R=NULL,*Q=NULL;///le menu , et les bouttons
    int statut = EXIT_FAILURE;
    SDL_Color blanc = {255, 255, 255, 255};
    if(0 != init(&window, &renderer, 1200, 650)) /* ecrire cette fonction */
        goto Quit;

    image = loadImage("images/menu2.bmp", renderer);
    J=loadImage("images/jouer.bmp",renderer);
    R=loadImage("images/regles.bmp",renderer);
    Q=loadImage("images/quitter.bmp",renderer);
    if(NULL == image || J==NULL || Q==NULL || R==NULL )
        goto Quit;
    A:
    setWindowColor(renderer, blanc);
    SDL_Rect dst = {275,0,650, 650};
    SDL_RenderCopy(renderer, image, NULL, &dst);
    SDL_Rect dest[3]={ {522,285,156,64} ,{522,399,156,64} ,{522,513,156,64} };
    SDL_RenderPresent(renderer);
    int continuer1 = 1;
    int e=0;
    while (continuer1)
    {
        SDL_WaitEvent(&event);
        if(event.type==SDL_MOUSEMOTION){e=1;}
        if(event.type==SDL_QUIT || (e==1 && event.button.button==SDL_BUTTON_LEFT && event.button.y>=480 && event.button.y<=480+70 && event.button.x>=480 && event.button.x<=480+240))
            {continuer1=0;
            break;
            }
        if(event.motion.y>=285 && event.motion.y<=285+64 && event.motion.x>=247+275 && event.motion.x<=247+156+275){
            SDL_RenderCopy(renderer, J, NULL, &dest[0]);
            SDL_RenderPresent(renderer);
        }
       else if(event.motion.y>=399 && event.motion.y<=399+64 && event.motion.x>=247+275 && event.motion.x<=247+156+275){
            SDL_RenderCopy(renderer, R, NULL, &dest[1]);
            SDL_RenderPresent(renderer);
        }
        else if(event.motion.y>=513 && event.motion.y<=513+64 && event.motion.x>=247+275 && event.motion.x<=247+156+275){
            SDL_RenderCopy(renderer, Q, NULL, &dest[2]);
            SDL_RenderPresent(renderer);
        }
        else
        {
            SDL_RenderCopy(renderer, image, NULL, &dst);
            SDL_RenderPresent(renderer);
        }
        if(event.type==SDL_QUIT || (e==1 && event.button.button==SDL_BUTTON_LEFT && event.button.y>=284 && event.button.y<=284+70 && event.button.x>=480 && event.button.x<=480+240))
            {/// jouer
                    SDL_Texture* Plateau=loadImage("images/plateau.bmp",renderer);
                    int n=jouer(renderer,Plateau);
                    if(n==1)
                        exit(1);
                    if(n==0)
                        goto A;


            }
        if(event.type==SDL_QUIT || (e==1 && event.button.button==SDL_BUTTON_LEFT && event.button.y>=400 && event.button.y<=400+70 && event.button.x>=480 && event.button.x<=480+240))
            {/// afficher les regles;
                    SDL_Texture* R2=loadImage("images/regles.bmp",renderer);
                    SDL_Rect dst2 = {372,113,456, 424};
                    SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer, R2, NULL, &dst2);
                    SDL_RenderPresent(renderer);
                    while(1){
                        SDL_WaitEvent(&event);
                        if(event.type==SDL_KEYUP)
                            break;
                    }
            }
            }
    Quit:
    if(NULL != image)
        SDL_DestroyTexture(image);
    if(NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if(NULL != window)
        SDL_DestroyWindow(window);
    SDL_Quit();
    return statut;
}
