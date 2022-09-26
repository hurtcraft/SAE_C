
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commandes.h"
#include "fonctions.h"
#define nb_args_min_epr 3 //on définie ici le nombre minimum d'argument que prend la commande épreuve
                          //soit 3 (num_semestre nom_matiere nom épreuve)
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

    
    if(buffer[strlen(buffer)+1]==' '){
        buffer[strlen(buffer)]='\0';
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

void analyse_commande(Commande ma_commande){

    if(strcmp(ma_commande.nom_commande,"epreuve")==0 ){

        printf("sqds");
    
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

BOOL create_epreuve(Commande ma_commande , Commande_Epreuve *commande_E, int nb_UE,Matiere liste_mat[],int *nb_matiere){
    int nb_coeff_equal_zero=0;
    int mon_coeff;
    

    if(ma_commande.nb_args!=nb_args_min_epr+nb_UE){
        printf("Trop ou pas assez d'argument : \n ex : <epreuve> <num_semestre> <nom_matiere> <nom_epreuve><1_coeff_par_UE>il y'a %d UE\n",nb_UE);
        return False;
    }
    commande_E->num_semestre=atoi(ma_commande.args[0]);   
    strcpy(commande_E->nom_matiere,ma_commande.args[1]);
    strcpy(commande_E->nom_epreuve,ma_commande.args[2]); 

    for (size_t i = 0; i < nb_UE; i++)
    {
        mon_coeff=atoi(ma_commande.args[i+3]);
        if(mon_coeff==0){
            nb_coeff_equal_zero++;
        }
        else if (mon_coeff<0){
            printf("Au moins un des coefficients est incorrect\n");
            return False;
        }
        commande_E->tab_coeff_UE[i]=mon_coeff;
    }

    if(nb_coeff_equal_zero==nb_UE){
        printf("Au moins un des coefficients doit etre positif\n");
        return False;
    }
    if (semestre_is_valid(ma_commande)==False){
        return False;
    }


    int matiere_indice=get_matiere_indice(*commande_E,liste_mat,*nb_matiere);
    Matiere ma_matiere;
    if (epreuve_already_exist(*commande_E,liste_mat,*nb_matiere)==True){
        printf("Une meme epreuve existe deja\n");
        return False;

    }
    if (matiere_indice==-1){
        // creation matiere
        
        ma_matiere.nb_epreuve=0;
        strcpy(ma_matiere.nom,commande_E->nom_matiere);
        ma_matiere.liste_epr[ma_matiere.nb_epreuve]=*commande_E;
        ma_matiere.nb_epreuve+=1;
        liste_mat[*nb_matiere]=ma_matiere;
        *nb_matiere+=1;
        printf("Matiere ajoute a la formation\n");
        return True;
    }
    else{
        ma_matiere.liste_epr[ma_matiere.nb_epreuve]=*commande_E;
        ma_matiere.nb_epreuve+=1;
        liste_mat[matiere_indice]=ma_matiere;
        printf("Epreuve ajouter a la formation\n");
        return True;
        
    }


}
   
BOOL verif_coeff(Commande ma_commande ,Matiere liste_mat[],int nb_matiere, const int nb_UE){
    if (semestre_is_valid(ma_commande)==False)
    {
        return False;
    }
    int num_semestre=atoi(ma_commande.args[0]);
    int **array_UE=create_2d_array(nb_matiere,nb_UE);

   
    for (size_t i = 0; i < nb_matiere; i++)
    {   //parcours matieres
        
        for (size_t j = 0; j < liste_mat[i].nb_epreuve; j++)
        {   //parcours epreuves
            //if(liste_mat[i].liste_epr[j].num_semestre==num_semestre){
                //printf("%d \n",liste_mat[i].nb_epreuve);
                for (size_t z = 0; z < nb_UE; z++)
                {
                    printf("%d ",liste_mat[i].liste_epr[j].tab_coeff_UE[z]);
                }
            //}
        }
        
        
    }
    //print_array(array_UE,nb_matiere,nb_UE);
    clear_2d_array(array_UE,nb_matiere,nb_UE);
    return True;   
}