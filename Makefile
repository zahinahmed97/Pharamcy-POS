all: main

main: MedicalStoreManagementSystem.o mainmenu.o customermenu.o employeemenu.o suppliermenu.o files.o
	gcc -o main MedicalStoreManagementSystem.o mainmenu.o customermenu.o employeemenu.o suppliermenu.o files.o

MedicalStoreManagementSystem.o: MedicalStoreManagementSystem.c menu.h
				gcc -c MedicalStoreManagementSystem.c -o MedicalStoreManagementSystem.o

mainmenu.o: mainmenu.c menu.h
		gcc -c mainmenu.c -o mainmenu.o

customermenu.o: customermenu.c menu.h
		gcc -c customermenu.c -o customermenu.o

employeemenu.o: employeemenu.c menu.h
		gcc -c employeemenu.c -o employeemenu.o

suppliermenu.o: suppliermenu.c menu.h
		gcc -c suppliermenu.c -o suppliermenu.o

files.o: files.c menu.h
	 gcc -c files.c -o files.o


clean:
	del MedicalStoreManagementSystem.o mainmenu.o customermenu.o employeemenu.o suppliermenu.o files.o