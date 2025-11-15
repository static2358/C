# TP 3 - Analyse de Complexité et Structures Avancées

## Description

Ce TP se concentre sur l'analyse de complexité des algorithmes de coloration de graphes et l'implémentation de structures de données avancées :
- **Arbres génériques** : structure avec nombre illimité de fils via pointeurs frère/premier fils
- **Graphes avec listes d'adjacence** : représentation optimisée en mémoire
- **Benchmark Welsh-Powell** : analyse empirique de la complexité algorithmique

## Structure du Projet

```
tp_3/
├── bin/                        # Exécutables
├── include/
│   ├── arbre_generique.h       # Interface des arbres génériques
│   └── graphe_liste.h          # Interface des graphes (listes)
├── src/
│   ├── arbre_generique.c       # Implémentation des arbres génériques
│   ├── monArbre.c              # Programme de test des arbres
│   ├── graphe_liste.c          # Implémentation des graphes (listes)
│   ├── monGraphe.c             # Programme de test des graphes
│   └── benchmark_welsh_powell.c # Analyse de complexité
└── Correction_chatgpt/         # Corrections de codes existants
    ├── welsh_powell.c          # Version corrigée de Welsh-Powell (C)
    └── welsh_powell.py         # Version corrigée de Welsh-Powell (Python)
```

---

## Module Arbre Générique

### Structure de Données

```c
typedef struct noeud {
    char val;
    int num;
    struct noeud *premierFils;   
    struct noeud *frèreSuivant;  
} noeud;
```

### Fonctions Disponibles

- `noeud *nouvNoeud(char carac)` : Crée un nouveau nœud
- `noeud *rechercheNoeud(noeud *n, int num_noeud)` : Recherche par numéro
- `void ajouterFils(noeud *parent, noeud *fils)` : Ajoute un fils au parent
- `void parcoursPrefixe(noeud *n)` : Affiche en parcours préfixe
- `void afficherArbre(noeud *n, int niveau)` : Affichage hiérarchique

### Compilation

```bash
gcc -I./include -o bin/monArbre src/arbre_generique.c src/monArbre.c
./bin/monArbre
```

---

## Module Graphe (Listes d'Adjacence)

### Structures de Données

```c
typedef struct voisin {
    int sommet;
    struct voisin *suivant;
} voisin;

typedef struct Graphe {
    int nb_sommets;
    voisin **voisins;     // Tableau de listes chaînées
    int *couleurs;
    int *degres;
} Graphe;
```

### Fonctions Disponibles

- `Graphe *creerGraphe(int nb_sommets)` : Crée un graphe vide
- `void ajouterArete(Graphe *g, int u, int v)` : Ajoute une arête
- `void welshPowell(Graphe *g)` : Applique l'algorithme de coloration
- `void afficherGraphe(Graphe *g)` : Affiche les listes d'adjacence
- `void afficherColoration(Graphe *g)` : Affiche le résultat de la coloration
- `void exporterDot(Graphe *g, const char *nomFichier)` : Export Graphviz
- `void libererGraphe(Graphe *g)` : Libère toute la mémoire

### Compilation

```bash
gcc -I./include -o bin/monGraphe src/graphe_liste.c src/monGraphe.c
./bin/monGraphe
```

---

## Module Benchmark Welsh-Powell

### Objectif

Analyser empiriquement la complexité de l'algorithme de Welsh-Powell en mesurant le temps d'exécution sur des graphes de tailles croissantes.


### Structures de Données

```c
#define MAX_SOMMETS 100000

struct Graphe {
    int nb_sommets;
    int **matrice_adjacence; 
};
```

### Fonctions Disponibles

- `struct Graphe* creerGraphe(int nb_sommets)` : Alloue dynamiquement un graphe
- `struct Graphe* genererGraphe(int nb_sommets)` : Génère un graphe aléatoire (50% densité)
- `void ajouterArete(struct Graphe* graphe, int u, int v)` : Ajoute une arête
- `int compterAretes(struct Graphe* graphe)` : Compte le nombre d'arêtes
- `int welshPowell(struct Graphe* graphe)` : Retourne le nombre de couleurs utilisées
- `void libererGraphe(struct Graphe* graphe)` : Libère la mémoire

### Utilisation

```bash
# Compilation
gcc -I./include -o bin/benchmark src/benchmark_welsh_powell.c

# Exécution avec N sommets
./bin/benchmark 10
./bin/benchmark 100
./bin/benchmark 1000
./bin/benchmark 2000
```

### Mesure du Temps (PowerShell)

```powershell
# Mesurer le temps d'exécution
Measure-Command { .\bin\benchmark.exe 1000 }
```

### Analyse de Complexité

L'algorithme de Welsh-Powell a une complexité :
- **Pire cas théorique** : O(N³)
- **Cas pratique (graphes peu denses)** : O(N²)

## Correction ChatGPT

Le dossier `Correction_chatgpt/` contient les versions corrigées de l'algorithme de Welsh-Powell fourni par ChatGPT (C et Python).

### Version C (welsh_powell.c)

#### Bugs Corrigés

1. **Initialisation des couleurs** :
   ```c
   // AVANT (bug)
   int color[MAX_VERTICES] = {-1};  // Seul le premier élément = -1
   
   // APRÈS (corrigé)
   for (i = 0; i < graph->vertices; i++)
       color[i] = -1;
   ```

2. **Logique de groupement** :
   - Le code original incrémentait la couleur trop tôt
   - Correction : grouper tous les sommets compatibles avec la couleur courante avant d'incrémenter

### Version Python (welsh_powell.py)

Implémentation en Python avec deux classes de graphes :
- `GraphBacktracking` : avec backtracking pour la coloration
- `GraphWelshPowell` : implémentation classique de Welsh-Powell

#### Fonctionnalités Python

- Classes orientées objet
- Méthodes `add_edge()`, `welsh_powell()`, `display()`
- Affichage clair des résultats de coloration
---

## Objectifs Pédagogiques

1. Comprendre les **arbres génériques** et leur implémentation efficace
2. Maîtriser les **listes d'adjacence** pour les graphes
3. Analyser empiriquement la **complexité algorithmique**
4. Utiliser les **outils de mesure** (time, Measure-Command)
5. Corriger et optimiser du **code existant**
6. Comparer différentes **structures de données**

---

## Compilation Complète

```bash
# Arbre générique
gcc -I./include -o bin/monArbre src/arbre_generique.c src/monArbre.c

# Graphe avec listes
gcc -I./include -o bin/monGraphe src/graphe_liste.c src/monGraphe.c

# Benchmark
gcc -I./include -o bin/benchmark src/benchmark_welsh_powell.c

# Welsh-Powell corrigé (C)
gcc -o bin/welsh_powell Correction_chatgpt/welsh_powell.c

# Welsh-Powell corrigé (Python) - pas de compilation nécessaire
```

---

## Exécution

```bash
# Test de l'arbre générique
./bin/monArbre

# Test du graphe (listes)
./bin/monGraphe

# Benchmark avec 1000 sommets
./bin/benchmark 1000

# Welsh-Powell corrigé (C)
./bin/welsh_powell

# Welsh-Powell corrigé (Python)
python Correction_chatgpt/welsh_powell.py
```

---

## Auteur

Ali Gouarab
