#ifndef __FONTCIONS_H
#define __FONCTIONS_H
typedef enum BOOL {
    False,
    True,
}BOOL;
typedef struct Commande
{
    char nom_commande[30];
    char args[6][30];
    
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


void analyse_saisie(Commande *ma_commande);
void exit_prog();
BOOL formation(Commande_Formation *ma_commande_formation);







#endif