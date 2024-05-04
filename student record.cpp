#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


struct Student{
	struct Personal{
		char id[12];
		char first_Name[30];
		char middle_Name[30];
		char last_Name[30];
		
		char address[50];
		char birthdate[11];
		int age;
		char gender[5]; //m/f
		
		char phone_Number[12];
		char email_Address[30];
		
		char mother_First_Name[30];
		char mother_Middle_Name[30];
		char mother_Last_Name[30];
		char mother_Occupation[30];
	
		char father_First_Name[30];
		char father_Middle_Name[30];
		char father_Last_Name[30];
		char father_Occupation[30];
		
		char guardian_Number[12];
	}per;
	
	
};

struct Student stu;

void menu_Registration(){
	char gender;
	char menu_Choice;
	
	system("cls");
	FILE *fpointer;
	fpointer = fopen("record.txt", "ab+");
	
	if(fpointer == NULL){
		printf("Error, cannot write to file.");
	}else{
		printf("Student ID: ");gets(stu.per.id);
		printf("Students First Name: ");gets(stu.per.first_Name);
		printf("Students Middle Name: ");gets(stu.per.middle_Name);
		printf("Students Last Name: ");gets(stu.per.last_Name);
		printf("Address: ");gets(stu.per.address);
		printf("Birthdate MM/DD/YYYY: ");gets(stu.per.birthdate);
		
		printf("Age: ");scanf("%i", &stu.per.age);getchar();
		
		printf("Gender: "); gets(stu.per.gender);
		printf("Phone Number: ");gets(stu.per.phone_Number);
		printf("Email Address: ");gets(stu.per.email_Address);
		
		printf("Mother's First Name: ");gets(stu.per.mother_First_Name);
		printf("Mother's Middle Name: ");gets(stu.per.mother_Middle_Name);
		printf("Mother's Last Name: ");gets(stu.per.mother_Last_Name);

		printf("Fathers's First Name: ");gets(stu.per.father_First_Name);
		printf("Fathers's Middle Name: ");gets(stu.per.father_Middle_Name);
		printf("Mother's Last Name: ");gets(stu.per.mother_Last_Name);
		
		printf("Guardians' Phone Number: ");gets(stu.per.guardian_Number);
		
		
		
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
