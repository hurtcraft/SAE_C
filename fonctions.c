#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void analyse_saisie(Commande *ma_commande){
    if (strcmp(ma_commande->nom_commande,"exit")==0){
        exit_prog();
    }
    else if(strcmp(ma_commande->nom_commande,"formation")==0){
        printf("");
    }

}
void exit_prog(){
    printf("programme terminé :)\n");
    exit(EXIT_SUCCESS);
}
BOOL formation(Commande_Formation *ma_commande_formation){
    if(ma_commande_formation->nb_UE>=3 && ma_commande_formation->nb_UE<=6 ){
        printf("Le nombre d'UE est deja definie");
        return True;
    }
    else{
        printf("Le nombre d'UE est incorrect");
        return False;
    }

}
