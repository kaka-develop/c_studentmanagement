/*
 * StudentManager.h
 *
 *  Created on: Apr 18, 2016
 *      Author: youngkaka
 */

#ifndef STUDENTMANAGER_H_
#define STUDENTMANAGER_H_


#include "../models/StudentArray.c"

int existingStudentByID(StudentArray *array, char sId[]);
int addStudent(StudentArray *array, Student newStudent);
int deleteStudent(StudentArray *array, char sId[]);

void printStudent(Student student);
void printListOfStudent(StudentArray array);
int searchStudentsByName(StudentArray array, char text[]);
int updateStudent(StudentArray *array, Student newStudent);
#endif /* STUDENTMANAGER_H_ */
