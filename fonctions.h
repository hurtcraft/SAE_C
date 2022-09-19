#ifndef __FONTCIONS_H
#define __FONCTIONS_H

void analyse_saisie(char command[]);
void exit_prog();
typedef struct Commande
{
    char nom_commande[30];
    char args[5][30];


}Commande;

typedef struct Commande_Formation
{
    unsigned int nb_UE;
};



#endif