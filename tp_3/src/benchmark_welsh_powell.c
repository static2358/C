#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SOMMETS 100000

struct Graphe {
    int nb_sommets;
    int **matrice_adjacence;  
};

struct Graphe* creerGraphe(int nb_sommets) {
    struct Graphe* graphe = (struct Graphe*)malloc(sizeof(struct Graphe));
    graphe->nb_sommets = nb_sommets;
    
    graphe->matrice_adjacence = (int**)malloc(nb_sommets * sizeof(int*));
    for (int i = 0; i < nb_sommets; i++) {
        graphe->matrice_adjacence[i] = (int*)calloc(nb_sommets, sizeof(int));
    }
    
    return graphe;
}

void libererGraphe(struct Graphe* graphe) {
    for (int i = 0; i < graphe->nb_sommets; i++) {
        free(graphe->matrice_adjacence[i]);
    }
    free(graphe->matrice_adjacence);
    free(graphe);
}

void ajouterArete(struct Graphe* graphe, int u, int v) {
    graphe->matrice_adjacence[u][v] = 1;
    graphe->matrice_adjacence[v][u] = 1;
}

struct Graphe* genererGraphe(int nb_sommets) {
    struct Graphe* graphe = creerGraphe(nb_sommets);
    
    for (int i = 0; i < nb_sommets; i++) {
        for (int j = i + 1; j < nb_sommets; j++) {  
            if (rand() % 2) {  
                ajouterArete(graphe, i, j);
            }
        }
    }
    
    return graphe;
}

int compterAretes(struct Graphe* graphe) {
    int compteur = 0;
    for (int i = 0; i < graphe->nb_sommets; i++) {
        for (int j = i + 1; j < graphe->nb_sommets; j++) {
            if (graphe->matrice_adjacence[i][j] == 1) {
                compteur++;
            }
        }
    }
    return compteur;
}

int welshPowell(struct Graphe* graphe) {
    int* degre = (int*)calloc(graphe->nb_sommets, sizeof(int));
    int i, j, couleur_courante;

    for (i = 0; i < graphe->nb_sommets; i++) {
        for (j = 0; j < graphe->nb_sommets; j++) {
            if (graphe->matrice_adjacence[i][j] == 1)
                degre[i]++;
        }
    }

    int* sommets_tries = (int*)malloc(graphe->nb_sommets * sizeof(int));
    for (i = 0; i < graphe->nb_sommets; i++)
        sommets_tries[i] = i;

    for (i = 0; i < graphe->nb_sommets - 1; i++) {
        for (j = 0; j < graphe->nb_sommets - i - 1; j++) {
            if (degre[sommets_tries[j]] < degre[sommets_tries[j + 1]]) {
                int temp = sommets_tries[j];
                sommets_tries[j] = sommets_tries[j + 1];
                sommets_tries[j + 1] = temp;
            }
        }
    }

    int* couleur = (int*)malloc(graphe->nb_sommets * sizeof(int));
    for (i = 0; i < graphe->nb_sommets; i++)
        couleur[i] = -1;

    couleur_courante = 0;

    for (i = 0; i < graphe->nb_sommets; i++) {
        int sommet = sommets_tries[i];
        
        if (couleur[sommet] == -1) {
            couleur[sommet] = couleur_courante;
            
            for (j = i + 1; j < graphe->nb_sommets; j++) {
                int v = sommets_tries[j];
                
                if (couleur[v] == -1) {
                    if (graphe->matrice_adjacence[sommet][v] == 0) {
                        int peut_colorer = 1;
                        int k = 0;
                        while (k < graphe->nb_sommets && peut_colorer) {
                            if (graphe->matrice_adjacence[v][k] == 1 && couleur[k] == couleur_courante) {
                                peut_colorer = 0;
                            }
                            k++;
                        }
                        if (peut_colorer) {
                            couleur[v] = couleur_courante;
                        }
                    }
                }
            }
            couleur_courante++;
        }
    }

    int nb_couleurs = couleur_courante;

    free(degre);
    free(sommets_tries);
    free(couleur);

    return nb_couleurs;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <nombre_de_sommets>\n", argv[0]);
        printf("Exemple: %s 1000\n", argv[0]);
        return 1;
    }
    
    int nb_sommets = atoi(argv[1]);
    
    if (nb_sommets <= 0 || nb_sommets > MAX_SOMMETS) {
        printf("Erreur: nombre de sommets doit etre entre 1 et %d\n", MAX_SOMMETS);
        return 1;
    }
    
    srand(time(NULL));
    

    printf("Nombre de sommets: %d\n", nb_sommets);
    
    printf("Generation du graphe aleatoire...\n");
    struct Graphe* graphe = genererGraphe(nb_sommets);
    
    int nb_aretes = compterAretes(graphe);
    printf("Nombre d'aretes: %d\n", nb_aretes);
    printf("Densite: %.2f%%\n", (double)nb_aretes / ((nb_sommets * (nb_sommets - 1)) / 2) * 100);
    
    printf("Application de l'algorithme de Welsh-Powell...\n");
    int nb_couleurs = welshPowell(graphe);
    
    printf("RESULTAT\n");
    printf("Nombre de couleurs utilisees: %d\n", nb_couleurs);
    
    libererGraphe(graphe);
    
    return 0;
}
