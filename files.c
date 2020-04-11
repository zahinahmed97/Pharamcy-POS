#include <stdio.h>
#include "menu.h"

void viewstock(FILE *fptr) {

    meds new= {0,"","",0,0};

    int result;

    printf( "\n\n\t\t\t\t%-6s%-21s%-21s%-10s%-10s%\n", "Code", "Name", "Manufacturer","Price", "Quantity" );

    while ( !feof( fptr ) ) {
        result = fread( &new, sizeof( meds ), 1, fptr );
        if ( result != 0 && new.code != 0 ) {
            printf( "\t\t\t\t%-6d%-21s%-21s%-10d%-10d\n", new.code, new.name, new.maker,new.price, new.quantity);
        }
    }
    fclose(fptr);
}

void addmed (FILE *fptr) {

    meds new = { 0, "", "",0,0};
    unsigned int code;


    printf( "%s", "\t\t\t\tEnter new code number: " );
    scanf( "%d", &code );

    fseek( fptr, (code-1) * sizeof(meds),SEEK_SET );

    fread( &new, sizeof( new ), 1, fptr );

    if ( new.code!= 0 ) {
        printf( "\t\t\t\tCode #%d already contains information.\n", new.code );
    }

    else {

        printf( "%s", "\t\t\t\tEnter Name, Manufacturer,Price, Quantity\n? " );
        scanf( "%19s%24s%d%d", &new.name, &new.maker,&new.price,&new.quantity);
        new.code= code;

        fseek( fptr, ( new.code - 1 ) *sizeof( meds ), SEEK_SET );

        fwrite( &new, sizeof(meds), 1, fptr );
    }

    fclose(fptr);
}

void finalbill (FILE *fptr, FILE *gptr) {

    int total=0, quant;
    meds new = { 0, "", "", 0,0};
    client newclient ={"",0,0};
    unsigned int code, result,old;

    printf( "%s", "\n\n\t\t\t\t\t\tEnter code number: (Enter 0 to end) " );
    scanf( "%d", &code);



    while(code!=0) {

    printf("\t\t\t\t\t\tEnter quantity:");
    scanf ("%d", &quant);

    new.code= code;
    fseek( fptr, (new.code-1) * sizeof(meds),SEEK_SET );

    fread( &new, sizeof( new ), 1, fptr );

    old= new.quantity;
    new.quantity= quant;

    printf( "\n\t\t\t\tName:%-15sManufacturer:%-20sPrice:%-10d\n", new.name, new.maker,new.price);

    fwrite( &new, sizeof(meds), 1, gptr );

    total+=new.price*quant;

    fseek( fptr, ( new.code - 1 ) *sizeof( meds ), SEEK_SET );

    new.quantity= old-quant;
    fwrite( &new, sizeof(meds), 1, fptr );

    printf( "%s", "\n\t\t\t\t\t\tEnter code number: (Enter 0 to end) " );
    scanf( "%d", &code);
    }
    fclose(gptr);

    printf("\t\t\t\tEnter your Name, age and gender (f for female & m for male) :\n\t\t\t\t");
    scanf("%19s%d %c", newclient.name, &newclient.age, &newclient.gender);

    printf("\n\n\t\t\t\t****************         Receipt          ****************\n\n\n");
    printf("\t\t\t\tName: %-s\n\t\t\t\tAge: %-d\n\t\t\t\tGender: %-c\n\n", newclient.name, newclient.age, newclient.gender);

    if ((gptr = fopen("purchase.dat", "rb")) == NULL ) {
        puts( "File could not be opened" );
    }
    else {
        printf("\t\t\t|%-6s|%-21s|%-21s|%-10s|%-10s|%-10s|\n\n","Code","Name of Medicine","Manufacturer","Price","Quantity","Total");
        while (!feof(gptr)) {
            result=fread( &new, sizeof( meds ), 1, gptr );
            if ( result != 0 && new.code!= 0 ) {
                printf( "\t\t\t|%-6d|%-21s|%-21s|%-10d|%-10d|%-10d|\n", new.code, new.name, new.maker,new.price, new.quantity, new.price*new.quantity);
            }
        }
    }
    printf("\n\t\t\t|Total=\t\t\t\t\t\t\t\t\t |%-10d|",total);
    printf("\t\t\t\t\t-------------------------------------------------------------------------------------");
    fclose(fptr);
    fclose(gptr);

}

void remmed (FILE *fptr) {

    meds new={0,"","",0,0};
    meds blank = { 0, "", "", 0,0 };
    unsigned int code;

    printf( "%s", "\t\t\t\t\t\t\tEnter code to delete: " );
    scanf( "%d", &code );


    fseek( fptr, (code - 1 ) * sizeof( meds ), SEEK_SET );

    fread( &new, sizeof(meds ), 1, fptr );

    if ( new.code == 0 ) {
        printf( "\t\t\t\t\t\t\tMedicine of code %d does not exist.\n", code );
    }

    else {
        fseek( fptr, (new.code - 1 ) * sizeof(meds), SEEK_SET );
        fwrite( &blank, sizeof(meds), 1, fptr );
    }

    fclose(fptr);
}

void makestock(FILE *fptr) {

    meds new = { 0, "", "", 0.0 };

    printf( "%s", "Enter code: (0 to end input )\n? " );
    scanf( "%d", &new.code );

    while ( new.code != 0 ) {

        printf( "%s", "Enter name, manufacturer, price, quantity:\n? " );

        fscanf( stdin, "%19s%24s%d%d", new.name, new.maker,&new.price,&new.quantity );

        fseek( fptr, ( new.code- 1 ) *sizeof( meds ), SEEK_SET );

        fwrite( &new, sizeof( meds ), 1, fptr );

        printf( "%s", "Enter code\n? " );
        scanf( "%d", &new.code);
    }
    fclose( fptr );
}//this function was used to create both store stock and supplierstock. I've kept it show how i inputted the records.


