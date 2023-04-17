#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
#include <dirent.h>
#define LARGEUR_CONSOLE 80
#define UTIL 280
#define CELLULE 100



typedef enum{ actif = 1 , inactif }ETAT;
//Entite CATEGORIE
typedef struct{
    int idCa , montantCa ;
    char codeCa[30] , libCa[30], desCa[100] ;
    ETAT etatCa ;
}CATEGORIE;

//Entite CHAMBRE
typedef struct{
    int idC , telC ;
    ETAT etatC ;
    CATEGORIE CatC ;
}CHAMBRE;

//Entite UTILISATEUR
typedef struct{
    int idU,telU ;
    char login[6],mdp[20],nom[30],prenom[30],email[30] ;
}UTILISATEUR;

//Entite CLIENT
typedef struct{
    char nomCl[30],prenomCl[50],adresseCl[20];
    int telCl ;
}CLIENT;

//Entite PRESTATION
typedef struct{
    int codePres,prixPres ;
    char desPres[100];
}PRESTATION;


//Entite RESERVATION
typedef struct{
    char numRes[100];
    int idRes,mtRes ;
    CHAMBRE chambreRes;
    PRESTATION presRes;
    UTILISATEUR utilRes ;
    CLIENT clientRes ;
}RESERVATION;


//FONCTION ADMIN

void CreerUtil(UTILISATEUR );
void CreerCategorie(CATEGORIE Cat);
void CreerChambre(CHAMBRE ,int ,CATEGORIE TCat[]);
void ListerChambres(CHAMBRE [] ,int);
void ListerCategorie(CATEGORIE [] , int );
void Chambredispo(char nomFichier[]);
void Chambreindispo(char nomFichier[]);
void ReservationLive(char nomFichier[]);
void CreerClient(FILE *);
void VoirClient(char nomFichier[]);
void centrer (const char* str);

void cryptermdp(char *);
void decryptermdp(char *);

void Prestation(FILE *);
void ListerPrestation(FILE *);
void FaireReservation(CHAMBRE Tch[] , int ,UTILISATEUR);
int verifEtatChambre(FILE * , int );
void ListerReservation(FILE * );
void rendredispochambre(FILE *,CHAMBRE [],int ,int );
char * today();
void Client (FILE *);
void modifierchambre(FILE *,CHAMBRE [],CATEGORIE [],int , int , int);

//CREATION D'ADMIN

/*

    FILE *f = fopen("UTILISATEUR.txt","w+b");
    if(f!=NULL){
        printf("Donner le nom de l'utilisateur : ");
        gets(u.nom);
        printf("Donner le prenom de l'utilisateur : ");
        gets(u.prenom);
        sprintf(u.email,"%c%c%d@boulakodaradiaral.sn",tolower(u.nom[0]),tolower(u.nom[strlen(u.nom)-1]),2022);
        strcpy(u.login,"ADMIN");
        strcpy(u.mdp,"dxzzar");
        printf("Donner le telephone de l'utilisateur: ");
        scanf("%d",&u.telU);
        u.idU=1;
        fflush(stdin);
    fwrite(&u,sizeof(UTILISATEUR),1,f);
    }
    fclose(f);
*/

//CRYPTER LE MOT PASSE
/*
    tous les a sont remplacer par # les p par d
    les e par a , les s par z , les b par l(L) et les d par q ;

    a la saisie de l'utilisateur nous crypterons sa saisie et la comparer
    avec celui enregistrer dans la base;


*/



/*
        DATE ACTUELLE

      int h, min, ss, day, mois, an;
      time_t now;

      // Renvoie l'heure actuelle
      time(&now);
      // Convertir au format heure locale
      struct tm *local = localtime(&now);
      h = local->tm_hour;
      min = local->tm_min;
      ss = local->tm_sec;
      day = local->tm_mday;
      mois = local->tm_mon + 1;
      an = local->tm_year + 1900;

      printf("L'heure : %02d:%02d:%02d\n", h, min, ss);
      // Afficher la date courante
      printf("La date : %02d/%02d/%d\n", day, mois, an);

*/
