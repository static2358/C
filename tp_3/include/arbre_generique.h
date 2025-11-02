#ifndef ARBRE_H
#define ARBRE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct noeud {
    char val;
    int num;
    struct noeud *premierFils;   
    struct noeud *frèreSuivant;   
} noeud;

noeud *nouvNoeud(char carac);
noeud *rechercheNoeud(noeud *n, int num_noeud);
void ajouterEnfant(noeud *parent, noeud *enfant);
void parcoursPrefixe(noeud *n);

#endif
