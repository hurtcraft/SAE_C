#include <stdio.h>

#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include "fonctions.h"
#include "commandes.h"
int main(){
    setlocale(LC_ALL,"");
    BOOL running=True;
    char buffer[256]={0};

    Commande ma_commande;
    Commande_Formation commande_F;
    init_formation(ma_commande,&commande_F);

    return 0;

}