#ifndef __COMMANDES_H
#define __COMMANDES_H
#include "struct.h"


Commande get_commande();
void analyse_commande(Commande *ma_commande);
void exit_prog();
Commande_Formation create_formation(Commande *ma_commande);

BOOL formation_is_init(Commande_Formation *commandeF);




#endif