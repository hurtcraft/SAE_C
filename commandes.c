
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commandes.h"
#include "fonctions.h"

Commande get_commande(){
    Commande ma_commande;
    char buffer[256];
    char temp[30]={0};
    
    ma_commande.nb_args=0;
    

    printf("saisir commande : ");
    scanf(" %[^\n]",buffer);

    if (strcmp(buffer,"exit")==0)
    {
        /* si l'utilisateur ecrit "exit"--> sortie programme 
        pas besoin d'executé le reste*/
        exit_prog();
    }
    

    unsigned int i =0;
    unsigned int count=0;
    strcat(buffer," ");//l'ajout d'un espace est necessaire
                       //-->voir fonctionnement de la boucle 
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
    //pour ajouté le dernier args qui n'est pas pris en compte par la boucle
    --ma_commande.nb_args;
    return ma_commande;

}

void analyse_commande(Commande *ma_commande){

    if(strcmp(ma_commande->nom_commande,"formation")==0){
        Commande_Formation commandeF;

    }

}
void exit_prog(){
    printf("programme terminé :)\n");
    exit(EXIT_SUCCESS);
}



BOOL create_formation(Commande ma_commande,Commande_Formation *commande_F){
    /* return True si la formation à pu se créer
    */
    if (ma_commande.nb_args!=1)
    {
        printf("trop ou pas assez de d'argument pour la commande <formation>\n ex: <formation> <nb_UE:INT>\n");
        return False;
    }
    int nb_UE;
    if (*ma_commande.args[0]>=48 && *ma_commande.args[0]<=57)
    //ma_commande.args doit etre compris entre 0 et 9 soit 48 et 57 dans la table ascii

    {
        nb_UE=atoi(ma_commande.args[0]);
    }
    else{
        printf("saisie incorrect <formation> <nb_UE:INT>\n");
        return False;
    }
    
    
    

    if (commande_F->nb_UE_is_def==True){
        printf("Le nombre d'UE est deja definie\n");
        return False;
    }
    
    else if(nb_UE>=3 && nb_UE<=6){
        printf("Le nombre d'UE est definie\n");
        commande_F->nb_UE_is_def=True;
        commande_F->nb_UE=nb_UE;
        return True;
        
    }
    else{
        printf("Le nombre d'UE est incorrect\n");
        commande_F->nb_UE_is_def=False;
        return False;
    }

}

void init_formation(Commande ma_commande,Commande_Formation *commande_F){
    commande_F->nb_UE_is_def=False;
    BOOL formation_is_valid=False;
    
    while (formation_is_valid==False)
    {

        ma_commande=get_commande();
        if(strcmp(ma_commande.nom_commande,"formation")!=0 ){
            printf("Le nombre d'UE n'est pas definie\n");
            continue;
        }
        else{
            formation_is_valid=create_formation(ma_commande,&*commande_F);
            
                    
            if(commande_F->nb_UE_is_def==False){
                printf("le nombre d'UE n'est pas definie\n");
                continue;
            }
        }

    }

}

