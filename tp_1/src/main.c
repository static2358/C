#include "graphe.h"

int main(void) {
    printf("========================================\n");
    printf("ALGORITHME DE WELSH-POWELL\n");
    printf("VERSION NORMALE (matrice 2D)\n");
    printf("========================================\n\n");
    
    printf("EXEMPLE 1: Graphe a 5 sommets\n");
    printf("----------------------------------\n\n");
    
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
    printf("---------------------------------------------\n");
    welshPowell(g1);
    
    printf("\n");
    afficherColoration(g1);
    
    exporterDot(g1, "graph1.dot");
    
    libererGraphe(g1);
    
    printf("\n\n========================================\n");
    printf("EXEMPLE 2: Triangle (graphe complet K3)\n");
    printf("----------------------------------\n\n");
    
    Graphe *g2 = creerGraphe(3);
    ajouterArete(g2, 0, 1);
    ajouterArete(g2, 1, 2);
    ajouterArete(g2, 2, 0);
    
    afficherMatrice(g2);
    afficherDegres(g2);
    
    printf("Application de l'algorithme de Welsh-Powell:\n");
    printf("---------------------------------------------\n");
    welshPowell(g2);
    
    printf("\n");
    afficherColoration(g2);
    
    // Exporter le graphe au format DOT
    exporterDot(g2, "graph2.dot");
    
    libererGraphe(g2);
    
    return 0;
}
