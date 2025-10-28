#include <stdio.h>
#include "arbre.h"

int main(void) {
    noeud *racine = NULL;
    noeud *n1, *n2, *n3, *n4;
    
    printf("=== CREATION D'UN ARBRE BINAIRE ===\n\n");
    
    // Création de plusieurs nœuds
    printf("Creation de noeuds...\n");
    
    racine = nouvNoeud('A');
    printf("Noeud cree: val='%c', num=%d\n", racine->val, racine->num);
    
    n1 = nouvNoeud('B');
    printf("Noeud cree: val='%c', num=%d\n", n1->val, n1->num);
    
    n2 = nouvNoeud('C');
    printf("Noeud cree: val='%c', num=%d\n", n2->val, n2->num);
    
    n3 = nouvNoeud('D');
    printf("Noeud cree: val='%c', num=%d\n", n3->val, n3->num);
    
    n4 = nouvNoeud('E');
    printf("Noeud cree: val='%c', num=%d\n", n4->val, n4->num);
    
    printf("\nConstruction de l'arbre...\n");
    
    // Construction d'un arbre simple
    //        A(1)
    //       /    \
    //     B(2)   C(3)
    //     /  \
    //   D(4) E(5)
    
    racine->filsGauche = n1;
    racine->filsDroit = n2;
    n1->filsGauche = n3;
    n1->filsDroit = n4;
    
    printf("\nStructure de l'arbre:\n");
    printf("Racine: %c(%d)\n", racine->val, racine->num);
    printf("  Fils gauche: %c(%d)\n", racine->filsGauche->val, racine->filsGauche->num);
    printf("    Fils gauche: %c(%d)\n", racine->filsGauche->filsGauche->val, racine->filsGauche->filsGauche->num);
    printf("    Fils droit: %c(%d)\n", racine->filsGauche->filsDroit->val, racine->filsGauche->filsDroit->num);
    printf("  Fils droit: %c(%d)\n", racine->filsDroit->val, racine->filsDroit->num);
    
    printf("\nArbre binaire cree avec succes!\n");
    
    // Test de la fonction rechercheNoeud
    printf("\n=== TEST DE RECHERCHE DE NOEUD ===\n");
    noeud *trouve = rechercheNoeud(racine, 3);
    if (trouve != NULL) {
        printf("Noeud %d trouve: val='%c'\n", trouve->num, trouve->val);
    }
    
    // Test de la fonction insererFG
    printf("\n=== TEST D'INSERTION EN FILS GAUCHE ===\n");
    
    // Créer un nouveau nœud F
    noeud *n5 = nouvNoeud('F');
    printf("Nouveau noeud cree: val='%c', num=%d\n", n5->val, n5->num);
    
    // Insérer F comme fils gauche du nœud 3 (C)
    printf("Insertion de F(%d) comme fils gauche de C(%d)...\n", n5->num, 3);
    insererFG(n5, racine, 3);
    
    printf("F insere avec succes!\n");
    printf("Verification: Fils gauche de C = %c(%d)\n", 
           racine->filsDroit->filsGauche->val, 
           racine->filsDroit->filsGauche->num);
    
    // Test d'insertion avec remplacement
    printf("\n=== TEST D'INSERTION AVEC REMPLACEMENT ===\n");
    noeud *n6 = nouvNoeud('G');
    printf("Nouveau noeud cree: val='%c', num=%d\n", n6->val, n6->num);
    
    // Insérer G comme fils gauche du nœud 2 (B) qui a déjà D comme fils gauche
    printf("Insertion de G(%d) comme fils gauche de B(%d) qui a deja D(%d)...\n", 
           n6->num, 2, 4);
    insererFG(n6, racine, 2);
    
    printf("G insere avec succes!\n");
    printf("Verification:\n");
    printf("  Fils gauche de B = %c(%d)\n", 
           racine->filsGauche->filsGauche->val, 
           racine->filsGauche->filsGauche->num);
    printf("  Fils gauche de G = %c(%d)\n", 
           racine->filsGauche->filsGauche->filsGauche->val, 
           racine->filsGauche->filsGauche->filsGauche->num);
    
    printf("\n=== STRUCTURE FINALE DE L'ARBRE ===\n");
    printf("       A(1)\n");
    printf("      /    \\\n");
    printf("    B(2)   C(3)\n");
    printf("     /\\      /\n");
    printf("   G(7) E(5) F(6)\n");
    printf("    /\n");
    printf("  D(4)\n");
    
    // Test du parcours préfixe
    printf("\n=== TEST DU PARCOURS PREFIXE ===\n");
    printf("Parcours prefixe de l'arbre: ");
    parcoursPrefixe(racine);
    printf("\n");
    
    printf("\nOrdre de visite explique:\n");
    printf("1. A (racine)\n");
    printf("2. B (fils gauche de A)\n");
    printf("3. G (fils gauche de B)\n");
    printf("4. D (fils gauche de G)\n");
    printf("5. E (fils droit de B)\n");
    printf("6. C (fils droit de A)\n");
    printf("7. F (fils gauche de C)\n");
    
    return 0;
}
