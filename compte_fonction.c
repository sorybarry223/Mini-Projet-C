#include <stdlib.h>
#include "stdio.h"
#include "structures_compte.h"
#include <string.h>
#include <time.h>
/* ajout d'un nouveau compte */

/* ***********************************/
void saisie_CIN(compte *le_compte)               //fonction de donn�e du CIN//
{
    int num;
do
{
    printf("\ndonner votre CIN ou N� passeport pour les etrangers:\n");
    scanf("%d",&num);
}while(num<0);
le_compte->CIN=num;
}
/* ******************************/
void saisie_num_registre(compte *le_compte)   //donn�e du num de registre pour les entreprises//
{
    int num_registre;
  do
{
   printf("\ndonner votre numero de registre:\n");
   scanf("%d",&num_registre);
}while(num_registre<=0);
le_compte->num_registre=num_registre;

}
/* **************************************/
void saisie_adresse(compte *le_compte)     //fonction saisie de l'adresse//
{
printf("\ndonner votre adresse :\n");
fgetc(stdin);
fgets(le_compte->adresse,50,stdin);

}
/* **************************************/
void saisie_aleatoire_du_num_compte(compte *le_compte)
{
 srand(time(NULL));
    le_compte->num_compte=rand()%1000000+1;    //numero de compte aleatoire entre 1-10000//
    printf("\n votre numero de compte est:%d\n",le_compte->num_compte);

}
/* **************************************/
void mot_de_passe(compte *le_compte)   // saisie du mot de passe par le client//
{
    char mdp[50];
do
 {
     printf("veillez saisir votre mot de passe:");
    fgetc(stdin);
fgets(mdp,50,stdin);
 }while(strlen(mdp)<=4);    //controle sur la taille du mot de passe//
strcpy(le_compte->mot_de_passe,mdp);
}

/* **************************************/
void saisie_du_nom(compte *le_compte)     //fonction saisie du nom//
{
printf("\ndonnez votre nom :\n");
fgetc(stdin); // permet de lire  des caracteres dans le buffer mais pas l'entr�e standard (cad\n) et les retourne
fgets(le_compte->nom,50,stdin); //les val retourn�es sont lises au clavier sont mises dans le compte
}
/* **************************************/
void saisie_du_nom_entreprise(compte *le_compte)     //fonction saisie du nom de l'entreprise//
{
printf("\ndonnez le nom de votre entreprise:\n");
fgetc(stdin);
fgets(le_compte->nom,50,stdin);
}

