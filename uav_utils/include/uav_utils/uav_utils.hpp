#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/Vector3.h>
#include <cstdio>
#include <cmath>

#include "geometry_msgs/Vector3.h"

class PID
{
	private:
	public:
	///////////
	//Variables
	double P, I, D, satU, satL, Ts, Tau, trim;
	double Iterm, Iprev, Eprev, Uprev, Dprev;
	double output;
	///////////
	//Functions
	
	//Constructor
	PID (double Pi, double Ii, double Di, double satUi, double satLi, double trim, double Tsi, double Ni);

	//Destructor
	~PID ();
	
	//Main step
	double step(double error);
	double step(double error, double dt);
	double step(double error, double dt, double derivative);
	void init(void);
};

class APID
{
public:
	///////////
	//Variables
	double P, I, D, satU, satL, Ts, Tau, trim;
	double Pinit, Iinit, Dinit;
	double Iterm, Iprev, Eprev, Uprev, Dprev;
	double Ierror, bumplessI1, bumplessI2, trErr;
	double output;
	///////////
	//Functions
	
	//Constructor
	APID (double Pi, double Ii, double Di, double satUi, double satLi, double trim, double Tsi, double Ni);

	//Destructor
	~APID ();
	
	//Main step
	double step(double error, bool track, double trInput);
	void init(void);	
};

geometry_msgs::Vector3 getAirData (geometry_msgs::Vector3 speeds);

void WGS84_NM(double lat,double *NE, double *ME);
