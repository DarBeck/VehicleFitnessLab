#pragma once

#include "Vehicle.h"

class Node
{
private:
	Vehicle* data;
	Node* prevNode;
	Node* nextNode;

public:
	Node() 
	{
		data = nullptr;
		prevNode = nullptr;
		nextNode = nullptr;
	}

	Node(Vehicle* inData)
	{
		data = inData;
		prevNode = nullptr;
		nextNode = nullptr;
	}

	Node(Vehicle* inData, Node* inPrevNode, Node* inNextNode)
	{
		data = inData;
		prevNode = inPrevNode;
		nextNode = inNextNode;
	}

	Node* GetPrevNode()
	{
		return prevNode;
	}

	void SetPrevNode(Node* inPrevNode)
	{
		prevNode = inPrevNode;
	}

	Node* GetNextNode()
	{
		return nextNode;
	}

	void SetNextNode(Node* inNextNode)
	{
		nextNode = inNextNode;
	}

	Vehicle* GetData()
	{
		return data;
	}

	void SetData(Vehicle* inData)
	{
		data = inData;
	}

	void DisplayData()
	{
		data->DisplayVehicle();
	}
};