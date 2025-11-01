#include "graphe.h"

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
 
    Graphe *g = chargeGraphe("carte_europe.txt");
    
    if (!g) {
        fprintf(stderr, "Erreur : impossible de charger carte_europe.txt\n");
        return 1;
    }
    
    afficherGraphe(g);
    
    welshPowell(g);

    libererGraphe(g);
    
    printf("\n========================================\n");
    printf("Coloration terminee\n");
    printf("========================================\n");
    
    return 0;
}
