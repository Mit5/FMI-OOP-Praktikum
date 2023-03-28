#include "String.h"

char* String::getElements() const
{
	char* copy = new char[strlen(elements)];
	strcpy(copy, elements);
	return copy;
}

void String::setElements(const char* elements)
{
	delete[] this->elements;
	char* copy = new char[strlen(elements)];
	strcpy(copy, elements);
	this->elements = copy;
}

int String::lenght() const
{
	return strlen(elements);
}

String::String()
{
	elements = new char[1];
	*elements = '\0';
}

String::String(const char* string)
{
	elements = new char[strlen(string)];
	char* copy = new char[strlen(string)];
	strcpy(copy, string);
	elements = copy;
}

String::String(String const& string)
{
	elements = new char[string.lenght()];
	char* copy = new char[string.lenght()];
	strcpy(copy, string.getElements());
	elements = copy;
}

String& String::operator=(const char* string)
{
	delete[] elements;

	elements = new char[strlen(string)];
	char* copy = new char[strlen(string)];
	strcpy(copy, string);
	elements = copy;

	return *this;
}

String& String::operator=(String const& string)
{
	if (this != &string)
	{
		delete[] elements;
		elements = new char[string.lenght()];
		char* copy = new char[string.lenght()];
		strcpy(copy, string.getElements());
		elements = copy;
	}

	return *this;
}

String& String::operator=(String&& string) noexcept
{
	elements = new char[string.lenght()];
	char* copy = new char[string.lenght()];
	strcpy(copy, string.getElements());
	elements = copy;
	delete[] string.elements;
}

char String::operator[](int index) const
{
	char* copy = new char[this->lenght()];
	strcpy(copy, elements);
	int counter = 0;
	while (*copy)
	{
		if (index == counter)
		{
			return *copy;
		}
		copy++;
	}

	throw std::runtime_error("Index out of range!");
}

void String::operator+=(const String& other)
{
	char* copy = new char[this->lenght()];
	strcpy(copy, this->getElements());

}

String::String(String&& string) noexcept
{
	elements = new char[strlen(string.getElements())];
	char* copy = new char[strlen(string.getElements())];
	strcpy(copy, string.getElements());
	elements = copy;
	delete[] string.elements;
}

String::~String()
{
	delete[] elements;
}

String operator+(String& firstString, String& secondString)
{
	int firstLenght = firstString.lenght(), secondLenght = secondString.lenght();
	char* resultElements = new char[firstLenght + secondLenght];
	for (int i = 0; i < firstLenght; i++)
	{
		*resultElements = firstString[i];
		resultElements++;
	}
	for (int i = 0; i < secondLenght; i++)
	{
		*resultElements = secondString[i];
		resultElements++;
	}
	resultElements -= firstLenght + secondLenght;
	
	String result(resultElements);

	return result;
}

String operator+(const char* firstString, String& secondString)
{
	int firstLenght = strlen(firstString), secondLenght = secondString.lenght();
	char* resultElements = new char[firstLenght + secondLenght];
	for (int i = 0; i < firstLenght; i++)
	{
		*resultElements = firstString[i];
		resultElements++;
	}
	for (int i = 0; i < secondLenght; i++)
	{
		*resultElements = secondString[i];
		resultElements++;
	}
	resultElements -= firstLenght + secondLenght;

	String result(resultElements);

	return result;
}

String operator+(String& firstString, const char* secondString)
{
	int firstLenght = firstString.lenght(), secondLenght = strlen(secondString);
	char* resultElements = new char[firstLenght + secondLenght];
	for (int i = 0; i < firstLenght; i++)
	{
		*resultElements = firstString[i];
		resultElements++;
	}
	for (int i = 0; i < secondLenght; i++)
	{
		*resultElements = secondString[i];
		resultElements++;
	}
	resultElements -= firstLenght + secondLenght;

	String result(resultElements);

	return result;
}
