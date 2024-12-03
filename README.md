# Push_swap

**Push_swap** est un projet d'algorithmie de l'école 42. L'objectif est de trier une pile d'entiers à l'aide d'un ensemble limité d'instructions, en utilisant le moins d'opérations possibles. Ce projet permet d'explorer les algorithmes de tri et d'améliorer leur efficacité.

---

## 📝 Description du Projet

Le projet consiste à :

- Implémenter un programme `push_swap` qui calcule et affiche la séquence d'instructions nécessaire pour trier une pile d'entiers.
- Manipuler deux piles (`a` et `b`) en utilisant un ensemble défini d'instructions (comme `sa`, `pb`, `ra`, etc.).
- Minimiser le nombre d'opérations nécessaires pour accomplir le tri.
- En cas d'erreur (paramètres invalides, doublons), le programme doit afficher "Error" suivi d'un saut de ligne.

#### 🔑 Notions Clés

- Conception et implémentation d'algorithmes de tri efficaces.
- Analyse de la complexité des algorithmes.
- Gestion de piles en mémoire et manipulation via des instructions.

---

## 📋 Structure du Projet

### 1. Partie Obligatoire

- Implémenter le programme `push_swap`, capable de trier une pile d'entiers passée en argument.
- Afficher la séquence minimale d'instructions nécessaires pour effectuer le tri.
- Les instructions disponibles incluent :
  - **sa** / **sb** / **ss** : Échanger les deux premiers éléments d'une pile.
  - **pa** / **pb** : Déplacer le premier élément d'une pile vers l'autre.
  - **ra** / **rb** / **rr** : Faire pivoter une pile vers le haut.
  - **rra** / **rrb** / **rrr** : Faire pivoter une pile vers le bas.

Le programme sera évalué en fonction du nombre d'opérations nécessaires pour trier une pile aléatoire.

---

## ⚙️ Instructions d'Utilisation

1. **Cloner le dépôt** :  
   ```bash
   git clone https://github.com/0x2Anessie/42-PushSwap.git
   ```
   ```bash
   cd 42-PushSwap
   ```

2. **Compiler le projet :**
   Utilisez le Makefile pour compiler les fichiers sources :
   ```bash
   make
   ```

4. **Lancer le programme `push_swap` :**
   ```bash
   ./push_swap <liste d'entiers>
   ```

   Par exemple :
   ```bash
   ./push_swap 4 3 2 1 8
   ```

**Note : Pour avoir une vue globale de l'algorithme de tri, du nombre d'operations et tester le programme avec un grand nombre d'entiers, utilisez le [Push Swap Visualizer](https://github.com/o-reo/push_swap_visualizer).**

---

## 🛠️ Rendu

- Le dépôt doit contenir les fichiers sources nécessaires pour le programme `push_swap` et un `Makefile` avec les règles suivantes :
  - `make` : Compile le projet.
  - `make clean` : Supprime les fichiers objets.
  - `make fclean` : Supprime les fichiers objets et les exécutables.
  - `make re` : Recompile tout depuis le début.
- Tous les fichiers inutiles ou non demandés ne doivent pas être inclus dans le dépôt.
- La norme de l'école 42 doit être strictement respectée.

---

## 📜 Licence

Ce projet est soumis aux règles de l'école 42.
