#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "funciones.h"

#define MAX_CHIPS 3

int main(){
    char chips[MAX_CHIPS][20];
    int stockChips[MAX_CHIPS];
    int metalParts = 0, buttons = 0, optM = 0, optC = 0;
    char products[MAX_CHIPS][20];
    int productsCostMaterial[MAX_CHIPS][MAX_CHIPS];
    int productsChips[MAX_CHIPS][MAX_CHIPS];
    float productsPrice[MAX_CHIPS];

    while(optC != 1){

        optM = menu(chips, stockChips, &buttons, &metalParts, productsCostMaterial, products , productsChips, productsPrice);
        optC = validateInts();
    }
    printf("Si desea continuar presione 0, caso contrario presione 1\n");
    printf(">> ");

    return 0;
}
