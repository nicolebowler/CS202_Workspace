#ifndef SENSOR_H
#define SENSOR_H

class Sensor{
	public:
		Sensor();
		Sensor(char * type, float excost); //parameterized ctor
		Sensor(const Sensor & s) const; //cpyctor
		char * getType();
		float getExCost();
		void setType(char * type);
		void setExCost(float cost);
		static int getAndResetGps();
		static int getAndResetCamera();
		static int getAndResetLidar();
		static int getAndResetRadar();
		const Sensor operator ==(const Sensor &s) const;

	private:
	char * m_type;
	float m_extracost;
	static int gps_cnt;
	static int camera_cnt;
	static int lidar_cnt;
	static int radar_cnt

};

#endif
