# TP 2 - Graphes et Arbres Binaires

## Description

Ce TP combine deux structures de données importantes :
- **Graphes** : coloration de graphes avec Welsh-Powell, chargement depuis fichier
- **Arbres binaires** : création d'arbres aléatoires, parcours (préfixe, infixe, postfixe), export DOT

Application pratique : coloration de la carte d'Europe pour déterminer le nombre minimal de couleurs nécessaires afin que deux pays adjacents n'aient pas la même couleur.

## Structure du Projet

```
tp_2/
├── carte_europe.txt       # Matrice d'adjacence des pays européens
├── bin/                   # Exécutables et fichiers DOT générés
├── include/
│   ├── graphe.h          # Interface des graphes
│   └── arbre.h           # Interface des arbres binaires
└── src/
    ├── graphe.c          # Implémentation des graphes
    ├── monGraphe.c       # Programme test graphe (carte Europe)
    ├── arbre.c           # Implémentation des arbres
    └── monArbre.c        # Programme test arbre
```

---

## Module Graphe

### Fonctionnalités

- **Chargement** depuis fichier texte (matrice d'adjacence)
- **Coloration** avec algorithme de Welsh-Powell
- **Affichage** de la matrice, des degrés et de la coloration
- **Export DOT** pour visualisation avec Graphviz

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

- `Graphe *creerGraphe(int nbSommets)` : Crée un graphe vide
- `Graphe *chargeGraphe(const char *nomFichier)` : Charge un graphe depuis un fichier
- `void libererGraphe(Graphe *g)` : Libère la mémoire
- `void afficherGraphe(Graphe *g)` : Affiche la matrice d'adjacence
- `void afficherDegres(Graphe *g)` : Affiche les degrés de tous les sommets
- `void afficherMatrice(Graphe *g)` : Affiche la matrice d'adjacence formatée
- `void parcoursEnProfondeur(Graphe *g, int sommetDepart)` : Parcours en profondeur (DFS)
- `void parcoursEnLargeur(Graphe *g, int sommetDepart)` : Parcours en largeur (BFS)
- `void welshPowell(Graphe *g)` : Applique l'algorithme de Welsh-Powell
- `void afficherColoration(Graphe *g)` : Affiche le résultat de la coloration
- `void exporterDot(Graphe *g, const char *nomFichier)` : Exporte au format DOT

### Format du Fichier d'Entrée

```
11                    # Nombre de sommets
0 1 0 1 1 0 1 1 1 1 0 # Ligne 0 de la matrice
1 0 1 1 0 0 0 0 0 0 0 # Ligne 1
...                   # Lignes suivantes
```

### Carte d'Europe

Le fichier `carte_europe.txt` contient 11 pays :
- 0 : France
- 1 : Espagne
- 2 : Portugal
- 3 : Andorre
- 4 : Italie
- 5 : Autriche
- 6 : Suisse
- 7 : Allemagne
- 8 : Luxembourg
- 9 : Belgique
- 10 : Pays-Bas

### Compilation et Exécution

```bash
# Compiler le programme graphe
gcc -I./include -o bin/monGraphe src/graphe.c src/monGraphe.c

# Exécuter
./bin/monGraphe

# Visualiser le résultat
dot -Tpng carte_europe.dot -o carte_europe.png
```

---

## Module Arbre Binaire

### Fonctionnalités

- **Création manuelle** de nœuds avec numérotation automatique
- **Création automatique** d'arbres complets ou aléatoires
- **Parcours** : préfixe, infixe, postfixe
- **Recherche** de nœuds par numéro
- **Insertion** de fils gauche/droit
- **Export DOT** pour visualisation avec représentation des nœuds NULL

### Structure de Données

```c
typedef struct noeud {
    char val;               
    int num;                
    struct noeud *filsGauche;
    struct noeud *filsDroit;
} noeud;
```

### Fonctions Disponibles

- `noeud *nouvNoeud(char carac)` : Crée un nouveau nœud
- `noeud *rechercheNoeud(noeud *n, int num_noeud)` : Recherche un nœud par numéro
- `void insererFG(noeud *noeudAInserer, noeud *arbre, int num_parent)` : Insère comme fils gauche
- `void insererFD(noeud *noeudAInserer, noeud *arbre, int num_parent)` : Insère comme fils droit
- `void parcoursPrefixe(noeud *n)` : Parcours Nœud → Gauche → Droit
- `void parcoursInfixe(noeud *n)` : Parcours Gauche → Nœud → Droit
- `void parcoursPostfixe(noeud *n)` : Parcours Gauche → Droit → Nœud
- `noeud *creerArbre(int hauteur, char valeurDepart)` : Crée un arbre complet
- `noeud *creerArbreAleatoire(int hauteur, char valeurDepart)` : Crée un arbre aléatoire
- `void exporterArbreDot(noeud *n, const char *nomFichier)` : Exporte au format DOT

### Compilation et Exécution

```bash
# Compiler le programme arbre
gcc -I./include -o bin/monArbre src/arbre.c src/monArbre.c

# Exécuter
./bin/monArbre

# Visualiser l'arbre généré
dot -Tpng arbre_binaire.dot -o arbre_binaire.png
```

---

## Exemples d'Utilisation

### Exemple 1 : Coloration de la Carte d'Europe

```bash
./bin/monGraphe
```

Sortie attendue :
```
Graphe charge avec succes : 11 sommets

Matrice d'adjacence (11 sommets):
...

=== ALGORITHME DE WELSH-POWELL ===

Degres des sommets:
  Sommet 0 : degre 7
  Sommet 7 : degre 6
  ...

Attribution des couleurs:
  Sommet 0 -> Couleur 0
  Sommet 2 -> Couleur 0
  ...

--- RESULTAT DE LA COLORATION ---
Nombre de couleurs utilisees : 4

Couleur 0 : 0 2 5 10
Couleur 1 : 7 4
Couleur 2 : 1 6 9
Couleur 3 : 3 8
```

### Exemple 2 : Arbre Binaire Aléatoire

```bash
./bin/monArbre
```

Sortie attendue :
```
Creation d'un arbre aleatoire de hauteur 4...
Arbre cree avec succes!

==> Fichier DOT genere: arbre_binaire.dot

PARCOURS PREFIXE : 
A(1) B(2) C(3) D(4) ...

PARCOURS INFIXE : 
C(3) B(2) D(4) A(1) ...

PARCOURS POSTFIXE : 
C(3) D(4) B(2) ...
```

---

## Compilation Complète

```bash
# Compiler les deux programmes
gcc -I./include -o bin/monGraphe src/graphe.c src/monGraphe.c && \
gcc -I./include -o bin/monArbre src/arbre.c src/monArbre.c

# Exécuter les deux
./bin/monGraphe
./bin/monArbre
```

---

## Notes

- **Matrice d'adjacence** : `adjacence[i][j] = 1` si les sommets i et j sont voisins
- **Compteur statique** : Les nœuds de l'arbre sont numérotés automatiquement via un compteur global
- **Arbres aléatoires** : Utilisent `rand()` pour décider si un fils est créé ou non
- **Format DOT** : Standard pour la description de graphes, utilisé par Graphviz
- **Nœuds NULL** : Représentés dans le DOT par des points noirs pour visualiser la structure complète

---

## Auteur

Ali Gouarab
