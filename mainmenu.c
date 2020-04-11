#include <stdio.h>
#include "menu.h"

void MainMenu()
{

    printf ("\n\n\t\t\t****************     Welcome to A&Z Pharmaceuticals    ****************\n\n\n");

    printf ("\t\t\t\t\t\t    Are you a:\n\n");

    printf ("\t\t\t\t\t\t    A. Customer\n");

    printf ("\t\t\t\t\t\t    B. Store Employee\n");

    printf ("\t\t\t\t\t\t    C. Supplier\n\n");

    printf ("\t\t\t\t\t    Please type in A, B or C as a response: ");

}

void SelectMainMenu(char x)
{
    char c;

    switch(x) {

    case 'a':
    case 'A':
        customermenu();
        break;

    case 'b':
    case 'B':
        employeecheck();
        break;

    case 'c':
    case 'C':
        suppliercheck();
        break;

    default:
        printf("\t\t\t\tInvalid input please try again:");
        scanf(" %c", &c);
        SelectMainMenu(c);
        break;
    }
}

