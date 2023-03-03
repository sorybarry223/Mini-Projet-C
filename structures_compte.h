#ifndef STRUCTURES_COMPTE_H_INCLUDED
#define STRUCTURES_COMPTE_H_INCLUDED

#include "Datee.h"



struct compte
{
    char nom[50];  //nom de 50 caracteres
    int CIN;
    int num_registre;
    char adresse[50];  //adresse de 50 caracteres         //structure relative aux informations d'un compte//
    float solde;
    float montant;
    int num_compte;
    char mot_de_passe[50];  //mdp de 50 caracteres
    Date date_ouverture;    // variable de type Date//
};
typedef struct compte compte;


struct Liste
{
    compte cpte;      //variable de type compte                          //struct liste chainnés
    struct compte *suivant;   //pointeur de parcour de la liste
};
typedef struct Liste Liste;

void saisie_CIN(compte *le_compte);
void saisie_num_registre(compte *le_compte);
void saisie_adresse(compte *le_compte);
void saisie_aleatoire_du_num_compte(compte *le_compte);  // prototypes des fonctions dans le headers.h//
void mot_de_passe(compte *le_compte);
float montant(compte *le_compte);
float retrait(compte *le_compte);
void saisie_compte(compte *le_compte);
void creer_compte(compte *le_compte);
void saisie_du_nom(compte *le_compte);
void saisie_du_nom_entreprise(compte *le_compte);
Liste *initialisation();
Liste *ajout_compte(compte C,Liste *first);
void affiche_compte(int num,Liste *first);
void cloturer_compte(int num,Liste *first);
void modif_compte(int num,Liste *first);
void consult_solde(int num,Liste *first);
void transfert(int num1,int num2,Liste *first);
int existe_compte(int num,Liste *first);
void new_montant(int num,Liste *first);
float new_retrait(int num,Liste *first);

//**********Prototypes********************/


#endif // STRUCTURES_COMPTE_H_INCLUDED
