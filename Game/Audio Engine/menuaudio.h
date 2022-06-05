#include <windows.h>
#include <process.h>

void moveCursor()
{
    Beep(500, 200);
    _endthread();
}

void useItem()
{
    for(short int i = 5; i < 12; i++)
            {
              Beep(250*i, 100);
            }
    _endthread();
}

void closeMenu()
{
    Beep(700, 250);
    _endthread();
}


void endGame()
{
    for(short int i = 6; i > 0; i--)
            {
              Beep(250*i, 140);
            }
    _endthread();
}
