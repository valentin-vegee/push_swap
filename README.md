Voici un README prêt à copier dans `README.md` :

*This project has been created as part of the 42 curriculum by tbenavid, vavegee.*

# push_swap

## Description

`push_swap` est un projet algorithmique de l'école 42 dont l'objectif est de trier une pile d'entiers avec un nombre d'opérations aussi faible que possible, en utilisant uniquement un ensemble limité d'instructions sur deux piles.

Au départ :
- la pile `a` contient les nombres à trier ;
- la pile `b` est vide.

Le programme doit afficher une suite d'opérations (`sa`, `pb`, `ra`, etc.) permettant de trier la pile `a` en ordre croissant, avec le plus petit élément en haut.

Ce projet a pour but de travailler :
- la manipulation de structures de données ;
- la complexité algorithmique ;
- l'optimisation ;
- le choix d'une stratégie de tri adaptée à la forme de l'entrée.

---

## Objectif du projet

Le sujet impose d'intégrer plusieurs stratégies de tri et de pouvoir en sélectionner une à l'exécution selon un flag ou selon un mode adaptatif.

Le projet doit :
- parser correctement les arguments ;
- gérer les erreurs ;
- manipuler deux piles ;
- exécuter uniquement les opérations autorisées ;
- proposer plusieurs algorithmes de tri ;
- mesurer le niveau de désordre initial de la pile ;
- afficher éventuellement des statistiques en mode `--bench`.

---

## Instructions

### Compilation

```bash
make


### Nettoyage

```bash
make clean
make fclean
make re
```

### Exécution

Sans flag, le programme utilise le mode adaptatif :

```bash
./push_swap 3 2 1
```

Avec une stratégie forcée :

```bash
./push_swap --simple 3 2 1
./push_swap --medium 3 2 1
./push_swap --complex 3 2 1
./push_swap --adaptive 3 2 1
```

Avec benchmark :

```bash
./push_swap --bench 3 2 1
./push_swap --bench --medium 8 3 6 1 7 2 5 4
./push_swap --complex --bench 8 3 6 1 7 2 5 4
```

### Entrées acceptées

Le programme accepte :

* plusieurs arguments séparés :

```bash
./push_swap 4 2 9 1 3
```

* ou une seule chaîne contenant plusieurs nombres :

```bash
./push_swap "4 2 9 1 3"
```

### Gestion d'erreurs

Le programme affiche :

```bash
Error
```

sur la sortie d'erreur en cas de :

* doublons ;
* argument non numérique ;
* dépassement de `int` ;
* flag invalide ;
* entrée vide ou mal formée.

Exemples :

```bash
./push_swap 3 2 a
./push_swap 3 2 3
./push_swap --badflag 1 2 3
```

---

## Opérations autorisées

Le tri repose uniquement sur les opérations suivantes :

* `sa` : échange les deux premiers éléments de `a`
* `sb` : échange les deux premiers éléments de `b`
* `ss` : `sa` et `sb` en même temps
* `pa` : pousse le premier élément de `b` vers `a`
* `pb` : pousse le premier élément de `a` vers `b`
* `ra` : rotation de `a` vers le haut
* `rb` : rotation de `b` vers le haut
* `rr` : `ra` et `rb` en même temps
* `rra` : rotation inverse de `a`
* `rrb` : rotation inverse de `b`
* `rrr` : `rra` et `rrb` en même temps

---

## Structure générale du projet

Le projet est organisé autour de plusieurs blocs :

* **parse** : validation des flags et des nombres, remplissage de la pile `a`
* **stack** : utilitaires de manipulation et d'analyse de piles
* **ops** : implémentation des opérations autorisées
* **algo** : stratégies de tri
* **bench** : statistiques d'exécution et affichage du mode benchmark
* **main** : initialisation, choix de la stratégie, lancement du tri

---

## Choix techniques

### Représentation des piles

Les piles sont représentées avec une liste chaînée.
Chaque nœud contient :

* la valeur d'origine ;
* un `index` correspondant à son rang dans l'ordre trié ;
* un pointeur vers l'élément suivant.

Cette approche permet une manipulation naturelle des opérations de pile, notamment `push`, `swap` et `rotate`.

### Indexation

Avant le tri, chaque valeur reçoit un `index` représentant sa position dans l'ordre croissant de l'ensemble des données.

Exemple :

Valeurs :

```text
42 -5 100 8
```

Indices :

```text
2 0 3 1
```

Cette normalisation simplifie fortement les algorithmes de tri, surtout pour le radix sort et le tri par chunks.

### Mesure du désordre

Le projet calcule un `disorder` compris entre `0` et `1`, basé sur le nombre d'inversions dans la pile initiale.

* `0` : pile déjà triée
* `1` : pile entièrement inversée

Cette valeur sert au mode adaptatif pour sélectionner une stratégie plus pertinente selon l'état initial de la pile.

---

## Algorithmes choisis

Le sujet impose quatre approches : simple, medium, complex et adaptive.

### 1. Algorithme simple — `O(n²)`

La stratégie simple repose sur une approche basique de tri adaptée à `push_swap`, pensée pour les cas les plus simples ou les piles peu désordonnées.

Justification :

* implémentation lisible ;
* comportement prévisible ;
* bonne base pour répondre à l'exigence du sujet sur une stratégie quadratique ;
* adaptée aux petites tailles ou aux entrées presque triées.

### 2. Algorithme medium — `O(n√n)` : tri par chunks

La stratégie medium repose sur un découpage des index en groupes appelés *chunks*.

Principe :

1. diviser l'intervalle des index en blocs ;
2. pousser progressivement dans `b` les éléments appartenant au chunk courant ;
3. organiser `b` pour faciliter la remontée ;
4. replacer les éléments dans `a` du plus grand au plus petit.

Pourquoi ce choix :

* approche adaptée au modèle `push_swap` ;
* meilleur compromis que l'algorithme simple sur des entrées intermédiaires ;
* plus efficace qu'un tri quadratique pur ;
* répond bien à la complexité attendue par le sujet pour la catégorie medium.

### 3. Algorithme complexe — `O(n log n)` : radix sort sur les index

La stratégie complexe repose sur un radix sort binaire appliqué aux index.

Principe :

1. lire les bits des index du plus faible au plus fort ;
2. envoyer dans `b` les éléments dont le bit courant vaut `0` ;
3. faire tourner `a` pour conserver ceux dont le bit vaut `1` ;
4. remettre ensuite tous les éléments de `b` dans `a` ;
5. répéter pour chaque bit.

Pourquoi ce choix :

* très utilisé sur `push_swap` ;
* facile à justifier ;
* robuste sur des entrées importantes ;
* très bien adapté à une pile indexée ;
* donne de bons résultats sur les gros cas.

### 4. Algorithme adaptatif

Le mode adaptatif choisit automatiquement la stratégie selon le `disorder`.

Seuils utilisés :

* `disorder < 0.2` → stratégie simple
* `0.2 <= disorder < 0.5` → stratégie medium
* `disorder >= 0.5` → stratégie complexe

Justification :

* une pile presque triée ne nécessite pas toujours un algorithme lourd ;
* les entrées intermédiaires profitent d'un découpage par chunks ;
* les entrées très désordonnées sont mieux gérées par un radix.

Cette approche permet de répondre à la contrainte du sujet tout en donnant au programme un comportement plus flexible.

---

## Mode benchmark

Le flag `--bench` affiche des informations complémentaires sur `stderr` :

* pourcentage de désordre initial ;
* stratégie réellement exécutée ;
* complexité théorique associée ;
* nombre total d'opérations ;
* détail du nombre de chaque opération (`sa`, `pb`, `ra`, etc.).

Exemple :

```bash
./push_swap --bench --medium 8 3 6 1 7 2 5 4
```

Exemple de sortie benchmark :

```text
[bench] disorder: 60.71%
[bench] strategy: Medium (O(n√n))
[bench] total_ops: ...
[bench] sa: ... sb: ... ss: ... pa: ... pb: ...
[bench] ra: ... rb: ... rr: ... rra: ... rrb: ... rrr: ...
```

---

## Exemples d'utilisation

Tri simple :

```bash
./push_swap 2 1 3
```

Tri forcé avec stratégie medium :

```bash
./push_swap --medium 5 1 4 2 3
```

Tri forcé avec stratégie complexe :

```bash
./push_swap --complex 8 3 6 1 7 2 5 4
```

Mode benchmark :

```bash
./push_swap --bench --adaptive 8 3 6 1 7 2 5 4
```

Entrée sous forme de chaîne :

```bash
./push_swap --complex "3 2 1 6 5 4"
```

---

## Tests utilisés

Le projet a été validé sur plusieurs types de cas :

* listes déjà triées ;
* listes inversées ;
* listes avec peu de désordre ;
* listes aléatoires ;
* nombres négatifs et positifs ;
* erreurs de parsing ;
* tests avec `--bench` ;
* tests avec chaque stratégie forcée.

Exemples :

```bash
./push_swap --simple 2 1
./push_swap --medium 5 1 4 2 3
./push_swap --complex 8 3 6 1 7 2 5 4
./push_swap --adaptive 1 2 3 5 4
./push_swap --bench --complex 3 2 1
```

---

## Répartition du travail

Projet réalisé en binôme par :

* `vavegee`
* `tbenavid`

Répartition générale :

* parsing, structure du projet, intégration, débogage, bench et organisation générale ;
* implémentation des opérations, calcul du disorder, algorithmes de tri et raccords entre modules.

Cette répartition a évolué pendant le projet au fur et à mesure des besoins, des corrections et des phases de fusion entre les branches.

---

## Utilisation de l'IA

L'IA a été utilisée comme outil d'assistance, notamment pour :

* clarifier le sujet ;
* aider à structurer le projet ;
* proposer des pistes d'organisation de fichiers ;
* aider au débogage et à l'intégration entre modules ;
* relire et reformuler certaines parties de la documentation.

L'IA n'a pas été utilisée comme substitut à la compréhension du projet.
Chaque partie intégrée au code a été relue, adaptée, testée et discutée dans le cadre du binôme.

---

## Resources

### Documentation et références classiques

* Documentation C standard
* Documentation GNU Make
* Donald Knuth — travaux sur la complexité algorithmique
* Ressources générales sur les listes chaînées
* Ressources sur radix sort
* Ressources sur les approches de tri par chunks
* Sujet officiel `push_swap`

### Ressources utiles à consulter

* man pages : `man gcc`, `man make`, `man write`
* articles sur la notation Big-O
* tutoriels sur les structures de piles et listes chaînées

---

## Notes finales

Le projet a été pensé pour respecter :

* les contraintes du sujet ;
* une architecture modulaire ;
* une séparation claire entre parsing, structures, opérations, algorithmes et bench ;
* une logique de choix de stratégie pilotée par les flags ou par le désordre initial.

L'objectif principal n'a pas été seulement de trier, mais de trier intelligemment dans le cadre très contraint imposé par `push_swap`.

```

Si tu veux, je peux aussi te faire une **version plus courte et plus “propre 42”**, un peu moins détaillée.
```
