#ifndef GRAPHE_H
#define GRAPHE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Graphe Graphe;

Graphe *creerGraphe(int nbSommets);
Graphe *chargeGraphe(const char *nomFichier);
void libererGraphe(Graphe *g);

void afficherGraphe(Graphe *g);
void afficherDegres(Graphe *g);
void afficherMatrice(Graphe *g);
void parcoursEnProfondeur(Graphe *g, int sommetDepart);
void parcoursEnLargeur(Graphe *g, int sommetDepart);
void welshPowell(Graphe *g);
void afficherColoration(Graphe *g);
void exporterDot(Graphe *g, const char *nomFichier);

#endif
