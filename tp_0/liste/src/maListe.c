#include <stdio.h>
#include "liste.h"

/**
 * Fonction main pour tester les fonctionnalités de la liste doublement chaînée
 */
int main(void) {
    cellule *liste = NULL;
    point p;
    cellule *nouvelleCel;
    
    
    printf("1. Insertion de 5 points initiaux:\n");
    
    p.x = 0; p.y = 0;
    nouvelleCel = NouvCel(p);
    InsererCellule(0, nouvelleCel, &liste);
    
    p.x = 10; p.y = 0;
    nouvelleCel = NouvCel(p);
    InsererCellule(1, nouvelleCel, &liste);
    
    p.x = 10; p.y = 10;
    nouvelleCel = NouvCel(p);
    InsererCellule(2, nouvelleCel, &liste);
    
    p.x = 5; p.y = 15;
    nouvelleCel = NouvCel(p);
    InsererCellule(3, nouvelleCel, &liste);
    
    p.x = 0; p.y = 10;
    nouvelleCel = NouvCel(p);
    InsererCellule(4, nouvelleCel, &liste);
    
    Afficher(liste);
    
    printf("2. Insertion d'un nouveau point (7, 5) à la position 2:\n");
    p.x = 7; p.y = 5;
    nouvelleCel = NouvCel(p);
    InsererCellule(2, nouvelleCel, &liste);
    Afficher(liste);
    
    printf("3. Suppression du point à la position 3:\n");
    SupprimeCellule(3, &liste);
    Afficher(liste);
    
   
    printf("4. Insertion d'un point (-5, -5) au début (position 0):\n");
    p.x = -5; p.y = -5;
    nouvelleCel = NouvCel(p);
    InsererCellule(0, nouvelleCel, &liste);
    Afficher(liste);
    
    printf("5. Suppression du premier point (position 1):\n");
    SupprimeCellule(1, &liste);
    Afficher(liste);
    
    printf("Liste finale de la forme polygonale:\n");
    Afficher(liste);
        
    return 0;
}
