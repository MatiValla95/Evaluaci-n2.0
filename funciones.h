#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHIPS 3

int validateInts();
float validateFloats();
void readChain(char *chain, int n);
int menu(char chips[MAX_CHIPS][20], int stockChips[MAX_CHIPS], int *buttons, int *metalParts, int productsCostMaterial [MAX_CHIPS][MAX_CHIPS], char products[MAX_CHIPS][20], int productsChips[MAX_CHIPS][MAX_CHIPS], float productsPrice [MAX_CHIPS]);
void enterMaterials(char chips[MAX_CHIPS][20], int stockChips[MAX_CHIPS], int *buttons, int *metalParts);
void registerProducts(int productsCostMaterial[MAX_CHIPS][MAX_CHIPS], char products[MAX_CHIPS][20], char chips [MAX_CHIPS][20], int productsChips[MAX_CHIPS][MAX_CHIPS], float productsPrice [MAX_CHIPS]);
void createAndSellProducts(char chips[MAX_CHIPS][20], int stockChips[MAX_CHIPS], int *buttons, int *metalParts , int productsCostMaterial[MAX_CHIPS][MAX_CHIPS], char products[MAX_CHIPS][20], int productsChips[MAX_CHIPS][MAX_CHIPS], float productsPrice [MAX_CHIPS]);
void addMaterialStock(char chips[MAX_CHIPS][20], int *buttons, int *metalParts, int stockChips[MAX_CHIPS]);
void changeProductsName(char products[MAX_CHIPS][20]);
void changeProductsMaterialsNeed(char products[MAX_CHIPS][20], char chips[MAX_CHIPS][20], int productsChips[MAX_CHIPS][MAX_CHIPS], float productsPrice [MAX_CHIPS], int productsCostMaterial[MAX_CHIPS][MAX_CHIPS]);
void deleteProductandtheMaterialsitneeds(char products[MAX_CHIPS][20], char chips[MAX_CHIPS][20], int productsChips[MAX_CHIPS][MAX_CHIPS], float productsPrice [MAX_CHIPS], int productsCostMaterial[MAX_CHIPS][MAX_CHIPS]);
void viewMaterialsStock(char chips[MAX_CHIPS][20], int stockChips[MAX_CHIPS], int *buttons, int *metalParts);
void viewProductsInfo(char products[MAX_CHIPS][20], char chips[MAX_CHIPS][20], int productsChips[MAX_CHIPS][MAX_CHIPS], float productsPrice [MAX_CHIPS], int productsCostMaterial[MAX_CHIPS][MAX_CHIPS]);
