
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;

template <class T>
class Array {
	template <class U>
	friend ostream& operator<<(ostream& ost, Array<U>&);

	public:
		//constructor
		Array();

		//destructor
		~Array();

		T& operator[](int index);
		T& operator[](int index) const;
		Array<T>& operator+=(T& elem);
		Array<T>& operator-=(T& elem);

		//other
		void add(T& t);
		int get(int index) const;
		int getSize() const;
		bool isFull() const;
		void clear();

	private:
		int size;
		T* elements;

};
template <class U>
ostream& operator<<(ostream& ost, Array<U>& arr){
	ost<<"Array: "<<endl;
	for(int i=0;i<arr.size;i++){
		ost<<"\t"<<arr.elements[i];
	}
	return ost;
}

template <class T>
Array<T>::Array(){
	elements = new T[MAX_ARRAY];
	size = 0;
}

template <class T>
Array<T>::~Array(){
	delete[] elements;
}

template <class T>
T& Array<T>::operator[](int index){
	if(index < 0 || index >= size){
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	else{
		return elements[index];
	}
}

template <class T>
T& Array<T>::operator[](int index) const{
	if(index < 0 || index >= size){
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	else{
		return elements[index];
	}
}

template <class T>
Array<T>& Array<T>::operator+=(T& elem){
	if(this->isFull()) return *this;
	else{
		elements[size++] = elem;
		return *this;
	}
}

template <class T>
Array<T>& Array<T>::operator-=(T& elem){
	for(int i=0;i<size;i++){
		if(elem == elements[i]){
			for(int j=i;j<size-1;j++){
				elements[j] = elements[j+1];
			}
			elements[size-1] == NULL;
			size -= 1;
			return *this;
		}
	}
	return *this;
}

template <class T>
void Array<T>::add(T& t){
	*this += t;
}

template <class T>
int Array<T>::getSize() const{
	return size;
}

template <class T>
bool Array<T>::isFull() const{
	return size >= MAX_ARRAY;
}

/*int Array::get(int index){
	if (index < 0 || index >= size) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}*/

template <class T>
void Array<T>::clear(){
	for(int i=0;i<size;i++){
		elements[i] = NULL;
	}
	size = 0;
}

#endif
