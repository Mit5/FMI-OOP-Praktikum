#ifndef SORTED_H
#define SORTED_H

#include <iostream>

const int DEF_CAPACITY1 = 10;

template <typename T>

class Sorted
{
private:
	T* elements;
	int size;
	int capacity;

	void copy(Sorted<T>& other);
	void free();
	void move(Sorted<T>&& other);
	void resize(int capacity);

public:
	Sorted();
	Sorted(Sorted<T>& other);
	Sorted<T>& operator=(Sorted<T>& other);
	~Sorted();

	Sorted(Sorted<T>&& other);
	Sorted<T>& operator=(Sorted<T>&& other);

	void add(T& element);

	void print();
};


template<typename T>
void Sorted<T>::copy(Sorted& other)
{
	this->size = other.size;
	this->capacity = other.capacity;

	this->elements = new T[capacity];

	for (int i = 0; i < size; i++)
	{
		this->elements[i] = other.elements[i];
	}
}

template<typename T>
void Sorted<T>::free()
{
	delete[] elements;
}

template<typename T>
void Sorted<T>::move(Sorted&& other)
{
	this->elements = other.elements;
	this->size = other.size;
	this->capacity = other.capacity;
	delete other.elements;
}

template<typename T>
void Sorted<T>::resize(int capacity)
{
	if (capacity >= size)
	{
		this->capacity = capacity;
	T* newArr = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			newArr[i] = elements[i];
		}
		free();
		elements = newArr;
		delete newArr;
	}
}

template<typename T>
Sorted<T>::Sorted()
{
	size = 0;
	capacity = DEF_CAPACITY1;
	elements = new T[capacity];
}

template<typename T>
Sorted<T>::Sorted(Sorted<T>& other)
{
	copy(other);
}

template<typename T>
Sorted<T>& Sorted<T>::operator=(Sorted<T>& other)
{

	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

template<typename T>
Sorted<T>::~Sorted()
{
	free();
}

template<typename T>
Sorted<T>::Sorted(Sorted<T>&& other)
{
	move(std::move(other));
}

template<typename T>
inline Sorted<T>& Sorted<T>::operator=(Sorted<T>&& other)
{
	if (this != &other)
	{
		free();
		move(std::move(other));
	}

	return *this;
}

template<typename T>
inline void Sorted<T>::add(T& element)
{
	if (capacity <= size)
	{
		resize(capacity * 2);
	}
	int index = size;

	for (int i = 0; i < size; i++)
	{
		if (elements[i] > element)
		{
			index = i;
			break;
		}
	}

	for (int i = size; i > index; i--)
	{
		elements[i] = elements[i - 1];
	}
	elements[index] = element;
	size++;
}

template<typename T>
inline void Sorted<T>::print()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << elements[i] << " ";
	}
	std::cout << "\n";
}

#endif