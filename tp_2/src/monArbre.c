#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arbre.h"

int main(void) {
    srand(time(NULL));

    printf("Creation d'un arbre aleatoire de hauteur 6...\n");
    noeud *arbre = creerArbreAleatoire(6, 'A');
    
    if (arbre == NULL) {
        printf("Erreur: arbre vide\n");
        return 1;
    }
    
    printf("Arbre cree avec succes!\n\n");

    exporterArbreDot(arbre, "arbre_binaire.dot");
    
    printf("PARCOURS PREFIXE : \n");
    parcoursPrefixe(arbre);
    printf("\n\n");
    
    printf("PARCOURS INFIXE : \n");
    parcoursInfixe(arbre);
    printf("\n\n");
    
    printf("PARCOURS POSTFIXE : \n");
    parcoursPostfixe(arbre);
    printf("\n\n");   
    return 0;
}