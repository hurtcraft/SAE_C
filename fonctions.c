#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>
void analyse_saisie(char command[]){
    if (command =="exit"){
        exit_prog;
    }
    else if (command=="formation"){

    }
}
void exit_prog(){
    printf("programme terminé :)\n");
    exit(EXIT_SUCCESS);
}

