/*
 * DataManager.c
 *
 *  Created on: Apr 21, 2016
 *      Author: youngkaka
 */

#include "DataManager.h"

#include <stdio.h>
#include "../../managers/DataManager.h"

void test_loadDefaultData() {
	printf("test_loadDefaultData ->");

	if (loadDefaultData())
		printf("Pass");
	else
		printf("Failed");

	printf("\n");
}
void test_saveDataToFile() {
	printf("test_saveDataToFile ->");

	if (saveDataToFile())
		printf("Pass");
	else
		printf("Failed");

	printf("\n");
}
void test_loadDataFromFile() {
	printf("test_loadDataFromFile ->");

	if (loadDataFromFile())
		printf("Pass");
	else
		printf("Failed");

	printf("\n");
}
