#include <stdio.h>
#include "menu.h"


int main ()
{
    char answer;
    MainMenu();
    scanf(" %c", &answer);
    printf("\n\n");
    SelectMainMenu(answer);
    scanf(" %c", &answer);

    return 0;
}

