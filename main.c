#include <stdio.h>
#include "fonctions.h"
#include <string.h>
#include <stdlib.h>
#include <locale.h>
int main(){
    setlocale(LC_ALL,"UTF8");
    BOOL nb_ue_is_def=False;
    BOOL running=True;
    Commande ma_commande;
    char str[20];
    printf("saisir : ");
    scanf("%[^\n]",str);
    printf("%s",str);
    
    
    
    return 0;

}