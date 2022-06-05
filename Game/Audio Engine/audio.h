#include <windows.h>
#include <process.h>

void healSpot()
{
        for(short int i = 0; i < 10; i++)
            {
              Beep(250*i, 120);
            }
      _endthread();
}

void footStep()
{
    Beep(220, 200);
    _endthread();
}

void openMenu()
{
    Beep(1000, 200);
    _endthread();
}

void openSkillMenu()
{
    Beep(800, 200);
    _endthread();
}

void moveCombatCursor()
{
    Beep(500, 200);
    _endthread();
}

void selectCombatAction()
{
    Beep(1100, 100);
    _endthread();
}

void returnFromSkills()
{
    Beep(850, 250);
    _endthread();
}
