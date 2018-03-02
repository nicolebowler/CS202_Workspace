/*


Name: proj1.cpp

Author: Nicole Bowler

Purpose: This program asks the user for an input and output file. 
10 names of 8 characters will be copied into a 2D array. The names
 will then be printed to the console, sorted alphabetically then 
printed to the console again and then written to the output file. 


CS 202 - 1001 || Project One || Due Wednesday, 1/31/2018, 11:59PM

*/


#include <iostream>
#include <fstream>

using namespace std; 

/* --DECLARATION OF FUNCTIONS-- */
void myStringCopy(char destination[], const char source[]);
int myStringLength(const char str[]);
int myStringCompare(const char str1[], const char str2[]);


/* --MAIN-- */
int main(void)
{
	char inputFileName[40]; //declaration of variables 
	char outputFileName[40];
	char nameHolder[10][8];
	char sortedNames[10][8];
	char temp[8];
	char copyChar;
	int order[10];


	cout << "Enter input file name: "; //console I/O for files
	cin >> inputFileName;
	cout << "Enter output file name: ";
	cin >> outputFileName;

	ifstream inputFile; //preparation for file I/O on input and output files
	ofstream outputFile;

	inputFile.open(inputFileName);
	outputFile.open(outputFileName);
	/* Checks for file readability */
	if (!inputFile)
	{
		cout << "Cannot Read input file." << endl;
		return 1;
	}

	if (!outputFile)
	{
		cout << "Cannot read output file." << endl; 
		return 1;
	}

	for (int y = 0; y < 10; y++) //loop that reads the input file and then copies it to the 2D character array
	{
		inputFile >> nameHolder[y];
	}

	/* Printing of Unsorted Data to Console */
	cout << "Unsorted Data: " << endl;
	

	for (int orginalIndex = 0; orginalIndex < 10; orginalIndex++){ //outputs the original order of names to the console
		cout << (orginalIndex + 1) << " ";
		for (int a = 0; a < 8; a++) {
			cout <<  nameHolder[orginalIndex][a] ;
		}
		cout << endl;
	}
	cout << endl;

	/* Printing of Unsorted Data to output file */
	outputFile << "Unsorted Data: " << endl;
	for (int o = 0; o < 10; o++) {
		outputFile << o + 1 << ' ' << nameHolder[o] << endl;
	}
	outputFile << endl;


	/*Copy original string array into an array for sorting*/
	for (int c = 0; c < 10; c++){
		myStringCopy(sortedNames[c], nameHolder[c]);
	}



	/*SORTING LOOPS*/
	int sortedIndex[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int tempInt; 

	for (int s = 0; s < 9; s++){
		for (int u = 0; u < 9; u++){
			if (myStringCompare(sortedNames[u], sortedNames[u + 1]) == 2){
				myStringCopy(temp, sortedNames[u]);
				myStringCopy(sortedNames[u], sortedNames[u + 1]);
				myStringCopy(sortedNames[u + 1], temp);
				tempInt = sortedIndex[u];
				sortedIndex[u] = sortedIndex[u + 1];
				sortedIndex[u + 1] = tempInt; 
			}
		}
	}

	/*Printing of SORTED data to Console*/
	cout << "Sorted Data:" << endl; 
	for(int printV = 0; printV < 10; printV++){
		cout << sortedIndex[printV] << ' ' << sortedNames[printV] << endl; 
	}

	/*Printing of SORTED data to output file*/
	outputFile << "Sorted Data:" << endl;
	for(int fileV = 0; fileV < 10; fileV++){
		outputFile << sortedIndex[fileV] << ' ' << sortedNames[fileV] << endl; 
	}
	

	inputFile.close();
	outputFile.close();

	return 0;
}

/* --FUNCTION DEFINITIONS-- */


/* This function takes the contents of the source array and copies it into
	the destination array until a /0 is found in the source array. The it null 
	terminates the destination array. */
void myStringCopy(char destination[], const char source[])
{
	int i = 0;
	while (i < 8){
		if(source[i] != '\0'){
			destination[i] = source[i];
		}
		i++;
		if(source[i] == '\0'){
			destination[i] = '\0';
		}
	}
	


}

/* This function counts the number of chars in the string until a
	terminating character is found. */
int myStringLength(const char str[])
{
	int size = 0;
	while (str[size] != '\0'){
		size++;
	}

	return size;
}

/* This function checks each letter of both strings until the letters do not match
	then it compares the values of the unmatched letters and returns an int based 
	on how they compare. */
int myStringCompare(const char str1[], const char str2[])
{
	int i = 0;
	for (; i < 8; i++)
	{
		if (str1[i] != str2[i]){
			break; 
		}
	}

	if (str1[i] > str2[i]){
		return 2;
	}

	if (str1[i] < str2[i]){
		return -2;
	}

	return 0;
}
