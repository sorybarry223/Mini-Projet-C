#ifndef DATEE_H_INCLUDED
#define DATEE_H_INCLUDED

struct Date
{
    int jour;
    int mois;           //structure relative à une date//
    int annee;
};
typedef struct Date Date;
void date_ouverture(Date *la_date);  // fonction date de type date//

#endif // DATEE_H_INCLUDED
