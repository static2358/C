# Projet Forme Polygonale - Liste Doublement Chaînée

## Description
Ce projet implémente une forme polygonale représentée par une liste doublement chaînée de points dans un espace 2D.

## Structure du projet

```
tp_0/
├── include/           # Fichiers d'en-tête (.h)
│   └── liste.h       # Définitions des structures et prototypes
├── src/              # Fichiers sources (.c)
│   ├── liste.c       # Implémentation des fonctions de liste
│   └── main.c        # Programme principal
├── bin/              # Exécutables
    ├── polygone.c    # fichier executable          
└── README.md         # Ce fichier

```

## Fonctionnalités

- **NouvCel()** : Création d'une nouvelle cellule
- **InsererCellule()** : Insertion d'une cellule à une position donnée
- **SupprimeCellule()** : Suppression d'une cellule à une position donnée
- **Afficher()** : Affichage de tous les points de la liste

## Compilation

### Avec Makefile (recommandé)
```powershell
make              # Compile le projet
make run          # Compile et exécute
make clean        # Nettoie les fichiers générés
make rebuild      # Nettoie et recompile
```

### Compilation manuelle
```powershell
gcc -Wall -Wextra -std=c99 -Iinclude -c src/liste.c -o obj/liste.o
gcc -Wall -Wextra -std=c99 -Iinclude -c src/main.c -o obj/main.o
gcc obj/liste.o obj/main.o -o bin/polygone.exe
```

## Exécution
```powershell
.\bin\polygone.exe
```

## Auteur
Projet réalisé dans le cadre du TP de structures de données en C.
