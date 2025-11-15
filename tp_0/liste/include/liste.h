#ifndef LISTE_H
#define LISTE_H

typedef struct {
    int x;
    int y;
} point;

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
