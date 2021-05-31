#include <SDL2/SDL.h>
#ifndef MOULIN_H
#define MOULIN_H

typedef struct position{
    int pos;
    struct position* suiv;
}position;

typedef struct{
    position* first;
    position* last;
}positions_possible;
//////////////////////////////////////////////////////////////
typedef struct captur{
    int cap;
    struct captur* suiv;
}captur;

typedef struct{
    captur* first;
    captur* last;
}captures_possibles;
////////////////////////////////////////////////////////////////////////

typedef struct deplacement{
    int dep;
    int arr;
    struct deplacement* suiv;
}deplacement;

typedef struct{
    deplacement* first;
    deplacement* last;
}deplacements_possibles;


///////////les menus et la grille du jeu//////////////////////////



///////////////////////////////////////////////////////////////////////////:

int estBloquer(int j,int Jeu[24]);


void minimax(int T[24],int depth,int max_palyer,int jou,int* coup,int* S,int N);



SDL_Texture *loadImage(const char path[], SDL_Renderer *renderer);


#endif // MOULIN_H
