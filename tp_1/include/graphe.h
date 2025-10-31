#ifndef GRAPHE_H
#define GRAPHE_H

#include <stdio.h>
#include <stdlib.h>

/*
 * DEUX IMPLÉMENTATIONS DISPONIBLES :
 * 
 * 1. graphe.c + main.c : VERSION NORMALE
 *    - Matrice d'adjacence : int **adjacence (tableau 2D)
 *    - Accès : adjacence[i][j]
 *    - Allocation : n+1 malloc
 * 
 * 2. graphe_lineaire.c + main_lineaire.c : VERSION AMÉLIORÉE
 *    - Matrice d'adjacence : int *adjacence (tableau 1D linéarisé)
 *    - Accès : adjacence[i * nbSommets + j]
 *    - Allocation : 1 seul calloc (n²)
 *    - Avantages : mémoire contigüe, cache-friendly, moins de malloc/free
 * 
 * NOTE : La structure Graphe est redéfinie dans chaque fichier .c
 *        pour permettre les deux implémentations différentes.
 */

// Fonctions de base
typedef struct Graphe Graphe;  // Forward declaration

Graphe *creerGraphe(int nbSommets);
void ajouterArete(Graphe *g, int sommet1, int sommet2);
void libererGraphe(Graphe *g);

// Algorithme de coloration
void welshPowell(Graphe *g);
void trierSommetsParDegre(Graphe *g, int *sommetsOrdre);
int couleurUtiliseeParVoisin(Graphe *g, int sommet, int couleur);

// Affichage
void afficherMatrice(Graphe *g);
void afficherDegres(Graphe *g);
void afficherColoration(Graphe *g);

// Export
void exporterDot(Graphe *g, const char *nomFichier);

#endif
