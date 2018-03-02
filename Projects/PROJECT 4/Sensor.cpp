/* Name: Sensor.cpp
   Author: Nicole Bowler
   Purpose: This file is part of proj4.cpp and contains the functions 
   used in the "Sensor" class.
   WARNING!!! THIS IS NOT FINISHED AND SHOULD NOT BE IMPLEMENTED UNTIL
   READY; COMMENT OUT ANY USE OF THE SENSOR CLASS UNTIL READY
 */

#include <Sensor.h>
#include <iostream>


int myStringCompare(const char * str1, const char * str2);
char * myStringCopy(char * destination, const char * source); 

/*CTORS*/

Sensor::Sensor() : {//default ctor
	myStringCopy(m_type, " ");
	m_extracost = 0;

}

Sensor::Sensor(char * type, float excost): //parameterized ctor
{
	myStringcopy(m_type, type);
	m_extracost = excost;
	if (myStringCompare(type, "gps") == 0){
		gps_cnt++;
	}

	if (myStringCompare(type, "lidar") == 0){
		lidar_cnt++;
	}

	if (myStringCompare(type, "radar") == 0){
		radar_cnt++;
	}

	if (myStringCompare(type, "camera") == 0){
		camera_cnt++;
	}

}


Sensor::Sensor(const Sensor & s)://cpy ctor
{
	myStringCopy(m_type, s.m_type);
	m_extracost(s.m_extracost);
	if (myStringCompare(s.m_type, "gps") == 0){
		gps_cnt++;
	}

	if (myStringCompare(s.m_type, "lidar") == 0){
		lidar_cnt++;
	}

	if (myStringCompare(s.m_type, "radar") == 0){
		radar_cnt++;
	}

	if (myStringCompare(s.m_type, "camera") == 0){
		camera_cnt++;
	}

}

/*GET/SET FUNCTIONS*/

char * Sensor::getType():
{
	return m_type;
}

float Sensor::getExCost():
{
	return m_extracost;
}

static int Sensor::getAndResetGps():
{
	int temp = gps_cnt;
	gps_cnt = 0;
	return temp;
}

static int Sensor::getAndResetCamera():
{
	int temp = camera_cnt;
	camera_cnt = 0;
	return temp;
}

static int Sensor::getAndResetLidar():
{
	int temp = lidar_cnt;
	lidar_cnt = 0;
	return temp;
}

static int Sensor::getAndResetRadar():
{
	int temp = radar_cnt;
	radar_cnt = 0;
	return temp;
}

const Sensor::Sensor operator ==(constSensor & s) const
{
	if (myStringCopy(m_type, s.m_type) == 0){
		return 1;
	}
	else {
		return 0;
	}
}