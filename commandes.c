
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commandes.h"
#include "fonctions.h"
Commande get_saisie(){
    Commande ma_commande;
    char buffer[256];
    char temp[30];
    
    ma_commande.nb_args=0;

    printf("saisir commande : ");
    scanf("%[^\n]",buffer);

    unsigned int i =0;
    unsigned int count=0;
    unsigned int num_args=0;
    clear_str(temp,strlen(temp));
    while (buffer[i]!='\0')
    {

        if (buffer[i]==' '){
            if(num_args==0){
                /*l'argument de l'indice 0 est toujours le nom de la commande 
                ex: formation 2 --> ici l'agument d'indice 0 est "formation"
                et l'argument d'indice 1 est "2"
                */
                strcpy(ma_commande.nom_commande,temp);
            }
            num_args++;
            ma_commande.nb_args++;
            count=0;
            clear_str(temp,strlen(temp));
        }
        else{
            temp[count]=buffer[i];
            ++count;
        }
        
        ++i;
    }

    printf("%s",ma_commande.nom_commande);
    
    return ma_commande;
    

}
void analyse_commande(Commande *ma_commande){
    if (strcmp(ma_commande->nom_commande,"exit")==0){
        exit_prog();
    }
    else if(strcmp(ma_commande->nom_commande,"formation")==0){
        printf("");
    }
    //scanf("%[^\n]",str);
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
