#ifndef CHAINE_H_INCLUDED
#define CHAINE_H_INCLUDED


typedef struct Element Element;
struct Element
{
    char nom;
    int CIN;
    int num_registre;
    char adresse;         // creation d'un element de type compte
    float solde;
    float montant;
    int num_compte;
    char mot_de_passe;
    Element *suivant;
};
typedef struct Liste Liste;
struct Liste
{
    Element *premier;
};
Liste *initialisation();
void inserer(Liste *liste,nv_CIN,nv_num_registre,nv_solde,nv_montant,nv_num_compte,nv_nom,nv_adresse,nv_mot_de_passe);


#endif // CHAINE_H_INCLUDED
