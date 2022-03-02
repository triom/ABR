// SONWA MANE Triomphante
#include "arbre.h"
#include <time.h>
#define VALEUR_MAX 100 // valeur max d'un noeud
#define VALEUR_MIN 2   // valeur min d'un noeud
#define SIZE 10        // taille du tableau
#define MAX(a, b) ((a) > (b) ? a : b)
#define MIN(a, b) ((a) < (b) ? a : b)

// on crée un nouveau noeud
Arbre *nouveau_noeud(int n)
{
    Arbre *abr = malloc(sizeof(*abr));

    if (abr == NULL)
    {
        printf("Erreur: alloc nouveau noeud.\n");
        exit(-1);
    }

    abr->racine = n;  // on crée la racine
    abr->pere = NULL; // attribuer la valeur NULL au pere, fils gauche et fils droit de l'arbre
    abr->arbre_droit = NULL;
    abr->arbre_gauche = NULL;

    printf("Le noeud %d crée !!!\n ", abr->racine);

    return abr;
}

// renvoie une arbre vide
Arbre *arbre_vide()
{
    Arbre *abr;
    if (abr == NULL) // si arbre null ne rien faire
        ;

    printf("Suppression de %d\n", abr->racine);
    // appel recursif sur les fils gauche e droit
    abr = NULL;
    return abr;
}

// reunir un arbre avec racine le noeud , et les fils gauches et droits les arbres passés en parametre
Arbre *reunir_arbre(int noeud, Arbre *fag, Arbre *fad)
{
    Arbre *abr = nouveau_noeud(noeud); // on crée un arbre avec un seul noeud, la racine
    abr->arbre_gauche = fag;           // on lui attribut le fils(arbre) gauche
    abr->arbre_droit = fad;
    if (fad != NULL) // on definit les peres de chaque arbre (gauche et droit)
        fad->pere = abr;
    if (fag != NULL)
        fag->pere = abr;
    return abr;
}

Arbre *inserer_noeud(Arbre *arbre, Arbre *noeud)
{
    printf("%s\n", "on rentre dans la fonctionde de constructiion de l'arbre");
    if (arbre == NULL)
    {
        arbre->racine = noeud->racine;
        printf("%d crée\t\n", arbre->racine);
        return arbre;
    }
    if (arbre != NULL)
    {
        if (noeud->racine > arbre->racine) // valeur inferieur a la racine on va a droite
        {
            printf("%d > %d, %d va à droite\t\n", noeud->racine, arbre->racine, noeud->racine);
            inserer_noeud(arbre->arbre_droit, noeud);
            return reunir_arbre(arbre->racine, arbre->arbre_gauche, arbre->arbre_droit);
        }
        else if (noeud->racine < arbre->racine) // valeur superieur a la racine on va a gauche
        {
            printf("%d < %d, %d va à gauche\t\n", noeud->racine, arbre->racine, noeud->racine);
            inserer_noeud(arbre->arbre_gauche, noeud);
            return reunir_arbre(arbre->racine, arbre->arbre_gauche, arbre->arbre_droit);
        }
        else
        {
            printf("rien faire\n");
        }
    }
}

int compter_noeuds(Arbre *abr)
{
    if (abr == NULL)
        return 0;

    return (1 + compter_noeuds(abr->arbre_gauche) + compter_noeuds(abr->arbre_droit));
}

// parcours de l'arbre en affichage infixe en affichant les noeuds de façon croissante
void parcours_infixe(Arbre *abr)
{
    if (abr == NULL)
        printf("arbre vide\n");

    if (abr->arbre_gauche != NULL)
        printf("(%d) -> %d\n", abr->pere, abr->racine);
    parcours_infixe(abr->arbre_gauche);

    printf("(%d)\n", abr->racine);

    if (abr->arbre_droit != NULL)
        parcours_infixe(abr->arbre_droit);
}

// parcours de l'arbre en affichage prefixe
void parcours_prefixe(Arbre *abr)
{
    if (abr == NULL)
        printf("arbre vide\n");

    printf("(%d)\n", abr->racine);

    if (abr->arbre_gauche != NULL)
        parcours_prefixe(abr->arbre_gauche);

    if (abr->arbre_droit != NULL)
        parcours_prefixe(abr->arbre_droit);
}

// parcours de l'arbre affichage postfixe
void parcours_suffixe(Arbre *abr)
{
    if (abr == NULL)
        printf("arbre vide\n");

    if (abr->arbre_gauche != NULL)
        parcours_suffixe(abr->arbre_gauche);

    if (abr->arbre_droit != NULL)
        parcours_suffixe(abr->arbre_droit);

    printf("(%d)\n", abr->racine);
}

bool rechercher_valeur(Arbre *abr, int a)
{
    if (abr == NULL)
    {
        return false;
    }
    else
    {
        if (a == abr->racine)
        {
            return true;
        }
        else if (a < abr->racine)
        {
            return rechercher_valeur(abr->arbre_gauche, a);
        }
        else
        {
            return rechercher_valeur(abr->arbre_droit, a);
        }
    }
}

int valeur_max(Arbre *abr)
{
    if (abr == NULL)
        ;
    if (abr->arbre_droit == NULL)
    {
        return abr->racine;
    }
    else
    {
        return (valeur_max(abr->arbre_droit));
    }
}

Arbre *d_max(Arbre *abr)
{
    if (abr == NULL)
        ;
    if (abr->arbre_droit == NULL)
    {
        return abr->arbre_gauche;
    }
    else
    {
        return (reunir_arbre(abr->racine, abr->arbre_gauche, d_max(abr->arbre_droit)));
    }
}

Arbre *supprimer_noeud(Arbre *abr, int a)
{
    if (abr == NULL)
    {
        return abr;
    }
    else if (a > abr->racine)
    {
        return reunir_arbre(abr->racine, abr->arbre_gauche, supprimer_noeud(abr->arbre_droit, a));
    }
    else if (a < abr->racine)
    {
        return reunir_arbre(abr->racine, supprimer_noeud(abr->arbre_gauche, a), abr->arbre_droit);
    }
    else // si a = la racine
    {
        if ((abr->arbre_gauche == NULL) && (abr->arbre_droit == NULL))
        {
            return arbre_vide(abr);
        }
        else if (abr->arbre_gauche == NULL)
        {
            return abr->arbre_droit;
        }
        else if (abr->arbre_droit == NULL)
        {
            return abr->arbre_gauche;
        }
        else // si a = la racine
        {
            return (valeur_max(abr->arbre_gauche), d_max(abr->arbre_gauche), abr->arbre_droit);
        }
    }
}
int hauteur_arbre(Arbre *abr)
{
    if (abr == NULL)
    {
        return 0;
    }
    else
    {
        return MAX(hauteur_arbre(abr->arbre_droit), hauteur_arbre(abr->arbre_gauche)) + 1;
    }
}

// generer le tableau donc nous avons besoin
int *generer_tableau()
{
    srand(time(NULL));
    int *tableau = NULL;
    tableau = malloc(sizeof(int) * SIZE);
    for (int j = 0; j < SIZE; j++)
    {
        tableau[j] = (rand() % (VALEUR_MAX - VALEUR_MIN + 1) + VALEUR_MIN);
    }

    return tableau;
}

// la fonction de tri
Arbre *tri_tableau_arbre(int *tableau)
{
    Arbre *abr = NULL;
    printf("\n");

    for (int i = 0; i < SIZE; i++)
    {
        // abr = inserer_noeud(abr, tableau[i]);
        ;
    }
    return abr;
}

int nombres_feuilles(Arbre *abr)
{
    if (abr == NULL)
        return 0;
    else if (abr->racine)
        return 1;
    else
        return nombres_feuilles(abr->arbre_droit) + nombres_feuilles(abr->arbre_gauche);
}