#include "graphe.h"

// Noms des pays (selon ta matrice)
const char *PAYS[] = {
    "France (Fr)", 
    "Espagne (Es)", 
    "Portugal (Po)", 
    "Andorre (An)",
    "Italie (It)", 
    "Autriche (Au)", 
    "Suisse (Su)", 
    "Allemagne (Al)",
    "Luxembourg (Lu)", 
    "Belgique (Be)", 
    "Pays-Bas (PB)"
};

int main(void) {
    printf("========================================\n");
    printf("COLORATION DE LA CARTE D'EUROPE\n");
    printf("Algorithme de Welsh-Powell\n");
    printf("========================================\n\n");
    
    // Charger le graphe depuis le fichier
    Graphe *g = chargeGraphe("carte_europe.txt");
    
    if (!g) {
        fprintf(stderr, "Erreur : impossible de charger carte_europe.txt\n");
        return 1;
    }
    
    // Afficher la matrice d'adjacence
    afficherGraphe(g);
    
    // Appliquer Welsh-Powell
    welshPowell(g);
    
    // Libérer la mémoire
    libererGraphe(g);
    
    printf("\n========================================\n");
    printf("Coloration terminee\n");
    printf("========================================\n");
    
    return 0;
}
