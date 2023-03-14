#pragma once
class Set
{
	int* elements;
	int numberOfElements;
	int capacity;

	void resize();

public:
	Set();

	Set(Set const& other);

	Set& operator= (Set const& other);

	~Set();

	bool contains(int element) const;

	bool addElement(const int element);

	bool deleteElement(const int element);

	void print() const;

	void setUnion(Set const& other);

	void setIntersection(Set const& other);
};

