#include <stdio.h>
#include "fonctions.h"
#include <string.h>
#include <stdlib.h>
int main(){
    Commande c1;

    strcpy(c1.args[0],"bjr");
    strcpy(c1.args[1],"orv");
    
    printf("%s et %s",c1.args[0],c1.args[0]);
    
    
    
    return 0;

}