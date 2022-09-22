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

    
    while (running==True)
    {

        ma_commande=get_commande();
        
        if(create_formation(ma_commande,&commande_F)){
            
            printf("il ya : %d UE\n",commande_F.nb_UE);
        }
        else{
            printf("marche pas\n");
        }        
    }

    return 0;

}