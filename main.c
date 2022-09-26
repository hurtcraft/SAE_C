#include <stdio.h>

#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include "fonctions.h"
#include "commandes.h"

int main(){
    setlocale(LC_ALL,"");
    const int NB_EPR_MAX=5;
    const int NB_MAT_MAX=10;
    Commande ma_commande;
    Commande_Formation commande_F;
    Commande_Epreuve commande_E;
    Matiere liste_mat[NB_MAT_MAX];
    int nb_matiere=0;
   
    
    ma_commande=get_commande();

    //init_formation(ma_commande,&commande_F);

    //int nb_UE=commande_F.nb_UE;
    int nb_UE=4;
    create_epreuve(ma_commande,&commande_E,nb_UE,liste_mat,&nb_matiere);
    ma_commande=get_commande();
    create_epreuve(ma_commande,&commande_E,nb_UE,liste_mat,&nb_matiere);

    verif_coeff(ma_commande,liste_mat,nb_matiere,nb_UE);
    //epreuve_already_exist(commande_E,liste_mat,&nb_matiere,&nb_epreuve);


    /*
    liste_mat[0]=math;
    int nb_UE=4;
    int a = create_epreuve(ma_commande,&commande_E,nb_UE,math.liste_epr);
    printf("%d",a);
    */
    return 0;

}