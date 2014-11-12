/**
 * \file liste.c
 * \brief Fonctions permettant de manipuler une liste chainée
 * \author Yann Feunteun
 * \version 0.1
 * \date 19 Septembre 2014
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "liste.h"


Information* remplir(Information* dico, FILE* flux)
{
   char buffer[512];
   Information* tmp = NULL; /* element d'insertion */

    while (lireMot(flux, &buffer[0])) {
        tmp = existe(dico, buffer);
        if(tmp == NULL) /* le mot n'est pas présent dans le tableau */
        {
            dico = insererEnTete(dico, buffer);
        } else {                    /* Le mot est déjà présent dans le tableau */
            ++
            tmp->nbOcc;
        }
    }

    return dico;
}

void afficher(Information* dico)
{
    Information *local_cpy = dico;  /* copie de l'index pour éviter de modifier le pointeur */
    while(local_cpy != NULL)
    {
        printf("%s => %d\n", local_cpy->mot, local_cpy->nbOcc);
        local_cpy = local_cpy->suivant;
    }
}

Information* existe(Information* dico, char* mot)
{
    Information *local_cpy = dico;  /* copie de l'index pour éviter de modifier le pointeur */
    while(local_cpy != NULL)
    {
        if(strcmp(mot, local_cpy->mot) == 0) {
            return local_cpy;
        }
        local_cpy = local_cpy->suivant;
    }
    return NULL;
}

int lireMot(FILE * fp, char * mot) {
   int i;
   char c;
   while ( ! (isalpha (c = fgetc(fp)))) {
      if  (c == EOF) {
         mot[0] = '\0';
         return 0;
      }
   }
   mot[0] = c & 0xdf;
   i = 1;
   while ( isalpha (c = fgetc(fp))) {
      mot[i] = c & 0xdf;
      i++;
   }
   mot[i] = '\0';
   return 1;
}

Information* insererEnTete(Information* dico, char * mot)
{

    Information * elem = malloc(sizeof(Information));

    if(elem!=NULL)
    {
        elem->mot = (char *)malloc(strlen(mot) + 1 * sizeof(char));
        // Affecter les bonnes valeurs dans chacun de ses champs
        strcpy(elem->mot, mot);
        elem->nbOcc = 1;
        elem->suivant = dico;

        // Le nouvel élément devant se situer en tête de la liste, son adresse est la nouvelle adresse de la structure.
        dico=elem;
    }
    else
        exit(EXIT_FAILURE);

    return dico;


}
