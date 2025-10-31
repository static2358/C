#ifndef GRAPHE_H
#define GRAPHE_H

#include <stdio.h>
#include <stdlib.h>

// Déclaration anticipée de la structure
typedef struct Graphe Graphe;

// Fonctions de base
Graphe *creerGraphe(int nbSommets);
Graphe *chargeGraphe(const char *nomFichier);
void libererGraphe(Graphe *g);

// Affichage
void afficherGraphe(Graphe *g);
void afficherDegres(Graphe *g);
void afficherMatrice(Graphe *g);

// Parcours
void parcoursEnProfondeur(Graphe *g, int sommetDepart);
void parcoursEnLargeur(Graphe *g, int sommetDepart);

// Coloration de graphe (Welsh-Powell)
void welshPowell(Graphe *g);
void afficherColoration(Graphe *g);

// Export
void exporterDot(Graphe *g, const char *nomFichier);

#endif
