/*
 * DataManager.c
 *
 *  Created on: Apr 18, 2016
 *      Author: youngkaka
 */

#include "DataManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char mFilePath[] = "/tmp/students.txt";

int loadDefaultData() {
	Student s;
	strcpy(s.sId, "GC00701");
	strcpy(s.sName, "Kaka");
	strcpy(s.sDoB, "10/10/2016");
	strcpy(s.sEmail, "kaka@gmail.com");
	strcpy(s.sPhone, "0123456789");
	strcpy(s.sAddress, "London City");

	addStudent(&students, s);

	strcpy(s.sId, "GC00702");
	strcpy(s.sName, "Ronaldo");
	strcpy(s.sDoB, "31/01/2016");
	strcpy(s.sEmail, "ronaldo@gmail.com");
	strcpy(s.sPhone, "0987654321");
	strcpy(s.sAddress, "Newyork city");

	addStudent(&students, s);

	strcpy(s.sId, "GC00703");
	strcpy(s.sName, "Messi");
	strcpy(s.sDoB, "12/02/2014");
	strcpy(s.sEmail, "messig@gmail.com");
	strcpy(s.sPhone, "0213812819");
	strcpy(s.sAddress, "Tokyo city");

	addStudent(&students, s);

	if (students.count > 0)
		return 1;
	else
		return 0;
}

// student to tring
void studentToString(Student student, char *string) {
	strcat(string, student.sId);
	strcat(string, "|");
	strcat(string, student.sName);
	strcat(string, "|");
	strcat(string, student.sDoB);
	strcat(string, "|");
	strcat(string, student.sEmail);
	strcat(string, "|");
	strcat(string, student.sPhone);
	strcat(string, "|");
	strcat(string, student.sAddress);
	strcat(string, "\n");
}

// write text to file
int saveDataToFile() {
	FILE *fp;
	fp = fopen(mFilePath, "w+");
	if (fp == NULL)
		return 0;
	char buff[500] = "";
	for (int i = 0; i < students.count; i++) {
		Student s = students.students[i];
		studentToString(s, buff);

	}
	fprintf(fp, "%s", buff);
	fclose(fp);
	return 1;
}

// read text from file
int loadDataFromFile() {
	FILE * fp;
	char * line = NULL;
	size_t len = 0;

	fp = fopen(mFilePath, "r");
	if (fp == NULL)
		return loadDefaultData();
	else {
		while (getline(&line, &len, fp) != -1) {
			Student stu;
			int count = 0;
			const char s[2] = "|";
			char *token;
			token = strtok(line, s);
			while (token != NULL) {
				if (count == 0)
					strcpy(stu.sId, token);
				else if (count == 1)
					strcpy(stu.sName, token);
				else if (count == 2)
					strcpy(stu.sDoB, token);
				else if (count == 3)
					strcpy(stu.sEmail, token);
				else if (count == 4)
					strcpy(stu.sPhone, token);
				else if (count == 5) {
					strtok(token, "\n");
					strcpy(stu.sAddress, token);
				}
				count++;
				token = strtok(NULL, s);
			}
			addStudent(&students, stu);
		}
	}
	fclose(fp);
	if (line)
		free(line);

	return 1;
}

