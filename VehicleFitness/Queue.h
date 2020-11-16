#pragma once

#include "Node.h"

class Queue
{
private:
	Node* front;
	Node* rear;

public:
	Queue()
	{
		front = nullptr;
		rear = nullptr;
	}

	bool IsEmpty()
	{
		if (front == nullptr)
		{
			return true;
		}

		return false;
	}

	bool IsFull()
	{
		Node* temp = new Node();

		if (temp)
		{
			delete temp;
			return false;
		}

		return true;
	}

	void AddVehicle(Vehicle* data)
	{
		if (!IsFull())
		{
			Node* temp = new Node(data);

			if (IsEmpty()) {
				front = rear = temp;
			}
			else
			{
				rear->SetNextNode(temp);
				temp->SetPrevNode(rear);
				rear = temp;
			}
		}
		else
		{
			cerr << "Error! Out of Memory. Cannot add to Queue" << endl;
		}
	}

	Vehicle* ProcessVehicle()
	{
		Vehicle* vehicleToProcess = nullptr;

		if (!IsEmpty())
		{
			if (rear == front)
			{
				rear = nullptr;
			}
			vehicleToProcess = front->GetData();
			front = front->GetNextNode();

			if (front != nullptr)
				front->SetPrevNode(nullptr);

			return vehicleToProcess;

		}
		else
		{
			cout << "No Vehicles in Queue!" << endl;
			return vehicleToProcess;
		}
	}

	int CountVehicles()
	{
		int count = 0;

		if (!IsEmpty())
		{
			Queue* tempQueue = new Queue();

			while (!IsEmpty())
			{
				tempQueue->AddVehicle(ProcessVehicle());
				count++;
			}

			while (!tempQueue->IsEmpty())
			{
				AddVehicle(tempQueue->ProcessVehicle());
			}

			return count;
		}
		else
		{
			return count;
		}
	}

	void DisplayVehicles()
	{
		if (!IsEmpty())
		{
			Queue* tempQueue = new Queue();

			while (!IsEmpty())
			{
				front->DisplayData();
				tempQueue->AddVehicle(ProcessVehicle());
				
			}

			while (!tempQueue->IsEmpty())
			{
				AddVehicle(tempQueue->ProcessVehicle());
			}
		}
		else
		{
			cout << "No Vehicles in Queue!" << endl;
		}
	}

	void DisplayFront()
	{
		if (!IsEmpty())
		{
			front->DisplayData();
		}
		else
		{
			cout << "No Vehicles in Queue!" << endl;
		}
		
	}

	void DisplayRear()
	{
		if (!IsEmpty())
		{
			rear->DisplayData();
		}
		else
		{
			cout << "No Vehicles in Queue!" << endl;
		}
	}
};