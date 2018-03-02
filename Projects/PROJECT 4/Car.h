#ifndef CAR_H
#define CAR_H

class Car{
	public:
		Car();
		Car(char * make, char * model, int year, Sensor sensors, float basePrice, float finalPrice, bool available, char * owner);
		Car(const Car & cCar) const;
		char* getMake();
		char* getModel();
		int getYear();
		//Sensor getSensor();
		float getBasePrice();
		float getFinalPrice();
		bool getAvailable();
		char * getOwner();
		void setMake(char * make);
		void setModel(char * model);
		void setYear(int year);
		void setBasePrice(float bPrice);
		void setAvailable(bool available);
		void setOwner(char * owner);
		void updatePrice(float price);
		void Print(Car carData);
		float EstimateCost(int days);
		//add sensor
		//const Car& operator+(char* owner);  seek help and understand how to use it
	private:
		char * m_make[256];
		char * m_model[256];
		int m_year;
		Sensor m_sensors[3];
		float m_baseprice;
		float m_finalprice;
		bool m_available;
		char * m_owner[256];
};

#endif
