#include <stdio.h>
#include "fonctions.h"

void clear_str(char str[],int len){
    for (size_t i = 0; i < len; i++){
        str[i]=0;
    }
}