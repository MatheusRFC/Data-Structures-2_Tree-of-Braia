#include "HashTable_PlayerLines.h"
#define TABLE_SIZE 10
#define SIZE 2000

    struct dialog pLine;
    struct dialog pLines[TABLE_SIZE] =  {
                                            {1,": Sure!"},
                                            {2,": No, thanks."},
                                            {3,": I see, thanks for the tip, i just need to learn their weaknesses then."},
                                            {4,": Is it really that simple? huh..."},
                                            {5,": I remember seeing one or two of them before, i will remember to check them."},
                                            {6,": So... no grinding. Got it."},
                                            {7,": Yes, i did have to fight a boss to get a key before, but i did not think it was the same for all keys."},
                                        };


Hash* InsertHashData(){
    Hash *playertable = CreateHash(SIZE);
    int i;

    for(i=0; i < TABLE_SIZE; i++){
        InsertHash(playertable, pLines[i]);
    }
    return playertable;
}
