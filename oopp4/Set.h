#pragma once
class Set
{
	int* elements;
	int numberOfElements;
	int capacity;

	void resize();

public:

	int getNumberOfElements() const;

	int getCapacity() const;

	int* getElements() const;

	void setNumberOfElements(int numberOfElements);

	void setCapacity(int capacity);

	void setElements(int* elements);

	Set();

	Set(const Set& other);

	Set(Set&& other) noexcept;

	Set& operator+ (int number);

	Set& operator= (const Set& other);

	Set& operator= (Set&& other);

	Set& operator+= (const Set& other);

	~Set();

	void copy(int const* elements, int numElements, int capacity);

	bool contains(int element) const;

	bool addElement(const int element);

	bool deleteElement(const int element);

	void print() const;

	void setUnion(Set const& other);

	void setIntersection(Set const& other);
};

Set operator+ (const Set& first, const Set& second);

