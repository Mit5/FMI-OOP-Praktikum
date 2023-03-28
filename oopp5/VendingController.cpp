#include "VendingController.h"

void VendingController::resize()
{
	this->capacity *= 2;
	VendingMachine* newMachinesList = new VendingMachine[capacity];
	for (int i = 0; i < this->numMachines; i++)
	{
		newMachinesList[i] = vendingMachineList[i];
	}
	delete[] this->vendingMachineList;
	this->vendingMachineList = newMachinesList;
}

void VendingController::addVendingMachine(VendingMachine machine)
{
	for (int i = 0; i < this->numMachines; i++)
	{
		if (vendingMachineList[i].getId() == machine.getId())
		{
			return;
		}
	}

	if (this->numMachines = this->capacity)
	{
		this->resize();
	}

	this->vendingMachineList[numMachines] = machine;
	numMachines++;
}
