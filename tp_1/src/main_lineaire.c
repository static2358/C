#include "graphe.h"

int main(void) {
    printf("ALGORITHME DE WELSH-POWELL\n");
    printf("VERSION LINEAIRE (matrice 1D)\n");
    
    printf("Graphe a 5 sommets\n");
    
    Graphe *g1 = creerGraphe(5);
    
    ajouterArete(g1, 0, 1);
    ajouterArete(g1, 0, 2);
    ajouterArete(g1, 0, 3);
    ajouterArete(g1, 1, 2);
    ajouterArete(g1, 1, 3);
    ajouterArete(g1, 2, 3);
    ajouterArete(g1, 2, 4);
    ajouterArete(g1, 3, 4);
    
    afficherMatrice(g1);
    afficherDegres(g1);
    
    printf("Application de l'algorithme de Welsh-Powell:\n");
    welshPowell(g1);
    
    printf("\n");
    afficherColoration(g1);
    
    exporterDot(g1, "graph1_lineaire.dot");
    
    libererGraphe(g1);
       
    return 0;
}
