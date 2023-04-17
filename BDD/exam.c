#include "exam.h"
//FONCTION QUI PERMET DE CENTRER UN TEXTE
void centrer (const char* str)
{
    unsigned int n;
    for (n = 0; n < (LARGEUR_CONSOLE-strlen(str)) / 2; n++)
    {
        putchar(' ');
    }
    printf("%s", str);
}

void CreerUtil(UTILISATEUR u){
/*
    FILE *f = fopen("UTILISATEUR.txt","w+b");
    if(f!=NULL){
        printf("Donner le nom de l'utilisateur : ");
        gets(u.nom);
        strlwr(u.nom);
        u.nom[0]=toupper(u.nom[0]);
        printf("Donner le prenom de l'utilisateur : ");
        gets(u.prenom);
        strlwr(u.prenom);
        u.prenom[0]=toupper(u.prenom[0]);
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

    int x=1;
    FILE *f = fopen("UTILISATEUR.txt","a+b");
    if(f!=NULL){
        rewind(f);
        while(fread(&u,sizeof(UTILISATEUR),1,f)!=0){
            x++;
        }
        printf("Donner le nom de l'utilisateur : ");
        gets(u.nom);
        strlwr(u.nom);
        u.nom[0]=toupper(u.nom[0]);
        printf("Donner le prenom de l'utilisateur : ");
        gets(u.prenom);
        strlwr(u.prenom);
        u.prenom[0]=toupper(u.prenom[0]);
        sprintf(u.email,"%c%c%d@boulakodaradiaral.sn",tolower(u.nom[0]),tolower(u.nom[strlen(u.nom)-1]),2022);
        strcpy(u.login,"USERS");
        strcpy(u.mdp,"dxzzarlqq");
        printf("Donner le telephone de l'utilisateur: ");
        scanf("%d",&u.telU);
        u.idU=x;
        fflush(stdin);
    fwrite(&u,sizeof(UTILISATEUR),1,f);
    }
    fclose(f);

}


void CreerCategorie(CATEGORIE Cat)
{
    FILE *fCat= fopen("CATEGORIE.txt","a+b");
         printf("Donner le libelle de la categorie : ");
        scanf("%s",&Cat.libCa);
        printf("Donner la description de la categorie : ");
        scanf("%s",&Cat.desCa);
        printf("Donner le montant de la categorie :");fflush(stdin);
        scanf("%d",&Cat.montantCa);
        fflush(stdin);
        strcpy(Cat.codeCa,"#Simple");
        Cat.idCa=2;
        //fprintf(fCat,"%s %s %s %d %d\n",Cat.libCa,Cat.desCa,Cat.codeCa,Cat.idCa,Cat.montantCa);
        fwrite(&Cat,sizeof(CATEGORIE),1,fCat);
    fclose(fCat);
}


void CreerChambre(CHAMBRE Ch,int N,CATEGORIE TCat[])
{
    int c;
    FILE *fCh= fopen("CHAMBRE.txt","a+b");
    for(int i=0;i<N;i++){
        printf("Donner le telephone de la chambre : ");
        scanf("%d",&Ch.telC);
        Ch.etatC=1;
        Ch.idC=i+1;
        do{
            puts("1.Suite");
            puts("2.Simple");
            printf("Quelle Categorie voulez-vous? : ");
            scanf("%d",&c);
        }while(c<1 || c>2);
        Ch.CatC=TCat[c-1];
        fwrite(&Ch,sizeof(CHAMBRE),1,fCh);
    }
    fclose(fCh);
}

void ListerChambres(CHAMBRE Tch[] , int s)
{
    for(int i=0;i<s;i++){
        Sleep(500);
        printf("\n\n\t\t\t Indice : %d --> Categorie : %s - Telephone : %d - prix : %d\n\n",Tch[i].idC,Tch[i].CatC.libCa,Tch[i].telC,Tch[i].CatC.montantCa);
    }

}

void ListerCategorie(CATEGORIE TCat[] , int v)
{
    for(int i=0;i<v;i++){
        printf("\n\n\t\t\tCategorie : %d \n\n",TCat[i].codeCa);
    }

}

void cryptermdp(char * str)
{
    for(int i=0;i<strlen(str);i++){
        if(str[i]=='a')
            str[i]='x';
        if(str[i]=='s')
            str[i]='z';
        if(str[i]=='b')
            str[i]='l';
        if(str[i]=='d')
            str[i]='q';
        if(str[i]=='p')
            str[i]='d';
        if(str[i]=='e')
            str[i]='a';
    }

}

void decryptermdp(char *str)
{
    for(int i=0;i<strlen(str);i++){
        if(str[i] == 'd')
            str[i] = 'p';
        if(str[i] == 'z')
            str[i] = 's';
        if(str[i] == 'a')
            str[i] = 'e';
        if(str[i] == 'x')
            str[i] = 'a';
        if(str[i] == 'l')
            str[i] = 'b';
        if(str[i] == 'q')
            str[i] = 'd';

    }

}

void Chambredispo(char nomFichier[])
{
    FILE * fCh = fopen(nomFichier,"r+b");
    CHAMBRE cham ;
    rewind(fCh);
    while(fread(&cham,sizeof(CHAMBRE),1,fCh)!=0){
        if(cham.etatC==1){
            printf("Numero telephone chambre : %d -- Categorie : %s \n",cham.telC,cham.CatC.libCa);
        }
    }
    fclose(fCh);
}

void Chambreindispo(char nomFichier[])
{
    FILE * fCh = fopen(nomFichier,"r+b");
    CHAMBRE cham ;
    rewind(fCh);
    while(fread(&cham,sizeof(CHAMBRE),1,fCh)!=0){
        if(cham.etatC==2){
            printf("Indice : %d -->Numero telephone chambre : %d -- Categorie : %s \n",cham.telC,cham.CatC.libCa);
        }
    }
    fclose(fCh);
}

void Prestation(FILE * fPres)
{
    PRESTATION Pr;
    fPres=fopen("PRESTATION.txt","a+");
    if(fPres){
        strcpy(Pr.desPres,"Supplementaire");
        Pr.codePres=3;
        Pr.prixPres=12500;
        fprintf(fPres,"%s %d %d \n",Pr.desPres,Pr.codePres,Pr.prixPres);
    }
    fclose(fPres);
}

void ListerPrestation(FILE *fPres)
{
    PRESTATION Pr;
    fPres=fopen("PRESTATION.txt","a+");
    if(fPres){
        rewind(fPres);
        while(!feof(fPres)){
            fscanf(fPres,"%s %d %d \n",&Pr.desPres,&Pr.codePres,&Pr.prixPres);
            printf("\n\t\t\tType prestation : %s -- Prix : %d \n",Pr.desPres,Pr.prixPres);
        }
    }
    fclose(fPres);
}

//retourne la date actuelle tout colle
char * today()
{
          int h, min, ss, day, mois, an ;
          char *r ;
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
      r = malloc(30*sizeof(char));
    asprintf(&r,"%04d%02d%02d%02d%02d%02d",an,mois,day,h,min,ss);
      return r ;
}

void CreerClient(FILE *fCli)
{
    fflush(stdin);
    fCli = fopen("CLIENT.txt","a+b");
    CLIENT Cli;
    if(fCli){
        printf("\t\t\t\t\tDonner le nom du client : ");
        scanf("%s",&Cli.nomCl);
        printf("\t\t\t\t\tDonner le prenom du client : ");
        scanf("%s",&Cli.prenomCl);
        printf("\t\t\t\t\tDonner l'adresse du client : ");
        scanf("%s",&Cli.adresseCl);
        printf("\t\t\t\tDonner le numero de telephone du client : ");
        scanf("%s",&Cli.telCl);
        fwrite(&Cli,sizeof(CLIENT),1,fCli);
    }
    fclose(fCli);


}

void FaireReservation(CHAMBRE Tch[] , int taille,UTILISATEUR u)
{
    fflush(stdin);
    CHAMBRE ChRes , Ch;
    PRESTATION PresRes;
    UTILISATEUR URes;
    CLIENT Cli;
    RESERVATION Res;
    FILE * fch , *fpre , *fu , *fcli , *fres  ;
    char string[10], titre[255];

    int pr,i=0;
    /*Parcours le repertoire et donner le nombre de fichier present
        Debut{
    */
    struct dirent *dir;
    // opendir() renvoie un pointeur de type DIR.
    DIR *d = opendir("RESERVATIONS/.");
    if (d)
    {
        i=-1;
        while ((dir = readdir(d)) != NULL)
        {
            //printf("%s\n", dir->d_name);
            i++;
        }
        closedir(d);
    }
     /* }Fin */

    //CreerClient(fcli);
        fflush(stdin);
        fcli = fopen("CLIENT.txt","a+b");
        if(fcli){
            printf("\t\t\t\t\tDonner le nom du client : ");
            scanf("%s",&Cli.nomCl);
            printf("\t\t\t\t\tDonner le prenom du client : ");
            scanf("%s",&Cli.prenomCl);
            printf("\t\t\t\t\tDonner l'adresse du client : ");
            scanf("%s",&Cli.adresseCl);
            printf("\t\t\t\tDonner le numero de telephone du client : ");
            scanf("%s",&Cli.telCl);
            fwrite(&Cli,sizeof(CLIENT),1,fcli);
        }
        fclose(fcli);
    fflush(stdin);
    Res.clientRes = Cli ;

     Res.idRes=i;
    Res.utilRes=u;

    strcpy(titre,"RESERVATIONS/RECU_");
    strcat(titre,today());
    strcat(titre,"_");
    itoa(i,string,10);
    strcat(titre,string);
    strcat(titre,"_");
    strcat(titre,u.login);
    strcat(titre,".txt");

    strcat(Res.numRes,today());

    printf("\t\t\t\t\tNumero Reservation ==> %s \n",Res.numRes);
    int choice ;
    do{
        puts("\t\t\t\t\t1.Suite");
        puts("\t\t\t\t\t2.Simple");
        printf("\t\t\t\t\tQuelle categorie voulez vous ? ");
        scanf("%d",&choice);
    }while(choice<1 || choice >2);
    fflush(stdin);
    for(int j = 0 ; j<taille ; j++)
    {
        if(Tch[j].CatC.idCa==choice){
            if(Tch[j].etatC==1){
                Tch[j].etatC=2;
                Res.chambreRes = Tch[j];
                fch  = fopen("CHAMBRE.txt","w+b");
                rewind(fch);
                for(int f = 0 ; f < taille ; f++)
                {
                    Ch = Tch[f];
                    fwrite(&Ch,sizeof(CHAMBRE),1,fch);
                }
                fclose(fch);

                break;
            }
        }
    }

    printf("\n\t\t\t\t\tInformation de la chambre prise : \nTelephone : %d -- numero : %d -- Categorie : %s \n\n",
           Res.chambreRes.telC,Res.chambreRes.idC,Res.chambreRes.CatC.libCa);

                system("color B");
                Sleep(500);
                puts("\t\t\t\t\t(Attention:)--Vous ne pouvez faire qu'une seule prestation ");
                Sleep(1500);
                system("color 3");
                do{
                    puts("\t\t\t\t\tQue voulez vous ? ");
                    puts("\t\t\t\t\t1. Petit Dejeuner");
                    puts("\t\t\t\t\t2. Dejeuner");
                    puts("\t\t\t\t\t3. Supplement");
                    puts("\t\t\t\t\t4. Aucun");
                    printf("\t\t\t\t\tFaites votre choix : ");
                    scanf("%d",&d);
                }while(pr<1 && pr>4);

                if(pr!=4){

                fpre=fopen("PRESTATION.txt","r");
                rewind(fpre);
                PRESTATION Pr;
                if(fpre){
                    rewind(fpre);
                    while(!feof(fpre)){
                        fscanf(fpre,"%s %d %d \n",&Pr.desPres,&Pr.codePres,&Pr.prixPres);
                        if(Pr.codePres==d){
                            printf("\n\t\t\t\t\tType prestation : %s -- Prix : %d \n",Pr.desPres,Pr.prixPres);
                            Res.presRes=Pr ;
                            break;
                        }
                    }
                }
                fclose(fpre);
                }else{
                    Res.presRes.prixPres=0;
                }
        Res.mtRes = Res.chambreRes.CatC.montantCa + Res.presRes.prixPres ;

        // Lorsque tu reouvres ce fichier on continuera avec les fichier reservation

        fres = fopen(titre,"a+");
        if(fres){
                fprintf(fres,"%s %d %d %d %d %d %s %s %d %s %d  %d %s %s %s %d %s %s \n",Res.numRes,Res.idRes,Res.mtRes,Res.chambreRes.idC,
                        Res.chambreRes.telC,Res.chambreRes.etatC,Res.chambreRes.CatC.codeCa,Res.chambreRes.CatC.libCa,Res.chambreRes.CatC.montantCa,
                        Res.presRes.desPres,Res.presRes.codePres,Res.presRes.prixPres,Res.utilRes.nom,Res.utilRes.prenom,Res.utilRes.login,Res.utilRes.telU,
                        Res.clientRes.nomCl,Res.clientRes.prenomCl);
                        printf("\n ok \n");
            }
    fclose(fres);
    printf("\t\t\t\t\tPrix Total de la Reservation : %d \n\n",Res.mtRes);

}

// Verification disponibilite chambre

int verifEtatChambre(FILE * fCh , int position )
{
    CHAMBRE Ch ;
    fCh = fopen("CHAMBRE.txt","a+b");
    rewind(fCh);
    while(fread(&Ch,sizeof(CHAMBRE),1,fCh)!=0){
        if(Ch.idC==position){
            if(Ch.etatC==1)
                return Ch.etatC;
            else if(Ch.etatC==2)
                return Ch.etatC;
            else
                return 0;
        }
    }
    fclose(fCh);
}

void ListerReservation(FILE * fres)
{
    system("cls");
     int pr,i=0;
    /*Parcours le repertoire et donner le nombre de fichier present
        Debut{
    */
    struct dirent *dir;
    // opendir() renvoie un pointeur de type DIR.
    DIR *d = opendir("RESERVATIONS/.");
    char titre[255];
    if (d)
    {
        i=-1;
        while ((dir = readdir(d)) != NULL)
        {
            if(i>0){
                strcpy(titre,dir->d_name);
                fres=fopen(titre,"a+");
                if(fres){
                        RESERVATION Res;
                        printf("ok\n");
                    rewind(fres);
                    while(!feof(fres)){
                        printf("%s\n",titre);
                        fflush(stdin);
                        fscanf(fres,"%s %d %d %d %d %d %s %s %d %s %d  %d %s %s %s %d %s %s \n",&Res.numRes,&Res.idRes,&Res.mtRes,&Res.chambreRes.idC,
                        &Res.chambreRes.telC,&Res.chambreRes.etatC,&Res.chambreRes.CatC.codeCa,&Res.chambreRes.CatC.libCa,&Res.chambreRes.CatC.montantCa,
                        &Res.presRes.desPres,&Res.presRes.codePres,&Res.presRes.prixPres,&Res.utilRes.nom,&Res.utilRes.prenom,&Res.utilRes.login,&Res.utilRes.telU,
                        &Res.clientRes.nomCl,&Res.clientRes.prenomCl);
                            fflush(stdin);

                          /*      printf("Numero de Reservation : %s \nid Reservation : %d \nMontant de la Reservation : %d \nid de la chambre reservee : %d \nTel de la Chambre : %d \nEtat de la chambre : %d \nCode categorie de la chambre : %s\nLibelle de la categorie de la chambre : %s\nPrix de la chambre : %d\nDescription de la prestation : %s \nCode de la prestation : %d \nPrix de la prestation : %d \nNom Utilisateur : %s\n Prenom Utilisateur : %s\nLogin : %s\n Tel Utilisateur : %d \nNom du client : %s\nPrenom du client : %s \n",
                            Res.numRes,Res.idRes,Res.mtRes,Res.chambreRes.idC,
                            Res.chambreRes.telC,Res.chambreRes.etatC,Res.chambreRes.CatC.codeCa,Res.chambreRes.CatC.libCa,Res.chambreRes.CatC.montantCa,
                            Res.presRes.desPres,Res.presRes.codePres,Res.presRes.prixPres,Res.utilRes.nom,Res.utilRes.prenom,Res.utilRes.login,Res.utilRes.telU,
                            Res.clientRes.nomCl,Res.clientRes.prenomCl);
                            */


                    }
                }
                fclose(fres);
            }
            i++;
        }
        closedir(d);
    }
     /* }Fin */
}

void rendredispochambre(FILE *fch,CHAMBRE Tch[],int s, int position )
{
    CHAMBRE Ch;
    for(int i=0;i<s;i++){
        if(i==position-1){
            Tch[i].etatC=1;
                fch  = fopen("CHAMBRE.txt","w+b");
                rewind(fch);
                for(int f = 0 ; f < s ; f++)
                {
                    Ch = Tch[f];
                    fwrite(&Ch,sizeof(CHAMBRE),1,fch);
                }
                fclose(fch);

                break;
            }
        }
}

void modifierchambre(FILE *fch ,CHAMBRE Tch[],CATEGORIE Tcat[],int s , int position , int v)
{
    CHAMBRE Ch;
    for(int i=0;i<s;i++){
        if(i==position-1){
                int choix;
                do{
                        fflush(stdin);
                    puts("1. Suite");
                    puts("2. Simple");
                    printf("Donner la categorie de la chambre");
                    scanf("%d",&choix);
                }while(choix<1 || choix>2);
                printf("Donner le telephone de la chambre : ");
                scanf("%d",&Tch[i].telC);
                fflush(stdin);
                Tch[i].CatC=Tcat[choix-1];
                fch  = fopen("CHAMBRE.txt","w+b");
                rewind(fch);
                for(int f = 0 ; f < s ; f++)
                {
                    Ch = Tch[f];
                    fwrite(&Ch,sizeof(CHAMBRE),1,fch);
                }
                fclose(fch);

                break;
            }
        }
}


void Client (FILE * f )
{
    CLIENT cli ;
    f = fopen("CLIENT.txt","a+b");
    rewind(f);
    while(fread(&cli,sizeof(CLIENT),1,f)!=0){
            printf("Nom : %s -- Prenom : %s -- Adresse : %s -- Tel : %d \n",cli.nomCl,cli.prenomCl,cli.adresseCl,cli.telCl);
    }
    fclose(f);
}
