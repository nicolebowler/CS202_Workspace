/*

Name: proj2.cpp
Author: Nicole Bowler
Purpose: This program assists users in renting a car. The user will input a datasheet (txt doc) 
			with five cars each being identical in format. Then a menu of options will be listed
			for the user. 
			1) Ask the user for an input file, then store the values into an array of structs.
			2) print out all data for the cars to the terminal.
			3) similar to number to but with asking the user to define an output file then printing the data to said output file. 
			4) Sort the structs by ascending price
			5) Ask the user how many days they would like to rent and post the acsending order of the total prices
			6) Ask the user which car they would like and how many days they would like to rent. Check availablility and print out a warning/success message to terminal
			7) Exit program. 

CS - 202 - 1001 - Papachristos - Due: Wednesday February 7th, 2018

*/

#include <iostream>
#include <fstream>
using namespace std; 




/*Primary struct to hold the data for the rental car data*/
struct car{
	int year;
	char make[10];
	char model[10];
	float price;
	bool available; 
};




/* --FUNCTION DECLARATIONS(prototypes)-- */

	/*character array functions*/
int myStringLength(const char * str);
int myStringCompare(const char * str1, const char * str2);
char * myStringCopy(char * destination, const char * source);
char * myStringCat(char * destination, const char * source);
void myCarCopy(car * carOne, const car * carTwo);
	/*menu functions*/
int inputUpdate(ifstream * inputFile, car carData[]);
int printDataTerminal(car * carData);
int printDataFile(car * carData);
int sortCar(car * carData);
int priceCheck(car * carData);
int rentCar(car * carData);
	/*additional functions*/
int printMenu(void);





/* --MAIN FUNCTION-- */

int main()
{
	car rentalCar[5];
	ifstream inputFile; 
	int menuNum = 0;


	menuNum = inputUpdate(&inputFile, rentalCar);
	if (menuNum == 40) {
		return 1;
	}
	/* FOR STRUCT TESTING PURPOSES ONLY!!! NOT TO BE COMPILED IN FINAL SUBMISSION 
	for (int t = 0; t < 5; t++){
		cout << rentalCar[t].year << rentalCar[t].make << rentalCar[t].model << rentalCar[t].price << rentalCar[t].available << endl;
	}
*/
	while (menuNum != 6){ //infinte loop that allows for repeated menu use
		switch(menuNum){
			case 0:
				menuNum = inputUpdate(&inputFile, rentalCar);
				break;
			case 1:
				menuNum = printDataTerminal(rentalCar);
				break;
			case 2:
				menuNum = printDataFile(rentalCar);
				break;
			case 3:
				menuNum = sortCar(rentalCar);
				break;
			case 4:
				menuNum = priceCheck(rentalCar);
				break;
			case 5:
				menuNum = rentCar(rentalCar);
				break;
			case 6:
				inputFile.close();
				return 0;
			default:
				printMenu();
				break;

		}
	}

	inputFile.close();
	return 0;
}

/* --FUNCTION DEFINITIONS-- */

/*This function finds the length of the passed in string by incrementing
a variable call 'size' until a null character is found*/
int myStringLength(const char * str)
{
	int size = 0;
	while (str[size] != '\0'){
		size++;
	}

	return size;
}



/*This function compares two passed in strings and returns a 0, -1, or -2
based on the result. The characters are compared until they do not match.*/
int myStringCompare(const char * str1, const char * str2)
{
	int i = 0;
	for (; i < 10; i++)
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

/*This function copies the contents of the source string passed in 
to the destination string passed in*/
char * myStringCopy(char * destination, const char * source)
{
	int i = 0;
	while (i < 10){
			destination[i] = source[i];
			i++;
			if(source[i] == '\0'){
				break;
			}
	}
	while (i < 10){
		destination[i] = '\0';
		i++;
	}
}
/*This function finds the null character of the desination string\
then copies over character by character of the source string into the 
remaining character indexes*/
char * myStringCat(char * destination, const char * source){
	int s1Pos = 0;
	int s2Pos = 0; 

	while (destination[s1Pos] != '\0'){
		s1Pos++;
	}
	while (source[s1Pos] != '\0'){
		destination[s1Pos] = source[s2Pos];
		s1Pos++;
		s2Pos++;
	}
}

/*This function copies the contents of carSource into carDest datatype by datatype*/
void myCarCopy(car * carDest, const car * carSource)
{
	carDest->year = carSource->year;
	myStringCopy(carDest->make, carSource->make);
	myStringCopy(carDest->model, carSource->model);
	carDest->price = carSource->price;
	carDest->available = carSource->available;
}
/*This function promts the user to enter a file name and takes the data given in the specified input
and enters it into the car struct types*/
int inputUpdate(ifstream * inputFile, car carData[])
{
	char inputFileName[40];

		cout << "Enter input file name: ";
		cin >> inputFileName;

		inputFile->open(inputFileName);
		if (!inputFile){
			cout << "Cannot Read File..." << endl;
			return 40;
	
		}


	while (!inputFile->eof()){
		for (int m = 0; m < 5; m++){
			*inputFile >> carData[m].year >> carData[m].make >> carData[m].model >> carData[m].price >> carData[m].available;
		}
	}

	return printMenu();
}



/*This function takes the information stored in each of the data types in the car struct
and prints them out to the terminal in a for loop. int t stands for terminal*/
int printDataTerminal(car * carData)
{
	for (int t = 0; t < 5; t++){
		cout << endl << carData[t].year << ", " << carData[t].make << " " << carData[t].model << ", Price per Day: $" << carData[t].price << ", " << "Availability: ";
		if (carData[t].available == 0){
			cout << "FALSE";
		}
		else {
			cout << "TRUE";
		}
	}
	return printMenu();

}


/*This function is similar to the one above but it prints to an output file
specified by the user after promted.*/
int printDataFile(car * carData)
{
	ofstream outputFile;
	char outputFileName[40];

	cout << "Printing data to output... please enter a file name for the output:";
	cin >> outputFileName;

	outputFile.open(outputFileName);
	if (!outputFile){
		return 40; //a large number outside of the menu that will force the default case
				   //of the switch statement, resulting in another call for printMenu()
	}

	else {
		outputFile << "Car Inventory Data:";
		for (int t = 0; t < 5; t++){
			outputFile << endl << carData[t].year << ", " << carData[t].make << " " << carData[t].model << ", Price per Day: $" << carData[t].price << ", " << "Availability: ";
			if (carData[t].available == 0){
				outputFile << "FALSE";
			}
			else {
			outputFile << "TRUE";
			}
		}
		
	}
	outputFile.close();
	return printMenu();
}

/*This function has to sets of for loops that look at the
array of car structs and compares two adjacent prices. If the 
higher price is before the lower(or the lower is after the higher)
then the two arrays get flipped. A temp car struct is used to aid 
in swapping. Of course each struct element will be individually copied,
this will be done in a function call myCarCopy.*/
int sortCar(car * carData)
{
	car temp;
	for (int a = 0; a < 8; a++){
		for (int b = 0; b < 9; b++){
			if (carData[b].price > carData[b+1].price){
				myCarCopy(&temp, &carData[b]);
				myCarCopy(&carData[b], &carData[b+1]);
				myCarCopy(&carData[b+1], &temp);

			if (carData[b].price <= carData[b+1].price);
			}
		}
	}

	return printMenu();
}
/*This function asks the user for how many days they would like to 
rent a car for. Then it prints out the TOTAL prices for ONLY the 
available cars.*/ 
int priceCheck(car * carData)
{
	int day; 

	cout << "Enter the number of days you would like to rent for: ";
	cin >> day; 

	for (int d = 0; d < 5; d++){
		if (carData[d].available != 0){
			cout << endl << carData[d].year << " " << carData[d].make << " " << carData[d].model << ", Total Cost: $" << (carData[d].price)*(day);  
		}
	}
	return printMenu();
}
/*This function also asks the user for how many days they would like to 
rent. It also asks for the index of the car they want to rent. If the car is available then
a success message is printed to the console with a TOTAL price and the availability is changed accordingly. A warning message is 
printed if the desired car is not available.*/
int rentCar(car * carData)
{
	int userIndex;
	int userDay;

	cout << "Enter the index of the car: ";
	cin >> userIndex;
	cout << "Enter the number of days to rent: ";
	cin >> userDay;

	if(carData[userIndex].available == 0){
		cout << "FAILED! Car " << userIndex << " is not available." << endl;
		return printMenu();
	}

	else {
		cout << "SUCCESS! Your total price is: $" << (userDay)*carData[userIndex].price << endl;
		carData[userIndex].available = 0;
		return printMenu();
	}

}


int printMenu(void)
{
	int optionPick;
	cout << endl << "Menu Options:" << endl;
	cout << "0: Enter/change input file." << endl;
	cout << "1: Print out all data to TERMINAL." << endl;
	cout << "2: Print out all data to a TEXT FILE."<< endl;
	cout << "3: Sort cars by acsending price." << endl;
	cout << "4: Price per day inquiry." << endl;
	cout << "5: Rent a car." << endl;
	cout << "6: EXIT." << endl << "-----------------------------------------" << endl;
	cout << "Please Select an Option: ";
	cin >> optionPick;

	return optionPick;
}