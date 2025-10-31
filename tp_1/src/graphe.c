#include "graphe.h"

// Structure du graphe - VERSION NORMALE (matrice 2D)
struct Graphe {
    int nbSommets;          
    int **adjacence;        // Tableau 2D : int**
    int *couleurs;          
    int *degres;            
};

// Créer un graphe avec n sommets
Graphe *creerGraphe(int nbSommets) {
    Graphe *g = (Graphe *)malloc(sizeof(Graphe));
    g->nbSommets = nbSommets;

    g->adjacence = (int **)malloc(nbSommets * sizeof(int *));
    for (int i = 0; i < nbSommets; i++) {
        g->adjacence[i] = (int *)calloc(nbSommets, sizeof(int));
    }
    
    g->couleurs = (int *)malloc(nbSommets * sizeof(int));
    g->degres = (int *)malloc(nbSommets * sizeof(int));
    
    for (int i = 0; i < nbSommets; i++) {
        g->couleurs[i] = -1;
        g->degres[i] = 0;
    }
    
    return g;
}

// Ajouter une arête entre deux sommets
void ajouterArete(Graphe *g, int sommet1, int sommet2) {
    g->adjacence[sommet1][sommet2] = 1;
    g->adjacence[sommet2][sommet1] = 1;
    g->degres[sommet1]++;
    g->degres[sommet2]++;
}

// Trier les sommets par ordre décroissant de degré
void trierSommetsParDegre(Graphe *g, int *sommetsOrdre) {
    // Initialiser l'ordre des sommets
    for (int i = 0; i < g->nbSommets; i++) {
        sommetsOrdre[i] = i;
    }
    
    // Tri à bulles par degré décroissant
    for (int i = 0; i < g->nbSommets - 1; i++) {
        for (int j = 0; j < g->nbSommets - i - 1; j++) {
            if (g->degres[sommetsOrdre[j]] < g->degres[sommetsOrdre[j + 1]]) {
                int temp = sommetsOrdre[j];
                sommetsOrdre[j] = sommetsOrdre[j + 1];
                sommetsOrdre[j + 1] = temp;
            }
        }
    }
}

// Vérifier si une couleur est utilisée par un voisin
int couleurUtiliseeParVoisin(Graphe *g, int sommet, int couleur) {
    for (int i = 0; i < g->nbSommets; i++) {
        if (g->adjacence[sommet][i] == 1 && g->couleurs[i] == couleur) {
            return 1;
        }
    }
    return 0;
}

// Algorithme de Welsh-Powell
void welshPowell(Graphe *g) {
    // Tableau pour stocker l'ordre des sommets triés par degré
    int *sommetsOrdre = (int *)malloc(g->nbSommets * sizeof(int));
    
    // Étape 1 : Trier les sommets par ordre décroissant de degré
    trierSommetsParDegre(g, sommetsOrdre);
    
    printf("Ordre des sommets par degre decroissant: ");
    for (int i = 0; i < g->nbSommets; i++) {
        printf("%d(degre=%d) ", sommetsOrdre[i], g->degres[sommetsOrdre[i]]);
    }
    printf("\n\n");
    
    // Étape 2 : Assigner les couleurs
    int couleurCourante = 0;
    
    for (int i = 0; i < g->nbSommets; i++) {
        int sommet = sommetsOrdre[i];
        
        // Si le sommet n'a pas encore de couleur
        if (g->couleurs[sommet] == -1) {
            // Assigner la couleur courante
            g->couleurs[sommet] = couleurCourante;
            printf("Sommet %d -> Couleur %d\n", sommet, couleurCourante);
            
            // Essayer d'assigner la même couleur aux sommets non adjacents
            for (int j = i + 1; j < g->nbSommets; j++) {
                int autreSommet = sommetsOrdre[j];
                
                // Si pas encore coloré et pas adjacent
                if (g->couleurs[autreSommet] == -1 && 
                    !couleurUtiliseeParVoisin(g, autreSommet, couleurCourante)) {
                    g->couleurs[autreSommet] = couleurCourante;
                    printf("Sommet %d -> Couleur %d\n", autreSommet, couleurCourante);
                }
            }
            
            couleurCourante++;
            printf("\n");
        }
    }
    
    free(sommetsOrdre);
}

// Afficher la matrice d'adjacence
void afficherMatrice(Graphe *g) {
    printf("Matrice d'adjacence:\n");
    printf("   ");
    for (int i = 0; i < g->nbSommets; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    for (int i = 0; i < g->nbSommets; i++) {
        printf("%d: ", i);
        for (int j = 0; j < g->nbSommets; j++) {
            printf("%d ", g->adjacence[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Afficher les degrés
void afficherDegres(Graphe *g) {
    printf("Degres des sommets:\n");
    for (int i = 0; i < g->nbSommets; i++) {
        printf("Sommet %d: degre = %d\n", i, g->degres[i]);
    }
    printf("\n");
}

// Afficher le résultat de la coloration
void afficherColoration(Graphe *g) {
    printf("Resultat de la coloration:\n");
    
    // Trouver le nombre de couleurs utilisées
    int maxCouleur = -1;
    for (int i = 0; i < g->nbSommets; i++) {
        if (g->couleurs[i] > maxCouleur) {
            maxCouleur = g->couleurs[i];
        }
    }
    
    printf("Nombre de couleurs utilisees: %d\n\n", maxCouleur + 1);
    
    // Afficher par couleur
    for (int c = 0; c <= maxCouleur; c++) {
        printf("Couleur %d: ", c);
        for (int i = 0; i < g->nbSommets; i++) {
            if (g->couleurs[i] == c) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
}

// Exporter le graphe au format DOT avec coloration
void exporterDot(Graphe *g, const char *nomFichier) {
    FILE *f = fopen(nomFichier, "w");
    if (!f) {
        perror("Erreur lors de la creation du fichier DOT");
        return;
    }
    
    fprintf(f, "graph G {\n");
    fprintf(f, "    node [style=filled];\n");
    
    // Couleurs pour la visualisation (palette)
    const char *couleursPalette[] = {
        "red", "blue", "green", "yellow", 
        "pink", "cyan", "violet", "gold", "coral", "lime"
    };
    int nbCouleursPalette = 10;
    
    // Définir les sommets avec leurs couleurs
    for (int i = 0; i < g->nbSommets; i++) {
        int couleur = g->couleurs[i];
        const char *couleurHTML = couleursPalette[couleur % nbCouleursPalette];
        fprintf(f, "    %d [fillcolor=%s, label=\"%d\\n(c%d)\"];\n", 
                i, couleurHTML, i, couleur);
    }
    
    // Définir les arêtes (parcourir seulement la moitié supérieure pour éviter les doublons)
    for (int i = 0; i < g->nbSommets; i++) {
        for (int j = i + 1; j < g->nbSommets; j++) {
            if (g->adjacence[i][j] == 1) {
                fprintf(f, "    %d -- %d;\n", i, j);
            }
        }
    }
    
    fprintf(f, "}\n");
    fclose(f);
    printf("\n==> Fichier DOT genere: %s\n", nomFichier);
    printf("    Pour visualiser: dot -Tpng %s -o graph.png\n\n", nomFichier);
}

// Libérer la mémoire du graphe
void libererGraphe(Graphe *g) {
    for (int i = 0; i < g->nbSommets; i++) {
        free(g->adjacence[i]);
    }
    free(g->adjacence);
    free(g->couleurs);
    free(g->degres);
    free(g);
}
