#include <stdio.h>
#include <stdlib.h>
#include "structures_compte.h"
#include "Datee.h"
#include "Banque.h"

int main(void)
{
int a,b,c,num,num1,num2,quit=1;
compte le_compte;    // variable de type compte en tant que pointeur//
Liste *first=NULL;
FILE *fp;
if ((fp=fopen("banque.txt","a"))==NULL)
{
    printf("erreur.........!");
    exit(1);
}
while(quit==1)
{

printf("\nveillez choisir votre action\n");
printf("\npour creer un nouveau compte tapez 1\n");
printf("\npour vous connecter a un compte existant tapez 2\n");      //Menu//
printf("\npour cloturer un compte existant tapez 3\n");
printf("\npour consulter votre solde taper 4\n");
printf("\npour transferer un montant tapez 5\n");
scanf("%d",&a);
switch(a)
{
    case 1: printf("\nsi vous voulez creer un compte courant tapez 1\n");     //compte courant ou épargne//
     printf("\nsi vous voulez creer un compte epargne  tapez 2\n");
     scanf("%d",&b);
     saisie_aleatoire_du_num_compte(&le_compte); //appel à la fonction saisie aleatoire du num compte
     if(existe_compte(le_compte.num_compte,first)==1)
     {
       printf("Le compte existe\n");break; //Existance
     }
     switch(b)
     {
         case 1:  printf("\n vous etes un operateur particulier\n");
         saisie_du_nom(&le_compte);saisie_CIN(&le_compte);break;//appel à la fonction saisie du CIN pour les clients particuliers
         case 2:  { printf("\n vous etes une entreprise\n ");
         saisie_du_nom_entreprise(&le_compte);saisie_num_registre(&le_compte);break;}//appel à la fonction saisie du num de registre pour les entreprises

    };
    saisie_adresse(&le_compte);//enregistrement de l'adresse saisie par le client
    mot_de_passe(&le_compte);date_ouverture(&(le_compte.date_ouverture)); //enregistrement du mot de passe saisie par le client

    first=ajout_compte(le_compte,first);
    affiche_compte(le_compte.num_compte,first);
    printf("\n Votre compte a bien ete creer merci d avoir choisi team BARRY_NEBLI\n");break;
    case 2: printf("\ntapez votre numero de compte \n");
      scanf("%d",&num);        // saisie du num de compte du client//
      printf("\nsi vous voulez ajouter un montant tapez 1\n ");
      printf("\nsi vous voulez retirer un montant tapez 2\n "); //choix d'ajout ou de retrait//
      printf("\npour afficher les informations de votre compte tapez 3\n");
      printf("\npour modifier votre compte tapez 4\n");
      scanf("%d",&c);
      switch(c)
      {
          case 1: new_montant(num,first);break;                            // appel à la fonction d'ajout d'un montant//
          case 2:new_retrait(num,first);break;                           // appel à la fonction retrait d'un montant//
          case 3: affiche_compte(num,first);break;
          case 4: modif_compte(num,first);break;
      };break;
      case 3: printf("\n veillez donner votre num de compte\n");
      scanf("%d",&num);
              cloturer_compte(num,first);break;
      case 4:  printf("\n veillez donner votre num de compte\n");
               scanf("%d",&num);
          consult_solde(num,first);break;
      case 5:  printf("\n veillez donner le num de compte du donneur\n");
      scanf("%d",&num1);
      printf("\n veillez donner le num de compte du receveur\n");
      scanf("%d",&num2);
          transfert(num1,num2,first);break;
      default : printf ("\nvotre choix est non valide \n");
};
printf("\n pour revoir les actions tapez 1 sinon 0\n");
scanf("%d",&quit);
if(quit==0)
{
   fprintf(fp,"%10d%20s%10d%10s%10s%10",le_compte.num_compte,le_compte.nom,le_compte.CIN,le_compte.adresse,le_compte.mot_de_passe,le_compte.date_ouverture);
   fclose(fp);
}
}
}

