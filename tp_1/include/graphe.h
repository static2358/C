#ifndef GRAPHE_H
#define GRAPHE_H

#include <stdio.h>
#include <stdlib.h>

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
