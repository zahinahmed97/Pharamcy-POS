#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void employeecheck(){
    int pass=123;
    int passcheck;

    printf ("Enter password:");

    scanf ("%d",&passcheck);

    if (passcheck==123) {
      employeemenu();
    }

    else {
        printf("Invalid password. Try again.\n");
        employeecheck();

    }
}

void employeemenu(){
    char x;
    printf ("\n\n\t\t\t\t****************    Hello, Employee!    ****************\n\n\n");

    printf ("\t\t\t\t\t\t    Would you like to:\n\n");

    printf ("\t\t\t\t\t\t    A. View Stock\n");

    printf ("\t\t\t\t\t\t    B. Remove Medicine\n");

    printf ("\t\t\t\t\t\t    C. Return to main menu\n");

    printf ("\t\t\t\t\t\t    D. Exit\n\n");

    printf ("\t\t\t\t\t    Please type in A, B, C or D as a response: ");

    scanf(" %c", &x);
    empsubmenu(x);
}

void empsubmenu (char x) {

    char c;
    FILE *gfptr;

    if ((gfptr = fopen("storestock.dat", "rb+")) == NULL ) {
        puts( "File could not be opened" );
    }

    else {
    switch (x) {

    case 'a':
    case 'A':
        viewstock(gfptr);
        employeemenu();
        break;

    case 'b':
    case 'B':
        remmed(gfptr);
        employeemenu();
        break;

    case 'c':
    case 'C':
        main();
        break;

    case 'd':
    case 'D':
        exit(0);
        break;

    default:
        printf("\t\t\t\tInvalid input please try again:");
        scanf(" %c", &c);
        empsubmenu(c);
        break;
    }
    }

}
