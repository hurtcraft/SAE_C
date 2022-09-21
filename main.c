#include <stdio.h>
#include "commandes.h"
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include "fonctions.h"
int main(){
    setlocale(LC_ALL,"UTF8");
    BOOL running=True;

    Commande ma_commande;
    Commande_Formation commande_F;

    
    do
    {
        ma_commande = get_saisie();
        commande_F=create_formation(&ma_commande);
    } while (strcmp(ma_commande.nom_commande,"formation")!=0 && nb_UE_is_valid(commande_F));
    

    
    
    

    return 0;

}