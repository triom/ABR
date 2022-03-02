//SONWA MANE Triomphante
#include "arbre.h"

int main(void)
{
    int *tab = NULL;
    Arbre *abr, *abr_aux = NULL;
    int nombres_noeuds, hauteur_abr, noeud;
    tab = generer_tableau(); // vreer le tableau
    printf("%d\t", abr->racine);
    // afficher le tableau crée
    for (int c = 0; c < SIZE; c++)
    {
        printf("%d\t", tab[c]);
    }
    printf("\n");
    // abr = inserer_noeud(NULL, 5);
    //  creer notre arbre à partir du tableau
    for (int c = 0; c < SIZE; c++)
    {
        printf("!.................************...............!\n");
        abr_aux = nouveau_noeud(tab[c]);
        abr = inserer_noeud(abr, abr_aux);
        free(abr_aux);
    }
    parcours_prefixe(abr);
    nombres_noeuds = compter_noeuds(abr);
    /*hauteur_abr = hauteur_arbre(abr);
    parcours_infixe(abr);*/
    // free(tab);
    // free(abr);
    return 0;
}