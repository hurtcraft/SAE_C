#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void analyse_saisie(Commande *ma_commande){
    if (strcmp(ma_commande->nom_commande,"abc")==0){
        printf("sa marc");
    }
    else{
        printf("azert");
    }

}
void exit_prog(){
    printf("programme terminé :)\n");
    exit(EXIT_SUCCESS);
}

