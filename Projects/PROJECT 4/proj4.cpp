/*
Name: proj4.cpp
Author: Nicole Bowler
Purpose: 



CS 202 - 1001 || Project Four || DUE: Wednesday, 2/ /2018 11:59PM

*/

#include <iostream>
#include <fstream>
#include "Agency.h"
#include "Car.h"
#include "Sensor.h"

using namespace std;

/* --Program Function Prototypes-- */

/*Menu Functions*/
int getData(Car * cardata);
int printData(Car * cardata);
int printSensors(Car * cardata);
int rentExpensive(Car * cardata);
/*cString functions*/
size_t myStringLength(const char * str);
int myStringCompare(const char * str1, const char * str2);
char * myStringCopy(char * destination, const char * source);
char * myStringCat(char * destination, const char * source);
/*additional functions*/
int menu_prompt(void);

/* --MAIN-- */
int main();

	char * file_name;
	int menu_num = 1;
	Car cars[5];

	while (menu_num != 5) {
		switch (menu_num){
			case 1: 
				menu_num = getData(cars);
				break;
			case 2:
				menu_num = printRelated(cars);
				break;
			case 3:
				menu_num = printSensors(cars);
				break;
			case 4:
				menu_num = rentExpensive(cars);
				break;
		}
	}

	return 0;


/* --Function Definitions-- */

/*MENU FUNCTIONS*/

int getData(Car * cardata)
{
	char inputFileName[256]; 
	char tempMake[256]; //temporary replicas of Car class members to gather file information
	char tempModel[256]
	int tempYear;
	float tempPrice;
	char sensor[256];
	bool tempAvail;
	char tempOwner[256];
	char tempAgency[256]; //temporary replicas of Agency class members
	int tempZip;
	ifstream inputFile;

	cout << "Enter File Name:";
	cin >> inputFileName;

	inputFile.open(inputFileName);
	if (!inputFile){
		cout << "CANNOT READ FILE..." << endl;
		return 5;
	}

	
	while (!inputFile.EOF()){
		inputFile>>tempAgency>>tempZip;
		Agency.setName(tempAgency);
		Agency.setZip(tempZip);

		for (int i =0; i < 5; i++){
			inputFile>>year>>tempMake>>tempModel>>tempPrice/*>>sensor>>availability>>owner*/;
			*cardata->setMake(tempMake);
			*cardata->setModel(tempModel);
			*cardata->setYear(tempYear);
			*cardata->setBasePrice(tempPrice);
			cardata++;
		}
	inputFile.close;
	return menu_prompt;
}
int printData(Car * cardata)
{
	return menu_prompt;
}
int printSensors(Car * cardata)
{
	return menu_prompt;
}
int rentExpensive(Car * cardata)
{
	return menu_prompt;
}

/*cSTRING FUNCTIONS*/

/*This function finds the length of the passed in string by incrementing
a variable call 'size' until a null character is found*/
int myStringLength(const char * str)
{
	int size = 0;
	while (*str != '\0'){
		str++;
		size++;
	}
	return size;

}

/*This function compares two passed in strings and returns a 0, -1, or -2
based on the result. The characters are compared until they do not match.*/
int myStringCompare(const char * str1, const char * str2)
{

	while (*str1 != *str2){
		str1++;
		str2++;
	}

	if (*str1 > *str2){
		return 2;
	}

	if (*str1 < *str2){
		return -2;
	}

	return 0;
}

/*This function copies the contents of the source string passed in 
to the destination string passed in*/
char * myStringCopy(char * destination, const char * source)
{
	
	while (*source != '\0'){
			*destination = *source;
			source++;
			destination++;
	}
	destination++;
	*destination = '\0'
	return destination;

}

/*This function finds the null character of the desination string\
then copies over character by character of the source string into the 
remaining character indexes*/
char * myStringCat(char * destination, const char * source){
	int s1Pos = 0;
	int s2Pos = 0; 

	while (*destination != '\0'){
		destination++;
	}
	while (*source != '\0'){
		*destination = *source;
		destination++;
		source++;
	}
	return destination;
}

/*ADDITIONAL FUNCTIONS*/

int menu_prompt(void)
{
	int optionPick;
	cout << "-----------------------------------------" << endl << "Menu Options:" << endl;
	cout << "1: Enter/change input file." << endl;
	cout << "2: Print out all data." << endl;
	cout << "3: Print out total number of sensors."<< endl;
	cout << "4: Find most expensive car." << endl;
	cout << "5: EXIT." << endl << "-----------------------------------------" << endl;
	cout << "Please Select an Option: ";
	cin >> optionPick;

	return optionPick;
}
