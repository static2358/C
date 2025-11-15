#include "graphe.h"

int main(void) {
 
    Graphe *g = chargeGraphe("carte_europe.txt");
    
    if (!g) {
        fprintf(stderr, "Erreur : impossible de charger carte_europe.txt\n");
        return 1;
    }
    
    afficherGraphe(g);
    
    welshPowell(g);

    libererGraphe(g);
    
    return 0;
}
