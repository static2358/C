# TP 1 - Coloration de Graphes avec Welsh-Powell

## Description

Ce TP implémente l'algorithme de Welsh-Powell pour la coloration de graphes en langage C. Deux versions sont proposées pour comparer différentes approches d'implémentation de la matrice d'adjacence :
- **Version normale** : matrice d'adjacence 2D (int**)
- **Version linéarisée** : matrice d'adjacence 1D (int*) - optimisée pour le cache

## Structure du Projet

```
tp_1/
├── bin/                   # Exécutables   
├── include/
│   └── graphe.h           # Interface commune des graphes
└── src/
    ├── graphe.c           # Implémentation normale (matrice 2D)
    ├── main.c             # Programme test version normale
    ├── graphe_lineaire.c  # Implémentation linéarisée (matrice 1D)
    └── main_lineaire.c    # Programme test version linéarisée
```

---

## Algorithme de Welsh-Powell

### Principe

L'algorithme de Welsh-Powell est un algorithme glouton pour la coloration de graphes :

1. **Trier** les sommets par ordre décroissant de degré
2. **Colorer** le premier sommet non coloré avec la couleur courante
3. **Parcourir** les sommets restants et colorer ceux qui ne sont pas adjacents aux sommets déjà colorés avec la même couleur
4. **Incrémenter** la couleur et répéter jusqu'à ce que tous les sommets soient colorés

---

## Version Normale (Matrice 2D)

### Structure de Données

```c
struct Graphe {
    int nbSommets;
    int **adjacence;  
    int *couleurs;
    int *degres;
};
```

### Fonctions Disponibles

- `Graphe *creerGraphe(int nbSommets)` : Crée un graphe avec n sommets
- `void ajouterArete(Graphe *g, int sommet1, int sommet2)` : Ajoute une arête non orientée
- `void welshPowell(Graphe *g)` : Applique l'algorithme de Welsh-Powell
- `void trierSommetsParDegre(Graphe *g, int *sommetsOrdre)` : Trie par degré décroissant
- `int couleurUtiliseeParVoisin(Graphe *g, int sommet, int couleur)` : Vérifie si un voisin utilise une couleur
- `void afficherMatrice(Graphe *g)` : Affiche la matrice d'adjacence
- `void afficherDegres(Graphe *g)` : Affiche les degrés de tous les sommets
- `void afficherColoration(Graphe *g)` : Affiche le résultat de la coloration
- `void exporterDot(Graphe *g, const char *nomFichier)` : Exporte au format DOT (Graphviz)
- `void libererGraphe(Graphe *g)` : Libère toute la mémoire

### Compilation

```bash
gcc -I./include -o bin/main src/graphe.c src/main.c
./bin/main
```

---

## Version Linéarisée (Matrice 1D)

### Structure de Données

```c
struct Graphe {
    int nbSommets;
    int *adjacence;     // Matrice 1D : adjacence[i * n + j]
    int *couleurs;
    int *degres;
};
```

### Fonctions Disponibles

Identiques à la version normale, seule l'implémentation interne change.

### Compilation

```bash
gcc -I./include -o bin/main_lineaire src/graphe_lineaire.c src/main_lineaire.c
./bin/main_lineaire
```

---

## Comparaison des Deux Versions

| Critère | Version Normale (2D) | Version Linéarisée (1D) |
|---------|---------------------|------------------------|
| **Allocation** | n+1 malloc | 1 calloc |
| **Accès** | `adj[i][j]` | `adj[i*n + j]` |
| **Mémoire** | Fragmentée | Contigüe |
| **Cache** | Moins efficace | Cache-friendly |
| **Libération** | Boucle + n free | 1 free |
| **Performance** | Standard | Optimisée |
| **Simplicité** | Intuitive | Nécessite calcul d'index |

---

## Export et Visualisation

### Format DOT (Graphviz)

Les programmes génèrent des fichiers `.dot` pour visualiser les graphes colorés.

```bash
# Générer une image PNG à partir du fichier DOT
circo -Tpng graph1.dot -o graph1.png

# Générer un PDF
circo -Tpdf graph2.dot -o graph2.pdf
```

---

## Exécution

```bash
# Tester la version normale
./bin/main

# Tester la version linéarisée
./bin/main_lineaire

```

---

## Notes

- **Matrice symétrique** : Comme le graphe est non orienté, `adjacence[i][j] == adjacence[j][i]`
- **Tri à bulles** : Utilisé pour sa simplicité, pourrait être remplacé par le tri rapide ou le tri fusion pour de meilleurs performances

---

## Auteur

Ali Gouarab
