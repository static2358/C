#include "graphe_liste.h"

// Créer un nouveau noeud
noeud *creerNoeud(const char *nom) {
    noeud *n = (noeud *)malloc(sizeof(noeud));
    if (n == NULL) {
        printf("Erreur d'allocation mémoire\n");
        return NULL;
    }
    
    n->nom = (char *)malloc(strlen(nom) + 1);
    strcpy(n->nom, nom);
    n->voisins = NULL;
    
    return n;
}

// Ajouter une arête entre deux noeuds (graphe non orienté)
void ajouterArete(noeud *n1, noeud *n2) {
    if (n1 == NULL || n2 == NULL) {
        printf("Erreur: noeud NULL\n");
        return;
    }
    
    // Ajouter n2 aux voisins de n1
    voisin *v1 = (voisin *)malloc(sizeof(voisin));
    v1->noeud = n2;
    v1->suivant = n1->voisins;
    n1->voisins = v1;
    
    // Ajouter n1 aux voisins de n2 (graphe non orienté)
    voisin *v2 = (voisin *)malloc(sizeof(voisin));
    v2->noeud = n1;
    v2->suivant = n2->voisins;
    n2->voisins = v2;
}

// Afficher les voisins d'un noeud
void afficherVoisins(noeud *n) {
    if (n == NULL) return;
    
    printf("%s est voisin de: ", n->nom);
    voisin *v = n->voisins;
    while (v != NULL) {
        printf("%s ", v->noeud->nom);
        v = v->suivant;
    }
    printf("\n");
}

// Afficher tout le graphe
void afficherGraphe(noeud **graphe, int nb_noeuds) {
    printf("\n=== GRAPHE (LISTE D'ADJACENCE) ===\n\n");
    for (int i = 0; i < nb_noeuds; i++) {
        afficherVoisins(graphe[i]);
    }
}

// Calculer le degré d'un noeud
int degre(noeud *n) {
    if (n == NULL) return 0;
    
    int deg = 0;
    voisin *v = n->voisins;
    while (v != NULL) {
        deg++;
        v = v->suivant;
    }
    return deg;
}

// Libérer la mémoire du graphe
void libererGraphe(noeud **graphe, int nb_noeuds) {
    for (int i = 0; i < nb_noeuds; i++) {
        // Libérer la liste des voisins
        voisin *v = graphe[i]->voisins;
        while (v != NULL) {
            voisin *tmp = v;
            v = v->suivant;
            free(tmp);
        }
        
        // Libérer le nom et le noeud
        free(graphe[i]->nom);
        free(graphe[i]);
    }
}
