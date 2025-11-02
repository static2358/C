#include <stdio.h>
#include "arbre_generique.h"

int main(void) {
    noeud *racine = NULL;
    noeud *n1, *n2, *n3, *n4;
    
    printf("=== CREATION D'UN ARBRE GENERIQUE ===\n\n");
    
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
    
    // Construction d'un arbre générique
    //        A(1)
    //       /|\ 
    //     B C D
    //     |
    //     E
    
    ajouterEnfant(racine, n1);  // B est le 1er enfant de A
    ajouterEnfant(racine, n2);  // C est un frère de B
    ajouterEnfant(racine, n3);  // D est un frère de B et C
    ajouterEnfant(n1, n4);      // E est enfant de B
    
    printf("\nStructure de l'arbre:\n");
    printf("Racine: %c(%d)\n", racine->val, racine->num);
    printf("  Premier fils: %c(%d)\n", racine->premierFils->val, racine->premierFils->num);
    printf("    Frere suivant: %c(%d)\n", racine->premierFils->frèreSuivant->val, racine->premierFils->frèreSuivant->num);
    printf("    Frere suivant: %c(%d)\n", racine->premierFils->frèreSuivant->frèreSuivant->val, racine->premierFils->frèreSuivant->frèreSuivant->num);
    printf("  Premier fils de B: %c(%d)\n", racine->premierFils->premierFils->val, racine->premierFils->premierFils->num);
    
    printf("\nArbre generique cree avec succes!\n");
    
    // Test de la fonction rechercheNoeud
    printf("\n=== TEST DE RECHERCHE DE NOEUD ===\n");
    noeud *trouve = rechercheNoeud(racine, 3);
    if (trouve != NULL) {
        printf("Noeud %d trouve: val='%c'\n", trouve->num, trouve->val);
    }
    
    // Test d'ajout d'un nouvel enfant
    printf("\n=== TEST D'AJOUT D'ENFANT ===\n");
    
    noeud *n5 = nouvNoeud('F');
    printf("Nouveau noeud cree: val='%c', num=%d\n", n5->val, n5->num);
    
    printf("Ajout de F(%d) comme enfant de C(%d)...\n", n5->num, 3);
    ajouterEnfant(n2, n5);
    
    printf("F ajoute avec succes!\n");
    printf("Verification: Premier fils de C = %c(%d)\n", 
           n2->premierFils->val, n2->premierFils->num);
    
    // Test d'ajout de plusieurs enfants
    printf("\n=== TEST D'AJOUT DE PLUSIEURS ENFANTS ===\n");
    noeud *n6 = nouvNoeud('G');
    noeud *n7 = nouvNoeud('H');
    printf("Nouveaux noeuds crees: G(%d), H(%d)\n", n6->num, n7->num);
    
    printf("Ajout de G et H comme enfants de D(%d)...\n", 3);
    ajouterEnfant(n3, n6);
    ajouterEnfant(n3, n7);
    
    printf("G et H ajoutes avec succes!\n");
    printf("Verification:\n");
    printf("  Premier fils de D = %c(%d)\n", n3->premierFils->val, n3->premierFils->num);
    printf("  Frere suivant de G = %c(%d)\n", n3->premierFils->frèreSuivant->val, n3->premierFils->frèreSuivant->num);
    
    printf("\n=== STRUCTURE FINALE DE L'ARBRE ===\n");
    printf("         A(1)\n");
    printf("       / | \\\n");
    printf("      B  C  D\n");
    printf("      |  |  |\\\n");
    printf("      E  F  G H\n");
    
    // Test du parcours préfixe
    printf("\n=== TEST DU PARCOURS PREFIXE ===\n");
    printf("Parcours prefixe de l'arbre: ");
    parcoursPrefixe(racine);
    printf("\n");
    
    printf("\nOrdre de visite explique:\n");
    printf("1. A (racine)\n");
    printf("2. B (premier fils de A)\n");
    printf("3. E (premier fils de B)\n");
    printf("4. C (frere de B)\n");
    printf("5. F (premier fils de C)\n");
    printf("6. D (frere de C)\n");
    printf("7. G (premier fils de D)\n");
    printf("8. H (frere de G)\n");
    
    return 0;
}
