#include "Set.h"
#include<iostream>

Set::Set()
{
	this->capacity = 2;
	this->numberOfElements = 0;
	this->elements = new int[capacity];
}

Set::Set(Set const& other)
{
	this->capacity = other.capacity;
	this->numberOfElements = other.numberOfElements;
	delete[] this->elements;
	this->elements = other.elements;
}

Set& Set::operator= (Set const& other)
{
	if (this != &other)
	{
		this->capacity = other.capacity;
		this->numberOfElements = other.numberOfElements;
		delete[] this->elements;
		this->elements = other.elements;
		delete[] other.elements;
	}
	return *this;
}

Set::~Set()
{
	delete[] elements;
}

bool Set::contains(int element) const
{
	for (int i = 0; i < this->numberOfElements; i++)
	{
		if (this->elements[i] == element)
		{
			return true;
		}
	}
	return false;
}

void Set::resize()
{
	int* copyElements = new int[this->capacity*2];
	for (int i = 0; i < this->capacity; i++)
	{
		copyElements[i] = this->elements[i];
	}
	delete[] this->elements;
	this->elements = copyElements;
	this->capacity *= 2;
}

bool Set::addElement(const int element)
{
	if (this->numberOfElements == capacity)
	{
		this->resize();
	}

	for (int i = 0; i < this->numberOfElements; i++)
	{
		if (this->elements[i] == element)
		{
			return false;
		}
	}
	
	this->elements[this->numberOfElements] = element;
	this->numberOfElements++;
	return true;
}

bool Set::deleteElement(const int element)
{
	bool hasDeleted = 0;
	int indexOfElement = -1;
	for (int i = 0; i < this->numberOfElements; i++)
	{
		if (this->elements[i] == element)
		{
			hasDeleted = 1;
			indexOfElement = i;
			break;
		}
	}
	if (hasDeleted)
	{
		this->numberOfElements--;
		for (int i = indexOfElement; i < this->numberOfElements; i++)
		{
			this->elements[i] = this->elements[i + 1];
		}
	}
	return hasDeleted;
}

void Set::print() const
{
	for (int i = 0; i < this->numberOfElements; i++)
	{
		std::cout << this->elements[i] << " ";
	}
	std::cout << "\n";
}

void Set::setUnion(Set const& other)
{
	for (int i = 0; i < other.numberOfElements; i++)
	{
		this->addElement(other.elements[i]);
	}
}

void Set::setIntersection(Set const& other)
{
	for (int i = 0; i < this->numberOfElements; i++)
	{
		if (!other.contains(this->elements[i]))
		{
			this->deleteElement(this->elements[i]);
			i--;
		}
	}
}