#pragma once
#include<iostream>
template <typename T>

class MyVector
{
private:
	T* elements;
	int size;
	int capacity;

	void resize();

	void copy(MyVector& other);
	void move(MyVector&& other);
	void free();

public:
	MyVector();
	MyVector(MyVector& other);
	MyVector<T>& operator=(MyVector& other);
	~MyVector();

	MyVector(MyVector&& other);
	MyVector<T>& operator=(MyVector&& other);

	void addElement(T element);

	T operator[](int index);
	template <typename R>
	void apply(R(*func) (T&));
};

template<typename T>
inline void MyVector<T>::resize()
{
	T* newElements = new T[capacity * 2];
	for (int i = 0; i < size; i++)
	{
		newElements[i] = elements[i];
	}
	delete[] elements;
	elements = newElements;
	capacity *= 2;
}

template<typename T>
inline void MyVector<T>::copy(MyVector& other)
{
	size = other.size;
	capacity = other.capacity;
	elements = new T[capacity];
	for (int i = 0; i < size; i++)
	{
		elements[i] = other.elements[i];
	}
}

template<typename T>
inline void MyVector<T>::move(MyVector&& other)
{
	elements = other.elements;
	size = other.size;
	capacity = other.capacity;
	other.elements = nullptr;
	other.size = 0;
	other.capacity = 0;
}

template<typename T>
inline void MyVector<T>::free()
{
	delete[] elements;
}

template<typename T>
inline MyVector<T>::MyVector()
{
	capacity = 10;
	size = 0;
	elements = new T[capacity];
}

template<typename T>
inline MyVector<T>::MyVector(MyVector& other)
{
	copy(other);
}

template<typename T>
inline MyVector<T>& MyVector<T>::operator=(MyVector& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

template<typename T>
inline MyVector<T>::~MyVector()
{
	free();
}

template<typename T>
inline MyVector<T>::MyVector(MyVector&& other)
{
	move(std::move(other));
}

template<typename T>
inline MyVector<T>& MyVector<T>::operator=(MyVector&& other)
{
	if (this != &other)
	{
		free();
		move(std::move(other));
	}

	return *this;
}


template<typename T>
inline void MyVector<T>::addElement(T element)
{
	if (size == capacity)
	{
		resize();
	}

	elements[size] = element;
	size++;
}

template<typename T>
inline T MyVector<T>::operator[](int index)
{
	return elements[index];
}

template<typename T>
template<typename R>
inline void MyVector<T>::apply(R(*func)(T&))
{
	for (int i = 0; i < size; i++)
	{
		func(elements[i]);
	}
}
