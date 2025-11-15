#ifndef ARBRE_H
#define ARBRE_H

typedef struct noeud {
    char val;
    int num;
    struct noeud *filsGauche;
    struct noeud *filsDroit;
} noeud;

noeud *nouvNoeud(char carac);
noeud *rechercheNoeud(noeud *n, int num_noeud);
void insererFG(noeud *noeudAInserer, noeud *arbre, int num_parent);
void insererFD(noeud *noeudAInserer, noeud *arbre, int num_parent);
void parcoursPrefixe(noeud *n);

#endif
