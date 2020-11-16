#pragma once

#include <iostream>

using namespace std;

class Vehicle
{
private:
	int registrationNumber;
	string licensePlate;
	string vehicleType;

public:
	Vehicle()
	{
		registrationNumber = 0;
		licensePlate = "";
		vehicleType = "";
	}

	Vehicle(int inRegistrationNumber, string inLicensePlate, string inVehicleType)
	{
		registrationNumber = inRegistrationNumber;
		licensePlate = inLicensePlate;
		vehicleType = inVehicleType;
	}

	void DisplayVehicle()
	{
		cout << "Registration Number: " << registrationNumber << endl;
		cout << "License Plate: " << licensePlate << endl;
		cout << "Vehicle Type: " << vehicleType << endl;
		cout << endl;
	}
};