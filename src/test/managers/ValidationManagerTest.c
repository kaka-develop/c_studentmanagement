/*
 * ValidationManagerTest.c
 *
 *  Created on: Apr 21, 2016
 *      Author: youngkaka
 */

#include "ValidationManagerTest.h"
#include <stdio.h>
#include <string.h>
#include "../../managers/ValidationManager.h"


void test_validateID() {
	printf("test_validateID ->");
	int isPass = 0;

	char value[] = "GC00704";
	if (validateID(value)) {
		stpcpy(value, "asadasa");
		if (!validateID(value)) {
			stpcpy(value, "GCaas");
			if (!validateID(value))
				isPass = 1;
		}
	}

	if (isPass)
		printf("Pass");
	else
		printf("Failed");

	printf("\n");
}

void test_validateName() {
	printf("test_validateName ->");
	int isPass = 0;

	char value[] = "Kaka";
	if (validateName(value)) {
		stpcpy(value, "sa");
		if (!validateName(value)) {
			stpcpy(value, "-");
			if (!validateName(value))
				isPass = 1;

		}
	}

	if (isPass)
		printf("Pass");
	else
		printf("Failed");
	printf("\n");
}

void test_validateDoB() {
	printf("test_validateDoB ->");
	int isPass = 0;

	char value[] = "21/10/1996";
	if (validateDoB(value)) {
		stpcpy(value, "12131");
		if (!validateDoB(value)) {
			stpcpy(value, "12311198");
			if (!validateDoB(value))
				isPass = 1;
		}
	}

	if (isPass)
		printf("Pass");
	else
		printf("Failed");
	printf("\n");
}

void test_validateEmail() {
	printf("test_validateEmail ->");
	int isPass = 0;

	char value[] = "kaka@gmail.com";
	if (validateEmail(value)) {
		stpcpy(value, "kaka");
		if (!validateEmail(value)) {
			stpcpy(value, "kaka@.");
			if (!validateEmail(value))
				isPass = 1;
		}
	}

	if (isPass)
		printf("Pass");
	else
		printf("Failed");
	printf("\n");
}


void test_validatePhone() {
	printf("test_validatePhone ->");
	int isPass = 0;

	char value[] = "0123456789";
	if (validatePhone(value)) {
		stpcpy(value, "1234");
		if (!validatePhone(value)) {
			stpcpy(value, "921344");
			if (!validatePhone(value))
				isPass = 1;
		}
	}

	if (isPass)
		printf("Pass");
	else
		printf("Failed");
	printf("\n");
}


void test_validateAddress() {
	printf("test_validateAddress ->");
	int isPass = 0;

	char value[] = "London City";
	if (validateAddress(value)) {
		stpcpy(value, "");
		if (!validateAddress(value)) {
			stpcpy(value, "lon");
			if (!validateAddress(value))
				isPass = 1;
		}
	}

	if (isPass)
		printf("Pass");
	else
		printf("Failed");
	printf("\n");
}
