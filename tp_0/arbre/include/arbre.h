#ifndef ARBRE_H
#define ARBRE_H

// Structure d'un nœud de l'arbre binaire
typedef struct noeud {
    char val;
    int num;
    struct noeud *filsGauche;
    struct noeud *filsDroit;
} noeud;

// Prototypes des fonctions
noeud *nouvNoeud(char carac);
noeud *rechercheNoeud(noeud *n, int num_noeud);
void insererFG(noeud *noeudAInserer, noeud *arbre, int num_parent);
void insererFD(noeud *noeudAInserer, noeud *arbre, int num_parent);
void parcoursPrefixe(noeud *n);

#endif
