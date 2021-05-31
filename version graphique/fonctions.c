#include <SDL2/SDL.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "fonctions.h"
#define MAX 1000


SDL_Event event;


int first_palyer(SDL_Renderer* t){
    srand(time(NULL));
    int tirage=rand()%2+1;
    SDL_Rect dst,dst1;
    dst.x = 0;
    dst.y = 0;
    dst.h=650;
    dst.w=1200;
    dst1.w=200;
    dst1.h=200;
    SDL_Texture* i = loadImage("images\\tirage.bmp",t);
    SDL_Texture* f = loadImage("images\\fleche.bmp",t);
    SDL_RenderCopy(t, i, NULL, &dst);
    SDL_RenderPresent(t);
    SDL_Delay(1000);
    for(int j=0;j<10;j++){
        dst1.x=208;dst1.y=132;
        SDL_RenderCopy(t, i, NULL, &dst);
        SDL_RenderCopy(t, f, NULL, &dst1);
        SDL_RenderPresent(t);
        SDL_Delay(500);
        dst1.x=770;
        dst1.y=143;
        SDL_RenderCopy(t, i, NULL, &dst);
        SDL_RenderCopy(t, f, NULL, &dst1);
        SDL_RenderPresent(t);
        SDL_Delay(500);
        SDL_RenderClear(t);
    }
    if(tirage==1){///le joueur humain qui va commencer
        dst1.x=208;dst1.y=132;
        SDL_RenderCopy(t, i, NULL, &dst);
        SDL_RenderCopy(t, f, NULL, &dst1);
        SDL_RenderPresent(t);
    }
    while(1){
        SDL_WaitEvent(&event);
        if(event.type==SDL_KEYUP)
            break;
    }
    return tirage;
}

int tester_moulin(int pos,int Jeu[24])
{///la case d'indice pos est supposée pleine
    switch(pos-1)
    {///position joué par le joueur
        case 0:{
            if(Jeu[0]==Jeu[9] && Jeu[9]==Jeu[21])
                return 1;
            if(Jeu[0]==Jeu[1] && Jeu[1]==Jeu[2])
                return 1;
            break;
        }
        case 1:{
            if(Jeu[1]==Jeu[0] && Jeu[0]==Jeu[2])
                return 1;///cpature();
            if(Jeu[1]==Jeu[4] &&Jeu[4]==Jeu[7])
                return 1;
            break;
        }
        case 2:{
            if(Jeu[2]==Jeu[1] && Jeu[1]==Jeu[0])
                return 1;///cpature();
            if(Jeu[2]==Jeu[14] &&Jeu[23]==Jeu[14])
                return 1;
            break;
        }
        case 3:{
            if(Jeu[3]==Jeu[4] && Jeu[4]==Jeu[5])
                return 1;///cpature();
            if(Jeu[3]==Jeu[10] &&Jeu[10]==Jeu[18])
                return 1;
            break;
        }
        case 4:{
            if(Jeu[4]==Jeu[3] && Jeu[3]==Jeu[5])
                return 1;///cpature();
            if(Jeu[4]==Jeu[1] &&Jeu[1]==Jeu[7])
                return 1;
            break;
        }
        case 5:{
            if(Jeu[5]==Jeu[4] && Jeu[4]==Jeu[3])
                return 1;///cpature();
            if(Jeu[5]==Jeu[13] &&Jeu[13]==Jeu[20])
                return 1;
            break;
        }
        case 6:{
            if(Jeu[6]==Jeu[7] && Jeu[7]==Jeu[8])
                return 1;///cpature();
            if(Jeu[6]==Jeu[11] &&Jeu[11]==Jeu[15])
                return 1;
            break;
        }
        case 7:{
            if(Jeu[7]==Jeu[4] && Jeu[4]==Jeu[1])
                return 1;///cpature();
            if(Jeu[7]==Jeu[6] &&Jeu[6]==Jeu[8])
                return 1;
            break;
        }
        case 8:{
            if(Jeu[8]==Jeu[7] && Jeu[7]==Jeu[6])
                return 1;///cpature();
            if(Jeu[8]==Jeu[12] &&Jeu[12]==Jeu[17])
                return 1;
            break;
        }
        case 9:{
            if(Jeu[9]==Jeu[10] && Jeu[10]==Jeu[11])
                return 1;///cpature();
            if(Jeu[9]==Jeu[0] &&Jeu[0]==Jeu[21])
                return 1;
            break;
        }
        case 10:{
            if(Jeu[10]==Jeu[9] && Jeu[10]==Jeu[11])
                return 1;///cpature();
            if(Jeu[10]==Jeu[3] &&Jeu[3]==Jeu[18])
                return 1;
            break;
        }
        case 11:{
            if(Jeu[11]==Jeu[6] && Jeu[6]==Jeu[15])
                return 1;///cpature();
            if(Jeu[11]==Jeu[10] &&Jeu[10]==Jeu[9])
                return 1;
            break;
        }
        case 12:{
            if(Jeu[12]==Jeu[13] && Jeu[13]==Jeu[14])
                return 1;///cpature();
            if(Jeu[12]==Jeu[8] &&Jeu[8]==Jeu[17])
                return 1;
            break;
        }
        case 13:{
            if(Jeu[13]==Jeu[12] && Jeu[12]==Jeu[14])
                return 1;///cpature();
            if(Jeu[13]==Jeu[5] &&Jeu[5]==Jeu[20])
                return 1;
            break;
        }
        case 14:{
            if(Jeu[14]==Jeu[2] && Jeu[2]==Jeu[23])
                return 1;///cpature();
            if(Jeu[14]==Jeu[13] &&Jeu[13]==Jeu[12])
                return 1;
            break;
        }
        case 15:{
            if(Jeu[15]==Jeu[16] && Jeu[16]==Jeu[17])
                return 1;///cpature();
            if(Jeu[15]==Jeu[11] &&Jeu[11]==Jeu[6])
                return 1;
            break;
        }
        case 16:{
            if(Jeu[16]==Jeu[15] && Jeu[15]==Jeu[17])
                return 1;///cpature();
            if(Jeu[16]==Jeu[19] &&Jeu[19]==Jeu[22])
                return 1;
            break;
        }
        case 17:{
            if(Jeu[17]==Jeu[16] && Jeu[16]==Jeu[15])
                return 1;
            if(Jeu[17]==Jeu[12] &&Jeu[12]==Jeu[8])
                return 1;
            break;
        }
        case 18:{
            if(Jeu[18]==Jeu[19] && Jeu[19]==Jeu[20])
                return 1;
            if(Jeu[18]==Jeu[10] &&Jeu[10]==Jeu[3])
                return 1;
            break;
        }
        case 19:{
            if(Jeu[19]==Jeu[18] && Jeu[18]==Jeu[20])
                return 1;
            if(Jeu[19]==Jeu[16] &&Jeu[16]==Jeu[22])
                return 1;
            break;
        }
        case 20:{
            if(Jeu[20]==Jeu[19] && Jeu[19]==Jeu[18])
                return 1;
            if(Jeu[20]==Jeu[13] &&Jeu[13]==Jeu[5])
                return 1;
            break;
        }
        case 21:{
            if(Jeu[21]==Jeu[22] && Jeu[22]==Jeu[23])
                return 1;
            if(Jeu[21]==Jeu[9] &&Jeu[9]==Jeu[0])
                return 1;
            break;
        }
        case 22:{
            if(Jeu[22]==Jeu[21] && Jeu[21]==Jeu[23])
                return 1;
            if(Jeu[22]==Jeu[19] &&Jeu[19]==Jeu[16])
                return 1;
            break;
        }
        case 23:{
            if(Jeu[23]==Jeu[22] && Jeu[22]==Jeu[21])
                return 1;
            if(Jeu[23]==Jeu[14] &&Jeu[14]==Jeu[2])
                return 1;
            break;
        default:break;
        }
    }
    return 0;
}


int pion_free(int j,int Jeu[24]){
  	int c = 0;
  	for (int i = 0; i < 24; i++)
  	{
  		if(tester_moulin(i+1,Jeu)==0 && Jeu[i]==j)
  			c++;
  	}
  	return c;
  }

int deplaceable(int dep,int arr)
{
    arr=arr-1;
    switch(dep-1)
    {
        case 0:return (arr==1 || arr==9);break;
        case 1:return (arr==0 || arr==2 || arr==4);break;
        case 2:return (arr==1 || arr==14);break;
        case 3:return (arr==4 || arr==10);break;
        case 4:return (arr==3 || arr==5 || arr==1 || arr==7);break;////
        case 5:return (arr==4 || arr==13);break;
        case 6:return (arr==7 || arr==11);break;
        case 7:return (arr==6 || arr==8 || arr==4);break;///
        case 8:return (arr==7 || arr==12);break;
        case 9:return (arr==0 || arr==21 || arr==10);break;///
        case 10:return (arr==3 || arr==9 || arr==18 || arr==11);break;////
        case 11:return (arr==6 || arr==15 || arr==10);break;///
        case 12:return (arr==17 || arr==8 || arr==13);break;///
        case 13:return (arr==12 || arr==5 || arr==20 || arr==14);break;
        case 14:return (arr==13 || arr==2 || arr==23);break;
        case 15:return (arr==16 || arr==11);break;
        case 16:return (arr==15 || arr==17 || arr==19);break;
        case 17:return (arr==16 || arr==12);break;
        case 18:return (arr==10 || arr==19);break;
        case 19:return (arr==16 || arr==18 || arr==20 || arr==22);break;
        case 20:return (arr==13 || arr==19);break;
        case 21:return (arr==9 || arr==22);break;
        case 22:return (arr==19 || arr==21 || arr==23);break;
        case 23:return (arr==22 || arr==14);break;
    }
}

int nbr_pion(int j,int Jeu[24])   /// nbr de pions sur la grille
{
	int n=0;
	for (int i = 0; i < 24; i++)
	{
		if(Jeu[i]==j)
			n++;
	}
	return n;
}

/////////////////////////////////////////////

int estBloquer(int jou,int Jeu[24])
{
    for(int i=0;i<24;i++)
    {
        for(int j=0;j<24;j++)
            if(Jeu[i]==jou && deplaceable(i,j) && Jeu[j]==0)
                return 0;
    }
    return 1;
}


void pose(int tab[24], int pos, int jou)
  {
  	tab[pos] = jou ;
  }

void capturer(int tab[24], int pos, int jou)
  {
    tab[pos] = 0;
  }

void deplace(int tab[24], int dep, int arr, int jou)
  {
  	tab[dep] = 0;
  	tab[arr] = jou ;
  }
//////////////////////////////////////////////////////////////////////////
int estVide1(positions_possible* p)
{
    return p->first==NULL;
}

positions_possible* CreeListe1()
{
    positions_possible* p=(positions_possible*)malloc(sizeof(positions_possible));
    p->first=NULL;
    p->last=NULL;
    return p;
}


void inserer_position(positions_possible* l,int p)
{
    position* e=(position*)malloc(sizeof(position));
    e->suiv=NULL;
    e->pos=p;
    if(estVide1(l))
    {
        l->first=e;
        l->last=e;
    }
    else{
        e->suiv=l->first;
        l->first=e;
    }
}

void supprimer_liste_position(positions_possible* l)
{
    position* e=l->first;
    position* temp;
    while(e)
    {
        temp=e;
        e=e->suiv;
        free(temp);
    }
    free(l);
}

captures_possibles* CreeListe2()
{
    captures_possibles* c=(captures_possibles*)malloc(sizeof(captures_possibles));
    c->first=NULL;
    c->last=NULL;
    return c;
}

void supprimer_liste_captures(captures_possibles* l)
{
    captur* e=l->first;
    captur* temp;
    while(e)
    {
        temp=e;
        e=e->suiv;
        free(temp);
    }
    free(l);
}

int estVide2(captures_possibles* c)
{
    return c->first==NULL;
}

void inserer_capture(captures_possibles* c,int capt)
{
    captur* e=(captur*)malloc(sizeof(captur));
    e->suiv=NULL;
    e->cap=capt;
    if(estVide2(c))
    {
        c->first=e;
        c->last=e;
    }
    else{
        e->suiv=c->first;
        c->first=e;
    }
}

deplacements_possibles* CreeListe3()
{
    deplacements_possibles* d=(deplacements_possibles*)malloc(sizeof(deplacements_possibles));
    d->first=NULL;
    d->last=NULL;
    return d;
}

int estVide3(deplacements_possibles* d)
{
    return d->first==NULL;
}

void inserer_deplacement(deplacements_possibles* d,int depa,int arv)
{
    deplacement* e=(deplacement*)malloc(sizeof(deplacement));
    e->suiv=NULL;
    e->arr=arv;
    e->dep=depa;
    if(estVide3(d))
    {
        d->first=e;
        d->last=e;
    }
    else
    {
        e->suiv=d->first;
        d->first=e;
    }
}


void generer_positions_possibles(positions_possible* c,int T[24],int j)
{
    for(int i=0;i<24;i++)
        if(T[i]==0)
            inserer_position(c,i);
}

void generer_deplacements_possibles(deplacements_possibles* d,int jou,int T[24])
{
    for(int i=0;i<24;i++)
    {
        for(int j=0;j<24;j++)
        {
            if(deplaceable(i+1,j+1) && T[j]==0 && T[i]==jou)
                inserer_deplacement(d,i,j);
        }
    }
}

void generer_capture_possibles(captures_possibles* c,int j,int T[24])
{
    for(int i=0;i<24;i++)
        if(T[i]==3-j && tester_moulin(i+1,T)==0)
            inserer_capture(c,i);
}


void copier(int tab1[24], int tab2[24])
  {
  	for(int i = 0; i < 24; i++)
  	{
  		tab1[i] = tab2[i];
  	}
  }


int he(int T[24],int j)
{
    return nbr_pion(j,T)-nbr_pion(3-j,T);
}

void minimax(int T[24],int depth,int max_palyer,int jou,int* coup,int* S,int N)///maxplayer , prend en parametre true ou false
{

    int c;
    int s1;
    int temp[24];
    positions_possible* p=CreeListe1();
    generer_positions_possibles(p,T,jou);
    if(N == 0)
    {
        if(max_palyer==1)
            *S=he(T,jou);
        else
            *S=-he(T,jou);
        return;
    }
    if(max_palyer==1)
        *S=-MAX;
    else
        *S=MAX;
    depth--;
    N--;
    position* e=p->first;
    while(e)
    {
        copier(temp,T);
        pose(temp,e->pos,jou);
        if(tester_moulin(e->pos+1,temp) && pion_free(3-jou,temp)!=0)
        {
            int a=pion_a_capturer(temp,jou);
            capturer(temp,a,jou);
        }
        if(depth!=0)
            minimax(temp,depth,1-max_palyer,3-jou,&c,&s1,N);
        else
            {
                if(max_palyer==1)
                    {
                        s1=he(temp,jou);
                    }
                else
                    {
                        s1=-he(temp,jou);
                        //return;
                    }
            }
        if(max_palyer==1)
        {
            if(s1>=*S)
            {
                *S=s1;
                *coup=e->pos;
            }
        }
        else{
            if(s1<=*S)
            {
                *S=s1;
                *coup=e->pos;
            }
        }
        e=e->suiv;
    }
    supprimer_liste_position(p);
}

int free_moulins(int Jeu[24],int pos)///retourne le nombre de free moulins du pion à la position pos
{
    int s=0;
    switch(pos)
        {case 0:{
                if((Jeu[0]==Jeu[9] && 0==Jeu[21]) || ( Jeu[0]==Jeu[21] && Jeu[9]==0 ) )
                    s++;
                if((Jeu[0]==Jeu[1] && 0==Jeu[2]) || (Jeu[0]==Jeu[2] && 0==Jeu[1]) )
                    s++;
                break;
            }
            case 1:{
                if((Jeu[1]==Jeu[0] && 0==Jeu[2]) || (Jeu[1]==Jeu[0] && 0==Jeu[0]))
                    s++;///cpature();
                if((Jeu[1]==Jeu[4] &&Jeu[7]==0) || (Jeu[1]==Jeu[7] &&Jeu[4]==0))
                    s++;
                break;
            }
            case 2:{
                if((Jeu[2]==Jeu[1] && Jeu[0]==0)  ||(Jeu[2]==Jeu[0] && Jeu[1]==0))
                    s++;///cpature();
                if((Jeu[2]==Jeu[14] &&Jeu[23]==0) || (Jeu[2]==Jeu[23] &&Jeu[14]==0))
                    s++;
                break;
            }
            case 3:{
                if((Jeu[3]==Jeu[4] && Jeu[5]==0) || (Jeu[3]==Jeu[5] && Jeu[4]==0))
                    s++;///cpature();
                if((Jeu[3]==Jeu[10] &&Jeu[18]==0) || (Jeu[3]==Jeu[18] && Jeu[10]==0) )
                    s++;
                break;
            }
            case 4:{
                if((Jeu[4]==Jeu[3] && 0==Jeu[5]) || (Jeu[4]==Jeu[5] && Jeu[3]==0) )
                    s++;///cpature();
                if((Jeu[4]==Jeu[1] &&0==Jeu[7]) || (Jeu[4]==Jeu[7] &&Jeu[1]==0 ))
                    s++;
                break;
            }
            case 5:{
                if((Jeu[5]==Jeu[4] && 0==Jeu[3]) || (Jeu[5]==Jeu[3] && Jeu[4]==0) )
                    s++;///cpature();
                if((Jeu[5]==Jeu[13] &&0==Jeu[20]) || (Jeu[5]==Jeu[20] &&Jeu[13]==0))
                    s++;
                break;
            }
            case 6:{
                if((Jeu[6]==Jeu[7] && 0==Jeu[8]) || (Jeu[6]==Jeu[8] && Jeu[7]==0))
                    s++;///cpature();
                if((Jeu[6]==Jeu[11] &&0==Jeu[15]) || (Jeu[6]==Jeu[15] &&Jeu[11]==0) )
                    s++;
                break;
            }
            case 7:{
                if((Jeu[7]==Jeu[4] && 0==Jeu[1]) || (Jeu[7]==Jeu[11] && Jeu[4]==0))
                    s++;///cpature();
                if((Jeu[7]==Jeu[6] &&0==Jeu[8]) || (Jeu[7]==Jeu[8] &&Jeu[6]==0))
                    s++;
                break;
            }
            case 8:{
                if((Jeu[8]==Jeu[7] && 0==Jeu[6]) || (Jeu[8]==Jeu[6] && Jeu[7]==0))
                    s++;///cpature();
                if((Jeu[8]==Jeu[12] &&0==Jeu[17]) || (Jeu[8]==Jeu[17] &&Jeu[12]==0))
                    s++;
                break;
            }
            case 9:{
                if((Jeu[9]==Jeu[10] && 0==Jeu[11]) || (Jeu[9]==Jeu[11] && Jeu[10]==0))
                    s++;///cpature();
                if((Jeu[9]==Jeu[0] &&0==Jeu[21]) || (Jeu[9]==Jeu[21] &&Jeu[0]==0))
                    s++;
                break;
            }
            case 10:{
                if((Jeu[10]==Jeu[9] && 0==Jeu[11]) || (Jeu[10]==Jeu[11] && Jeu[10]==0))
                    s++;///cpature();
                if((Jeu[10]==Jeu[3] &&0==Jeu[18]) || (Jeu[10]==Jeu[18] &&Jeu[3]==0))
                    s++;
                break;
            }
            case 11:{
                if((Jeu[11]==Jeu[6] && 0==Jeu[15]) || (Jeu[11]==Jeu[15] && Jeu[6]==0))
                    s++;///cpature();
                if((Jeu[11]==Jeu[10] &&0==Jeu[9]) || (Jeu[11]==Jeu[9] &&Jeu[10]==0))
                    s++;
                break;
            }
            case 12:{
                if((Jeu[12]==Jeu[13] && 0==Jeu[14] )|| (Jeu[12]==Jeu[14] && Jeu[13]==0))
                    s++;///cpature();
                if((Jeu[12]==Jeu[8] &&0==Jeu[17]) || (Jeu[12]==Jeu[17] &&Jeu[8]==0))
                    s++;
                break;
            }
            case 13:{
                if((Jeu[13]==Jeu[12] && 0==Jeu[14]) || (Jeu[13]==Jeu[14] && Jeu[12]==0))
                    s++;///cpature();
                if((Jeu[13]==Jeu[5] &&0==Jeu[20]) || (Jeu[13]==Jeu[20] &&Jeu[5]==0))
                    s++;
                break;
            }
            case 14:{
                if((Jeu[14]==Jeu[2] && 0==Jeu[23]) || (Jeu[14]==Jeu[23] && Jeu[2]==0))
                    s++;///cpature();
                if((Jeu[14]==Jeu[13] &&0==Jeu[12]) || (Jeu[14]==Jeu[12] &&Jeu[13]==0))
                    s++;
                break;
            }
            case 15:{
                if((Jeu[15]==Jeu[16] && 0==Jeu[17]) || (Jeu[15]==Jeu[17] && Jeu[16]==0))
                    s++;///cpature();
                if((Jeu[15]==Jeu[11] &&0==Jeu[6]) || (Jeu[15]==Jeu[6] &&Jeu[11]==0))
                    s++;
                break;
            }
            case 16:{
                if((Jeu[16]==Jeu[15] && 0==Jeu[17]) || (Jeu[16]==Jeu[17] && Jeu[15]==0))
                    s++;///cpature();
                if((Jeu[16]==Jeu[19] &&0==Jeu[22]) || (Jeu[16]==Jeu[22] &&Jeu[19]==0))
                    s++;
                break;
            }
            case 17:{
                if((Jeu[17]==Jeu[16] && 0==Jeu[15]) || (Jeu[17]==Jeu[15] && Jeu[16]==0))
                    s++;
                if((Jeu[17]==Jeu[12] &&0==Jeu[8]) || (Jeu[17]==Jeu[8] &&Jeu[12]==0))
                    s++;
                break;
            }
            case 18:{
                if((Jeu[18]==Jeu[19] && 0==Jeu[20]) || (Jeu[18]==Jeu[20] && Jeu[19]==0))
                    s++;
                if((Jeu[18]==Jeu[10] &&0==Jeu[3]) || (Jeu[18]==Jeu[3] &&Jeu[10]==0))
                    s++;
                break;
            }
            case 19:{
                if((Jeu[19]==Jeu[18] && 0==Jeu[20]) || (Jeu[19]==Jeu[20] && Jeu[18]==0))
                    s++;
                if((Jeu[19]==Jeu[16] &&0==Jeu[22]) || (Jeu[19]==Jeu[22] &&Jeu[16]==0))
                    s++;
                break;
            }
            case 20:{
                if((Jeu[20]==Jeu[19] && 0==Jeu[18]) || (Jeu[20]==Jeu[18] && Jeu[19]==0))
                    s++;
                if((Jeu[20]==Jeu[13] &&0==Jeu[5]) || (Jeu[20]==Jeu[5] &&Jeu[13]==0))
                    s++;
                break;
            }
            case 21:{
                if((Jeu[21]==Jeu[22] && 0==Jeu[23]) || (Jeu[21]==Jeu[23] && Jeu[22]==0))
                    s++;
                if((Jeu[21]==Jeu[9] &&0==Jeu[0]) || (Jeu[21]==Jeu[0] &&Jeu[9]==0))
                    s++;
                break;
            }
            case 22:{
                if((Jeu[22]==Jeu[21] && 0==Jeu[23]) || (Jeu[22]==Jeu[23] && Jeu[21]==0))
                    s++;
                if((Jeu[22]==Jeu[19] &&0==Jeu[16]) || (Jeu[22]==Jeu[16] &&Jeu[19]==0))
                    s++;
                break;
            }
            case 23:{
                if((Jeu[23]==Jeu[22] && 0==Jeu[21]) || (Jeu[23]==Jeu[21] && Jeu[22]==0))
                    s++;
                if((Jeu[23]==Jeu[14] &&0==Jeu[2]) || (Jeu[23]==Jeu[2] &&Jeu[14]==0))
                    s++;
                break;
            }
        }
        return s;
}

int pion_a_capturer(int T[24],int jou)
{
    int capt,s;
    captures_possibles* c=CreeListe2();
    generer_capture_possibles(c,jou,T);
    captur* e=c->first;
    capt=e->cap;
    s=free_moulins(T,e->cap);
    while(e)
    {
        if(s<free_moulins(T,e->cap))
        {
            s=free_moulins(T,e->cap);
            capt=e->cap;
        }
        e=e->suiv;
    }
    supprimer_liste_captures(c);
    return capt;
}


int mobile(int dep,int* Jeu)
{
  switch(dep-1)
    {
        case 0:{
            if(Jeu[9]==0 || Jeu[1]==0 )
                return 1;
            break;
        }
        case 1:{
            if(Jeu[0]==0 || Jeu[2]==0 || Jeu[4]==0)
                return 1;
            break;
        }
        case 2:{
            if( Jeu[1]==0 || Jeu[14]==0)
                return 1;
            break;
        }
        case 3:{
            if(Jeu[4]==0 || Jeu[10]==0)
                return 1;
            break;
        }
        case 4:{
            if(Jeu[1]==0 || Jeu[3]==0 || Jeu[5]==0 || Jeu[7]==0)
                return 1;
            break;
        }
        case 5:{
            if(Jeu[4]==0 || Jeu[13]==0)
                return 1;
            break;
        }
        case 6:{
            if(Jeu[7]==0 || Jeu[11]==0)
                return 1;
            break;
        }
        case 7:{
            if(Jeu[4]==0 || Jeu[6]==0 || Jeu[8]==0)
                return 1;
            break;
        }
        case 8:{
            if(Jeu[7]==0 || Jeu[12]==0)
                return 1;
            break;
        }
        case 9:{
            if(Jeu[0]==0 || Jeu[10]==0 || Jeu[21]==0)
                return 1;
            break;
        }
        case 10:{
            if(Jeu[3]==0 || Jeu[9]==0 || Jeu[11]==0 || Jeu[18]==0)
                return 1;
            break;
        }
        case 11:{
            if(Jeu[10]==0 ||Jeu[6]==0 || Jeu[15]==0)
                return 1;
            break;
        }
        case 12:{
            if(Jeu[8]==0 || Jeu[13]==0 || Jeu[17]==0)
                return 1;
            break;
        }
        case 13:{
            if(Jeu[5]==0 || Jeu[12]==0 || Jeu[14]==0 || Jeu[20]==0)
                return 1;
            break;
        }
        case 14:{
            if(Jeu[13]==0 || Jeu[2]==0 || Jeu[23]==0)
                return 1;
            break;
        }
        case 15:{
            if(Jeu[11]==0 || Jeu[16]==0 )
                return 1;
            break;
        }
        case 16:{
            if(Jeu[19]==0 || Jeu[15]==0 || Jeu[17]==0)
                return 1;
            break;
        }
        case 17:{
            if(Jeu[12]==0 || Jeu[16]==0 )
                return 1;
            break;
        }
        case 18:{
            if(Jeu[10]==0 || Jeu[19]==0 )
                return 1;
            break;
        }
        case 19:{
            if(Jeu[16]==0 || Jeu[18]==0 || Jeu[22]==0 || Jeu[20]==0)
                return 1;
            break;
        }
        case 20:{
            if(Jeu[13]==0 || Jeu[19]==0 )
                return 1;
            break;
        }
        case 21:{
            if(Jeu[9]==0 || Jeu[22]==0 )
                return 1;
            break;
        }
        case 22:{
            if(Jeu[19]==0 || Jeu[21]==0 || Jeu[23]==0)
                return 1;
            break;
        }
        case 23:{
            if(Jeu[14]==0 || Jeu[22]==0 )
                return 1;
            break;
        }
    }
    return 0;
}

void alphaBeta(int T[24],int depth,int max_palyer,int jou,int* coup,int* S,int alpha, int beta, int N)///maxplayer , prend en parametre true ou false
{

    int c;
    int s1;
    int temp[24];
    positions_possible* p=CreeListe1();       /// initialiser la liste juste creée p
    generer_positions_possibles(p,T,jou);
    if(N == 0)           /// lorsqu on arrive au dernier pion
    {
        if(max_palyer==1)
            *S=he(temp,jou);
        else
            *S=he(temp,3-jou);
        return;
    }
    //alpha=-MAX;
    //beta=+MAX;
    if(max_palyer==1)
        *S=-MAX;
    else
        *S=MAX;
    depth--;
    N--;
    position* e=p->first;
    while(e)          /* chaque boucle while  dans un apppel à minimax donne une ligne càd un niveau de noueds du mm père ayant le meme N */
    {
        copier(temp,T);
        pose(temp,e->pos,jou);
        if(tester_moulin(e->pos+1,temp) && pion_free(3-jou,temp)!=0)
        {
            int a=pion_a_capturer(temp,jou);
            capturer(temp,a,jou);
        }
        if(depth!=0)
            alphaBeta(temp,depth,1-max_palyer,3-jou,&c,&s1,alpha,beta,N);
        else               /// l'evaluation du feuille
            {
                if(max_palyer==1)
                    {
                        s1=he(temp,jou);
                    }
                else
                    {
                        s1=-he(temp,jou);
                        //return;
                    }
            }
        if(max_palyer==1)      /// la remonte
        {
            if(s1>=*S)
            {
                *S=s1;
                *coup=e->pos;
            }
            //*****//
            if(s1 > beta)
            	return; /// pour passer au noeud suivant du noeud-père
            else
            {
            	if(alpha <= s1)
            		alpha = s1;
            }
        }
        else{
            if(s1<=*S)
            {
                *S=s1;
                *coup=e->pos;
            }

            if ( s1 < alpha)
            	return;
            else
            {
            	if(beta >= s1)
            		beta = s1;

            }
        }
        e=e->suiv;
    }
    supprimer_liste_position(p);
}

void alphabeta2(int T[24],int depth,int max_player,int jou,int* dep,int* arrv,int alpha,int beta,int* S)
{
    int d,a;
    int s1;
    int temp[24];
    deplacements_possibles* p=CreeListe2();
    if(estBloquer(jou,T) || nbr_pion(jou,T)<=2)
    {
        if(max_player==1)
            *S=he(T,jou);
        else
            *S=-he(T,jou);
        return;
    }
    generer_deplacements_possibles(p,jou,T);
    if(max_player==1)
        *S=-MAX;
    else
        *S=MAX;
    depth--;
    deplacement* e=p->first;
    while(e)
    {
        /// générerer un nouveau noeud
        copier(temp,T);
        deplace(temp,e->dep,e->arr,jou);
        if(tester_moulin(e->arr+1,temp) && (pion_free(3-jou,temp)!=0))
            {
                int a=pion_a_capturer(temp,jou);
                capturer(temp,a,jou);

            }
        if(depth!=0)
            alphabeta2(temp,depth,1-max_player,3-jou,&d,&a,alpha,beta,&s1);
        else
            {
                if(max_player==1)
                    s1=he(temp,jou);
                else
                    s1=-he(temp,jou);
            }
        if(max_player==1)
        {
            if(s1>=*S)
            {
                *S=s1;
                *dep=e->dep;
                *arrv=e->arr;
            }
            if(s1 > beta)
            	return; /// pour passer au noeud suivant du noeud-père
            else
            {
            	if(alpha <= s1)
            		alpha = s1;
            }
        }
        else{
            if(s1<=*S)
            {
                *S=s1;
                *dep=e->dep;
                *arrv=e->arr;
            }
            if ( s1 < alpha)
            	return;
            else
            {
            	if(beta >= s1)
            		beta = s1;

            }
        }
        e=e->suiv;
    }
}

///________________________________SDL/////////////////////////////////////////////
int init(SDL_Window **window, SDL_Renderer **renderer, int w, int h)
{
    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        return -1;
    }
    if(0 != SDL_CreateWindowAndRenderer(w, h, SDL_WINDOW_SHOWN, window, renderer))
    {
        fprintf(stderr, "Erreur SDL_CreateWindowAndRenderer : %s", SDL_GetError());
        return -1;
    }
    return 0;
}

int setWindowColor(SDL_Renderer *renderer, SDL_Color color)
{
    if(SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a) < 0)
        return -1;
    if(SDL_RenderClear(renderer) < 0)
        return -1;
    return 0;
}

SDL_Texture *loadImage(const char path[], SDL_Renderer *renderer)
{
    SDL_Surface *tmp = NULL;
    SDL_Texture *texture = NULL;
    tmp = SDL_LoadBMP(path);
    if(NULL == tmp)
    {
        fprintf(stderr, "Erreur SDL_LoadBMP : %s", SDL_GetError());
        return NULL;
    }
    texture = SDL_CreateTextureFromSurface(renderer, tmp);
    SDL_FreeSurface(tmp);
    if(NULL == texture)
    {
        fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s", SDL_GetError());
        return NULL;
    }
    return texture;
}
//
void poser_pion(SDL_Renderer* ecran,int coup,int j){
    SDL_Texture* pion= NULL;
    SDL_Rect dst;
    dst.h=dst.w=56;
    if(j==1){pion=loadImage("images/pion2.bmp",ecran);}
    else{pion=loadImage("images/pion1.bmp",ecran);}
    switch(coup){
    case 1:
        dst.x=34;dst.y=27;SDL_RenderCopy(ecran,pion,NULL,&dst);
        break;
    case 2:
        dst.x=284;dst.y=27;SDL_RenderCopy(ecran,pion,NULL,&dst);
        break;
    case 3:
        dst.x=535;dst.y=27;SDL_RenderCopy(ecran,pion,NULL,&dst);
        break;
    case 4:
        dst.x=118;dst.y=111;SDL_RenderCopy(ecran,pion,NULL,&dst);
        break;
    case 5:
        dst.x=285;dst.y=111;SDL_RenderCopy(ecran,pion,NULL,&dst);
        break;
    case 6:
        dst.x=454;dst.y=111;SDL_RenderCopy(ecran,pion,NULL,&dst);
        break;
    case 7:
        dst.x=202;dst.y=191;SDL_RenderCopy(ecran,pion,NULL,&dst);
        break;
    case 8:
        dst.x=285;dst.y=191;SDL_RenderCopy(ecran,pion,NULL,&dst);
        break;
    case 9:
        dst.x=370;dst.y=191;SDL_RenderCopy(ecran,pion,NULL,&dst);
        break;
    case 10:
        dst.x=34;dst.y=274;SDL_RenderCopy(ecran,pion,NULL,&dst);
        break;
    case 11:
        dst.x=118;dst.y=274;SDL_RenderCopy(ecran,pion,NULL,&dst);
        break;
    case 12:
        dst.x=203;dst.y=274;SDL_RenderCopy(ecran,pion,NULL,&dst);
        break;
    case 13:
        dst.x=370;dst.y=274;SDL_RenderCopy(ecran,pion,NULL,&dst);
        break;
    case 14:
        dst.x=454;dst.y=275;SDL_RenderCopy(ecran,pion,NULL,&dst);
        break;
    case 15:
        dst.x=534;dst.y=274;SDL_RenderCopy(ecran,pion,NULL,&dst);
        break;
    case 16:
        dst.x=203;dst.y=357;SDL_RenderCopy(ecran,pion,NULL,&dst);
        break;
    case 17:
        dst.x=283;dst.y=357;SDL_RenderCopy(ecran,pion,NULL,&dst);
        break;
    case 18:
        dst.x=371;dst.y=357;SDL_RenderCopy(ecran,pion,NULL,&dst);
        break;
    case 19:
        dst.x=118;dst.y=439;SDL_RenderCopy(ecran,pion,NULL,&dst);
        break;
    case 20:
        dst.x=284;dst.y=438;SDL_RenderCopy(ecran,pion,NULL,&dst);
        break;
    case 21:
        dst.x=453;dst.y=439;SDL_RenderCopy(ecran,pion,NULL,&dst);
        break;
    case 22:
        dst.x=34;dst.y=521;SDL_RenderCopy(ecran,pion,NULL,&dst);
        break;
    case 23:
        dst.x=283;dst.y=521;SDL_RenderCopy(ecran,pion,NULL,&dst);
        break;
    case 24:
        dst.x=534;dst.y=521;SDL_RenderCopy(ecran,pion,NULL,&dst);
        break;
    }
}


void actualiser(SDL_Renderer* t,SDL_Texture* i,int* P,int N1,int N2){
    SDL_Rect dst = {0, 0, 1200, 650};
    SDL_RenderCopy(t,i, NULL, &dst);
    for(int i=0;i<24;i++){
        if(P[i]!=0){
            poser_pion(t,i+1,P[i]);
        }
    }
    if(N1!=0 || N2!=0)
    {
        SDL_Texture* pi=loadImage("images/pions.bmp",t);
        SDL_Texture* p1=loadImage("images/pion2.bmp",t);
        SDL_Texture* p2=loadImage("images/pion1.bmp",t);
        SDL_Rect pi1;
        SDL_Rect pi2;
        pi1.x=594;pi1.y=321;pi1.w=239;pi1.h=211;
        pi2.x=951;pi2.y=321;pi2.w=239;pi2.h=211;
        SDL_Rect d1[9]={{625,342,56,56},{687,342,56,56},{749,342,56,56},{625,404,56,56},{687,404,56,56},{749,404,56,56},{625,466,56,56},{687,466,56,56},{749,466,56,56}};
        SDL_Rect d2[9]={{982,342,56,56},{1044,342,56,56},{1106,342,56,56},{982,404,56,56},{1044,404,56,56},{1106,404,56,56},{982,466,56,56},{1044,466,56,56},{1106,466,56,56}};
        SDL_RenderCopy(t,pi,NULL,&pi1);
        SDL_RenderCopy(t,pi,NULL,&pi2);
        for(int i=0;i<N1;i++)
            SDL_RenderCopy(t,p1,NULL,&d1[i]);
        for(int i=0;i<N2;i++)
            SDL_RenderCopy(t,p2,NULL,&d2[i]);
    }
    SDL_RenderPresent(t);
}


int cellule(int pion, int* P){
        if(event.button.x>=38 && event.button.x<=38+45 && event.button.y>=30 && event.button.y<=30+45 && P[0]==pion)
            return 1;
        if(event.button.x>=289 && event.button.x<=289+45 && event.button.y>=30 && event.button.y<=30+45 && P[1]==pion)
            return 2;
        if(event.button.x>=539 && event.button.x<=539+45 && event.button.y>=30 && event.button.y<=30+45 && P[2]==pion)
            return 3;
        if(event.button.x>=123 && event.button.x<=123+45 && event.button.y>=116 && event.button.y<=116+45 && P[3]==pion)
            return 4;
        if(event.button.x>=289 && event.button.x<=289+45 && event.button.y>=116 && event.button.y<=116+45 && P[4]==pion)
            return 5;
        if(event.button.x>=458 && event.button.x<=458+45 && event.button.y>=116 && event.button.y<=116+45 && P[5]==pion)
            return 6;
        if(event.button.x>=208 && event.button.x<=208+45 && event.button.y>=195 && event.button.y<=195+45 && P[6]==pion)
            return 7;
        if(event.button.x>=289 && event.button.x<=289+45 && event.button.y>=195 && event.button.y<=195+45 && P[7]==pion)
            return 8;
        if(event.button.x>=375 && event.button.x<=375+45 && event.button.y>=195 && event.button.y<=195+45 && P[8]==pion)
            return 9;
        if(event.button.x>=38 && event.button.x<=38+45 && event.button.y>=278 && event.button.y<=278+45 && P[9]==pion)
            return 10;
        if(event.button.x>=123 && event.button.x<=123+45 && event.button.y>=279 && event.button.y<=279+45 && P[10]==pion)
            return 11;
        if(event.button.x>=208 && event.button.x<=208+45 && event.button.y>=279 && event.button.y<=279+45 && P[11]==pion)
            return 12;
        if(event.button.x>=375 && event.button.x<=375+45 && event.button.y>=279 && event.button.y<=279+45 && P[12]==pion)
            return 13;
        if(event.button.x>=458 && event.button.x<=458+45 && event.button.y>=279 && event.button.y<=279+45 && P[13]==pion)
            return 14;
        if(event.button.x>=539 && event.button.x<=539+45 && event.button.y>=278 && event.button.y<=278+45 && P[14]==pion)
            return 15;
        if(event.button.x>=208 && event.button.x<=208+45 && event.button.y>=361 && event.button.y<=361+45 && P[15]==pion)
            return 16;
        if(event.button.x>=289 && event.button.x<=289+45 && event.button.y>=361 && event.button.y<=361+45 && P[16]==pion)
            return 17;
        if(event.button.x>=375 && event.button.x<=375+45 && event.button.y>=361 && event.button.y<=361+45 && P[17]==pion)
            return 18;
        if(event.button.x>=123 && event.button.x<=123+45 && event.button.y>=443 && event.button.y<=443+45 && P[18]==pion)
            return 19;
        if(event.button.x>=289 && event.button.x<=289+45 && event.button.y>=443 && event.button.y<=443+45 && P[19]==pion)
            return 20;
        if(event.button.x>=458 && event.button.x<=458+45 && event.button.y>=443 && event.button.y<=443+45 && P[20]==pion)
            return 21;
        if(event.button.x>=38 && event.button.x<=38+45 && event.button.y>=525 && event.button.y<=525+45 && P[21]==pion)
            return 22;
        if(event.button.x>=289 && event.button.x<=289+45 && event.button.y>=525 && event.button.y<=525+45 && P[22]==pion)
            return 23;
        if(event.button.x>=539 && event.button.x<=539+45 && event.button.y>=525 && event.button.y<=525+45 && P[23]==pion)
            return 24;
        if(event.button.x>=1100 && event.button.x<=1100+100 && event.button.y>=0 && event.button.y<=38)
            return 25;
        if(event.button.x>=1000 && event.button.x<=1000+100 && event.button.y>=0 && event.button.y<=38)
            return 26;
        return 0;
}

int jouer(SDL_Renderer* r,SDL_Texture* t)
{
    int Jeu[24];
    int jou=1,jou1=1,jou2=2;
	char j1[9],j2[9],j[9];
    int N=18,N1=9,N2=9,k=0,ca=1,ca1=0;
    int max_palyer;
    int pos;
    int dep, arr,dep1,arr1;
    SDL_Rect d;
    d.x=780;d.y=50;d.w=200;d.h=300;
    SDL_Texture* reg1=loadImage("images/phase1.bmp",r);
    SDL_Texture* reg2=loadImage("images/phase2.bmp",r);
    SDL_Texture* player1=loadImage("images/pion2.bmp",r);
    int coup, S,i=0;
    for(k=0;k<24;k++)
        Jeu[k]=0;
    int a=first_palyer(r);
    if(a==2)
    {
        jou1=2;     /// le premier joueur sera la machine
        jou2=1;
    }
    if (a==1) /// l'humain qui commence
        jou=1;
    else if(a==2) ///
        jou=2;
    while(N>0){
    	if(jou==1)
    	{
            actualiser(r,t,Jeu,N1,N2);/// la position initiale === la grille vide
            SDL_RenderCopy(r,reg1,NULL,&d);
            SDL_RenderPresent(r);
            while(event.type!=SDL_MOUSEMOTION){SDL_WaitEvent(&event);}
            SDL_WaitEvent(&event);coup=cellule(0,Jeu);
            while(event.button.button!=SDL_BUTTON_LEFT || coup==0){
                SDL_WaitEvent(&event);
                coup=cellule(0,Jeu);
                }
            if(coup==25)
                return 1;
            if(coup==26)
                return 0;
            pose(Jeu,coup-1,jou);
            actualiser(r,t,Jeu,N1,N2);
            SDL_RenderCopy(r,reg1,NULL,&d);
            SDL_RenderPresent(r);
            if(tester_moulin(coup,Jeu) && pion_free(3-jou,Jeu)!=0)
            {
                while(tester_moulin(coup,Jeu)){
                    SDL_WaitEvent(&event);
                    coup=cellule(3-jou,Jeu);
                    while(event.button.button!=SDL_BUTTON_LEFT || coup==0){
                            SDL_WaitEvent(&event);
                            coup=cellule(3-jou,Jeu);
                    }
                if(coup==25)
                        return 0;
                if(coup==26)
                    return 1;
            }
            Jeu[coup-1]=0;
            }
            N--;
            N1--;
            jou=3-jou;
        }
        else if(jou==2)
        {
            actualiser(r,t,Jeu,N1,N2);
            SDL_RenderCopy(r,reg1,NULL,&d);
            SDL_RenderPresent(r);
        	max_palyer=1;
        	alphaBeta(Jeu,5,max_palyer,jou,&coup,&S,-MAX,MAX,N);
            pose(Jeu,coup,jou);
            if(tester_moulin(coup+1,Jeu) && pion_free(3-jou,Jeu)!=0)
            {
                int ca=pion_a_capturer(Jeu,jou);
                capturer(Jeu,ca,jou);
            }
            jou=3-jou;
            N--;
            N2--;
        }
    }
    ///____________________Phase de déplacement_________________/////////////

     while( !estBloquer(jou,Jeu) && nbr_pion(jou,Jeu)>2)
    {
        actualiser(r,t,Jeu,0,0);
        SDL_RenderCopy(r,reg2,NULL,&d);
        SDL_RenderPresent(r);
        int de,a;
        SDL_Rect dst;
        dst.w=dst.h=56;
        dst.x=0;
        dst.y=0;
        if(jou==1)
    	{
        while(event.type!=SDL_MOUSEMOTION)
            SDL_WaitEvent(&event);
        SDL_WaitEvent(&event);
        coup=cellule(jou,Jeu);
        while(event.button.button!=SDL_BUTTON_LEFT || coup==0){///choisir un pion
            SDL_WaitEvent(&event);
            coup=cellule(jou,Jeu);
        }
        if(coup==25)
            return 0;
        if(coup==26)
            return 1;
        while(!mobile(coup,Jeu))
        {///tester le pion choisi (deplaceble ou non)
            while(event.type!=SDL_MOUSEMOTION)
                SDL_WaitEvent(&event);
            SDL_WaitEvent(&event);
            coup=cellule(jou,Jeu);
            while(event.button.button!=SDL_BUTTON_LEFT || coup==0){
                SDL_WaitEvent(&event);
                coup=cellule(jou,Jeu);
                }
            if(coup==25)
                return 0;
            if(coup==26)
                return 1;
            if(nbr_pion(jou,Jeu) == 3)
                break;
        }
        de=coup;
        Jeu[de-1]=0;
        actualiser(r,t,Jeu,0,0);
        SDL_RenderCopy(r,reg2,NULL,&d);
        SDL_RenderPresent(r);
        SDL_WaitEvent(&event);
        while(event.type!=SDL_MOUSEMOTION)
            SDL_WaitEvent(&event);
        while(event.button.button!=SDL_BUTTON_LEFT && event.button.button!=SDL_BUTTON_RIGHT){
            SDL_WaitEvent(&event);
            dst.x=event.motion.x-28;
            dst.y=event.motion.y-28;
            actualiser(r,t,Jeu,0,0);
            SDL_RenderCopy(r,reg2,NULL,&d);
            SDL_RenderCopy(r, player1, NULL, &dst);
            SDL_RenderPresent(r);
        }
        if(event.button.button==SDL_BUTTON_LEFT){///tester sur la destination
            a=cellule(0,Jeu);
            if(a==25)
                return 0;
            if(a==26)
                return 1;
            if( nbr_pion(jou,Jeu)+1<=3 && a!=0 && a!=de )
                goto B;
            if(a==0 || !deplaceable(de,a)){
                Jeu[de-1]=jou;
                actualiser(r,t,Jeu,0,0);
                SDL_RenderCopy(r,reg2,NULL,&d);
                SDL_RenderPresent(r);
                continue;
                }
        }
        B:
        Jeu[a-1]=jou;
        actualiser(r,t,Jeu,0,0);
        SDL_RenderCopy(r,reg2,NULL,&d);
        SDL_RenderPresent(r);
        if(tester_moulin(a,Jeu) && pion_free(3-jou,Jeu)!=0)
            {
                while(tester_moulin(a,Jeu)){
                    SDL_WaitEvent(&event);
                    a=cellule(3-jou,Jeu);
                    while(event.button.button!=SDL_BUTTON_LEFT || a==0){
                            SDL_WaitEvent(&event);
                            a=cellule(3-jou,Jeu);
                    }
                if(a==25)
                        return 0;
                if(a==26)
                    return 1;
            }
            Jeu[a-1]=0;
            }
        jou=3-jou;
        }
    	else
        {
            max_palyer=1;
            alphabeta2(Jeu,5,max_palyer,jou,&dep1,&arr1,-MAX,MAX,&S);
            deplace(Jeu,dep1,arr1,jou);
            actualiser(r,t,Jeu,0,0);
            SDL_RenderCopy(r,reg2,NULL,&d);
            SDL_RenderPresent(r);
            SDL_Delay(1000);
            if(tester_moulin(arr1+1,Jeu) && pion_free(3-jou,Jeu)!=0)
            {
                int ca=pion_a_capturer(Jeu,jou);
                capturer(Jeu,ca,jou);
            }
            jou=3-jou;
        }
    }
    SDL_Texture* rej=loadImage("images/rejouer.bmp",r);
    SDL_Rect f={0,0,1200,650};
    SDL_RenderCopy(r,rej,NULL,&f);
    SDL_RenderPresent(r);
    int e=0;
    while(1)
    {
        SDL_WaitEvent(&event);
        if(event.type==SDL_MOUSEMOTION){e=1;}
        if(event.type==SDL_QUIT || (e==1 && event.button.button==SDL_BUTTON_LEFT && event.button.y>=440 && event.button.y<=520 && event.button.x>=291 && event.button.x<=477))
        {
            break;
        }
        if(event.type==SDL_QUIT || (e==1 && event.button.button==SDL_BUTTON_LEFT && event.button.y>=440 && event.button.y<=520 && event.button.x>=723 && event.button.x<=910))
        {
            break;
        }
    }
}


