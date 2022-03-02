// SONWA MANE Triomphante
#ifndef __ARBRE__H__
#define __ARBRE__H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define VALEUR_MAX 100 // valeur max d'un noeud
#define VALEUR_MIN 2   // valeur min d'un noeud
#define SIZE 10        // taille du tableau
#define MAX(a, b) ((a) > (b) ? a : b)
#define MIN(a, b) ((a) < (b) ? a : b)

typedef struct Arbre
{
    int racine;                 // la racine de l'arbre
    struct Arbre *pere;         // le parent d'un noeud
    struct Arbre *arbre_gauche; // le fils gauche d'un parent
    struct Arbre *arbre_droit;  // le fils droit d'un parent
} Arbre;

/* Prototypes des fonctions */

Arbre *nouveau_noeud(int n);
Arbre *arbre_vide();
Arbre *reunir_arbre(int noeud, Arbre *fag, Arbre *fad);
Arbre *inserer_noeud(Arbre *arbre, Arbre *noeud);
int compter_noeuds(Arbre *abr);
void parcours_infixe(Arbre *abr);
void parcours_prefixe(Arbre *abr);
void parcours_suffixe(Arbre *abr);
bool rechercher_valeur(Arbre *abr, int a);
Arbre *supprimer_noeud(Arbre *abr, int a);
int valeur_max(Arbre *abr);
Arbre *d_max(Arbre *abr);
int hauteur_arbre(Arbre *abr);
int *generer_tableau();
Arbre *tri_tableau_arbre(int *tableau);
int nombres_feuilles(Arbre *abr);

#endif