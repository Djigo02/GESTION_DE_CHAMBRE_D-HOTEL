#include "exam.h"

int main()
{
    int profil,choix ;
    int s,v,g ;
    // s est l'indice de parcour des chambres , v des categories , g des utilisateurs
    FILE *fU,*fCat, *fCh , *fPres ,*fres, *f;
    CHAMBRE Ch,TCh[CELLULE];
    UTILISATEUR u,Tu[UTIL];
    CATEGORIE Cat,TCat[CELLULE] ;



    //transfere des utilisateurs dans un tableau

   fU=fopen("UTILISATEUR.txt","r+b");
    g=0;
    if(fU){
        rewind(fU);
        while(fread(&u,sizeof(UTILISATEUR),1,fU)!=0){
            Tu[g]=u ;
            g++;
        }
    }
    fclose(fU);



 //transfere des categories dans un tableau

    fCat=fopen("CATEGORIE.txt","r+b");
    if(fCat){
        rewind(fCat);v=0;
        while(fread(&Cat,sizeof(CATEGORIE),1,fCat)!=0){
            TCat[v]=Cat;
            v++;
        }
    }

    fclose(fCat);

//transfere des Chambres dans un tableau

    fCh=fopen("CHAMBRE.txt","r+b");
        if(fCh){
            rewind(fCh); s=0;
            while(fread(&Ch,sizeof(CHAMBRE),1,fCh)!=0){
                TCh[s]=Ch;
                s++;
            }
        }
    fclose(fCh);

    system("color A");
    centrer("\t\t\tCHARGEMENT ");
    for(int z=0;z<3;z++){
        Sleep(700);
        printf(".");
    }
    Sleep(1500);
    connection :
    system("cls");
do{
    system("color 7");
    printf("\n\n");
    centrer("\t\t\t\t===============================================\n");
    puts("");
    centrer("\t\t\t\t*     BIENVENUE A l'HOTEL     *\n");
    centrer("\t\t\t\t*     BOULAKO-DARA-DIARAL     *\n");
    puts("");
    centrer("\t\t\t\t===============================================\n");
    printf("\n\n");
    Sleep(1000);
    system("color 3");

    Sleep(1000);
    printf("Veuillez entrer votre login : ");
    gets(u.login);
    strupr(u.login);
    printf("Veuillez entrer votre mot de passe : ");
        int e=0;
    do{
        u.mdp[e]=getch();
        if(u.mdp[e]!='\r'){
                if(u.mdp[e]!=8)
                    printf("*");
        }
        e++;
    }while(u.mdp[e-1]!='\r');
    u.mdp[e-1]='\0';
    getch();
    //gets(u.mdp);
    cryptermdp(&u.mdp);
    int j;
    for(j=0;j<g;j++){
        if(strcmp(u.login,Tu[j].login)==0 && strcmp(u.mdp,Tu[j].mdp)==0){
            system("color A");
            Sleep(1000);
            system("cls");
            centrer("\t\t\t\t*     Connection reussi ...     *\n");
            u=Tu[j];
            Sleep(1000);
            system("color 3");
            system("cls");
            if(strcmp(u.login,"ADMIN")==0){
                profil = 1;
            }
            else{
                profil = 2;
            }
            break;
        }
    }
    if(j==g){
        Sleep(500);
        system("color 4");
        printf("Ce profil n'existe pas !!!");
        Sleep(1500);
        system("cls");

    }
    if(j<g){
        break;
    }
}while(1);


    switch(profil)
    {
        case 1:
            do{
                Sleep(500);
                centrer("\t\t\t\t===============================================\n");
                puts("");
                centrer("\t\t\t\t*     MENU ADMIN    *\n");
                puts("");
                centrer("\t\t\t\t===============================================\n");
                printf("\n\n");
                Sleep(1000);
                do{
                    puts("\t1. Creer un utilisateur");
                    puts("\t2. Lister tous les chambres");
                    puts("\t3. Lister toutes les Categories");
                    puts("\t4. Lister tous les Chambres disponibles");
                    puts("\t5. Verifier si une chambre est  disponible");
                    puts("\t6. Rendre une chambre disponible");
                    puts("\t7. Modifier une chambre");
                    puts("\t8. Faire une reservation pour un client");
                    puts("\t9. Se deconnecter");
                    puts("\t10. Quitter");
                    printf("\tFaites votre choix : ");
                    scanf("%d",&choix);
                    Sleep(1000);
                }while(choix<1 || choix>10);
                switch(choix)
                {
                    case 1:
                        fflush(stdin);
                        CreerUtil(u);
                            fU=fopen("UTILISATEUR.txt","r+b");
                            g=0;
                            if(fU){
                                rewind(fU);
                                while(fread(&u,sizeof(UTILISATEUR),1,fU)!=0){
                                    Tu[g]=u ;
                                    g++;
                                }
                            }
                            fclose(fU);
                        for(int i=0;i<g;i++){
                            Sleep(500);
                            printf("Nom %s -- Prenom : %s\n\n",Tu[i].nom,Tu[i].prenom);
                        }
                        break;
                    case 2:
                        ListerChambres(TCh,s);
                        break;
                    case 3:
                        //ListerCategorie(TCat,v);
                        for(int h=0;h<v;h++){
                            printf("\n\n\t\t\tCategorie : %s \n\n",TCat[h].libCa);
                        }
                        break;
                    case 4:
                        //lister les chambres disponibles
                        Chambredispo("CHAMBRE.txt");
                        break;
                    case 5:
                        ListerChambres(TCh,s);
                        int choice ;
                        do{
                            printf("Veuillez donner l'ordre de la chambre a verifier : ");
                            scanf("%d",&choice);
                        }while(choice<1 || choice>s);
                        if(verifEtatChambre(fCh , choice )==1){
                            printf("\n\t\t\t* Chambre disponible *\n");
                        }else {
                            if(verifEtatChambre(fCh , choice )==2){
                                printf("\n\t\t\t* Chambre indisponible *\n");
                            }else{
                                printf("\n\t\t\t* Pas d'information *\n");
                            }
                        }
                        break;
                    case 6:
                        ListerChambres(TCh,s);
                        int position ;
                        do{
                            printf("Veuillez donner l'ordre de la chambre a verifier : ");
                            scanf("%d",&position);
                        }while(position<1 || position>s);
                        if(verifEtatChambre(fCh , position )==2){
                            rendredispochambre(fCh,TCh,s,position);
                        }else{
                            printf("\t\t\t\t\tChambre deja disponible \n");
                        }
                        break;
                    case 7:
                        ListerChambres(TCh,s);
                        int choi ;
                        do{
                            printf("Veuillez donner l'ordre de la chambre a verifier : ");
                            scanf("%d",&choi);
                        }while(choi<1 || choi>s);
                        fflush(stdin);
                        modifierchambre(fCh ,TCh,TCat,s,choi ,v);
                        break;
                    case 8:
                        FaireReservation(TCh,s,u);
                            fCh=fopen("CHAMBRE.txt","r+b");
                                if(fCh){
                                    rewind(fCh); s=0;
                                    while(fread(&Ch,sizeof(CHAMBRE),1,fCh)!=0){
                                        TCh[s]=Ch;
                                        s++;
                                    }
                                }
                            fclose(fCh);
                        break;
                    case 9:
                        fflush(stdin);
                        Sleep(600);
                        system("cls");
                        Sleep(600);
                        goto connection;
                        break;
                    case 10:
                        system("cls");
                        printf("\n\n");
    centrer("\t\t\t\t===============================================\n");
    puts("");
    centrer("\t\t\t\t*     AU REVOIR    *\n");
    centrer("\t\t\t\t*     A LA PROCHAINE IN SHAA ALLAH     *\n");
    puts("");
    centrer("\t\t\t\t===============================================\n");
    printf("\n\n");
                        return 0;

                }
            }while(1);
            break;
        case 2:
            do{
                Sleep(500);
                centrer("\t\t\t\t===============================================\n");
                puts("");
                centrer("\t\t\t\t*     MENU USERS    *\n");
                puts("");
                centrer("\t\t\t\t===============================================\n");
                printf("\n\n");
                Sleep(1000);
                do{
                    puts("\t1. Lister tous les Chambres disponibles");
                    puts("\t2. Verifier si une chambre est  disponible");
                    puts("\t3. Lister les reservations en cours");
                    puts("\t4. Voir les clients qui ont reserve une chambre");
                    puts("\t5. Faire une réservation pour un client");
                    puts("\t6. Rendre disponible une chambre");
                    puts("\t7. Se deconnecter");
                    puts("\t8. Quitter");
                    printf("\tFaites votre choix : ");
                    scanf("%d",&choix);
                }while(choix<1 || choix>8);
                switch(choix)
                {
                    case 1:
                        Chambredispo("CHAMBRE.txt");
                        break;
                    case 2:
                         ListerChambres(TCh,s);
                        int choice ;
                        do{
                            printf("Veuillez donner l'ordre de la chambre a verifier : ");
                            scanf("%d",&choice);
                        }while(choice<1 || choice>s);
                        if(verifEtatChambre(fCh , choice )==1){
                            printf("\n\t\t\t* Chambre disponible *\n");
                        }else {
                            if(verifEtatChambre(fCh , choice )==2){
                                printf("\n\t\t\t* Chambre indisponible *\n");
                            }else{
                                printf("\n\t\t\t* Pas d'information *\n");
                            }
                        }

                        break;
                    case 3:
                        ListerReservation(fres);
                        break;
                    case 4:
                        Client(f);
                        break;
                    case 5:
                        FaireReservation(TCh,s,u);
                            fCh=fopen("CHAMBRE.txt","r+b");
                                if(fCh){
                                    rewind(fCh); s=0;
                                    while(fread(&Ch,sizeof(CHAMBRE),1,fCh)!=0){
                                        TCh[s]=Ch;
                                        s++;
                                    }
                                }
                            fclose(fCh);
                        break;
                    case 6:
                        ListerChambres(TCh,s);
                        int position ;
                        do{
                            printf("Veuillez donner l'ordre de la chambre a verifier : ");
                            scanf("%d",&position);
                        }while(position<1 || position>s);
                        if(verifEtatChambre(fCh , position )==2){
                            rendredispochambre(fCh,TCh,s,position);
                        }else{
                            printf("\t\t\t\t\tChambre deja disponible \n");
                        }
                        break;
                    case 7:
                        fflush(stdin);
                        Sleep(600);
                        system("cls");
                        Sleep(600);
                        goto connection;
                        break;
                    case 8:
                        system("cls");
                        printf("\n\n");
    centrer("\t\t\t\t===============================================\n");
    puts("");
    centrer("\t\t\t\t*     AU REVOIR    *\n");
    centrer("\t\t\t\t*     A LA PROCHAINE IN SHAA ALLAH     *\n");
    puts("");
    centrer("\t\t\t\t===============================================\n");
    printf("\n\n");
                        return 0;

                }

            }while(1);
            break;
    }



    return 0;
}
