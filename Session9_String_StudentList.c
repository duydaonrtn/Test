#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct std {
	char name[50];
	int age;
	char num[10];
};

struct std student[20];
int stdIndex;

void menu() {
	printf("\n -STUDENT MANAGEMENT-");
	printf("\n 1. Add a student");
	printf("\n 2. List all students");
	printf("\n 3. Search a student");
//	printf("\n 4. Edit a student");
//	printf("\n 5. Delete a student");
//	printf("\n 6. Sorting students by name");
//	printf("\n 7. Save student list to file");
	printf("\n 8. Exit");
	printf("\n\n Select [1-8]: ");
}

//1. ADD A STUDENT	ADD A STUDENT	ADD A STUDENT	ADD A STUDENT	ADD A STUDENT	ADD A STUDENT	ADD A STUDENT	ADD A STUDENT	ADD A STUDENT	ADD A STUDENT	ADD A STUDENT	
void inputStd(int i) {
	printf("\n Enter student's name        : ");
	fflush(stdin);
	gets(student[i].name);
	
	printf("\n Enter student's age         : ");
	fflush(stdin);
	scanf("%d", &student[i].age);
	
	printf("\n Enter student's phone number: ");
	fflush(stdin);
	gets(student[i].num);
	
	int numcheck = strlen(student[i].num);
	while(numcheck!=10) {
		printf("\n There's something wrong with your phone number %s.\n Please check and re-enter again: ",student[i].num);
		fflush(stdin);
		gets(student[i].num);
		numcheck = strlen(student[i].num);
	}
	
	char a[10];
	strcpy(a,student[i].num);
	int j;
	for(j=0;j<stdIndex;j++) {
		int k = strcmp(student[j].num, a);
		if(k==0) {
			printf("\n There's already another student with the same phone number %s", student[j].num);
			printf("\n Please enter another phone number: ");
			fflush(stdin);
			gets(student[i].num);
			break;
		}
	}	
}

int addcont() {
	char option;
	
	printf("\n Do you want to add a new student? [Y/N] ");
	fflush(stdin);
	scanf("%c", &option);
	if(option == 'y' || option == 'Y') {
		return 1;
	}
	if(option == 'n' || option == 'N') {
		return 2;
	}
	else {
		printf("\n Invalid input, please reinput. ");
		addcont();
	}
}

void add() {
	int ans;

	system("cls");
	printf("\n -ADD A STUDENT-");
	printf("\n The current student number: %d", stdIndex);
	ans = addcont();
	switch (ans) {
		case 1:
			break;
		case 2:
			main();
	}
	inputStd(stdIndex);
	stdIndex++;
	printf("\n DONE!");
	printf("\n Press any key to return to menu");
	getch();
	main();
}

//2. STUDENT LIST	STUDENT LIST	STUDENT LIST	STUDENT LIST	STUDENT LIST	STUDENT LIST	STUDENT LIST	STUDENT LIST	STUDENT LIST	STUDENT LIST	STUDENT LIST	
int listcont() {
	char option;

	printf("\n Do you want to see more detail? [Y/N] ");
	fflush(stdin);
	scanf("%c", &option);
	if(option == 'y' || option == 'Y') {
		return 1;
	}
	if(option == 'n' || option == 'N') {
		return 2;
	}
	else {
		printf("\nInvalid input, please reinput.");
		listcont();
	}	
}

void listall() {
	int i;
	
	system("cls");
	printf("\n -LIST ALL STUDENT-");
	for(i = 0; i < stdIndex; i++)
	{
		printf("\n Student %d: %s", i+1, student[i].name);
	}
}

int listdetailcont() {
	char option;
	
	printf("\n Do you want to see another student's detail? [Y/N]");
	fflush(stdin);
	scanf("%c", &option);
	if(option == 'y' || option == 'Y') {
		return 1;
	}
	if(option == 'n' || option == 'N') {
		return 2;
	}
	else {
		printf("\n Invalid input, please reinput.");
		listdetailcont();
	}	
}

void listdetail() {
	int i, j, ans;

	listall();
	printf("\n");
	printf("\n Enter a student's index to see his/her details: ");
	fflush(stdin);
	scanf("%d", &i);
	if(i <= 0) {
		printf("\n Invalid input, please reinput.\n Press anykey to continue.");
		getch();
		listdetail();
	}
	if(i > stdIndex) {
		printf("\nThere are only %d students. Please select again!\n Press anykey to continue.", stdIndex);
		getch();
		listdetail();
	}
	else {
		printf("\n");
		printf("\n -STUDENT %d DETAILS-", i);
		printf("\n Name        : %s", student[i-1].name);
		printf("\n Age         : %d", student[i-1].age);
		printf("\n Phone number: %s", student[i-1].num);
		ans = listdetailcont();
		switch (ans) {
			case 1:
				listdetail();
				break;
			case 2:
				printf("\n Press any key to return to menu.");
				getch();
				main();
		}
	}
}

void list() {
	int ans;
	
	listall();
	if(stdIndex == 0) {
		printf("\n There are no student. Please add some more!\n Press any key to continue.");
		getch();
		add();
	}
	printf("\n");
	ans = listcont();
	switch (ans){
		case 1:
			listdetail();
		case 2:
			printf("\n Press any key to return to menu.");
			getch();
			main();
	}
}

//3. SEARCH A STUDENT	SEARCH A STUDENT	SEARCH A STUDENT	SEARCH A STUDENT	SEARCH A STUDENT	SEARCH A STUDENT	SEARCH A STUDENT	SEARCH A STUDENT	SEARCH A STUDENT	
void searchname() {
	int i;
	char find[50];
	char *found;
	int stdfound;
	
	printf("\n -SEARCH A STUDENT BY NAME-");
	printf("\n Enter student's name: ");
	fflush(stdin);
	scanf("%s", &find);
	for(i = 0; i < stdIndex; i++) {
		found = strstr(student[i].name, find);
		if(found) {
			printf("\n Student no.%d: %s", i+1, student[i].name);
			stdfound = 1;
		}
	}
	if(stdfound != 1) {
		printf("\n There is no student contain %s in his/her name.", find);	
	}
}

void searchnum() {
	int i;
	char find[10];
	char *found;
	int stdfound;
	
	printf("\n -SEARCH A STUDENT BY PHONE NUMBER-");
	printf("\n Enter student's phone number: ");
	fflush(stdin);
	scanf("%s", &find);
	for(i = 0; i < stdIndex; i++) {
		found = strstr(student[i].num, find);
		if(found) {
			printf("\n Student no.%d: %s has phone number %s", i+1, student[i].name, student[i].num);
			stdfound = 1;
		}
	}
	if(stdfound != 1) {
		printf("\n There is no student has phone number contains %s.", find);	
	}
}

void searchmenu() {
	printf("\n -SEARCH A STUDENT-");
	printf("\n Which types of search do you want to do?");
	printf("\n 1: By name.");
	printf("\n 2: By phone number.");
	printf("\n\n Select [1-2]: ");
}

void searchsub() {
	
	char choice;
	
	fflush(stdin);
	scanf("%d", &choice);
	switch(choice) {
		case 1:
			searchname();
			break;
		case 2:
			searchnum();
			break;
		default:
			printf("\n Invalid input, please select again [1-2]: ");
			searchsub();
	}
	printf("\n Press any key to return to menu");
	getch();
	main();	
}

void search() {
	system("cls");
	if(stdIndex == 0) {
		printf("\n There are no student. Please add some more!\n Press any key to continue.");
		getch();
		add();
	}
	searchmenu();
	searchsub();
}

//MAIN	MAIN	MAIN	MAIN	MAIN	MAIN	MAIN	MAIN	MAIN	MAIN	MAIN	MAIN	MAIN	MAIN	MAIN	MAIN	MAIN	MAIN	MAIN	MAIN	MAIN	MAIN	MAIN	MAIN
int main() {
	char choice;
	
	system("cls");
	menu();
	fflush(stdin);
	scanf("%d", &choice);
	switch(choice) {
		case 1:
			add(stdIndex);
			break;
		case 2:
			list();
			break;
		case 3:
			search();
			break;
//		case 4:
//			edit();
//			break;
//		case 5:
//			erase();
//			break;
//		case 6:
//			sort();
//			break;	
//		case 7:
//			printf("\nSave student list to file:");
//			break;			
		case 8:
			printf("\n See you again!");
			exit(0);
		default:
			printf("\n Invalid input. Please select again.\n Press any key to continue.");
			getch();
			main();
	}

	return 0;
}
