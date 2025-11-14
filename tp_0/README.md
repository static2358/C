# TP 0 - Structures de Données en C

## Description

Ce TP introduit deux structures de données fondamentales en langage C :
- **Arbres binaires** : représentation et manipulation d'arbres
- **Listes doublement chaînées** : gestion de formes polygonales via des points (x, y)

## Structure du Projet

```
tp_0/
├── arbre/              # Implémentation des arbres binaires
│   ├── bin/           # Exécutables compilés
│   ├── include/       
│   │   └── arbre.h    # Interface de l'arbre binaire
│   └── src/
│       ├── arbre.c    # Implémentation des fonctions
│       └── monArbre.c # Programme de démonstration
│
└── liste/             # Implémentation des listes doublement chaînées
    ├── bin/          # Exécutables compilés
    ├── include/
    │   └── liste.h   # Interface de la liste
    └── src/
        ├── liste.c   # Implémentation des fonctions
        └── maListe.c # Programme de démonstration
```

---

## Module Arbre Binaire

### Fonctionnalités

- **Création de nœuds** avec numérotation automatique
- **Recherche** d'un nœud par son numéro (parcours récursif)
- **Insertion** de fils gauche/droit avec gestion des remplacements
- **Parcours préfixe** : visite Nœud → Gauche → Droit

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

- `noeud *nouvNoeud(char carac)` : Crée un nouveau nœud avec un caractère
- `noeud *rechercheNoeud(noeud *n, int num_noeud)` : Recherche un nœud par son numéro
- `void insererFG(noeud *noeudAInserer, noeud *arbre, int num_parent)` : Insère comme fils gauche
- `void insererFD(noeud *noeudAInserer, noeud *arbre, int num_parent)` : Insère comme fils droit
- `void parcoursPrefixe(noeud *n)` : Affiche l'arbre en parcours préfixe

### Exemple d'Utilisation

Le programme `monArbre.c` construit l'arbre suivant :

```
       A(1)
      /    \
    B(2)   C(3)
     /\      /
   G(7) E(5) F(6)
    /
  D(4)
```

**Parcours préfixe** : `A(1) B(2) G(7) D(4) E(5) C(3) F(6)`

### Compilation

```bash
cd arbre
gcc -I./include -o bin/monArbre src/arbre.c src/monArbre.c
./bin/monArbre
```

---

## Module Liste Doublement Chaînée

### Fonctionnalités

- **Création** de cellules contenant des points (x, y)
- **Insertion** à une position donnée
- **Suppression** d'une cellule par position
- **Affichage** de tous les points de la liste
- Gestion bidirectionnelle (pointeurs `suiv` et `prec`)

### Structures de Données

```c
typedef struct {
    int x;
    int y;
} point;

typedef struct cellule {
    point p;
    struct cellule *suiv;  // Cellule suivante
    struct cellule *prec;  // Cellule précédente
} cellule;
```

### Fonctions Disponibles

- `cellule *NouvCel(point p)` : Crée une nouvelle cellule avec un point
- `void InsererCellule(int pl, cellule *cel, cellule **liste)` : Insère après la position `pl`
- `void SupprimeCellule(int pl, cellule **liste)` : Supprime la cellule à la position `pl`
- `void Afficher(cellule *liste)` : Affiche tous les points de la liste

### Cas d'Usage : Formes Polygonales

Le programme `maListe.c` démontre la création d'un polygone en gérant une liste de points :

```
Points initiaux : (0,0) → (10,0) → (10,10) → (5,15) → (0,10)
```

Opérations testées :
- Insertion au milieu
- Suppression d'éléments
- Insertion en début de liste

### Compilation

```bash
cd liste
gcc -I./include -o bin/maListe src/liste.c src/maListe.c
./bin/maListe
```

---

## Objectifs Pédagogiques

1. Comprendre les **pointeurs** et l'**allocation dynamique** en C
2. Maîtriser les **structures récursives** (arbres)
3. Implémenter des **listes chaînées bidirectionnelles**
4. Gérer la **mémoire** (`malloc`, `free`)
5. Manipuler des **structures complexes** avec pointeurs

---

## Compilation Complète

Pour compiler les deux modules :

```bash
# Arbre binaire
gcc -I./arbre/include -o arbre/bin/monArbre arbre/src/arbre.c arbre/src/monArbre.c

# Liste doublement chaînée
gcc -I./liste/include -o liste/bin/maListe liste/src/liste.c liste/src/maListe.c
```

---

## Notes

- **Numérotation automatique** : Les nœuds de l'arbre sont numérotés automatiquement via un compteur statique
- **Insertion avec remplacement** : Si un fils existe déjà, il devient le fils du nouveau nœud inséré
- **Liste doublement chaînée** : Permet un parcours bidirectionnel (utile pour les formes fermées)
- **Gestion mémoire** : Utilisation de `malloc` pour l'allocation dynamique

---

## Exécution

```bash
# Test de l'arbre binaire
./arbre/bin/monArbre

# Test de la liste doublement chaînée
./liste/bin/maListe
```

---

## Concepts Clés

- **Récursivité** : recherche de nœuds, parcours d'arbre
- **Pointeurs doubles** : modification de listes via `**liste`
- **Structures auto-référentes** : `struct noeud *filsGauche`
- **Allocation dynamique** : `malloc`, `free`
- **Parcours d'arbres** : préfixe, infixe, postfixe

---

## Auteur

Ali Gouarab