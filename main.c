/**
 * \file main.c
 * \brief Programme de tests.
 * \author Yann Feunteun
 * \version 0.1
 * \date 19 Septembre 2014
 *
 * Programme de test pour l'objet de gestion des informations avec une liste chaînée.
 *
 */


#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int main(int argc, char* argv[])
{

    FILE *fp;
    Information* dico = NULL;

    if (argc < 2)
       return EXIT_FAILURE;

    if ((fp = fopen(argv[1], "r")) == NULL) {
       printf("\n Pb d'ouverture du fichier %s \n", argv[1]);
       return EXIT_FAILURE;
    }

    dico = remplir(dico, fp);
    afficher(dico);

    return EXIT_SUCCESS;
}

