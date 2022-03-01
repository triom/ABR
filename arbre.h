#ifndef __ARBRE__H__
#define __ARBRE__H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Arbre
{
    int racine;                 // la racine de l'arbre
    struct Arbre *pere;         // le parent d'un noeud
    struct Arbre *arbre_gauche; // le fils gauche d'un parent
    struct Arbre *arbre_droit;  // le fils droit d'un parent
} Arbre;

/* Prototypes des fonctions */

Arbre *nouveau_noeud(int n);
Arbre *arbre_vide(Arbre *abr);
Arbre *reunir_arbre(int noeud, Arbre *fag, Arbre *fad);
Arbre *inserer_noeud(Arbre *arbre, int noeud);
int compter_noeuds(Arbre *abr);
void parcours_infixe(Arbre *abr);
void parcours_prefixe(Arbre *abr);
void parcours_suffixe(Arbre *abr);
bool rechercher_valeur(Arbre *abr, int a);
Arbre *supprimer_noeud(Arbre *abr, int a);
Arbre *valeur_max(Arbre *abr);
Arbre *d_max(Arbre *abr);
int hauteur_arbre(Arbre *abr);
Arbre *tri_tableau_arbre(int *tableau);

#endif