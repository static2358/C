#include <stdio.h>
#include "arbre_generique.h"

int main(void) {
    noeud *racine, *n1, *n2, *n3, *n4, *n5, *n6, *n7;
    
    racine = nouvNoeud('A');
    n1 = nouvNoeud('B');
    n2 = nouvNoeud('C');
    n3 = nouvNoeud('D');
    n4 = nouvNoeud('E');
    n5 = nouvNoeud('F');
    n6 = nouvNoeud('G');
    n7 = nouvNoeud('H');
    
    ajouterEnfant(racine, n1);
    ajouterEnfant(racine, n2);
    ajouterEnfant(racine, n3);
    ajouterEnfant(n1, n4);
    ajouterEnfant(n2, n5);
    ajouterEnfant(n3, n6);
    ajouterEnfant(n3, n7);
    
    noeud *trouve = rechercheNoeud(racine, 3);
    if (trouve != NULL) {
        printf("Noeud %d trouve: val='%c'\n", trouve->num, trouve->val);
    }
    
    printf("\nParcours prefixe: ");
    parcoursPrefixe(racine);
    printf("\n");
    
    return 0;
}
