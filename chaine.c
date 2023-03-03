#include "structures_compte.h"
#include "stdio.h"
#include <stdlib.h>
#include "Datee.h"
int existe_compte(int num,Liste *first)
{
    Liste *p=first;
    while(p != NULL)
    {
        if(p->cpte.num_compte==num)
            return 1;
        p=p->suivant;
    }
    return 0;
}
/* ***************************************************************/
Liste *ajout_compte(compte C,Liste *first)
{
    Liste *ptr;
    //C=(compte *)malloc(sizeof(compte));
    //C.solde=0;
    ptr=(Liste *)malloc(sizeof(Liste));
    ptr->cpte=C;
    //ptr=C;
    ptr->suivant=first;
    first=ptr;
    return ptr;
}
/* ******************************************************/
void affiche_compte(int num,Liste *first)     //afficher les elements relatifs à un compte
{
    Liste *pointeur=first;
    if(existe_compte(num,first)==0)
        printf("\nle compte n existe pas !\n");
    else
    {
        while(pointeur !=NULL)
        {
            if(pointeur->cpte.num_compte==num)            //recherche du numéro de compte dans la liste
                break;
            pointeur=pointeur->suivant;
        }
        printf("\n Le titulaire du compte est: %s resident a l adresse :%s\n",pointeur->cpte.nom,pointeur->cpte.adresse);
        printf("le solde du compte est :%f \n",pointeur->cpte.solde);
printf("la date d'ouverture du compte est %d/%d/%d :\n",pointeur->cpte.date_ouverture.jour,pointeur->cpte.date_ouverture.mois,pointeur->cpte.date_ouverture.annee);
        }

}
/* **************************************************/
void cloturer_compte(int num,Liste *first)
{
    int find=0;
    Liste *before;
    Liste *temp;
    temp=first;  //la variable temp et first pointent sur la meme chose
    if(existe_compte(num,first)==0)
        printf("Le compte n existe pas !\n");
        if(temp->cpte.num_compte==num)
        {
            first=first->suivant;
            free(temp);              //supprimer dans le cas ou c'est le seul compte de la liste
            printf("\n le compte numero %d a ete cloturer\n",num);
        }
    else
    {
        while(temp !=NULL)
        {
            before=temp;
            temp=temp->suivant;
            if(temp->cpte.num_compte==num)
            {
                before->suivant=temp->suivant;
                free(temp);        //supprimer  en une position quelconque en comparaison du num de compte
                find=1;
                break;
            }
        }
        if(find==1)
                {printf("\n le compte numero %d a ete cloturer\n",num);
                }
            else printf("\nle compte n existe pas\n");
    }
}
/* **************************************************/
void modif_compte(int num,Liste *first)                        //fonction pour modifier un compte
{
    int x,t=0;
    Liste *modif=first;
    if(existe_compte(num,first)==0)       //vérification d'existance
        printf("Le compte n existe pas !\n");
    else
    {
        while(modif !=NULL)
        {
            if(modif->cpte.num_compte==num)    //recherche du num de compte à modifier
            {
                printf(" pour modifier le nom tapez 1\n pour modifier l adresse tapez 2\n pour modifier le mot de passe tapez 3\n");
                scanf("%d",&x);
        switch(x)
        {
            case 1:
                      printf("\n donnez votre nouveau nom\n");
                      scanf("%s",modif->cpte.nom);
                      break;
            case 2:                                                     //modification des donnés du client
                      printf("\n donnez votre nouvel adresse\n");
                      scanf("%s",modif->cpte.adresse);break;
            case 3:
                      printf("\n donnez votre nouveau mot de passe\n");
                      scanf("%s",modif->cpte.mot_de_passe);break;
            default : printf("\nvotre choix est non valide\n");


        }
            t=1;
            }
                modif=modif->suivant;

        }
          if(t==1)
            printf("\nle compte a ete modifie\n");
         else
            printf("\nle compte n existe pas\n");
      }
}
/* **************************************************************/
void consult_solde(int num,Liste *first)          //fonction qui consulte le  solde
{
     int t=0;
     Liste *flouss;
     flouss=first;
     if(existe_compte(num,first)==0)
        printf("\n Le compte n existe pas !\n");
     else
     {
         while(flouss !=NULL)
         {
             if(flouss->cpte.num_compte==num)
             {
                 printf("votre solde est %f",flouss->cpte.solde);
                 t=1;
                 break;
             }
             flouss=flouss->suivant;
         }
     }
}
/* ************************************************************/
void transfert(int num1,int num2,Liste *first)   //fonction qui transfert d'un copte à un autre
{
    //int find1=0;
    float flouss1;
    Liste *point1,*point2;
    point1=first;
    point2=first; //ces deux pointeurs parcoureront la liste
    do
    {printf("\n donnez le montant a transferer\n");
    scanf("%f",&flouss1);
    }while(flouss1<=0);
    if(existe_compte(num1,first)==0 || existe_compte(num2,first)==0)
    {
        printf("\n Un des deux comptes n existe pas\n");
    }
    else
    {
        while(point1 !=NULL)
        {
            if(point1->cpte.num_compte==num1)
            {point1->cpte.solde=point1->cpte.solde-flouss1;
             break;
            }
            point1=point1->suivant;
        }
        while(point2 !=NULL)

        {
            if(point2->cpte.num_compte==num2)
            {point2->cpte.solde=point2->cpte.solde+flouss1;
             break;
            }
            point2=point2->suivant;
        }
        printf("\ntransaction approuvee\n");
        }
}

/* **************************************************************/
void new_montant(int num,Liste *first)
{
    float montant;
     Liste *flouss;
     flouss=first;
     if(existe_compte(num,first)==0)
     {
         printf("\nle compte n existe pas\n");   //controle sur l'existance du compte
     }
     else
     {
         while(flouss !=NULL)
         {
             if(flouss->cpte.num_compte==num)
             {
                 printf("\ndonnez le montant a ajouter sur le compte:\n");
                 scanf("%f",&montant);
                 flouss->cpte.solde=flouss->cpte.solde+montant;
             }
             flouss=flouss->suivant;
         }
     }
}
/* **************************************************************************/
float new_retrait(int num,Liste *first) //operation de retrait
{
     float montant;
     Liste *flouss;
     flouss=first;       //initialisation du pointeur flouss sur la tete de la liste
    if(existe_compte(num,first)==0)
     {
         printf("\n Le compte n existe pas\n");   //controle sur l'existance du compte
     }
     else
     {
         while(flouss !=NULL)
         {
             if(flouss->cpte.num_compte==num)  //trouvaille du compte
             {
                 do
                 {printf("\ndonnez le montant a retirer du compte:\n");
                 scanf("%f",&montant);
             }while(montant>flouss->cpte.solde || montant<0);
             flouss->cpte.solde=flouss->cpte.solde-montant;
             }
             flouss=flouss->suivant;
         }
     }
}

