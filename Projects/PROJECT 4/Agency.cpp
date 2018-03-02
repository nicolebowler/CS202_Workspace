/*Name: Agency.cpp
  Author: Nicole Bowler
  Purpose: THis file is used in proj4.cpp and contains the functions 
  used in the 'Agency' class.
*/
#include <iostream>
#include <iostream>

/*FUNCTION PROTOYPES FROM PROJ4.CPP*/

char * myStringCopy(char * destination, const char * source);

/*CTOR FUNCTIONS*/

Agency::Agency(const Car & car):
{
	myStringCopy(m_name, " ");
	m_zipcode = 0;
	for (int i =0; i < 5; i++){
		*m_inventory = *car;
		car++;
		m_inventory++;
	}
}

char * Agency::getName(){
	return m_name;
}

const int Agency::getZip(){
	return m_zipcode;
}

void Agency::setName(char * name){
	myStringCopy(m_name, name);
}

void Agency::setZip(const int zipNum){
	m_zipcode = zipNum;
}

void Agency::readAllData(ifstream file){
	//get some help pls
}

void Agency::printAllData(Agency * agencyData){
	//ahhhhhh
}

void Agency::printAvailable(Agency * agencyData){
	//omgggggg
}
