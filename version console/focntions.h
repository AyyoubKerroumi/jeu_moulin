#ifndef INT_H
#define INT_H


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



void grille(int Jeu[24]);
void color(int t,int f);
void setcurseur(int x,int y);
void init(void);
void init2(void);
void init3(void);
void fen1d(int x,int y,int l,int h,int clf,int clc,int clt, char c);
void fen2d(int x,int y,int l,int h,int clf,int clc,int clt, char ch[20],int choix);
void gestion();
void gestion2();
void gestion3();
int menuu1(void);
int menuu2(void);
int menuu3(void);
void jouer();
void jouer2();
void retour();
void bienvenue();
void afficher_pion(int c,int pion);
///////////////////////////////////////////////////////////////////////////:

int estBloquer(int j,int Jeu[24]);


void minimax(int T[24],int depth,int max_palyer,int jou,int* coup,int* S,int N);
#endif // INT_H

