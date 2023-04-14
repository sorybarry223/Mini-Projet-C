#include "Datee.h"
#include <stdio.h>

void date_ouverture(Date *la_date){
     int jmax;
do
{
    printf("\ndonner un mois\n");
     scanf("%d",&(la_date->mois));
}while(la_date->mois<=0||la_date->mois>12);  //controle de saisie sur le mois//
switch (la_date->mois)
{
    case 1: jmax=31;break;
    case 2: jmax=29;break;
    case 3: jmax=31;break;
    case 4: jmax=30;break;
    case 5: jmax=31;break;
    case 6: jmax=30;break;
    case 7: jmax=31;break;
    case 8: jmax=31;break;
    case 9: jmax=30;break;
    case 10: jmax=31;break;
    case 11: jmax=30;break;
    case 12: jmax=31;break;

}
do
 {
     printf("\ndonner un jour\n");
     scanf("%d",&(la_date->jour));
 }while(la_date->jour<=0||la_date->jour>jmax);   //controle de saisie sur la date y compris les mois de 28-29-30-31 jours//
do
{
    printf("\ndonner une annee\n");
     scanf("%d",&(la_date->annee));
}while(la_date->annee!=2020);                // controle sur l'ann�e//
}
