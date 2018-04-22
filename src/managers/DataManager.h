/*
 * DataManager.h
 *
 *  Created on: Apr 18, 2016
 *      Author: youngkaka
 */

#ifndef DATAMANAGER_H_
#define DATAMANAGER_H_

#include "StudentManager.h"

StudentArray students;
int loadDefaultData();
int saveDataToFile();
int loadDataFromFile();
#endif /* DATAMANAGER_H_ */
