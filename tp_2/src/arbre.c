#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arbre.h"


static int compteur = 0;


noeud *nouvNoeud(char carac) {
    noeud *nouveauNoeud = (noeud *)malloc(sizeof(noeud));
    
    if (nouveauNoeud == NULL) {
        printf("Erreur d'allocation mémoire\n");
        return NULL;
    }
    
    compteur++;
    nouveauNoeud->val = carac;
    nouveauNoeud->num = compteur;
    nouveauNoeud->filsGauche = NULL;
    nouveauNoeud->filsDroit = NULL;
    
    return nouveauNoeud;
}


noeud *rechercheNoeud(noeud *n, int num_noeud) {
    noeud *tmpNoeud;
    
    if (n == NULL)
        return NULL;
    
    if (n->num == num_noeud)
        return n;
    
    tmpNoeud = rechercheNoeud(n->filsGauche, num_noeud);
    if (tmpNoeud != NULL)
        return tmpNoeud;
    
    return rechercheNoeud(n->filsDroit, num_noeud);
}


void insererFG(noeud *noeudAInserer, noeud *arbre, int num_parent) {
    noeud *parent = rechercheNoeud(arbre, num_parent);
    
    if (parent == NULL) {
        printf("Erreur: noeud parent %d non trouve\n", num_parent);
        return;
    }
    
    if (noeudAInserer == NULL) {
        printf("Erreur: noeud a inserer est NULL\n");
        return;
    }
    
    if (parent->filsGauche != NULL) {
        noeudAInserer->filsGauche = parent->filsGauche;
    }
    
    parent->filsGauche = noeudAInserer;
}


void insererFD(noeud *noeudAInserer, noeud *arbre, int num_parent) {
    noeud *parent = rechercheNoeud(arbre, num_parent);
    
    if (parent == NULL) {
        printf("Erreur: noeud parent %d non trouve\n", num_parent);
        return;
    }
    
    if (noeudAInserer == NULL) {
        printf("Erreur: noeud a inserer est NULL\n");
        return;
    }
    
    if (parent->filsDroit != NULL) {
        noeudAInserer->filsDroit = parent->filsDroit;
    }
    
    parent->filsDroit = noeudAInserer;
}

void parcoursPrefixe(noeud *n) {
    if (n == NULL)
        return;
    
    printf("%c(%d) ", n->val, n->num);
    parcoursPrefixe(n->filsGauche);
    parcoursPrefixe(n->filsDroit);
}

void parcoursInfixe(noeud *n) {
    if (n == NULL)
        return;
    
    parcoursInfixe(n->filsGauche);
    printf("%c(%d) ", n->val, n->num);
    parcoursInfixe(n->filsDroit);
}

void parcoursPostfixe(noeud *n) {
    if (n == NULL)
        return;
    
    parcoursPostfixe(n->filsGauche);
    parcoursPostfixe(n->filsDroit);
    printf("%c(%d) ", n->val, n->num);
}


noeud *creerArbre(int hauteur, char valeurDepart) {
    if (hauteur == 0)
        return NULL;
    
    noeud *n = nouvNoeud(valeurDepart);
    
    n->filsGauche = creerArbre(hauteur - 1, valeurDepart + 1);
    n->filsDroit = creerArbre(hauteur - 1, valeurDepart + 1);

    
    return n;
}

noeud *creerArbreAleatoire(int hauteur, char valeurDepart) {
    if (hauteur == 0)
        return NULL;
    
    noeud *n = nouvNoeud(valeurDepart);
    
    if (rand() % 2) {
        n->filsGauche = creerArbreAleatoire(hauteur - 1, valeurDepart + 1);
    }
    
    if (rand() % 2) {
        n->filsDroit = creerArbreAleatoire(hauteur - 1, valeurDepart + 1);
    }
    
    return n;
}

static void ecrireNoeudNull(int parent_num, int nullcount, FILE *f) {
    fprintf(f, "    null%d_%d [shape=point, width=0.1, color=black, fillcolor=black];\n", parent_num, nullcount);
    fprintf(f, "    %d -> null%d_%d;\n", parent_num, parent_num, nullcount);
}

static void ecrireNoeudDot(noeud *n, FILE *f) {
    if (n == NULL) return;
    
    fprintf(f, "    %d [label=\"%c(%d)\"];\n", n->num, n->val, n->num);
    
    if (n->filsGauche != NULL) {
        fprintf(f, "    %d -> %d;\n", n->num, n->filsGauche->num);
        ecrireNoeudDot(n->filsGauche, f);
    } else {
        ecrireNoeudNull(n->num, 0, f);
    }
    
    if (n->filsDroit != NULL) {
        fprintf(f, "    %d -> %d;\n", n->num, n->filsDroit->num);
        ecrireNoeudDot(n->filsDroit, f);
    } else {
        ecrireNoeudNull(n->num, 1, f);
    }
}


void exporterArbreDot(noeud *n, const char *nomFichier) {
    FILE *f = fopen(nomFichier, "w");
    if (!f) {
        perror("Erreur lors de la creation du fichier DOT");
        return;
    }
    
    fprintf(f, "digraph ArbreBinaire {\n");
    fprintf(f, "    graph [ranksep=0.5, nodesep=0.5];\n");
    fprintf(f, "    node [shape=circle, style=filled, fillcolor=white, width=0.6, height=0.6, fixedsize=true];\n");
    fprintf(f, "    edge [color=black, arrowsize=0.8, penwidth=1.5];\n\n");
    
    if (!n) {
        fprintf(f, "\n");
    } else if (!n->filsGauche && !n->filsDroit) {
        fprintf(f, "    %d [label=\"%c(%d)\"];\n", n->num, n->val, n->num);
    } else {
        ecrireNoeudDot(n, f);
    }
    
    fprintf(f, "}\n");
    fclose(f);
    printf("\n==> Fichier DOT genere: %s\n", nomFichier);
    printf("    Pour visualiser: dot -Tpng %s -o arbre.png\n\n", nomFichier);
}
