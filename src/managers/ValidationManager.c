/*
 * ValidationManager.c
 *
 *  Created on: Apr 18, 2016
 *      Author: youngkaka
 */

#include "ValidationManager.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// validate ID   GCxxxxx (x is digital)
int validateID(char id[]) {
	if (strlen(id) != 7)
		return 0;
	if (strstr(id, "GC") == NULL)
		return 0;
	char check[5];
	strncpy(check, id + 2, 5);
	for (int i = 0; i < 5; i++) {
		if (!isdigit(check[i])) {
			return 0;
		}
	}
	return 1;
}

// validate email
int validateName(char name[]) {
	if (strlen(name) <= 2)
		return 0;
	if (isspace(name[0]))
		return 0;
	return 1;
}

// validate date of birth
int validateDoB(char mdate[]) {
	char *date = malloc(11 * sizeof(char));
	strcpy(date, mdate);
	if (strlen(date) != 10)
		return 0;
	const char s[2] = "/";
	char *token;
	token = strtok(date, s);
	while (token != NULL) {
		if (strlen(token) != 2 && strlen(token) != 4)
			return 0;
		int len = strlen(token);
		for (int i = 0; i < len; i++) {
			if (!isdigit(token[i])) {
				return 0;
			}
		}
		token = strtok(NULL, s);
	}

	free(date);
	return 1;
}

// validate email
int validateEmail(char memail[]) {
	char *email = malloc(100 * sizeof(char));
	strcpy(email, memail);
	if (strlen(email) <= 6)
		return 0;
	if (isspace(email[0]))
		return 0;
	if (strstr(email, "@") == NULL || strstr(email, ".") == NULL)
		return 0;

	char s[2] = "@";
	char *token;
	token = strtok(email, s);
	while (token != NULL) {
		s[1] = ',';
		if (strlen(token) <= 2)
			return 0;
		token = strtok(NULL, s);
	}
	free(email);
	return 1;
}

// validate phone number
int validatePhone(char mphone[]) {
	char *phone = malloc(12 * sizeof(char));
	strcpy(phone, mphone);
	int len = strlen(phone);
	if (len != 11 && len != 10)
		return 0;
	for (int i = 0; i < len; i++) {
		if (!isdigit(phone[i])) {
			return 0;
		}
	}
	free(phone);
	return 1;
}

// validate address
int validateAddress(char address[]) {
	if (strlen(address) <= 3)
		return 0;
	return 1;
}
