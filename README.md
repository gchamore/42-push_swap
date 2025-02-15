# 🔄 Push_swap

## 📝 Présentation

**Push_swap** est un projet d’**algorithmie et d’optimisation**, où l’objectif est de **trier une pile de nombres** en utilisant un **ensemble limité d’instructions**.  
Le programme doit générer **la séquence la plus courte possible** pour organiser la pile `a` dans l’ordre croissant en utilisant une seconde pile `b`.

Ce projet permet de **comprendre les algorithmes de tri**, la **gestion des piles**, et l’**optimisation des performances**.

---

## 🛠️ Fonctionnalités

### ✅ Partie Obligatoire :
- **Gestion de deux piles (`a` et `b`)**.
- **Utilisation des instructions de manipulation suivantes** :
  - `sa` / `sb` / `ss` : Swap des deux premiers éléments.
  - `pa` / `pb` : Push entre `a` et `b`.
  - `ra` / `rb` / `rr` : Rotation vers le haut.
  - `rra` / `rrb` / `rrr` : Rotation vers le bas.
- **Tri efficace avec le moins d’opérations possibles**.
- **Gestion des erreurs** :
  - Valeurs non numériques ou hors plage `int`.
  - Nombres dupliqués.
  - Aucun affichage en cas d'entrée vide.

### 🎯 Bonus (si implémenté) :
- **Programme `checker`** :  
  - Vérifie que les instructions générées par `push_swap` trient correctement la pile.
- **Optimisation du tri** pour respecter les contraintes suivantes :
  - `100 nombres` triés en **< 700 opérations**.
  - `500 nombres` triés en **< 5500 opérations**.
- **Gestion avancée des instructions pour minimiser le nombre de coups**.

---

## 📌 Technologies Utilisées

- **C (Norminette respectée)**
- **Manipulation des piles et structures de données**
- **Algorithmes de tri optimisés (`QuickSort`, `RadixSort`, `MergeSort`, etc.)**
- **Gestion de la mémoire et optimisation (`malloc`, `free`)**
- **Gestion des erreurs et validation d'entrée**

---

## 🏗️ Structure du Projet

📂 headers  
┣ 📜 libft.h  
┣ 📜 push_swap.h  
┗ 📜 push_swap_bonus.h  

📂 libft  

📂 my_checker  
┗ 📜 checker_bonus.c  

📂 srcs  
┣ 📂 algo  
┃ ┣ 📜 algo_1.c  
┃ ┣ 📜 algo_2.c  
┃ ┗ 📜 algo_3.c  
┣ 📂 instructions  
┃ ┣ 📜 push_function.c  
┃ ┣ 📜 reverse_rotate_functions.c  
┃ ┣ 📜 rotate_functions.c  
┃ ┗ 📜 swap_functions.c  
┣ 📂 parsing  
┃ ┣ 📜 parsing.c  
┃ ┗ 📜 parsing_1_arg.c  
┣ 📂 utils  
┃ ┣ 📜 algo_utils.c  
┃ ┣ 📜 algo_utils_2.c  
┃ ┣ 📜 init.c  
┃ ┣ 📜 mod_libft.c  
┃ ┗ 📜 parsing_utils.c  
┗ 📜 main.c  

📜 .gitignore  
📜 Makefile  

---

## 🔥 Difficultés Rencontrées

- **Choisir le meilleur algorithme de tri** en fonction du nombre d’éléments.  
- **Minimiser le nombre de mouvements** pour optimiser la performance.  
- **Gérer correctement les erreurs** (arguments invalides, dépassement d'entier, doublons).  
- **Implémenter un `checker` efficace** pour vérifier les résultats.  
- **Optimiser la gestion mémoire** pour éviter les fuites (`valgrind`).  

---

## 🏗️ Mise en place

1. **Cloner le dépôt** :  
   ```bash
   git clone https://github.com/ton-repo/push_swap.git
   cd push_swap
2. **Compiler le projet** :
   ```bash
   make
3. **Lancer le programme avec une liste de nombres** :
   ```bash
   ./push_swap 4 67 3 87 23
4. **Vérifier le tri avec checker (bonus)** :
   ```bash
   ./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
5. **Nettoyer les fichiers compilés** :
   ```bash
   make clean
   make fclean

---

## 👨‍💻 Équipe  

👤 Grégoire Chamorel (Gchamore)  

---

## 📜 Projet réalisé dans le cadre du cursus 42.  

Tu peux bien sûr modifier ce README selon tes besoins, ajouter plus de détails sur ton approche et des instructions d’installation précises. 🚀  
