#include <stdio.h>
#include "fonctions.h"
#include <string.h>
#include <stdlib.h>
int main(){
    Commande c;
    strcpy(c.nom_commande,"abc");
    
    analyse_saisie(&c);
    
    
    
    return 0;

}