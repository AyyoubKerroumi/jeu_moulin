#include "focntions.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>
#include <time.h>
#define RET 13
#define MAX 1000


extern int Jeu[24]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};///Tableau de 24 cases(les positions du jeu)
                ///0 si la case est vide , 1 s'il est rempli par un pion du joueur 1, 2 sinon;
int compteur=0;
extern int P1[9]={1,1,1,1,1,1,1,1,1};
extern int P2[9]={2,2,2,2,2,2,2,2,2};
char *menu1[]={"1.Jouer","2.Regles de jeu","3.Quitter"};
char *menu2[]={"1.J vs M","2.Retour","3-Quitter"};
char *menu3[]={"1.Moyen","2.Difficile"};
int larg,haut,l,h,dx,dy,clf,clc,clt,clf_m,clc_m,clt_m,x0,y0,nbr_tache,nbr_tache2,nbr_tache3;
void color(int t,int f){
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}

void setcurseur(int x,int y){ //fonction de positionner le curseur
	COORD pos;
	pos.X=x;
	pos.Y=y;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hStdOut,pos);
	return;
}

void init(void){
	int k;
	nbr_tache=3;
	x0=45,y0=10;
	dx=2,dy=1;
	l=20,h=3;
	larg=l+(2*dx);
	haut=(nbr_tache*h)+((nbr_tache+1)*dy);
	clc=11,clf=0,clt=13;
	clc_m=14,clf_m=0,clt_m=3;

	fen2d(x0,y0,larg,haut,clf,clc,1,"  ",1);

	for(k=0;k<nbr_tache;k++)
		fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf,clc,clt,menu1[k],1);

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void init2(void){
	int k;
	nbr_tache2=3;
	x0=45,y0=10;
	dx=2,dy=1;
	l=20,h=3;
	larg=l+(2*dx);
	haut=(nbr_tache2*h)+((nbr_tache2+1)*dy);
	clc=11,clf=0,clt=13;
	clc_m=14,clf_m=0,clt_m=3;

	fen2d(x0,y0,larg,haut,clf,clc,1,"  ",1);

	for(k=0;k<nbr_tache2;k++)
		fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf,clc,clt,menu2[k],1);

}

void init3(void){
	int k;
    nbr_tache3=2;
	x0=45,y0=10;
	dx=2,dy=1;
	l=25,h=3;
	larg=l+(2*dx);
	haut=(nbr_tache3*h)+((nbr_tache3+1)*dy);
	clc=11,clf=0,clt=13;
	clc_m=14,clf_m=0,clt_m=3;

	fen2d(x0,y0,larg,haut,clf,clc,1,"  ",1);

	for(k=0;k<nbr_tache3;k++)
		fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf,clc,clt,menu3[k],1);

}

void fen1d(int x,int y,int l,int h,int clf,int clc,int clt, char c){
	int i,j;
	color(clf,clf);
	for(i=0;i<l;i++){
		for(j=1;j<h;j++){
			setcurseur(x+i,y+j);
			printf(" ");
		}
	}
	color(clc,clf);
	for(i=0;i<l-1;i++){
		setcurseur(x+i,y);
	    printf("%c",205);
		setcurseur(x+i,y+h-1);
	    printf("%c",205);}

	for(j=1;j<h-1;j++){
			setcurseur(x,y+j);
			printf("%c",186);
			setcurseur(x+l-1,y+j);
			printf("%c",186);
		}
	setcurseur(x,y);
	printf("%c",201);
	setcurseur(x,y+h-1);
	printf("%c",200);
	setcurseur(x+l-1,y);
	printf("%c",187);
	setcurseur(x+l-1,y+h-1);
	printf("%c",188);
	color(clt,clf);
	setcurseur(x+(int)((l)/2),y+h/2);
	printf("%c",c);
}

void jouer()
{
	init2();
	gestion2();
}

void retour()
{
    color(1,0);
    system("cls");
    bienvenue();
    init();
    gestion();
}

void jouer2()
{
    system("cls");
    bienvenue();
	init3();
	gestion3();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void fen2d(int x,int y,int l,int h,int clf,int clc,int clt, char ch[20],int choix){
	int i,j,n;
	color(clf,clf);
	for(i=0;i<l;i++){
		for(j=1;j<h;j++){
			setcurseur(x+i,y+j);
			printf(" ");
		}
	}
	color(clc,clf);
	for(i=0;i<l-1;i++){
		setcurseur(x+i,y);
	    printf("%c",205);
		setcurseur(x+i,y+h-1);
	    printf("%c",205);}

	for(j=1;j<h-1;j++){
			setcurseur(x,y+j);
			printf("%c",186);
			setcurseur(x+l-1,y+j);
			printf("%c",186);
		}
	setcurseur(x,y);
	printf("%c",201);
	setcurseur(x,y+h-1);
	printf("%c",200);
	setcurseur(x+l-1,y);
	printf("%c",187);
	setcurseur(x+l-1,y+h-1);
	printf("%c",188);
	color(clt,clf);
	n=strlen(ch);
	switch(choix){
		case 0: setcurseur(x+1,y+1);
		        printf("%s",ch);
		        break;
		case 1: setcurseur(x+(int)((l-n)/2),y+h/2);
		        printf("%s",ch);
				break;
		case 2: setcurseur(x,y+h/2);
		        printf("%s",ch);
				break;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int menuu1(void){
	int k;
	char c;
	k=0;
	fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf_m,clc_m,clt_m,menu1[k],1);

	do{
		c=getch();
		switch(c){
			case 'P': fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf,clc,clt,menu1[k],1);
					  k++;
					  if(k==nbr_tache) k=0;
					  fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf_m,clc_m,clt_m,menu1[k],1);
					  break;
			case 'H': fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf,clc,clt,menu1[k],1);
					  if(k==0) k=nbr_tache;
					  k--;
					  fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf_m,clc_m,clt_m,menu1[k],1);
					  break;
			case RET: fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf,clc,clt,"",1);
					  return k;
		}
	}while(c!='x');
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void gestion(){
	int a;
	do{
		a=menuu1();
		fen2d(x0+dx,y0+dy+a*(h+dy),l,h,clf,clc,clt,menu1[a],1);
		switch(a){
			case 0 :jouer();
					 break;
			case 1 :regles_de_jeu();
                    break;
			case 2 :color(15,0);system("cls");exit(1);
		  			 break;
		}
	}while(a!=nbr_tache);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int menuu2(void){
	int k;
	char c;
	k=0;
	fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf_m,clc_m,clt_m,menu2[k],1);

	do{
		c=getch();
		switch(c){
			case 'P': fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf,clc,clt,menu2[k],1);
					  k++;
					  if(k==nbr_tache2) k=0;
					  fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf_m,clc_m,clt_m,menu2[k],1);
					  break;
			case 'H': fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf,clc,clt,menu2[k],1);
					  if(k==0) k=nbr_tache2;
					  k--;
					  fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf_m,clc_m,clt_m,menu2[k],1);
					  break;
			case RET: return k;
		}
	}while(c!='x');
}
////////////////////////////////////////////////////////////////////////////////////////////////////

void gestion2(){
	int a;
	do{
		a=menuu2();
		fen2d(x0+dx,y0+dy+a*(h+dy),l,h,clf,clc,clt,menu2[a],1);
		switch(a){
			case 0 :jouer2();
		  			 break;
			case 1 :retour();
		  			 break;
			case 2 :color(15,0);exit(1);
		  			 break;
		}
	}while(a!=nbr_tache2);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int menuu3(void){
	int k;
	char c;
	k=0;
	fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf_m,clc_m,clt_m,menu3[k],1);

	do{
		c=getch();
		switch(c){
			case 'P': fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf,clc,clt,menu3[k],1);
					  k++;
					  if(k==nbr_tache3) k=0;
					  fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf_m,clc_m,clt_m,menu3[k],1);
					  break;
			case 'H': fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf,clc,clt,menu3[k],1);
					  if(k==0) k=nbr_tache3;
					  k--;
					  fen2d(x0+dx,y0+dy+k*(h+dy),l,h,clf_m,clc_m,clt_m,menu3[k],1);
					  break;
			case RET: return k;
		}
	}while(c!='x');
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void gestion3(){
	int a;
	do{
		a=menuu3();
		fen2d(x0+dx,y0+dy+a*(h+dy),l,h,clf,clc,clt,menu3[a],1);
		switch(a){
			case 0 :jvsmachine();
					 break;
			case 1 :jvsmachine2();
		  			 break;

		}
	}while(a!=nbr_tache3);
}

void bienvenue(){
    system("cls");
    color(9,0);
    printf("                            \t\t\t***Bienvenue au Moulin!***\n");
    //printf("                   \n");
    color(12,0);
    printf("\t\t\t\t"); printf(" __________________________________________________\n");
    printf("\t\t\t\t"); printf("|                                                  |\n");
    printf("\t\t\t\t"); printf("|   *       * ******* *    * *     * *       *     |\n");
    printf("\t\t\t\t"); printf("|   * *   * * *     * *    * *     * * *     *     |\n");
    printf("\t\t\t\t"); printf("|   *   *   * *     * *    * *     * *   *   *     |\n");
    printf("\t\t\t\t"); printf("|   *       * *     * *    * *     * *     * *     |\n");
    printf("\t\t\t\t"); printf("|   *       * ******* ****** ***** * *       *     |\n");
    printf("\t\t\t\t"); printf("|__________________________________________________|");
    printf("\t\t\t\t"); printf("\n\n\n\n");
    color(15,0);
}
//////////////////////////////////////////////////////////////////////////////////////

void grille(int Jeu[24])
{
    system("cls");
    int i=-1;
    char c=0;
    printf("\n");
    printf("\t\t\t\t\t\t\t");
    afficher_pion(++c,Jeu[++i]);///1
    printf("------------------------");
    afficher_pion(++c,Jeu[++i]);///2
    printf("-------------------------");
    afficher_pion(++c,Jeu[++i]);///3
    color(15,0);
    printf("\t\n");
    printf("\t\t\t\t\t\t\t|                        |                         |\n");
    printf("\t\t\t\t\t\t\t|                        |                         |\n");
    printf("\t\t\t\t\t\t\t|                        |                         |\n");
    printf("\t\t\t\t\t\t\t|       ");
    afficher_pion(++c,Jeu[++i]);///4
    printf("----------------");
    afficher_pion(++c,Jeu[++i]);///5
    printf("-----------------");
    afficher_pion(++c,Jeu[++i]);///6
    printf("       |\n");
    printf("\t\t\t\t\t\t\t|       |                |                 |       |\n");
    printf("\t\t\t\t\t\t\t|       |                |                 |       |\n");

    printf("\t\t\t\t\t\t\t|       |      ");
    afficher_pion(++c,Jeu[++i]);///7
    printf("---------");
    afficher_pion(++c,Jeu[++i]);///8
    printf("---------");
    afficher_pion(++c,Jeu[++i]);///9
    printf("       |       |\n");


    printf("\t\t\t\t\t\t\t|       |      |                   |       |       |\n");
    printf("\t\t\t\t\t\t\t|       |      |                   |       |       |\n");
    printf("\t\t\t\t\t\t\t|       |      |                   |       |       |\n");

    printf("\t\t\t\t\t\t       ");
    afficher_pion(++c,Jeu[++i]);///10
    printf("------");
    afficher_pion(++c,Jeu[++i]);///11
    printf("-----");
    afficher_pion(++c,Jeu[++i]);///12
    printf("                  ");
    afficher_pion(++c,Jeu[++i]);///13
    printf("------");
    afficher_pion(++c,Jeu[++i]);///14
    printf("------");
    afficher_pion(++c,Jeu[++i]);///15
    printf(" \n");
    printf("\t\t\t\t\t\t\t|       |      |                   |       |       |\n");
    printf("\t\t\t\t\t\t\t|       |      |                   |       |       |\n");
    printf("\t\t\t\t\t\t\t|       |      |                   |       |       |\n");

    printf("\t\t\t\t\t\t\t|       |     ");
    afficher_pion(++c,Jeu[++i]);///16
    printf("--------");
    afficher_pion(++c,Jeu[++i]);///17
    printf("--------");
    afficher_pion(++c,Jeu[++i]);///18
    printf("       |       |\n");

    printf("\t\t\t\t\t\t\t|       |                |                 |       |\n");
    printf("\t\t\t\t\t\t\t|       |                |                 |       |\n");

    printf("\t\t\t\t\t\t\t|      ");
    afficher_pion(++c,Jeu[++i]);///19
    printf("---------------");
    afficher_pion(++c,Jeu[++i]);///20
    printf("----------------");
    afficher_pion(++c,Jeu[++i]);///21
    printf("       |\n");

    printf("\t\t\t\t\t\t\t|                        |                         |\n");
    printf("\t\t\t\t\t\t\t|                        |                         |\n");
    printf("\t\t\t\t\t\t\t|                        |                         |\n");

    printf("\t\t\t\t\t\t       ");
    afficher_pion(++c,Jeu[++i]);///22
    printf("-----------------------");
    afficher_pion(++c,Jeu[++i]);///23
    printf("------------------------");
    afficher_pion(++c,Jeu[++i]);///24
    printf("\n");
}


void afficher_pion(int c,int pion)
{
    if(pion==2)
    {
        color(15,4);
        printf("%d",c);
    }
    else if(pion==1)
    {
        color(15,1);
        printf("%d",c);
    }
    else
    {
        printf("%d",c);
    }
    color(15,0);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void  jouer_coup(int j,int *pos,int Jeu[24]){
  		A:
  		printf("donnez la position ou vous voulez poser votre pion \n" );
  		scanf("%d",pos);
  		if(*pos>=1 && *pos<=24)
        {
            if(Jeu[*pos-1]==0){
                if(j==1){
                Jeu[*pos-1] = 1;
                }
                else if(j==2){
                Jeu[*pos-1] = 2;
                }
            }
        }
  		else
  			{
  			    fflush(stdin);
  			    goto A;
  			}

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

void capture(int j,int Jeu[24])
{
    int pos;
    if(pion_free(3-j,Jeu)==0)
    {
        printf("vous ne pouvez supprimer aucun pion adverse!!!\n");
        Sleep(12);
        return;
    }
    A:
    printf("elever un pion adverse:");
    scanf("%d",&pos);
    if(pos<1 || pos>24)
    {
        printf("Merci de donner une position valide\n");
        goto A;
    }
    if(Jeu[pos-1]!=3-j)
    {
        printf("Merci de choisir un des pions de votre adversaire !\n");
        goto A;
    }
    if(tester_moulin(pos,Jeu))
    {
        printf("Ce pion fait parti d'un moulin, vous ne pouvez pas le supprimer.\n");
        goto A;
    }
    Jeu[pos-1]=0;
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

/** à ne pas applique que si les 9 pions deja posés */
void deplacer(int dep, int *arr, int j,int Jeu[24])
{

    A:
    printf("donnez la position du pion que vous voulez deplacer \n" );
    scanf("%d",&dep);
    if(Jeu[dep-1]!=j)
    {
        printf("veuillez choisir un parmi de vos pions\n");
        goto A;
    }
    printf("donnez la position ou vous voulez deplacer votre pion \n" );
    scanf("%d",arr);
    if(nbr_pion(j) > 3)
    {
        if(!(deplaceable(dep,*arr) && Jeu[*arr-1]==0))
        {
            printf("Merci de deplacer le pion vers un voisin vide \n");
            goto A;
        }


        if(deplaceable(dep,*arr) && Jeu[*arr-1]==0)
        {
            Jeu[dep-1] = 0;
            Jeu[*arr-1] = j;
        }
    }
    else{
        if(Jeu[*arr-1]!=0)
            {
                printf("Merci de deplacer le pion vers une position vide \n");
                goto A;
            }
            Jeu[dep-1] = 0;
            Jeu[*arr-1] = j;
    }
}

/********************/
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
            if(Jeu[i]==jou && deplaceable(i,j))
                return 0;
    }
    return 0;
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
        compteur++;
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


void minimax2(int T[24],int depth,int max_player,int jou,int* dep,int* arrv,int* S)
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
        compteur++;
        copier(temp,T);
        deplace(temp,e->dep,e->arr,jou);
        if(tester_moulin(e->arr+1,temp) && (pion_free(3-jou,temp)!=0))
            {
                int a=pion_a_capturer(temp,jou);
                capturer(temp,a,jou);

            }
        if(depth!=0)
            minimax2(temp,depth,1-max_player,3-jou,&d,&a,&s1);
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
        }
        else{
            if(s1<=*S)
            {
                *S=s1;
                *dep=e->dep;
                *arrv=e->arr;
            }
        }
        e=e->suiv;
    }
}


void jvsmachine()
{
    system("cls");
    color(15,0);
    int Jeu[24];
    int jou=1,jou1=1,jou2=2;
	char j1[9],j2[9],j[9];
    int N=18,k=0,ca=1,ca1=0;
    int max_palyer;
    int pos;
    int dep, arr,dep1,arr1;
    int coup, S,i=0;
    for(k=0;k<24;k++)
        Jeu[k]=0;
	strcpy(j2,"machine");
	int a;
	printf("entrer votre nom:\n");
	scanf("%s",j1);
	///strcpy(j,j1);

	srand(time(NULL));
        a=1+rand()%2;
        if(a==1)
            {
                printf("c'est %s qui va commencer\n",j1);
                printf("appuyez sur une touche pour commencer:");
                getch();
                strcpy(j,j1);
            }
        else
            {
                printf("c'est %s qui va commencer\n",j2);
                printf("appuyez sur une touche pour commencer:");
                getch();
                strcpy(j,j2);
                jou1=2;     /// le premier joueur sera la machine
                jou2=1;
            }
    if (jou1==1) /// l'humain qui commence
        jou=1;
    else if(jou1==2) ///
        jou=2;
    while(N>0){
    	if(jou==1)
    	{
            grille(Jeu);      /// la position initiale === la grille vide
            if(i!=0)
                {
                    printf("\n\n\nla machine a joue:%d\n",coup+1);
                    printf("nombre de noeuds explores:%d\n",compteur);
                }
            if(ca==ca1)
                printf("la machine a supprime le pion a la position %d\n",ca+1);
            printf("\nA vous de jouer:%s\n",j1);
            jouer_coup(jou,&pos,Jeu);
            if(tester_moulin(pos,Jeu))
                capture(jou,Jeu);
            N--;
            jou=3-jou;
        }

        else if(jou==2)
        {
            grille(Jeu);
        	max_palyer=1;
        	compteur=0;
        	minimax(Jeu,5,max_palyer,jou,&coup,&S,N);
            pose(Jeu,coup,jou);
            if(tester_moulin(coup+1,Jeu) && pion_free(3-jou,Jeu)!=0)
            {
                ca=pion_a_capturer(Jeu,jou);
                capturer(Jeu,ca,jou);
                ca1=ca;
            }
            else
                ca+=ca1;
            i++;
            jou=3-jou;
            N--;
        }
    }
    i=0;
    ///////phase de deplacement
    while( !estBloquer(jou,Jeu) && nbr_pion(jou,Jeu)>2)
    {
        ca=1;ca1=0;
        if(jou==1)
    	{
            grille(Jeu);
            if(ca==ca1)
                printf("\n\n\nla machine a supprime le pion à la position %d\n",ca+1);
            if(i!=0)
                {
                    printf("la machine a deplace %d vers %d\n",dep1+1,arr1+1);
                    printf("nombre de noeuds explores:%d\n",compteur);
                }
            printf("\nA vous de jouer:%s\n",j1);
            deplacer(dep,&arr,jou,Jeu);
            if(tester_moulin(arr,Jeu))
                capture(jou,Jeu);
            jou=3-jou;
    	}
    	else
        {
            max_palyer=1;
            grille(Jeu);
            compteur=0;
            minimax2(Jeu,5,max_palyer,jou,&dep1,&arr1,&S);
            deplace(Jeu,dep1,arr1,jou);
            if(tester_moulin(arr1+1,Jeu) && pion_free(3-jou,Jeu)!=0)
            {
                int ca=pion_a_capturer(Jeu,jou);
                capturer(Jeu,ca,jou);
                ca1=ca;
            }
            else
                ca+=ca1;
            i++;
            jou=3-jou;
        }
    }
    system("cls");
    if(gagnant(Jeu)==1)
    {
        system("cls");
        printf("felicitations %s,vous avez gagne!!!!\n\n",j1);
        getch();
    }
    else{
        system("cls");
        printf("malheureusement la %s a gagne!!!!\n\n",j1);
        getch();
    }
    ///revenir au menu principal
    bienvenue();
    jouer();
}


int gagnant(int tab[24])
{
    	int a=0, b=0;
    	for (int i = 0; i < 24; i++)
    	{
    		if (tab[i]==1)  /// le joueur
    		{
    			a++;
    		}
    		if (tab[i]==2)    /// la machine
    		{
    			 b++;
    		}
    	}
    	if (a>=3 && b<=2)
    		return 1;    ///joueur gagne
    		//printf("Felicitations !! Vous avez gagne %s\n", j1);
    	else if (b>=3 && a<=2)
    		return 2;      /// machine gagne
}


///////// afficher les regles//////////////////:
void regles_de_jeu(void){
    color(0,0);
    system("cls");
    color(6,0);
    FILE* fichier=NULL;
    char chaine[MAX]="";
    fichier = fopen("reglesMoulin.txt","r");
    if (fichier != NULL)
    {
        while (fgets(chaine,MAX,fichier) != NULL)
            printf("%s", chaine);

        fclose(fichier);
    }
    puts("appuyer sur une touche pour revenir au menu principale:");
    getch();
    system("cls");
    bienvenue();
    init();
    gestion();
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
            *S=-he(temp,jou);
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
        compteur++;
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
        compteur++;
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


void jvsmachine2()
{
    system("cls");
    color(15,0);
    int Jeu[24];
    int jou=1,jou1=1,jou2=2;
	char j1[9],j2[9],j[9];
    int N=18,k=0,ca=1,ca1=0;
    int max_palyer;
    int pos;
    int dep, arr,dep1,arr1;
    int coup, S,i=0;
    for(k=0;k<24;k++)
        Jeu[k]=0;
	strcpy(j2,"machine");
	int a;
	printf("entrer votre nom:\n");
	scanf("%s",j1);
	///strcpy(j,j1);

	srand(time(NULL));
        a=1+rand()%2;
        if(a==1)
            {
                printf("c'est %s qui va commencer\n",j1);
                printf("appuyez sur une touche pour commencer:");
                getch();
                strcpy(j,j1);
            }
        else
            {
                printf("c'est %s qui va commencer\n",j2);
                printf("appuyez sur une touche pour commencer:");
                getch();
                strcpy(j,j2);
                jou1=2;     /// le premier joueur sera la machine
                jou2=1;
            }
    if (jou1==1) /// l'humain qui commence
        jou=1;
    else if(jou1==2) ///
        jou=2;
    while(N>0){
    	if(jou==1)
    	{
            grille(Jeu);      /// la position initiale === la grille vide
            if(i!=0)
                {
                    printf("\n\n\nla machine a joue:%d\n",coup+1);
                    printf("nombre de noeuds explores:%d\n",compteur);
                }
            if(ca==ca1)
                printf("la machine a supprime le pion a la position %d\n",ca+1);
            printf("\nA vous de jouer:%s\n",j1);
            jouer_coup(jou,&pos,Jeu);
            if(tester_moulin(pos,Jeu))
                capture(jou,Jeu);
            N--;
            jou=3-jou;
        }

        else if(jou==2)
        {
            grille(Jeu);
        	max_palyer=1;
        	compteur=0;
        	alphaBeta(Jeu,5,max_palyer,jou,&coup,&S,-MAX,MAX,N);
            pose(Jeu,coup,jou);
            if(tester_moulin(coup+1,Jeu) && pion_free(3-jou,Jeu)!=0)
            {
                ca=pion_a_capturer(Jeu,jou);
                capturer(Jeu,ca,jou);
                ca1=ca;
            }
            else
                ca+=ca1;
            i++;
            jou=3-jou;
            N--;
        }
    }
    i=0;
    ///////phase de deplacement
    while( !estBloquer(jou,Jeu) && nbr_pion(jou,Jeu)>2)
    {
        ca=1;ca1=0;
        if(jou==1)
    	{
            grille(Jeu);
            if(ca==ca1)
                printf("\n\n\nla machine a supprime le pion à la position %d\n",ca+1);
            if(i!=0)
                {
                    printf("la machine a deplace %d vers %d\n",dep1+1,arr1+1);
                    printf("nombre de noeuds explores:%d\n",compteur);
                }
            printf("\nA vous de jouer:%s\n",j1);
            deplacer(dep,&arr,jou,Jeu);
            if(tester_moulin(arr,Jeu))
                capture(jou,Jeu);
            jou=3-jou;
    	}
    	else
        {
            max_palyer=1;
            grille(Jeu);
            compteur=0;
            alphabeta2(Jeu,8,max_palyer,jou,&dep1,&arr1,-MAX,MAX,&S);
            deplace(Jeu,dep1,arr1,jou);
            if(tester_moulin(arr1+1,Jeu) && pion_free(3-jou,Jeu)!=0)
            {
                int ca=pion_a_capturer(Jeu,jou);
                capturer(Jeu,ca,jou);
                ca1=ca;
            }
            else
                ca+=ca1;
            i++;
            jou=3-jou;
        }
    }
    system("cls");
    if(gagnant(Jeu)==1)
    {
        system("cls");
        printf("felicitations %s,vous avez gagne!!!!\n\n",j1);
        getch();
    }
    else{
        system("cls");
        printf("malheureusement la %s a gagne!!!!\n\n",j2);
        getch();
    }
    ///revenir au menu principal
    bienvenue();
    jouer();
}
