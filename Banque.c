/*#include <stdio.h>
#include <stdlib.h>
#include "structures_compte.h"
#include "Datee.h"

int sauvegarde_banque(compte *premier)
{
    FILE *fic;
    compte *ptr=premier;
    // ouverture du fichier pour l'�criture
    fic= fopen("banque.txt", "w");
    if(fic==NULL)
    {
        fprintf(stderr,"\n Erreur d'ouverture\n");
        exit(1);
    }
    // ecriture du compte dans le fichier
    while(ptr != NULL)
    {
        fwrite(ptr, sizeof(compte), 1, fic);
        ptr=ptr->suivant;
    }
    if(fwrite !=0)
        printf("\n");
    else
        printf("Erreur ouverture fichier\n");
    fclose(fic);
    return 0;
}
*/