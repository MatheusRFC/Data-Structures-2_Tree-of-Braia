#include "HashTableNPC.h"
#define TABLE_SIZE_NPC 32
#define SIZE_NPC 2000

    struct dialog_NPC npcLine;
    struct dialog_NPC npcLines[TABLE_SIZE_NPC] =   {
                                                    {1,"Merchant: Welcome! Would you like to buy a pack of items for 250 gold?"},
                                                    {2,"Merchant: Thank you for your purchase!!!"},
                                                    {3,"Merchant: Well, it can't be helped."},
                                                    {4,"Merchant: Pleasure Doing Business!"},
                                                    {5,"Merchant: Sorry, but you do not have enough gold."},
                                                    {6,"Merchant: Sorry, but one of your items is already at the maximum carrying capacity."},
                                                    {8,"Citizen: Did you know that the '?' signs are treasure chests?"},
                                                    {9,"Citizen: The maximum level is 10! No use in grinding for easier battles!"},
                                                    {10,"Cleric: If you use the 'R' next to me, you can rest and recover your stats."},
                                                    {11,"Citizen: Here's a tip: Different enemies have different weaknesses to magic."},
                                                    {12,"Citizen: Every key of each area is guarded by a boss, so be prepared."},
                                                };


Hash_NPC* InsertHashDataNPC()
{
    Hash_NPC *NPCtable = CreateHash_NPC(SIZE_NPC);
    int i;

    for(i=0; i < TABLE_SIZE_NPC; i++){
        InsertHash_NPC(NPCtable, npcLines[i]);
    }
    return NPCtable;
}
