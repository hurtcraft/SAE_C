#ifndef __COMMANDES_H
#define __COMMANDES_H
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
    unsigned int nb_UE;

}Commande_Formation;

typedef struct Commande_Epreuve{
    unsigned int num_semestre;
    char nom_matier[30];
    char nom_epreuve[30];
    unsigned int tab_coeff_UE[6];
}Commande_Epreuve;

typedef struct Commande_Coeff{
    unsigned int num_semetres;


}Commande_Coeff;

Commande get_saisie();
void analyse_commande(Commande *ma_commande);
void exit_prog();
BOOL formation(Commande_Formation *ma_commande_formation);







#endif