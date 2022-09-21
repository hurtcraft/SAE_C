
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commandes.h"
#include "fonctions.h"
Commande get_saisie(){
    Commande ma_commande;
    char buffer[256];
    char temp[30]={0};
    
    ma_commande.nb_args=0;

    printf("saisir commande : ");
    scanf("%[^\n]",buffer);

    unsigned int i =0;
    unsigned int count=0;
    unsigned int num_args=0;
    
    while (buffer[i]!='\0')
    {

        if (buffer[i]==' '){
            
            if (ma_commande.nb_args==0){
                strcpy(ma_commande.nom_commande,temp);
            }
            else{
                strcpy(ma_commande.args[ma_commande.nb_args-1],temp);
            }
            
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
    strcpy(ma_commande.args[ma_commande.nb_args-1],temp);
    
    return ma_commande;
    

}
void analyse_commande(Commande *ma_commande){
    if (strcmp(ma_commande->nom_commande,"exit")==0){
        exit_prog();
    }
    else if(strcmp(ma_commande->nom_commande,"formation")==0){
        Commande_Formation commandeF;

    }

}
void exit_prog(){
    printf("programme terminé :)\n");
    exit(EXIT_SUCCESS);
}
BOOL nb_UE_is_valid(Commande_Formation commandeF){
    if(commandeF.nb_UE>=3 && commandeF.nb_UE<=6){
        return True;
    }
    return False;
}
Commande_Formation create_formation(Commande *ma_commande){
    Commande_Formation commande_F;
    commande_F.nb_UE=atoi(ma_commande->args[0]);
    printf("%d\n",commande_F.nb_UE);
    if(commande_F.nb_UE>=3 && commande_F.nb_UE<=6 ){
        printf("Le nombre d'UE est deja definie");
        commande_F.nb_UE_is_def=True;
        
    }
    else{
        printf("Le nombre d'UE est incorrect");
        commande_F.nb_UE_is_def=False;
    }
    return commande_F;
}
