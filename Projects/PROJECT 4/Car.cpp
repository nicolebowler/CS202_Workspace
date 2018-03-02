/* Name: Car.cpp
   Author: Nicole Bowler
   Purpose: This file is to be used in proj4.cpp. It contains the functions
   that are used in the 'Car' class.
  */

#include "Car.h"
#include <iostream>

/*FUNCTION PROTOYPES FROM PROJ4.CPP*/
char * myStringCopy(char * destination, const char * source);

/* CTOR FUNCTIONS */
Car::Car():
	{
		myStringCopy(m_make," ");
		myStringCopy(m_model," ");
		m_year = 0;
		//m_sensor = sensors;
		m_baseprice = 0;
		m_finalprice = 0;
		m_available = available;
		myStringCopy(m_owner, " ");
	}
Car::Car(char * make, char * model, int year, Sensor sensors, float basePrice, float finalPrice, bool available, char * owner)
	{
		myStringCopy(m_make,make);
		myStringCopy(m_model,model);
		m_year = year;
		m_sensor = sensors;
		m_baseprice = basePrice;
		m_finalprice = finalPrice;
		m_available = available;
		m_owner = owner;
	}
Car::Car(const Car & cCar){
	myStringCopy(m_makec,Car.m_make);
	myStringCopy(m_model,cCar.m_model);
	m_year = cCar.m_year;
	m_sensor = cCar.m_sensor;
	m_baseprice = cCar.m_baseprice;
	m_finalprice = cCar.m_finalprice;
	m_available = cCar.m_available;
	m_owner = cCar.m_owner;
}

/* GET/SET FUNCTIONS*/
char * Car::getMake(){
	return m_make;
}

char * Car::getModel(){
	return m_model;
}

int  Car::getYear(){
	return m_year;
}

//Car::getSensor(){
//	return m_sensor;
//}

float Car::getBasePrice(){
	return m_baseprice;
}

float Car::getFinalPrice(){
	return m_finalprice;
}

bool Car::getAvailable(){
	return m_available;
}

char * Car::getOwner(){
	return m_owner;
}

void Car::setMake(char * make){
	myStringCopy(m_make, make);
}

void Car::setModel(char * model){
	myStringCopy(m_model, model);
}

void Car::setYear(int year){
	m_year = year;
}

void Car::setBasePrice(float bprice){
	m_baseprice = bprice;
}

void Car::setAvailable(bool available){
	m_available = available;
}

void Car::setOwner(char * owner){
	myStringCopy(m_owner, owner);
}

void Car::updatePrice(float price){
	m_finalprice = price;
}

/*ADD SENSOR OPERATOR FUNCTION GOES HERE*/

/*ADD LESSE OPERATOR FUNCTION GOES HERE*/