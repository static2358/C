#include "graphe_liste.h"

int main(void) {
    printf("=== CREATION D'UN GRAPHE AVEC LISTE D'ADJACENCE ===\n\n");
    
    // Créer les noeuds (pays européens)
    noeud *france = creerNoeud("France");
    noeud *espagne = creerNoeud("Espagne");
    noeud *allemagne = creerNoeud("Allemagne");
    noeud *italie = creerNoeud("Italie");
    noeud *suisse = creerNoeud("Suisse");
    noeud *belgique = creerNoeud("Belgique");
    
    printf("Noeuds crees:\n");
    printf("  - %s\n", france->nom);
    printf("  - %s\n", espagne->nom);
    printf("  - %s\n", allemagne->nom);
    printf("  - %s\n", italie->nom);
    printf("  - %s\n", suisse->nom);
    printf("  - %s\n", belgique->nom);
    
    // Tableau des noeuds pour faciliter la manipulation
    noeud *graphe[6] = {france, espagne, allemagne, italie, suisse, belgique};
    int nb_noeuds = 6;
    
    // Ajouter les arêtes (frontières)
    printf("\n=== AJOUT DES ARETES (FRONTIERES) ===\n\n");
    
    ajouterArete(france, espagne);
    printf("Arete ajoutee: France -- Espagne\n");
    
    ajouterArete(france, allemagne);
    printf("Arete ajoutee: France -- Allemagne\n");
    
    ajouterArete(france, italie);
    printf("Arete ajoutee: France -- Italie\n");
    
    ajouterArete(france, suisse);
    printf("Arete ajoutee: France -- Suisse\n");
    
    ajouterArete(france, belgique);
    printf("Arete ajoutee: France -- Belgique\n");
    
    ajouterArete(espagne, italie);
    printf("Arete ajoutee: Espagne -- Italie\n");
    
    ajouterArete(allemagne, suisse);
    printf("Arete ajoutee: Allemagne -- Suisse\n");
    
    ajouterArete(allemagne, belgique);
    printf("Arete ajoutee: Allemagne -- Belgique\n");
    
    ajouterArete(italie, suisse);
    printf("Arete ajoutee: Italie -- Suisse\n");
    
    // Afficher le graphe
    afficherGraphe(graphe, nb_noeuds);
    
    // Afficher les degrés
    printf("\n=== DEGRES DES NOEUDS ===\n\n");
    for (int i = 0; i < nb_noeuds; i++) {
        printf("%s: degre = %d\n", graphe[i]->nom, degre(graphe[i]));
    }
    
    // Test de recherche de voisins
    printf("\n=== TEST: LISTE DES VOISINS ===\n\n");
    printf("Voisins de France:\n");
    voisin *v = france->voisins;
    int i = 1;
    while (v != NULL) {
        printf("  %d. %s\n", i++, v->noeud->nom);
        v = v->suivant;
    }
    
    printf("\nVoisins d'Espagne:\n");
    v = espagne->voisins;
    i = 1;
    while (v != NULL) {
        printf("  %d. %s\n", i++, v->noeud->nom);
        v = v->suivant;
    }
    
    // Libérer la mémoire
    libererGraphe(graphe, nb_noeuds);
    
    printf("\n=== MEMOIRE LIBEREE ===\n");
    
    return 0;
}
