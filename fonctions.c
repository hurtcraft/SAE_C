#include <stdio.h>
#include "struct.h"

void clear_str(char str[],int len){
    for (size_t i = 0; i < len+1; i++){
        str[i]=0;
    }
}
BOOL commande_is_valid(Commande ma_commande){
    if (ma_commande.nom_commande[0]==-1){
        printf("Commande non reconnue ou manque d'argument ");
        return False;
    }   
    return True;
}
