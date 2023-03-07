#pragma once
class Set
{
	int* elements;
	int numberOfElements;
	int capacity;

	void resize();

	bool contains(int element);

public:
	Set();

	Set(Set const& other);

	Set& operator= (Set const& other);

	~Set();

	bool addElement(const int element);

	bool deleteElement(const int element);

	void print();

	void setUnion(const Set other);

	void setIntersection(const Set other);
};

