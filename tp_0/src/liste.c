#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

/**
 * Fonction qui alloue l'espace mémoire pour une cellule
 * Remplit les champs de la structure et retourne un pointeur sur cette cellule
 */
cellule *NouvCel(point p) {
    cellule *nouvelleCellule = (cellule *)malloc(sizeof(cellule));
    
    if (nouvelleCellule == NULL) {
        printf("Erreur d'allocation mémoire\n");
        return NULL;
    }
    
    nouvelleCellule->p = p;
    nouvelleCellule->suiv = NULL;
    nouvelleCellule->prec = NULL;
    
    return nouvelleCellule;
}

/**
 * Fonction qui insère la cellule cel après la position pl dans la liste
 */
void InsererCellule(int pl, cellule *cel, cellule **liste) {
    if (cel == NULL) {
        printf("Cellule à insérer est NULL\n");
        return;
    }
    
    // Cas 1: Liste vide ou insertion en position 0
    if (*liste == NULL || pl == 0) {
        cel->suiv = *liste;
        cel->prec = NULL;
        if (*liste != NULL) {
            (*liste)->prec = cel;
        }
        *liste = cel;
        return;
    }
    
    // Cas 2: Parcourir la liste jusqu'à la position pl
    cellule *courant = *liste;
    int position = 1;
    
    while (courant != NULL && position < pl) {
        courant = courant->suiv;
        position++;
    }
    
    // Si on a atteint la fin de la liste
    if (courant == NULL) {
        printf("Position %d hors limites\n", pl);
        return;
    }
    
    // Insertion après la position pl
    cel->suiv = courant->suiv;
    cel->prec = courant;
    
    if (courant->suiv != NULL) {
        courant->suiv->prec = cel;
    }
    
    courant->suiv = cel;
}

/**
 * Fonction qui supprime la cellule à la position pl dans la liste
 */
void SupprimeCellule(int pl, cellule **liste) {
    if (*liste == NULL) {
        printf("Liste vide, impossible de supprimer\n");
        return;
    }
    
    cellule *courant = *liste;
    int position = 1;
    
    // Cas particulier: suppression de la première cellule
    if (pl == 1) {
        *liste = courant->suiv;
        if (*liste != NULL) {
            (*liste)->prec = NULL;
        }
        free(courant);
        return;
    }
    
    // Parcourir jusqu'à la position pl
    while (courant != NULL && position < pl) {
        courant = courant->suiv;
        position++;
    }
    
    if (courant == NULL) {
        printf("Position %d hors limites\n", pl);
        return;
    }
    
    // Supprimer la cellule courante
    courant->prec->suiv = courant->suiv;
    
    if (courant->suiv != NULL) {
        courant->suiv->prec = courant->prec;
    }
    
    free(courant);
}

/**
 * Fonction qui affiche tous les points de la liste
 */
void Afficher(cellule *liste) {
    if (liste == NULL) {
        printf("Liste vide\n");
        return;
    }
    
    cellule *courant = liste;
    int position = 1;
    
    while (courant != NULL) {
        printf("Point %d: (%d, %d)\n", position, courant->p.x, courant->p.y);
        courant = courant->suiv;
        position++;
    }
}
