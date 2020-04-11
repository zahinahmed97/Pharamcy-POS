#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void suppliercheck(){
    int pass=456;
    int passcheck;

    printf ("Enter password:");

    scanf ("%d",&passcheck);

    if (passcheck==456) {
        suppliermenu();
    }

    else {
        printf("Invalid password. Try again.\n");
        suppliercheck();
    }
}

void suppliermenu(){

    char x;
    printf ("\n\n\t\t\t\t****************    Hello, Supplier!    ****************\n\n\n");

    printf ("\t\t\t\t\t\t    Would you like to:\n\n");

    printf ("\t\t\t\t\t\t    A. Check stock\n");

    printf ("\t\t\t\t\t\t    B. Send Medicine\n");

    printf ("\t\t\t\t\t\t    C. Return to main menu\n");

    printf ("\t\t\t\t\t\t    D. Exit\n\n");

    printf ("\t\t\t\t\t    Please type in A, B, C or D as a response: ");

    scanf(" %c", &x);
    supsubmenu(x);
}

void supsubmenu(char x) {

    char c;
    FILE *hfptr;
    FILE *gfptr;

    if ((hfptr = fopen("suppstock.dat", "rb")) == NULL ) {
        puts( "File could not be opened" );
    }
    else if ((gfptr = fopen("storestock.dat", "rb+")) == NULL ) {
        puts( "File could not be opened" );
    }

    else {
    switch (x) {

    case 'a':
    case 'A':
        viewstock(hfptr);
        suppliermenu();
        break;

    case 'b':
    case 'B':
        addmed(gfptr);
        suppliermenu();
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
        supsubmenu(c);
        break;
    }
    }

}

