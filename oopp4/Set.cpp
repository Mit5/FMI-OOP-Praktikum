#include "Set.h"
#include<iostream>

int INITIAL_CAPACITY = 10;

Set::Set()
{
	this->capacity = INITIAL_CAPACITY;
	this->numberOfElements = 0;
	this->elements = new int[capacity];
}

void Set::copy(int const* elements, int numElements, int capacity)
{
	this->capacity = capacity;
	this->numberOfElements = numElements;

	if (this->elements != nullptr)
	{
		delete[] this->elements;
	}

	this->elements = new int[this->capacity];

	for (int i = 0; i < this->numberOfElements; i++) 
	{
		this->elements[i] = elements[i];
	}
}

Set::Set(const Set& other)
{
	copy(other.elements, other.numberOfElements, other.capacity);
}

Set::Set(Set&& other) noexcept
{
	this->elements = other.elements;
	this->capacity = other.capacity;
	this->numberOfElements = other.numberOfElements;

	other.elements = nullptr;
	other.capacity = 0;
	other.numberOfElements = 0;
}

Set& Set::operator= (Set&& other)
{
	if (this != &other)
	{
		this->elements = other.elements;
		this->capacity = other.capacity;
		this->numberOfElements = other.numberOfElements;

		other.elements = nullptr;
		other.capacity = 0;
		other.numberOfElements = 0;
	}

	return *this;
}

Set& Set::operator= (const Set& other)
{
	if (this != &other)
	{
		copy(other.elements, other.numberOfElements, other.capacity);
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
	int* copyElements = new int[this->capacity * 2];
	for (int i = 0; i < this->capacity; i++)
	{
		copyElements[i] = this->elements[i];
	}
	delete[] this->elements;
	this->elements = copyElements;
	this->capacity *= 2;
}

int Set::getNumberOfElements() const
{
	return this->numberOfElements;
}

int Set::getCapacity() const
{
	return this->capacity;
}

int* Set::getElements() const
{
	return this->elements;
}

void Set::setNumberOfElements(int numberOfElements)
{
	if (numberOfElements < 0)
	{
		numberOfElements = 0;
	}
	

}

void Set::setCapacity(int capacity)
{
	this->capacity = capacity;
}

void Set::setElements(int* elements)
{
	delete[] this->elements;
	this->elements = elements;
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

Set operator+ (const Set& first, const Set& second)
{
	Set result;
	result.setUnion(first);
	result.setUnion(second);
	return result;
}

Set& Set::operator+ (int number)
{
	for (int i = 0; i < this->numberOfElements; i++)
	{
		elements[i] += number;
	}
	return *this;
}

Set& Set::operator+= (const Set& other)
{
	*this = (*this + other);
	return *this;
}