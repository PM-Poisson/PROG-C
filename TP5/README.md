# README TP4, TP5 et TP6

---

## TP4

**Objectifs :** Approfondir les opérateurs, les structures, les fichiers et la manipulation de données complexes en C.

### Exercice 4.1
- **Fichiers :** `operator.h`, `operator.c`, `main.c`  
- **Bibliothèques :** `stdio`  
- **Références :** cours sur les opérateurs et fonctions  
- **Difficulté :** facile ★  
- **Commentaires :** Implémentation de fonctions pour les opérations arithmétiques et logiques avec sélection via `switch`.

### Exercice 4.2
- **Fichiers :** `fichier.h`, `fichier.c`, `main.c`  
- **Bibliothèques :** `stdio`  
- **Références :** cours sur la gestion des fichiers  
- **Difficulté :** facile ★  
- **Commentaires :** Lecture et écriture dans des fichiers, gestion des erreurs.

### Exercice 4.3
- **Fichiers :** `etudiant_bd.c`, `fichier.c`, `fichier.h`  
- **Bibliothèques :** `stdio`, `string`  
- **Références :** TP2 sur les structures  
- **Difficulté :** moyenne ★★  
- **Commentaires :** Gestion d’une base de données d’étudiants et enregistrement dans un fichier.

### Exercice 4.4
- **Fichiers :** `calcule.c`, `operator.c`  
- **Bibliothèques :** `stdio`, `stdlib`  
- **Références :** TP4.1 sur les opérateurs  
- **Difficulté :** moyenne ★★  
- **Commentaires :** Calculatrice en ligne de commande utilisant des arguments de la ligne de commande.

### Exercice 4.5
- **Fichiers :** `factorielle.c`  
- **Bibliothèques :** `stdio`  
- **Références :** TP1 sur les fonctions récursives  
- **Difficulté :** moyenne ★★  
- **Commentaires :** Implémentation récursive de la factorielle.

### Exercice 4.6
- **Fichiers :** `chercherfichier.c`, `fichier.c`, `fichier.h`  
- **Bibliothèques :** `stdio`, `string`  
- **Références :** TP2, TP3 sur les fichiers et chaînes  
- **Difficulté :** difficile ★★★  
- **Commentaires :** Recherche d’une phrase dans un fichier avec comptage par ligne.

### Exercice 4.7
- **Fichiers :** `liste.c`, `liste.h`, `main.c`  
- **Bibliothèques :** `stdio`, `stdlib`  
- **Références :** TP2, TP3 sur les structures et listes chaînées  
- **Difficulté :** difficile ★★★  
- **Commentaires :** Gestion d’une liste chaînée de couleurs avec insertion et parcours.

---

## TP5

**Objectifs :** Manipulation de répertoires, itération et récursion, communication client-serveur en C.

### Exercice 5.1
- **Fichiers :** `repertoire.c`, `repertoire.h`, `main.c`  
- **Bibliothèques :** `stdio`, `dirent.h`  
- **Références :** documentation UNIX sur `opendir`/`readdir`  
- **Difficulté :** facile ★  
- **Commentaires :** Affichage des fichiers et répertoires d’un dossier.

### Exercice 5.2
- **Fichiers :** `repertoire.c`, `repertoire.h`, `main.c`  
- **Bibliothèques :** `stdio`, `dirent.h`  
- **Références :** 5.1  
- **Difficulté :** moyenne ★★  
- **Commentaires :** Parcours récursif d’un dossier et de ses sous-dossiers.

### Exercice 5.3
- **Fichiers :** `repertoire.c`, `repertoire.h`, `main.c`  
- **Bibliothèques :** `stdio`, `dirent.h`  
- **Références :** 5.2  
- **Difficulté :** moyenne ★★  
- **Commentaires :** Parcours itératif d’un dossier et de ses sous-dossiers.

### Exercice 5.4
- **Fichiers :** `serveur.c`, `client.c`, `serveur.h`, `client.h`  
- **Bibliothèques :** `stdio`, `stdlib`, `sys/types`, `sys/socket`  
- **Références :** communication client-serveur UNIX  
- **Difficulté :** moyenne ★★  
- **Commentaires :** Simulation client-serveur simple sur la même machine.

### Exercice 5.5
- **Fichiers :** `serveur.c`, `client.c`, `serveur.h`, `client.h`  
- **Bibliothèques :** `stdio`, `stdlib`, `sys/types`, `sys/socket`  
- **Références :** 5.4  
- **Difficulté :** difficile ★★★  
- **Commentaires :** Communication client-serveur avec calculs simples (+, -, *, /) et transmission des résultats.

---

## TP6

**Objectifs :** Analyse d’images BMP, extraction des couleurs, génération de graphiques SVG et communication client-serveur.

### Exercice 6.1
- **Fichiers :** `client.c`, `client.h`, `serveur.c`, `serveur.h`, `bmp.c`, `bmp.h`, `couleur.c`, `couleur.h`, `Makefile`  
- **Bibliothèques :** `stdio`, `stdlib`  
- **Références :** documentation BMP et sockets  
- **Difficulté :** facile ★  
- **Commentaires :** Extraction des 10 premières couleurs d’une image BMP et transmission au serveur pour affichage graphique.

### Exercice 6.2
- **Fichiers :** `client.c`, `serveur.c`, `client.h`, `serveur.h`  
- **Bibliothèques :** `stdio`, `stdlib`  
- **Références :** 6.1  
- **Difficulté :** moyenne ★★  
- **Commentaires :** Possibilité de choisir le nombre de couleurs à traiter (1-30) lors de l’exécution.

### Exercice 6.3
- **Fichiers :** `client.c`, `serveur.c`, `client.h`, `serveur.h`  
- **Bibliothèques :** `stdio`, `stdlib`, `cJSON`  
- **Références :** 6.1, 6.2  
- **Difficulté :** difficile ★★★  
- **Commentaires :** Passage à un format JSON structuré pour la communication client-serveur (messages, calculs et couleurs). Beaucoup de difficultés au niveau de l'implémentation sur Windows, j'ai donc changé en passant sur Ubuntu.