#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void customermenu(){
    char x;
    printf ("\n\n\t\t\t\t****************    Hello, Customer!    ****************\n\n\n");

    printf ("\t\t\t\t\t\t    Would you like to:\n\n");

    printf ("\t\t\t\t\t\t    A. View medicine\n");

    printf ("\t\t\t\t\t\t    B. Purchase medicine\n");

    printf ("\t\t\t\t\t\t    C. Return to main menu\n");

    printf ("\t\t\t\t\t\t    D. Exit\n\n");

    printf ("\t\t\t\t\t    Please type in A, B, C or D as a response: ");

    scanf(" %c", &x);
    cussubmenu(x);
}

void cussubmenu (char x) {

    char c;
    FILE *cfptr;
    FILE *gfptr;

    if ((cfptr = fopen("purchase.dat", "wb+")) == NULL ) {
        puts( "File could not be opened" );
    }

    else if ((gfptr = fopen("storestock.dat", "rb+")) == NULL ) {
        puts( "File could not be opened" );
    }


    else {

    switch (x) {

    case 'a':
    case 'A':
        viewstock(gfptr);
        customermenu();
        break;

    case 'b':
    case 'B':
        finalbill(gfptr,cfptr);
        customermenu();
        break;

    case 'c':
    case 'C':
        main();
        break;

    case 'd':
    case 'D':
        exit(0);

    default:
        printf("\t\t\t\tInvalid input please try again:");
        scanf(" %c", &c);
        cussubmenu(c);
        break;
    }
    }

}

