#ifndef __ARBRE__H__
#define __ARBRE__H__

#include <stdio.h>
#include <stdlib.h>

typedef struct Arbre
{
    int racine;                 // la racine de l'arbre
    struct Arbre *pere;         // le parent d'un noeud
    struct Arbre *arbre_gauche; // le fils gauche d'un parent
    struct Arbre *arbre_droit;  // le fils droit d'un parent
} Arbre;

/* Prototypes des fonctions */

nouveau_noeud(int x);
void clean_tree(Tree *tr);
Tree *join_tree(Tree *left, Tree *right, int node);
void print_tree_prefix(Tree *tr);
int count_tree_nodes(Tree *tr);

#endif