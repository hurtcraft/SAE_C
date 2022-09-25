#include <stdio.h>
#include "struct.h"
#include <string.h>
void clear_str(char str[],int len){
    for (size_t i = 0; i < len+1; i++){
        str[i]=0;
    }
}
BOOL commande_is_valid(Commande ma_commande){
    if (ma_commande.nom_commande[0]==-1){
        printf("Commande non reconnue ou manque d'argument \n");
        return False;
    }   
    return True;
}
int get_matiere_indice(Commande_Epreuve commande_E,Matiere liste_mat[],int nb_matiere){
    /*
        return l'indice qui a était attribuer à la matiere dans liste_mat[] 
        sinon renvoie -1 si la matiere n'existe pas 
    */
    for (size_t i = 0; i < nb_matiere; i++){
        if(strcmp(commande_E.nom_matiere,liste_mat[i].nom)==0){
            
            return i;
        }
    }
    
    return -1;
}
BOOL epreuve_already_exist(Commande_Epreuve commande_E,Matiere liste_mat[],int nb_matiere){

    int indice=get_matiere_indice(commande_E,liste_mat,nb_matiere);
    if (indice!=-1)
    {
        for (size_t i = 0; i < liste_mat[indice].nb_epreuve; i++)
        {
            if (strcmp(liste_mat[indice].liste_epr[i].nom_epreuve,commande_E.nom_epreuve)==0)
            {
                return True;
            }
        }
        
    }
    
    return False;
    
}
