# Projet Arbre Binaire

## Description
Implémentation d'un arbre binaire en C avec représentation chaînée.

## Structure du projet

```
arbre/
├── include/          # Fichiers d'en-tête (.h)
│   └── arbre.h      # Structure noeud et prototypes
├── src/             # Fichiers sources (.c)
│   ├── arbre.c      # Implémentation des fonctions
│   └── main.c       # Programme principal
└── bin/             # Exécutables
```

## Fonctionnalités

- **nouvNoeud()** : Créer un nouveau nœud
- **rechercheNoeud()** : Chercher un nœud par son numéro
- **insererFG()** : Insérer un nœud comme fils gauche
- **insererFD()** : Insérer un nœud comme fils droit
- **parcoursPrefixe()** : Parcourir l'arbre en préfixe

## Compilation

```powershell
gcc -Iinclude src/arbre.c src/main.c -o bin/arbre.exe
```

## Exécution

```powershell
.\bin\arbre.exe
```
