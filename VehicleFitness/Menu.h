#pragma once

#include "Queue.h"

#include <string>

class Menu
{
private:
	Queue* queue;

public:
	Menu()
	{
		queue = new Queue();
		InitializeMenu();
	}

	void InitializeMenu()
	{
		cout << "# # # # # # # # # # # # # # # # # # # #" << endl;
		cout << "#                                     #" << endl;
		cout << "#  Welcome To Vehicle Fitness System  #" << endl;
		cout << "#                                     #" << endl;
		cout << "# # # # # # # # # # # # # # # # # # # #" << endl;
		ShowMenu();
	}

	void ShowMenu()
	{
		cout << endl;
		cout << "----------------- Menu ----------------" << endl;
		cout << endl;
		cout << "[1] Add Vehile" << endl;
		cout << "[2] Process Vehicle" << endl;
		cout << "[3] Count Vehicles" << endl;
		cout << "[4] Display All Vehicles" << endl;
		cout << "[5] Display At Front" << endl;
		cout << "[6] Display At Rear" << endl;
		cout << "[7] Exit" << endl;
		cout << endl;

		int menuOption = 0;

		cout << "Select Option (1-7): ";
		cin >> menuOption;

		switch (menuOption)
		{
		case 1:
			AddVehicleOption();
			break;
		case 2:
			ProcessVehicleOption();
			break;
		case 3:
			CountVehicleOption();
			break;
		case 4:
			DisplayAllVehiclesOption();
			break;
		case 5:
			DisplayAtFrontOption();
			break;
		case 6:
			DisplayAtRearOption();
			break;
		case 7:
			cout << "Exiting Program..." << endl;
			break;
		default:
			cout << "Invalid Option Selected" << endl;
			ShowMenu();
			break;
		}
	}

	void AddVehicleOption()
	{
		cout << endl;
		cout << "------------- Add Vehicle -------------" << endl;

		int inRegistrationNumber = 0;
		string inLicensePlate = "";
		string inVehicleType = "";

		do
		{
			cout << endl;
			cout << "Enter Vehicle Registration No. (Enter 0 to Exit): ";
			cin >> inRegistrationNumber;

			if (inRegistrationNumber != 0)
			{
				while ((getchar()) != '\n'); // clears buffer

				cout << "Enter License Plate: ";
				getline(cin, inLicensePlate);

				//while ((getchar()) != '\n'); // clears buffer

				cout << "Enter Vehicle Type: ";
				cin >> inVehicleType;

				Vehicle* vehicle = new Vehicle(inRegistrationNumber, inLicensePlate, inVehicleType);

				queue->AddVehicle(vehicle);

				cout << endl;
				cout << "Vehicle Added Successfully!" << endl;
				cout << endl;
			}
		} while (inRegistrationNumber != 0);

		ShowMenu();
	}

	void ProcessVehicleOption()
	{
		cout << endl;
		cout << "Vehicle Processed: " << endl;
		queue->ProcessVehicle()->DisplayVehicle();

		ShowMenu();
	}

	void CountVehicleOption()
	{
		cout << endl;
		cout << "Number of Vehicles: " << queue->CountVehicles() << endl;
		cout << endl;

		ShowMenu();
	}

	void DisplayAllVehiclesOption()
	{
		cout << endl;
		queue->DisplayVehicles();

		ShowMenu();
	}

	void DisplayAtFrontOption()
	{
		cout << endl;
		queue->DisplayFront();

		ShowMenu();
	}

	void DisplayAtRearOption()
	{
		cout << endl;
		queue->DisplayRear();

		ShowMenu();
	}
};
