/*
 * test.c
 *
 *  Created on: Apr 21, 2016
 *      Author: youngkaka
 */

#include "managers/ValidationManagerTest.h"

#include <stdio.h>

void test_start() {
	printf("=====Validation Manager Test====\n");
	test_validateID();
	test_validateName();
	test_validateDoB();
	test_validateEmail();
	test_validatePhone();
	test_validateAddress();

	printf("\n=====Student Manager Test====\n");

	test_addStudent();
	test_existingStudentByID();
	test_deleteStudent();
	test_searchStudentsByName();
	test_updateStudent();

	printf("\n=====Data Manager Test====\n");
	test_loadDefaultData();
	test_saveDataToFile();
	test_loadDataFromFile();
}
