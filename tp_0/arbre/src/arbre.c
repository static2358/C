#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

// Compteur pour numéroter automatiquement les nœuds
static int compteur = 0;

// Créer un nouveau nœud avec un caractère
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

// Chercher un nœud dans l'arbre par son numéro
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

// Insérer un nœud comme fils gauche
// Si le parent a déjà un fils gauche, il devient le fils gauche du nouveau nœud
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

// Insérer un nœud comme fils droit
// Si le parent a déjà un fils droit, il devient le fils droit du nouveau nœud
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

// Parcours préfixe : Nœud -> Gauche -> Droit
void parcoursPrefixe(noeud *n) {
    if (n == NULL)
        return;
    
    printf("%c(%d) ", n->val, n->num);
    parcoursPrefixe(n->filsGauche);
    parcoursPrefixe(n->filsDroit);
}
