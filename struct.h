#ifndef __STRUCT_H
#define __STRUCT_H

typedef enum BOOL {
    False,
    True,
}BOOL;

typedef struct Commande
{
    
    char nom_commande[30];
    int nb_args;//nb d'argument qui suit la commande , la commande n'est pas pris en comtpe comme un argument
    char args[10][30];//tableau en 2D pouvant contenir 10 arguments de type str dont la taille max est de 30 chars

    
}Commande;

typedef struct Commande_Formation{
    BOOL nb_UE_is_def;
    unsigned int nb_UE;

}Commande_Formation;

typedef struct Commande_Epreuve{
    unsigned int num_semestre;
    char nom_matiere[30];
    char nom_epreuve[30];
    unsigned int tab_coeff_UE[6];
}Commande_Epreuve;

typedef struct Commande_Coeff{
    unsigned int num_semetres;


}Commande_Coeff;

typedef struct Etudiant
{
    char nom[30];
    
}etudiant;

typedef struct Matiere
{
    char nom[30];
    int nb_epreuve;
    Commande_Epreuve liste_epr[5];
}Matiere;

#endif