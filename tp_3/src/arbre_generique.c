#include <stdio.h>
#include <stdlib.h>
#include "arbre_generique.h"

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
    nouveauNoeud->premierFils = NULL;
    nouveauNoeud->frèreSuivant = NULL;
    
    return nouveauNoeud;
}

// Chercher un nœud dans l'arbre par son numéro
noeud *rechercheNoeud(noeud *n, int num_noeud) {
    noeud *tmpNoeud;
    
    if (n == NULL)
        return NULL;
    
    if (n->num == num_noeud)
        return n;
    
    tmpNoeud = rechercheNoeud(n->premierFils, num_noeud);
    if (tmpNoeud != NULL)
        return tmpNoeud;
    
    return rechercheNoeud(n->frèreSuivant, num_noeud);
}

// Ajouter un enfant à un parent
// L'enfant est ajouté à la fin de la liste des enfants
void ajouterEnfant(noeud *parent, noeud *enfant) {
    if (parent == NULL || enfant == NULL) {
        printf("Erreur: parent ou enfant est NULL\n");
        return;
    }
    
    if (parent->premierFils == NULL) {
        parent->premierFils = enfant;
    } else {
        noeud *frère = parent->premierFils;
        while (frère->frèreSuivant != NULL) {
            frère = frère->frèreSuivant;
        }
        frère->frèreSuivant = enfant;
    }
}

// Parcours préfixe : Nœud -> Enfants -> Frères
void parcoursPrefixe(noeud *n) {
    if (n == NULL)
        return;
    
    printf("%c(%d) ", n->val, n->num);
    parcoursPrefixe(n->premierFils);
    parcoursPrefixe(n->frèreSuivant);
}
