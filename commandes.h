#ifndef __COMMANDES_H
#define __COMMANDES_H
#include "struct.h"


Commande get_commande();
void analyse_commande(Commande *ma_commande);
void exit_prog();
BOOL create_formation(Commande ma_commande,Commande_Formation *commande_F);
BOOL formation_is_valid(Commande_Formation *commandeF);
void init_formation(Commande ma_commande,Commande_Formation *commande_F);




#endif