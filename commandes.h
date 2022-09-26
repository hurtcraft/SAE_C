#ifndef __COMMANDES_H
#define __COMMANDES_H
#include "struct.h"


Commande get_commande();
void analyse_commande(Commande ma_commande);
void exit_prog();

BOOL create_formation(Commande ma_commande,Commande_Formation *commande_F);
void init_formation(Commande ma_commande,Commande_Formation *commande_F);

BOOL create_epreuve(Commande ma_commande , Commande_Epreuve *commande_E, int nb_UE,Matiere liste_mat[],int *nb_matiere);

BOOL verif_coeff(Commande ma_comande,Matiere liste_mat[], int nb_matiere,const int nb_UE);


#endif