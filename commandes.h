#ifndef __COMMANDES_H
#define __COMMANDES_H
#include "struct.h"


Commande get_saisie();
void analyse_commande(Commande *ma_commande);
void exit_prog();
Commande_Formation create_formation(Commande *ma_commande);
BOOL nb_UE_is_valid(Commande_Formation commandeF);



#endif