#ifndef AGENCY_H
#define AGENCY_H

class Agency{
	public: 
		Agency(const Car & car);
		char * getName();
		const int getZip();
		void setName(char * name);
		void setZip(const int zipNum);
		//operatorFucntion
		void readAllData(ifstream file);
		void printAllData(Agency * agencyData);
		void printAvailableCars(Agency * agencyData);
	private:

		char * m_name[256];
		const int m_zipcode;
		Car m_inventory[5];
};

#endif
