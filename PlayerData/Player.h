#include "../TAD_SkillTree/Player_SkillTree.h" // Already includes windows.h library required for the buttons(used for colors too)

typedef struct items
{
    short int HPpotion;
    short int MPpotion;
    short int HPinc;
    short int MPinc;
}items;

struct playerChar
{
    char name[25];
    short int Level;
    int gold;
    int max_HP;
    int current_HP;
    int max_MP;
    int current_MP;
    int atk;
    int def;
    int inte;
    int luck;
    bool key;
    int current_XP;
    int next_XP;
    BinTree* magtree;
    BinTree* phystree;
    items it;
}playerChar;

void insertPlayerName();
void createPlayer(char playerName[25]);

void insertPlayerName()
{
    char name[25];
    system("cls");

    printf("\n\n\n\t\t\t|      BEFORE STARTING THE GAME...       |");
    printf("\n\t\t\t|  PLEASE INSERT YOUR CHARACTER'S NAME:  |");
    printf("\n\t\t\t\t|------------------------|");
    printf("\n\t\t\t\t|                        |");
    printf("\n\t\t\t\t|------------------------|");
    Sleep(50);
    printf("\033[1A");
    printf("\033[25D");

    fgets(name, sizeof(name), stdin);
    createPlayer(name);
}

void createPlayer(char playerName[25])
{
    playerChar.magtree = generate_BinTree();
    playerChar.phystree = generate_BinTree();
    insertMagSkills(playerChar.magtree);
    insertPhysSkills(playerChar.phystree);
    strcpy(playerChar.name, playerName);

    playerChar.Level = 1;
    playerChar.gold = 0;
    playerChar.max_HP = 1050; // Base 1050
    playerChar.current_HP = 1050; // Base 1050
    playerChar.max_MP = 110; // Base 110
    playerChar.current_MP = 110; // Base 110
    playerChar.atk = 112; // Base 112
    playerChar.def = 122; // Base 122
    playerChar.inte = 102; // Base 102
    playerChar.luck = 115; // Base 115
    playerChar.current_XP = 0;
    playerChar.next_XP = 100;
    playerChar.key = false;
    playerChar.it.HPpotion = 0;
    playerChar.it.HPinc = 0;
    playerChar.it.MPpotion = 0;
    playerChar.it.MPinc = 0;
}
