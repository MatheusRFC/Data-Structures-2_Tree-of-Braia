#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dialog{
    int key;
    char speak[255];
};

struct hashp{
    int qtd, TABLE_SIZE;
    struct dialog **speaks;
};

typedef struct hashp Hash;


Hash* CreateHash(int TABLE_SIZE);
void freeHash(Hash* ha);
int InsertHash(Hash* ha, struct dialog al);
void CreateHashDialog();

Hash* CreateHash(int TABLE_SIZE){
    Hash* ha = (Hash*) malloc(sizeof(Hash));
    if(ha != NULL){
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->speaks = (struct dialog**) malloc(TABLE_SIZE * sizeof(struct dialog*));
}
return ha;
}

void freeHash(Hash* ha){
    if(ha != NULL){
        int i;
        for(i=0; i < ha->TABLE_SIZE; i++){
            if(ha->speaks[i] != NULL)
                free(ha->speaks[i]);
        }
        free(ha->speaks);
        free(ha);
    }
}

int MultiplicationKey(int intKey, int TABLE_SIZE){
    double A = 0.4862365985;
    double value = intKey * A;
    value = value - (int) value;
    return (int) (TABLE_SIZE * value);
}

int InsertHash(Hash* ha, struct dialog al){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;

    int intKey = al.key;
    int pos = MultiplicationKey(intKey,ha->TABLE_SIZE);
    struct dialog* new;
    new = (struct dialog*) malloc(sizeof(struct dialog));

    if(new == NULL)
        return 0;
    *new = al;

    ha->speaks[pos] = new;
    ha->qtd++;
    return 1;
}

int SearchHash(Hash* ha, int mat, struct dialog* al){
    if(ha == NULL)
        return 0;

    int pos = MultiplicationKey(mat,ha->TABLE_SIZE);
    if(ha->speaks[pos] == NULL)
        return 0;
    *al = *(ha->speaks[pos]);
    return 1;
}
