#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


struct Student{
	char id[12];
	char name[30];
	char address[50];
	char birthdate[11];
	unsigned int age[];
};

struct Student stu;

void menu_Registration(){
	char menu_Choice;
	
	system("cls");
	FILE *fpointer;
	fpointer = fopen("record.txt", "ab+");
	
	if(fpointer == NULL){
		printf("Error, cannot write to file.");
	}else{
		printf("Student ID:");gets(stu.id);
		printf("Name:");gets(stu.name);
		printf("Address:");gets(stu.address);
		printf("Birthdate MM/DD/YYYY:");gets(stu.birthdate);
		printf("Age:");scanf("%ld", &stu.age);
		fwrite(&stu, sizeof(stu), 1, fpointer); // no error checking
		printf("\nDo you want to save this student to the database? [y/n]");menu_Choice = getche();
		if(menu_Choice != 'n'){
			printf("\nStudent successfuly added to database.");
			printf("\nPress any key to go back to main menu.");getch();return;
		}else{
			printf("\nStudent not added to database.");
			printf("\nPress any key to go back to main menu.");getch();return;
		}
	}
	
	

}


int main(){
	
	
	char choice;
	
	do{
		system("cls");
		printf("\nA.Registration");
		printf("\nB.Enrollment");
		printf("\nC.Payment");
		printf("\nD.Reports");
		printf("\nE.Exit");
		
		printf("\nEnter your choice: ");choice = getche();
		
		switch (choice){
		case 'a':
		case 'A':
			menu_Registration();
			break;
		
		default: 
			printf("Invalid option");
			break;
		
		}
		
	}while(choice != 'e' );
	return 0;
}
