#include <stdio.h>
#include "struct.h"
#include <string.h>
#include <stdlib.h>
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
BOOL semestre_is_valid(Commande ma_commande){
    if (atoi(ma_commande.args[0])>2 || atoi(ma_commande.args[0])<1 ){
        printf("Le numero de semestre saisie est incorrect\n");
        return False;
    }
    return True;
}
int **create_2d_array(int row,int col){
    static int **array=NULL;
    array=malloc(sizeof(int*)*row);
    if (array==NULL)
    {
        printf("pb alloc ");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < row; i++)
    {
        array[i]=malloc(sizeof(int)*col);
        if (array[i]==NULL)
        {
            printf("pb alloc ");
            exit(EXIT_FAILURE);
        }
    }
    return array;
    
}
void clear_2d_array(int **array,int row,int col){
    for (size_t i = 0; i < row; i++)
    {
        free(array[i]);
    }
    free(array);
}
void print_array(int **array, int row , int col){
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
    
}