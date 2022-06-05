#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dialog_NPC{
    int key;
    char speak[255];
};

struct hash1{
    int qtd_NPC, TABLE_SIZE_NPC;
    struct dialog_NPC **speaks;
};

typedef struct hash1 Hash_NPC;


Hash_NPC* CreateHash_NPC(int TABLE_SIZE_NPC);
void freeHash_NPC(Hash_NPC* ha);
int InsertHash_NPC(Hash_NPC* ha, struct dialog_NPC al);
void CreateHashdialog_NPC();

Hash_NPC* CreateHash_NPC(int TABLE_SIZE_NPC){
    Hash_NPC* ha = (Hash_NPC*) malloc(sizeof(Hash_NPC));
    if(ha != NULL){
        ha->TABLE_SIZE_NPC = TABLE_SIZE_NPC;
        ha->speaks = (struct dialog_NPC**) malloc(TABLE_SIZE_NPC * sizeof(struct dialog_NPC*));
}
return ha;
}

void freeHash_NPC(Hash_NPC* ha){
    if(ha != NULL){
        int i;
        for(i=0; i < ha->TABLE_SIZE_NPC; i++){
            if(ha->speaks[i] != NULL)
                free(ha->speaks[i]);
        }
        free(ha->speaks);
        free(ha);
    }
}

int MultiplicationKey_NPC(int intKey, int TABLE_SIZE_NPC){
    double A = 0.4862365985;
    double value = intKey * A;
    value = value - (int) value;
    return (int) (TABLE_SIZE_NPC * value);
}

int InsertHash_NPC(Hash_NPC* ha, struct dialog_NPC al){
    if(ha == NULL || ha->qtd_NPC == ha->TABLE_SIZE_NPC)
        return 0;

    int intKey = al.key;
    int pos = MultiplicationKey_NPC(intKey,ha->TABLE_SIZE_NPC);
    struct dialog_NPC* new;
    new = (struct dialog_NPC*) malloc(sizeof(struct dialog_NPC));

    if(new == NULL)
        return 0;
    *new = al;

    ha->speaks[pos] = new;
    ha->qtd_NPC++;
    return 1;
}

int SearchHash_NPC(Hash_NPC* ha, int mat, struct dialog_NPC* al){
    if(ha == NULL)
        return 0;

    int pos = MultiplicationKey_NPC(mat,ha->TABLE_SIZE_NPC);
    if(ha->speaks[pos] == NULL)
        return 0;
    *al = *(ha->speaks[pos]);
    return 1;
}
