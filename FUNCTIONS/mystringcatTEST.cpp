#include <iostream>

using namespace std;

char * myStringCat(char * destination, const char * source);

int main()
{
	char  input[50];
	char  ndin[50];
	char  output[50];

	cout << "Enter string: ";
	cin >> input;
	myStringCat(output, input);
	cout << output << endl;

	cout << "Enter string: ";
	cin >> ndin;
	myStringCat(output, ndin);
	cout << output << endl;

	return 0;
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
