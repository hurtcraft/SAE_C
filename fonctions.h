#ifndef __FONTCIONS_H
#define __FONCTIONS_H
typedef struct Commande
{
    char nom_commande[30];
    char args[5][30];
    int test;
}Commande;

void analyse_saisie(Commande *ma_commande);
void exit_prog();


typedef struct Commande_Formation{
    int nb_UE;

}Commande_Formation;




#endif