#include "VendingMachine.h"

int ID = 0;

void Inventory::changeSalty(int quantity)
{
	if (quantity < 0)
	{
		quantity = 0;
	}

	this->salty = quantity;
}

void Inventory::changeSweets(int quantity)
{
	if (quantity < 0)
	{
		quantity = 0;
	}

	this->sweet = quantity;
}

void Inventory::changeDrinks(int quantity)
{
	if (quantity < 0)
	{
		quantity = 0;
	}

	this->drinks = quantity;
}

void Inventory::print()
{
	std::cout << "Salty: " << salty << "\nSweet: " << sweet << "\nDrinks: " << drinks;
}

int VendingMachine::getId()
{
	return this->id;
}

VendingMachine::VendingMachine()
{
	id = ID++;
	address = '\0';
	inventory;
	numWarningMsgs = 0;
	capacity = 10;
	warningMessages = new char* [capacity];
}

VendingMachine::VendingMachine(char* address, Inventory inventory)
{
	id = ID++;
	delete[]this->address;
	this->address = address;
	this->inventory = inventory;
	numWarningMsgs = 0;
	capacity = 10;
	warningMessages = new char* [capacity];
}

VendingMachine::VendingMachine(VendingMachine const& other)
{
	this->id = ID++;
	std::strcpy(this->address, other.address);
	this->inventory = other.inventory;
	this->warningMessages = new char* [other.numWarningMsgs];
	for (int i = 0; i < other.numWarningMsgs; i++)
	{
		this->warningMessages[i] = new char[strlen(other.warningMessages[i])];
		strcpy(this->warningMessages[i], other.warningMessages[i]);
	}
	this->numWarningMsgs = other.numWarningMsgs;
	this->capacity = other.capacity;
}

VendingMachine::VendingMachine(VendingMachine&& other)
{
	this->id = other.id;
	std::strcpy(this->address, other.address);
	this->inventory = other.inventory;
	for (int i = 0; i < other.numWarningMsgs; i++)
	{
		strcpy(this->warningMessages[i], other.warningMessages[i]);
	}
	this->numWarningMsgs = other.numWarningMsgs;
	this->capacity = other.capacity;

	other.id = -1;
	delete[] other.address;
	delete[] other.warningMessages;
	numWarningMsgs = 0;
	capacity = 0;
}

VendingMachine& VendingMachine::operator=(VendingMachine const& other)
{
	if (this != &other)
	{
		std::strcpy(this->address, other.address);
		this->inventory = other.inventory;
		for (int i = 0; i < other.numWarningMsgs; i++)
		{
			strcpy(this->warningMessages[i], other.warningMessages[i]);
		}
		this->numWarningMsgs = other.numWarningMsgs;
		this->capacity = other.capacity;
	}

	return *this;
}

VendingMachine::~VendingMachine()
{
	delete[] address;
	delete[] warningMessages;
}
