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
    commande_F.nb_UE_is_def=False;

    printf("hellow world");
    
    while (running==True)
    {

        ma_commande=get_commande();
        printf("%s\n",ma_commande.nom_commande);
        commande_is_valid(ma_commande);
        analyse_commande(&ma_commande);
        
        
    }
    
    
    
    

  

    

    return 0;

}