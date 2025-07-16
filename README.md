# Philosophers

Philosophers est un projet du cursus 42 qui implémente le problème classique des philosophes à table en utilisant les threads et les mutex. Il simule des philosophes qui mangent, pensent et dorment, en gérant les ressources partagées (fourchettes) de manière thread-safe.

## Sommaire
- [Fonctionnalités](#fonctionnalités)
- [Arborescence](#arborescence)
- [Installation](#installation)
- [Utilisation](#utilization)
- [Le problème des philosophes](#le-problème-des-philosophes)
- [Auteur](#auteur)

---

## Fonctionnalités
- Simulation du problème des philosophes à table
- Gestion des threads avec pthread
- Synchronisation avec mutex
- Gestion des fourchettes comme ressources partagées
- Protection contre les deadlocks
- Affichage des états des philosophes en temps réel

---

## Arborescence

```
42-philosophers/
├── includes/
│   └── philosopher.h
├── src/
│   ├── core/
│   │   ├── main.c
│   │   └── parsing.c
│   ├── philosopher/
│   │   ├── philofactory.c
│   │   ├── routine.c
│   │   └── triche.c
│   └── utils/
│       └── ft_isdigit.c
├── obj/
├── Makefile
└── README.md
```

---

## Installation

1. **Cloner le dépôt**  
   ```sh
   git clone https://github.com/sabejaou/42-philosophers.git
   cd 42-philosophers
   ```

2. **Compiler le projet**  
   ```sh
   make
   ```
   Le binaire `philo` est généré à la racine.

---

## Utilisation

1. **Lancer le programme avec des paramètres :**
   ```sh
   ./philo [nombre_philosophes] [temps_mort] [temps_manger] [temps_dormir] [nombre_repas]
   ```

2. **Exemple d'utilisation :**
   ```sh
   ./philo 5 800 200 200
   ```
   - 5 philosophes
   - 800ms avant qu'un philosophe meure
   - 200ms pour manger
   - 200ms pour dormir

---

## Le problème des philosophes

Le problème classique des philosophes à table :
- N philosophes sont assis autour d'une table circulaire
- Chaque philosophe a besoin de 2 fourchettes pour manger
- Les philosophes alternent entre manger, penser et dormir
- Le défi est d'éviter les deadlocks et la famine

**États d'un philosophe :**
- **Manger** : prend 2 fourchettes, mange pendant un temps donné
- **Dormir** : dort pendant un temps donné
- **Penser** : pense (état par défaut)

---

## Auteur

- **Sabejaou**  
  [sabejaou@student.42lyon.fr](mailto:sabejaou@student.42lyon.fr)