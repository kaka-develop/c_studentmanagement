/*
 * MenuManager.c
 *
 *  Created on: Apr 19, 2016
 *      Author: youngkaka
 */

#include "DataManager.h"
#include "ValidationManager.h"
#include <stdio.h>
#include <stdlib.h>
const char SUCCESS_ADD_STUDENT[] = "Add new student successfully!";
const char SUCCESS_UPDATE_STUDENT[] = "Update student successfully!";

int menu_continue() {
	char choice;
	printf("Do you want to continue? (y/n): ");
	scanf(" %s", &choice);
	if (choice == 'y' || choice == 'Y')
		return 1;
	else if (choice == 'n' || choice == 'N')
		return 0;
	else
		return menu_continue();
}

void menu_addStudent() {

	Student student;
	printf("========Add new student=======\n");
	printf(
			"Please enter student's ID (GCxxxxx), name, date, email, phone (10 or 11 numbers) and address.\n");
	printf("ID: ");
	scanf(" %s", student.sId);
	printf("Name: ");
	scanf(" %s", student.sName);
	printf("Date of birth: ");
	scanf(" %s", student.sDoB);
	printf("Email: ");
	scanf(" %s", student.sEmail);
	printf("Phone: ");
	scanf(" %s", student.sPhone);
	printf("Address: ");
	scanf(" %s", student.sAddress);

	int check = 1;
	if (!validateID(student.sId)) {
		check = 0;
		printf("Failed! invalid id! ");
	}
	if (existingStudentByID(&students, student.sId) > -1) {
		check = 0;
		printf("Failed! This id existed! ");
	}
	if (!validateName(student.sName)) {
		check = 0;
		printf("Invalid name! ");
	}
	if (validateDoB(student.sDoB) == 0) {
		check = 0;
		printf("Invalid date of birld! ");
	}
	if (!validateEmail(student.sEmail)) {
		check = 0;
		printf("Invalid Email! ");
	}
	if (!validatePhone(student.sPhone)) {
		check = 0;
		printf("Invalid phone! ");
	}
	if (!validateAddress(student.sAddress)) {
		check = 0;
		printf("Invalid address! ");
	}

	if (check == 1) {
		addStudent(&students, student);
		printf("%s\n", SUCCESS_ADD_STUDENT);
	} else
		printf("\nFailed! invalid information\n");

	if (menu_continue())
		menu_addStudent();
}

void menu_viewStudents() {
	printf("========View all students=======\n");
	printListOfStudent(students);
	if (menu_continue())
		menu_viewStudents();
}

void menu_searchStudents() {
	printf("========Search students=======\n");
	printf("Searching by name of students \n");
	printf("Please enter searching text: ");
	char name[100];
	scanf(" %s", name);
	searchStudentsByName(students, name);

	if (menu_continue())
		menu_searchStudents();
}

void menu_deleteStudent() {
	printf("========Delete students=======\n");
	printf("Please enter student's id: ");
	char id[8];
	scanf(" %s", id);
	if (existingStudentByID(&students, id) > -1) {
		deleteStudent(&students, id);
		printf("Delete student successfully!\n");
	} else
		printf("Failed! This ID does not exist!\n");

	if (menu_continue())
		menu_deleteStudent();
}

void menu_updateStudent() {
	printf("========Update students=======\n");
	printf("Please enter student's id: ");
	char id[8];
	scanf(" %s", id);
	getchar();
	int index = existingStudentByID(&students, id);
	if (index > -1) {
		Student student = students.students[index];
		char *name = malloc(100 * sizeof(char));
		strcpy(name, "");
		char *dob = malloc(11 * sizeof(char));
		strcpy(dob, "");
		char *email = malloc(100 * sizeof(char));
		strcpy(email, "");
		char *phone = malloc(12 * sizeof(char));
		strcpy(phone, "");
		char *address = malloc(100 * sizeof(char));
		strcpy(address, "");
		char *errorMessage = malloc(200 * sizeof(char));
		strcpy(errorMessage, "");

		printf("Name %s-> ", student.sName);
		scanf("%100[0-9a-zA-Z ]", name);
		getchar();
		if (strlen(name) > 0) {
			strcpy(student.sName, name);
			if (!validateName(student.sName))
				strcat(errorMessage, "Invalid name! ");

		}
		printf("Date of birth %s-> ", student.sDoB);
		scanf("%12[0-9a-zA-Z/ ]", dob);
		getchar();
		if (strlen(dob) > 0) {
			strcpy(student.sDoB, dob);
			if (!validateDoB(student.sDoB))
				strcat(errorMessage, "Invalid date of birld! ");

		}
		printf("Email %s-> ", student.sEmail);
		scanf("%100[0-9a-zA-Z@. ]", email);
		getchar();
		if (strlen(email) > 0) {
			strcpy(student.sEmail, email);
			if (!validateEmail(student.sEmail))
				strcat(errorMessage, "Invalid Email! ");

		}
		printf("Phone %s-> ", student.sPhone);
		scanf("%13[0-9a-zA-Z ]", phone);
		getchar();
		if (strlen(phone) > 0) {
			strcpy(student.sPhone, phone);
			if (!validatePhone(student.sPhone))
				strcat(errorMessage, "Invalid phone! ");

		}
		printf("Address %s->", student.sAddress);
		scanf("%100[0-9a-zA-Z ]", address);
		getchar();
		if (strlen(address) > 0) {
			strcpy(student.sAddress, address);
			if (!validateAddress(student.sAddress))
				strcat(errorMessage, "Invalid address! ");
		}

		free(name);
		free(dob);
		free(email);
		free(phone);
		free(address);
		if (strlen(errorMessage) == 0) {
			updateStudent(&students, student);
			printf("%s \n", SUCCESS_UPDATE_STUDENT);
		} else {
			printf("%s\n", errorMessage);
			printf("Failed! invalid information\n");
		}

		free(errorMessage);
	} else
		printf("Failed! This ID does not exist!\n");

	if (menu_continue())
		menu_updateStudent();

}

void menu_save() {
	char choice;
	printf("Do you want to save data? (y/n): ");
	scanf(" %s", &choice);
	if (choice == 'y' || choice == 'Y') {
		saveDataToFile();
		exit(EXIT_SUCCESS);
	} else if (choice == 'n' || choice == 'N')
		exit(EXIT_SUCCESS);
	else
		return menu_save();
}

void main_menu() {
	loadDataFromFile();
	//loadDefaultData();

	while (1) {
		printf("=======================\n");
		printf("1. Add new student \n");
		printf("2. View all students \n");
		printf("3. Search students \n");
		printf("4. Delete students \n");
		printf("5. Update student \n");
		printf("6. Exit \n");
		printf("=======================\n");
		printf("Please choose: ");
		int choice = -1;
		scanf(" %d", &choice);
		getchar();
		switch (choice) {
		case 1:
			menu_addStudent();
			break;
		case 2:
			menu_viewStudents();
			break;
		case 3:
			menu_searchStudents();
			break;
		case 4:
			menu_deleteStudent();
			break;
		case 5:
			menu_updateStudent();
			break;
		case 6:
			menu_save();
			break;
		}
	}
}
