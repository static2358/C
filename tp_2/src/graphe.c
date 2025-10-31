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

// Charger un graphe depuis un fichier texte
Graphe *chargeGraphe(const char *nomFichier) {
    FILE *f = fopen(nomFichier, "r");
    if (!f) {
        perror("Erreur ouverture fichier");
        return NULL;
    }
    
    int nbSommets;
    if (fscanf(f, "%d", &nbSommets) != 1) {
        fprintf(stderr, "Erreur lecture nombre de sommets\n");
        fclose(f);
        return NULL;
    }
    
    Graphe *g = creerGraphe(nbSommets);
    if (!g) {
        fclose(f);
        return NULL;
    }
    
    // Lire la matrice d'adjacence
    for (int i = 0; i < nbSommets; i++) {
        for (int j = 0; j < nbSommets; j++) {
            if (fscanf(f, "%d", &g->adjacence[i][j]) != 1) {
                fprintf(stderr, "Erreur lecture matrice position [%d][%d]\n", i, j);
                libererGraphe(g);
                fclose(f);
                return NULL;
            }
            // Calculer les degrés (compter les voisins)
            if (g->adjacence[i][j] == 1) {
                g->degres[i]++;
            }
        }
    }
    
    fclose(f);
    printf("Graphe charge avec succes : %d sommets\n", nbSommets);
    return g;
}

// Afficher le graphe
void afficherGraphe(Graphe *g) {
    if (!g) return;
    
    printf("\nMatrice d'adjacence (%d sommets):\n", g->nbSommets);
    printf("   ");
    for (int i = 0; i < g->nbSommets; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    
    for (int i = 0; i < g->nbSommets; i++) {
        printf("%2d:", i);
        for (int j = 0; j < g->nbSommets; j++) {
            printf("%2d ", g->adjacence[i][j]);
        }
        printf("\n");
    }
    printf("\n");
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
    printf("\n=== ALGORITHME DE WELSH-POWELL ===\n");
    printf("Coloration de graphe par ordre decroissant de degre\n\n");
    
    // Tableau pour stocker l'ordre des sommets triés par degré
    int *sommetsOrdre = (int *)malloc(g->nbSommets * sizeof(int));
    
    // Afficher les degrés
    printf("Degres des sommets:\n");
    for (int i = 0; i < g->nbSommets; i++) {
        printf("  Sommet %d : degre %d\n", i, g->degres[i]);
    }
    printf("\n");
    
    // Étape 1 : Trier les sommets par ordre décroissant de degré
    trierSommetsParDegre(g, sommetsOrdre);
    
    printf("Ordre de traitement (par degre decroissant):\n  ");
    for (int i = 0; i < g->nbSommets; i++) {
        printf("%d ", sommetsOrdre[i]);
    }
    printf("\n\n");
    
    // Étape 2 : Assigner les couleurs
    int couleurCourante = 0;
    
    printf("Attribution des couleurs:\n");
    for (int i = 0; i < g->nbSommets; i++) {
        int sommet = sommetsOrdre[i];
        
        // Si le sommet n'a pas encore de couleur
        if (g->couleurs[sommet] == -1) {
            // Assigner la couleur courante
            g->couleurs[sommet] = couleurCourante;
            printf("  Sommet %d -> Couleur %d\n", sommet, couleurCourante);
            
            // Essayer d'assigner la même couleur aux sommets non adjacents
            for (int j = i + 1; j < g->nbSommets; j++) {
                int autreSommet = sommetsOrdre[j];
                
                // Si pas encore coloré et pas adjacent
                if (g->couleurs[autreSommet] == -1 && 
                    !couleurUtiliseeParVoisin(g, autreSommet, couleurCourante)) {
                    g->couleurs[autreSommet] = couleurCourante;
                    printf("  Sommet %d -> Couleur %d\n", autreSommet, couleurCourante);
                }
            }
            
            couleurCourante++;
        }
    }
    
    // Afficher le résultat
    afficherColoration(g);
    
    // Exporter au format DOT
    exporterDot(g, "carte_europe.dot");
    
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
    printf("\n--- RESULTAT DE LA COLORATION ---\n");
    
    // Trouver le nombre de couleurs utilisées
    int maxCouleur = -1;
    for (int i = 0; i < g->nbSommets; i++) {
        if (g->couleurs[i] > maxCouleur) {
            maxCouleur = g->couleurs[i];
        }
    }
    
    printf("Nombre de couleurs utilisees : %d\n\n", maxCouleur + 1);
    
    // Afficher par couleur
    for (int c = 0; c <= maxCouleur; c++) {
        printf("Couleur %d : ", c);
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
    
    // Noms des pays
    const char *PAYS[] = {
        "France", "Espagne", "Portugal", "Andorre",
        "Italie", "Autriche", "Suisse", "Allemagne",
        "Luxembourg", "Belgique", "Pays-Bas"
    };
    
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
        const char *nomPays = (i < 11) ? PAYS[i] : "Inconnu";
        fprintf(f, "    %d [fillcolor=%s, label=\"%s\\n(c%d)\"];\n", 
                i, couleurHTML, nomPays, couleur);
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
