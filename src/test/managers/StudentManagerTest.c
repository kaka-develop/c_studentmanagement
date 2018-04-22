/*
 * StudentManagerTest.c
 *
 *  Created on: Apr 21, 2016
 *      Author: youngkaka
 */

#include "StudentManagerTest.h"
#include <stdio.h>
#include <string.h>
#include "../../managers/StudentManager.h"

StudentArray array;
char id[] = "GC00703";
Student s;

void setup() {
	strcpy(s.sId, id);
	strcpy(s.sName, "Kaka");
	strcpy(s.sDoB, "10/10/2016");
	strcpy(s.sEmail, "kaka@gmail.com");
	strcpy(s.sPhone, "0123456789");
	strcpy(s.sAddress, "London City");
}
void test_addStudent() {
	printf("test_addStudent ->");
	setup();

	int isPass = 0;
	if (addStudent(&array, s)) {
		if (!addStudent(&array, s)) {
			strcpy(s.sDoB, "10102016");
			if (!addStudent(&array, s))
				isPass = 1;
		}
	}

	if (isPass)
		printf("Pass");
	else
		printf("Failed");

	printf("\n");
}

void test_existingStudentByID() {
	printf("test_existingStudentByID ->");
	setup();

	int isPass = 0;
	if (existingStudentByID(&array, id) >= 0) {
		if (existingStudentByID(&array, "gcsas") < 0) {
			if (existingStudentByID(&array, "GC1232") < 0)
				isPass = 1;
		}
	}

	if (isPass)
		printf("Pass");
	else
		printf("Failed");

	printf("\n");
}
void test_deleteStudent() {
	printf("test_deleteStudent ->");
	setup();

	int isPass = 0;
	if (deleteStudent(&array, id)) {
		if (!deleteStudent(&array, "gcsas")) {
			if (!deleteStudent(&array, "GC1232"))
				isPass = 1;
		}
	}

	if (isPass)
		printf("Pass");
	else
		printf("Failed");

	printf("\n");
}
void test_searchStudentsByName() {
	printf("test_searchStudentsByName ->");
		setup();
		addStudent(&array, s);

		char text[] = "a";
		int isPass = 0;
		if (searchStudentsByName(array, text)>0) {
			if (searchStudentsByName(array, "gcsas") == 0) {
				if (searchStudentsByName(array, "ksasdas")== 0)
					isPass = 1;
			}
		}

		if (isPass)
			printf("Pass");
		else
			printf("Failed");

		printf("\n");
}
void test_updateStudent() {
	printf("test_updateStudent ->");
		setup();

		int isPass = 0;
		strcpy(s.sEmail,"tom@gmail.com");
		if (updateStudent(&array, s)) {
			strcpy(s.sId,"GC00701");
			if (!updateStudent(&array, s)) {
				strcpy(s.sId,"GC00702");
				if (!updateStudent(&array, s))
					isPass = 1;
			}
		}

		if (isPass)
			printf("Pass");
		else
			printf("Failed");

		printf("\n");
}

