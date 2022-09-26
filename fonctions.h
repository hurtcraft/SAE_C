#ifndef __FONCTIONS_H
#define __FONCTIONS_H
#include "struct.h"

void clear_str(char str[],int len);
BOOL commande_is_valid(Commande ma_commande);

int get_matiere_indice(Commande_Epreuve commande_E,Matiere liste_mat[],int nb_matiere);
BOOL epreuve_already_exist(Commande_Epreuve commande_E,Matiere liste_mat[],int nb_matiere);
BOOL semestre_is_valid(Commande ma_commande);
int **create_2d_array(int row,int col);
void clear_2d_array(int **array,int row,int col);
void print_array(int **array, int row , int col);



#endif