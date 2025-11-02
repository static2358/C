#ifndef GRAPHE_LISTE_H
#define GRAPHE_LISTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour un élément de la liste des voisins
typedef struct voisin {
    struct noeud *noeud;          // Pointeur vers le noeud voisin
    struct voisin *suivant;       // Prochain voisin dans la liste
} voisin;

// Structure pour un noeud du graphe
typedef struct noeud {
    char *nom;                    // Nom du pays
    voisin *voisins;              // Liste chaînée des voisins
} noeud;

// Prototypes des fonctions
noeud *creerNoeud(const char *nom);
void ajouterArete(noeud *n1, noeud *n2);
void afficherVoisins(noeud *n);
void afficherGraphe(noeud **graphe, int nb_noeuds);
int degre(noeud *n);
void libererGraphe(noeud **graphe, int nb_noeuds);

#endif
