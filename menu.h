#ifndef MENU_H
#define MENU_H

void MainMenu();
void SelectMainMenu(char x);
void customermenu();
void employeecheck();
void employeemenu();
void suppliercheck();
void suppliermenu();
void cussubmenu (char x);
void empsubmenu (char x);
void supsubmenu (char x);
void addmed (FILE *fptr);
void finalbill (FILE *fptr, FILE *gptr);
void viewstock (FILE *fptr);
void remmed (FILE *fptr);
void makestock (FILE *fptr);

typedef struct Medicine {

    unsigned int code;
    char name [20];
    char maker[25];
    unsigned int price;
    unsigned int quantity;
} meds ;

typedef struct Customer {

    char name [20];
    unsigned int age;
    char gender;

} client;
#endif // MENU_H
