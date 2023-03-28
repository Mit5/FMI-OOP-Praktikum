#pragma once
#include<iostream>
#include<cstring>
class String
{
private:
	char* elements;

	char* getElements() const;

	void setElements(const char* elements);

public:
	int lenght() const;

	String();

	String(const char* string);

	String(String const& string);

	String(String&& string) noexcept;

	String& operator=(const char* string);

	String& operator=(String const& string);

	String& operator=(String&& string);

	char operator[](int index) const;

	void operator+=(const String& other);

	void operator+=(const char* other);

	~String();
};

String operator+(String& firstString, String& secondString);

String operator+(const char* firstString, String& secondString);

String operator+(String& firstString, const char* secondString);

