#ifndef LISTE_H
#define LISTE_H

// Structure pour représenter un point avec ses coordonnées
typedef struct {
    int x;
    int y;
} point;

// Structure pour une cellule de la liste doublement chaînée
typedef struct cellule {
    point p;
    struct cellule *suiv;
    struct cellule *prec;
} cellule;

// Prototypes des fonctions
cellule *NouvCel(point p);
void InsererCellule(int pl, cellule *cel, cellule **liste);
void SupprimeCellule(int pl, cellule **liste);
void Afficher(cellule *liste);

#endif
