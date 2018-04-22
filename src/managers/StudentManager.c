/*
 * StudentManager.c
 *
 *  Created on: Apr 18, 2016
 *      Author: youngkaka
 */

#include "StudentManager.h"
#include <stdio.h>
#include <string.h>

// check existing student by ID. if not exist return -1
int existingStudentByID(StudentArray *array, char sId[]) {
	int count = array->count;
	for (int i = 0; i < count; i++) {
		if (strcmp(array->students[i].sId, sId) == 0)
			return i;

	}
	return -1;
}

// add a student into array
int addStudent(StudentArray *array, Student newStudent) {
	int count = array->count;
	if (count < 100) {
		if (existingStudentByID(array, newStudent.sId) >= 0)
			return 0;

		array->students[count++] = newStudent;
		array->count = count;

		return 1;
	} else
		return 0;
}

// delete a student by ID
int deleteStudent(StudentArray *array, char sId[]) {
	int count = array->count;
	int index = existingStudentByID(array, sId);
	if (index >= 0) {
		for (int i = index; i < count; i++) {
			array->students[i] = array->students[i + 1];
		}
		array->count = count - 1;
		return 1;

	}

	return 0;
}

// print a student on the screen
void printStudent(Student student) {
	printf("%s | %s | %s | %s | %s | %s \n", student.sId, student.sName,
			student.sDoB, student.sEmail, student.sPhone, student.sAddress);
}

//print a list of students
void printListOfStudent(StudentArray array) {
	int count = array.count;
	printf("Count = %d \n", count);
	for (int i = 0; i < count; i++) {
		printStudent(array.students[i]);
	}
}

// search students by name
int searchStudentsByName(StudentArray array, char text[]) {
	int check = 0;
	int count = array.count;
	for (int i = 0; i < count; i++) {
		if (strstr(array.students[i].sName, text) != NULL) {
			printStudent(array.students[i]);
			check++;
		}
	}
	return check;
}

//update a student
int updateStudent(StudentArray *array, Student newStudent) {
	int index = existingStudentByID(array, newStudent.sId);
	if (index >= 0) {
		array->students[index] = newStudent;
		return 1;
	}
	return 0;
}

