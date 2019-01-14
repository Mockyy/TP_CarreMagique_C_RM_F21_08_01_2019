#include <stdio.h>
#include <stdlib.h>
#define TAILLE 5
#define MAX 25

///TYPES STRUCTUR�S
typedef struct tJeton{
    int nX;
    int nY;
}tJeton;

///ENUMERATION
typedef enum Bool{false, true} Bool;

///PROTOTYPES
void initialiserGrille(int tGrille[][TAILLE]);
void affichage(int tGrille[][TAILLE]);
void avancer(int tGrille[][TAILLE], tJeton *tPion, int nCpt);
void avancerDroite(tJeton *ptPion);
void avancerGauche(tJeton *ptPion);
void corriger(tJeton *ptPion);
Bool rechercheVide(int tGrille[][TAILLE], tJeton tPion);
void placer(int tGrille[][TAILLE],int x, int y, int nCpt);

int main()
{
    int tGrille[TAILLE][TAILLE];
    int nCpt = 1;
    char cPause;

    initialiserGrille(tGrille);

    tJeton tPion = {TAILLE/2-1, TAILLE/2};

    for(nCpt=1;nCpt<=MAX;nCpt++){
        avancer(tGrille, &tPion, nCpt);
        affichage(tGrille);
        scanf("%c",&cPause);
        system("cls");
    }

    affichage(tGrille);

    return 0;
}

//************************
//Principe : initialiser la grille selon sa taille et placer le jeton
//
//Entr�e : la taille de la grille
//
//Sortie : la grille remplie de "0" et le pion plac� au bon endroit
//
//Note :
//************************
void initialiserGrille(int tGrille[][TAILLE]){

    int nCpt1 = 0, nCpt2 = 0;

    for(nCpt1=0;nCpt1<TAILLE; nCpt1++){
        for(nCpt2=0;nCpt2<TAILLE;nCpt2++){
            tGrille[nCpt1][nCpt2] = 0;
        }
    }
}

//************************
//Principe : afficher la grille
//
//Entr�e : la grille
//
//Sortie : la grille
//
//Note :
//************************
void affichage(int tGrille[][TAILLE]){

    int nCpt1 = 0, nCpt2 = 0;

    for(nCpt1=0;nCpt1<TAILLE;nCpt1++){
        for(nCpt2=0;nCpt2<TAILLE;nCpt2++){
            printf("%d ",tGrille[nCpt1][nCpt2]);
        }
        printf("\n");
    }
}

//************************
//Principe : avancer le pion sur la prochaine case libre
//
//Entr�e : la grille, le pion et le compteur
//
//Sortie : la grille "incr�ment�e"
//
//Note : contient les m�thodes avancerGauche/Droite, corriger et placer
//************************
void avancer(int tGrille[][TAILLE], tJeton *tPion, int nCpt){

    avancerDroite(&*tPion);                             //On avance le pion vers la droite,
    corriger(&*tPion);                                  //On corrige sa trajectoire au cas o� il d�passe de la grille.

    if(rechercheVide(tGrille, *tPion)){                 //Si la case est libre
        placer(tGrille, tPion->nX, tPion->nY, nCpt);    //On place;
    }
    else{                                               //Sinon
        avancerGauche(&*tPion);                         //On avance vers la gauche,
        corriger(&*tPion);                              //on corrige,
        if(rechercheVide(tGrille, *tPion)){             //Si la case est libre
            placer(tGrille, tPion->nX, tPion->nY, nCpt);//On place;
        }
        else{                                           //Sinon
            do{
                avancerDroite(&*tPion);                 //On avance vers la droite jusqu'� trouver une case libre
                corriger(&*tPion);
            }while(rechercheVide(tGrille, *tPion));

        placer(tGrille, tPion->nX, tPion->nY, nCpt);    //Et on place.
        }
    }
}

//************************
//Principe : avance le jeton vers la droite
//
//Entr�e : le jeton
//
//Sortie : le jeton avanc� vers la droite
//
//Note :
//************************
void avancerDroite(tJeton *tPion){

    tPion->nX ++;
    tPion->nY --;
}

//************************
//Principe : avance le jeton vers la gauche
//
//Entr�e : le jeton
//
//Sortie : le jeton avanc� vers la gauche
//
//Note :
//************************
void avancerGauche(tJeton *tPion){

    tPion->nX --;
    tPion->nY --;
}

//************************
//Principe : permet de replacer correctement le jeton lorsqu'il d�passe de la grille
//
//Entr�e : le jeton
//
//Sortie :  le jeton correctement plac�
//
//Note :
//************************
void corriger(tJeton *tPion){

    if(tPion->nX<0){
        tPion->nX = TAILLE-1;
    }
    if(tPion->nX>TAILLE-1){
        tPion->nX=0;
    }
    if(tPion->nY<0){
        tPion->nY = TAILLE-1;
    }
    if(tPion->nY>TAILLE-1){
        tPion->nY=0;
    }
}

//************************
//Principe : renvoie si la case sur laquelle se trouve le jeton est vide (�gale � 0) ou non
//
//Entr�e : la grille, le jeton
//
//Sortie : vrai ou faux
//
//Note :
//************************
Bool rechercheVide(int tGrille[][TAILLE], tJeton tPion){

    if(tGrille[tPion.nY][tPion.nX]==0){
        return true;
    }
    else{
        return false;
    }
}
//************************
//Principe : placer le nombre du compteur sur la case
//
//Entr�e :
//
//Sortie :
//
//Note :
//************************
void placer(int tGrille[][TAILLE],int x, int y, int nCpt){

    tGrille[y][x]=nCpt;
}














