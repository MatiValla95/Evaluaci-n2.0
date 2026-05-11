#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "funciones.h"

#define MAX_CHIPS 3

int validateInts () {

    int n, aux = 0 ;

    while(aux !=1 ){
        aux = scanf("%d",&n);
        while((getchar()) != '\n');
        if (aux != 1){
            printf("El valor ingresado es incorrecto\n");
            printf(">> ");
        }
    }

    return n ;
}

float validateFloats () {

    float n, aux = 0 ;

    aux = scanf("%f",&n);
     while(aux !=1 ){
        aux = scanf("%f",&n);
        while((getchar()) != '\n');
        if (aux != 1){
            printf("El valor ingresado es incorrecto\n");
            printf(">> ");
        }
    }

    return n ;
}

void readChain(char *chain, int n){
    int len;
    fgets(chain,n,stdin);
    len = strlen(chain) - 1;
    chain[len] = '\0';
}



int menu ( char chips[MAX_CHIPS][20] , int stockChips[MAX_CHIPS], int *buttons, int *metalParts , int productsCostMaterial[MAX_CHIPS][MAX_CHIPS],  char products[MAX_CHIPS][20], int productsChips[MAX_CHIPS][MAX_CHIPS], float productsPrice [MAX_CHIPS]) {

    int opt = 0;

    printf("----OptiFlex Productions Program----\n\n");
    printf("Por favor seleccione lo que desea hacer:\n");
    printf("1.-Ingresar la cantidad de materiales de fabricacion\n");
    printf("2.-Ingresar el nombre de los productos, la cantidad de materiales que se necesita para realizarlos \ny su tiempo de fabricacion \n");
    printf("3.-Crear y vender productos\n");
    printf("4.-Aumentar stock de materiales de fabricacion\n");
    printf("5.-Editar nombres de los productos\n");
    printf("6.-Editar cantidad de materiales de fabricacion de los productos\n");
    printf("7.-Eliminar un producto\n");
    printf("8.-Cerrar programa\n");
    printf(">> ");

    opt = validateInts();


    switch (opt){

        case 1:
            enterMaterials(chips, stockChips, buttons, metalParts);


            break;
        case 2:
            registerProducts(productsCostMaterial, products, chips, productsChips, productsPrice);
        

            break;
        case 3:
            createAndSellProducts(chips,stockChips,buttons,metalParts,productsCostMaterial,products,productsChips,productsPrice);


            break;
        case 4:
            addMaterialStock (chips, buttons, metalParts, stockChips);
    

            break;
        case 5:
            changeProductsName(products);


            break;
        case 6:
            changeProductsMaterialsNeed(products, chips, productsChips, productsPrice , productsCostMaterial);


            break;

        case 7:
            deleteProduct(products, chips, productsChips, productsPrice , productsCostMaterial);


            break;
        case 8:
            printf("Programa finalizado, gracias por usarlo\n");

            break;

    }

    return opt;

}


void enterMaterials (char chips[MAX_CHIPS][20] , int stockChips[MAX_CHIPS], int *buttons, int *metalParts) {
    printf("Por favor, primero ingresa el nombre de los %d diferentes tipos de chips y su cantidad: \n", MAX_CHIPS);
        for (int i = 0 ; i < MAX_CHIPS ; i++){
            printf("Ingrese el nombre del chip numero %d: \n", i + 1);
            readChain(chips[i],20);
            printf("Ahora por favor ingrese su cantidad en stock: \n");
            stockChips[i] = validateInts();
        }
    printf("Ahora por favor ingrese la cantidad de botones con la que cuenta: \n");
        *buttons = validateInts();

    printf("Ahora por favor ingrese la cantidad de partes metálicas con la que cuenta: \n");
        *metalParts = validateInts();
    
    printf("Datos ingresados con exito \n");


}




void registerProducts (int productsCostMaterial[MAX_CHIPS][MAX_CHIPS], char products[MAX_CHIPS][20], char chips [MAX_CHIPS][20] , int productsChips[MAX_CHIPS][MAX_CHIPS], float productsPrice [MAX_CHIPS]){
    printf("Por favor ingrese el nombre y los materiales de fabricación de todos los productos: \n");
    for (int i = 0 ; i < MAX_CHIPS ; i++){
            printf("Ingrese el nombre del producto numero %d: \n", i + 1);
            readChain(products[i],20);
            for(int j = 0 ; j < MAX_CHIPS ; j++){
                printf("Ahora por favor ingrese cuantos chips %s va a necesitar el producto para realizarse: \n",chips[j]);
                productsChips[i][j] = validateInts();
            }
            printf("Ahora por favor ingrese cuantos botones va a necesitar el producto para realizarse: \n");
            productsCostMaterial[i][0] = validateInts();
            printf("Ahora por favor ingrese cuantas partes de metal  va a necesitar el producto para realizarse: \n");
            productsCostMaterial[i][1] = validateInts();
            printf("Ahora por favor ingrese cuanto tiempo se demora el producto en fabricarse: \n");
            productsCostMaterial[i][2] = validateInts(); 
            printf("Por favor ahora ingrese el precio del producto: \n");
            productsPrice[i] = validateFloats();

            
        }

    printf("Datos ingresados con exito");

    printf("\n========== INFORMACION DE PRODUCTOS ==========\n");

    for(int i = 0; i < MAX_CHIPS; i++){

        printf("\n----------------------------------------\n");

        printf("PRODUCTO: %s\n", products[i]);

        printf("\nMateriales necesarios:\n");

        for(int j = 0; j < MAX_CHIPS; j++){

            printf("- Chips %s: %d\n",
                   chips[j],
                   productsChips[i][j]);
        }

        printf("- Botones: %d\n",
               productsCostMaterial[i][0]);

        printf("- Partes metalicas: %d\n",
               productsCostMaterial[i][1]);

        printf("- Tiempo de fabricacion: %d minutos\n",
               productsCostMaterial[i][2]);
        printf("- Precio: %.2f dolares\n",
               productsPrice[i]);

    }

    printf("\n==============================================\n");


}

void createAndSellProducts(char chips[MAX_CHIPS][20] , int stockChips[MAX_CHIPS], int *buttons, int *metalParts , int productsCostMaterial[MAX_CHIPS][MAX_CHIPS],  char products[MAX_CHIPS][20], int productsChips[MAX_CHIPS][MAX_CHIPS], float productsPrice [MAX_CHIPS]){
    int optCrt = 0, itsOkay = 0 , numberProducts = 0;
    bool chipsOk = true , buttonsOk = true , metalPartsOk = true ; 
    
    printf("Por favor seleccione el numero del que producto desea crear: \n");
    for(int i = 0; i < MAX_CHIPS; i++){
        printf("%d.-%s \n", i , products[i]);
    }
    optCrt = validateInts();
    printf("Perfecto usted selecciono al producto %s \n", products[optCrt]);
    printf("Ahora por favor ingrese cuantas unidades del producto desea realizar: \n");

    while(itsOkay == 0){
        chipsOk = true;
        buttonsOk = true;
        metalPartsOk = true;
        numberProducts =  validateInts();
        for(int j = 0 ; j < MAX_CHIPS ; j++){
            if(numberProducts * productsChips[optCrt][j] <= stockChips[j]){
                
                
            }else{
                printf("Lo siento no contamos con los chips %s suficientes para fabricarlo intente con otro valor \n", chips[j]);
                chipsOk = false;
                break ;
            }
        }
       
        
        if(numberProducts * productsCostMaterial[optCrt][0]  <= *buttons){
                  
        }else{
            printf("Lo siento no contamos con los botones suficientes para fabricarlo intente con otro valor \n");
            buttonsOk = false;
        }
        if(numberProducts * productsCostMaterial[optCrt][1]  <= *metalParts){
                   
        }else{
            printf("Lo siento no contamos con las piezas de metal suficientes para fabricarlo intente con otro valor \n");
            metalPartsOk = false;
        }

        if(chipsOk && buttonsOk && metalPartsOk){
                
            for(int k = 0; k < MAX_CHIPS; k++){
                stockChips[k] = stockChips[k] - numberProducts * productsChips[optCrt][k];
            }

            *buttons = *buttons - numberProducts * productsCostMaterial[optCrt][0];
            *metalParts = *metalParts - numberProducts * productsCostMaterial[optCrt][1];

            itsOkay = 1;
            printf("Los productos estan en creacion, tiempo estimado: %d minutos \n", productsCostMaterial[optCrt][2] * numberProducts);
            printf("Su ganancia es de: %f \n", productsPrice[optCrt]* numberProducts);
        }

    }

}

void addMaterialStock (char chips[MAX_CHIPS][20], int *buttons, int *metalParts, int stockChips[MAX_CHIPS]){
    int optAddChip = 0;
    int optAddMat = 0;
    int stillAdd = 0;

    while(stillAdd != 1){
        printf("Por favor seleccione al chip al que quiere agregarle stock, en caso de que no quiera agregar a chips presione 5 \n");
        for(int i = 0 ; i < MAX_CHIPS ; i++){
            printf("%d.-%s \n", i , chips[i]);
        }
        optAddChip = validateInts();
        if(optAddChip >= 0 && optAddChip <= 2){
            printf("Perfecto usted selecciono al chip: %s \n", chips[optAddChip]);
            printf("Por favor ingrese el numero de chips que desea añadir: \n");
            stockChips[optAddChip] = stockChips[optAddChip] + validateInts();
            printf("Chips agregados con exito \n Ahora su stock es: %d \n", stockChips[optAddChip]);
        }
        printf("Seleccione el numero del material que desea añadir \n1.-Botones \n2.-Metal");
            optAddMat = validateInts();
            if(optAddMat == 1){
                printf("Por favor ingrese el numero de botones que desea añadir \n");
                *buttons = *buttons + validateInts();
                printf("Botones agregados con exito \n Ahora su stock es: %d", *buttons);
            }
            if(optAddMat == 2){
                printf("Por favor ingrese el numero de metales que desea añadir \n");
                *metalParts = *metalParts + validateInts();
                printf("Partes de metal agregadas con exito \n Ahora su stock es: %d \n", *metalParts);
            }

            printf("Si desea seguir añadiendo mas materiales a stock presione cualquier numero, caso contrario presione 1");
            stillAdd = validateInts();

    }
    

}


void changeProductsName(char products[MAX_CHIPS][20]){
        char name[20];
        int nameFound = 0 ;
        printf("Por favor ingrese el nombre del producto al que desea cambiarle el nombre \n");
        

        while(nameFound == 0){
            readChain(name,20);
            
            for(int i = 0; i < MAX_CHIPS ; i++){
                
                if(strcmp(name, products[i]) == 0){
                    printf("Por favor ingrese el nuevo nombre; \n");
                    readChain(products[i],20);
                    nameFound = 1;
                    break;
            } 
            
        }
        if(nameFound == 0){
                printf("Producto no encontrado, intente nuevamente\n");
            }
        }
        printf("Nuevo nombre ingresado con exito \n");
}

void changeProductsMaterialsNeed(char products[MAX_CHIPS][20], char chips[MAX_CHIPS][20], int productsChips[MAX_CHIPS][MAX_CHIPS], float productsPrice [MAX_CHIPS], int productsCostMaterial[MAX_CHIPS][MAX_CHIPS]){
    char name[20];
    int productFound = 0;
    int optEdit = 0;

    while(productFound == 0){

        printf("Por favor ingrese el nombre del producto que desea editar:\n");

        readChain(name,20);

        for(int i = 0; i < MAX_CHIPS; i++){

            if(strcmp(name, products[i]) == 0){

                productFound = 1;

                while(optEdit != 7){

                    printf("\n===== EDICION DE PRODUCTO =====\n");

                    printf("Producto seleccionado: %s\n", products[i]);

                    printf("1.-Editar chips necesarios\n");
                    printf("2.-Editar botones necesarios\n");
                    printf("3.-Editar partes metalicas necesarias\n");
                    printf("4.-Editar tiempo de fabricacion\n");
                    printf("5.-Editar precio\n");
                    printf("6.-Mostrar informacion del producto\n");
                    printf("7.-Salir de edicion\n");

                    optEdit = validateInts();

                    switch(optEdit){

                        case 1:

                            for(int j = 0; j < MAX_CHIPS; j++){

                                printf("Ingrese la nueva cantidad de chips %s:\n",
                                chips[j]);

                                productsChips[i][j] = validateInts();
                            }

                            printf("Chips modificados con exito\n");

                            break;

                        case 2:

                            printf("Ingrese la nueva cantidad de botones:\n");

                            productsCostMaterial[i][0] = validateInts();

                            printf("Botones modificados con exito\n");

                            break;

                        case 3:

                            printf("Ingrese la nueva cantidad de partes metalicas:\n");

                            productsCostMaterial[i][1] = validateInts();

                            printf("Partes metalicas modificadas con exito\n");

                            break;

                        case 4:

                            printf("Ingrese el nuevo tiempo de fabricacion:\n");

                            productsCostMaterial[i][2] = validateInts();

                            printf("Tiempo modificado con exito\n");

                            break;

                        case 5:

                            printf("Ingrese el nuevo precio:\n");

                            productsPrice[i] = validateFloats();

                            printf("Precio modificado con exito\n");

                            break;

                        case 6:

                            printf("\n======= INFORMACION DEL PRODUCTO =======\n");

                            printf("Producto: %s\n", products[i]);

                            for(int k = 0; k < MAX_CHIPS; k++){

                                printf("- Chips %s: %d\n",
                                    chips[k],
                                    productsChips[i][k]);
                                }

                            printf("- Botones: %d\n",
                                productsCostMaterial[i][0]);

                            printf("- Partes metalicas: %d\n",
                                productsCostMaterial[i][1]);

                            printf("- Tiempo de fabricacion: %d minutos\n",
                                productsCostMaterial[i][2]);

                            printf("- Precio: %.2f dolares\n",
                                productsPrice[i]);

                            break;

                        case 7:

                        printf("Saliendo de edicion...\n");

                            break;

                        default:

                        printf("Opcion invalida\n");
                    }
                }

                break;
            }
        }

        if(productFound == 0){

            printf("Producto no encontrado, intente nuevamente\n");
        }
    }
}

void deleteProduct(char products[MAX_CHIPS][20], char chips[MAX_CHIPS][20], int productsChips[MAX_CHIPS][MAX_CHIPS], float productsPrice [MAX_CHIPS], int productsCostMaterial[MAX_CHIPS][MAX_CHIPS]){
    char name[20];
    int productFound = 0;

    while(productFound == 0){

        printf("Por favor ingrese el nombre del producto que desea eliminar:\n");

        readChain(name,20);

        for(int i = 0; i < MAX_CHIPS; i++){

            if(strcmp(name, products[i]) == 0){

                productFound = 1;

                for(int j = i; j < 2; j++){
                    strcpy(products[j], products[j + 1]);
                    for(int k = 0; k < MAX_CHIPS; k++){
                        productsChips[j][k] = productsChips[j + 1][k];
                    }
                    productsCostMaterial[j][0] = productsCostMaterial[j + 1][0];
                    productsCostMaterial[j][1] = productsCostMaterial[j + 1][1];
                    productsCostMaterial[j][2] = productsCostMaterial[j + 1][2];
                    productsPrice[j] = productsPrice[j + 1];
                }

                strcpy(products[2], "");
                for(int k = 0; k < MAX_CHIPS; k++){
                    productsChips[2][k] = 0;
                }
                productsCostMaterial[2][0] = 0;
                productsCostMaterial[2][1] = 0;
                productsCostMaterial[2][2] = 0;
                productsPrice[2] = 0.0;

                printf("Producto eliminado con exito\n");

                break;
            }
        }

        if(productFound == 0){

            printf("Producto no encontrado, intente nuevamente\n");
        }
    }
}