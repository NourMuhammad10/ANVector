#include "ANVector.h"
#include<bits/stdc++.h>
using namespace std;

/**
 * @brief constructor to initialize the vector with a given capacity and size=0
 *
 * @param c the capacity of the vector
 */
template<class T>
ANVector<T>::ANVector(int c) : capacity(c), size(0) {
	data = new T [capacity];
}
/**
 * @brief constructor to copy elements from an array to the vector
 *
 * @tparam T* the array to be copied
 * @param n the size of the array
 */
template<class T>
ANVector<T>::ANVector(T *arr, int n): size(n), capacity(n) {
	if(n<0){
		cout<<"Error, negative size array"<<endl;
		exit(-1);
	}
	data = new T[n];
	for (int i = 0; i < n; ++i) {
		data[i] = arr[i];
	}
}
/**
 * @brief destructor to free the memory allocated to the vector
 *
 */
template<class T>
ANVector<T>::~ANVector() {
	delete[] data;
}
/**
 * @brief Constructor to copy the elements of another vector
 *
 * @tparam ANVector<T> the vector to be copied
 */
template<class T>
ANVector<T>::ANVector(const ANVector<T> & other) {
	cout<<"Copy constructor"<<endl;
	capacity = other.capacity;
	size = other.size;
	data = new T[other.capacity];
	for (int i = 0; i < other.Size(); ++i) {
		data[i] = other.data[i];
	}
}
/**
 * @brief size of the vector
 *
 */
template<class T>
int ANVector<T>::Size() const {
	return size;
}
/**
 * @brief return element at a given index
 *
 * @param index the index of the element to be returned
 */
template<class d>
d &ANVector<d>::operator[](int index) {
	try {
		if (index < 0 || index >= size) {
			throw(-1);
		}
		return data[index];
	}
	catch (int e){
		cout<<"/nERROR:Index out of range"<<endl;
		exit(-1);
	}
}
/**
 *@brief print the vector
 *
 * @tparam T
 * @param out
 * @param other
 * @return
 */
template<class T>
ostream &operator<<(ostream &out, ANVector<T> &other) {
	for(int i = 0; i < other.size;i++){
		out<<other[i]<<" ";
	}
	out<<endl;
	return out;
}
/**
 * @brief check if the vector is empty
 *
 */
template<class T>
bool ANVector<T>::empty() {
	if(size == 0) {
		return true;
	}else{
		return false;
	}
}
/**
 * @brief add an element to the end of the vector
 *
 * @tparam T the element to be added
 */
template<class T>
int ANVector<T>::push_back(T element) {
	if(size < capacity){
		data[size++] = element;
	}
	else{
		capacity *= 2;
		T* newData = new T [capacity];
		for(int i =0; i<size;i++){
			newData[i] = data[i];
		}
		newData[size++] = element;
		delete[] data;
		data = newData;
	}
	return size;
}
/**
 * @brief remove the last element of the vector
 *
 */
template<class T>
T ANVector<T>::pop_back(){
	T* newData = new T [capacity];
	size--;
	for(int i=0;i<size;i++){
		newData[i]=data[i];
	}
	T lastElement=data[size];
	delete[] data;
	//copying newData in data
	data =newData;
	return lastElement;
}
/**
 * @brief clear the vector
 *
 */
template<class T>
void ANVector<T>::clear() {
	delete []data;
	size = 0;
	capacity=5;
	data=new T [capacity];
}
/**
 * @brief  compare two vectors and return true if they are equal
 * @tparam T
 * @param other
 * @return
 */
template<class T>
bool ANVector<T>::operator==(const ANVector<T> &other) {
	if(size != other.size) {
		return false;
	}
	else{
		for(int i = 0; i<other.Size();i++){
			if(data[i]!= other.data[i]){
				return false;
			}
		}
	}
	return true;
}
/**
 * @brief return vector`s capacity
 *
 */
template<class T>
int ANVector<T>::Capacity() const {
	return capacity;
}
/**
 * @brief copy the elements of another vector to the current vector
 *
 * @tparam ANVector<T> the vector to be copied
 */
template<class T>
ANVector<T>& ANVector<T>::operator=(const ANVector<T> &Vector){
	if(this != &Vector) {
		delete[] data;
		cout << "copy assignment" << endl;
		capacity = Vector.capacity;
		size = Vector.size;
		data = new T[Vector.capacity];
		for (int i = 0; i < Vector.Size(); ++i) {
			data[i] = Vector.data[i];
		}
	}
	return *this;
}
/**
 * @brief move another vector to the current vector
 *
 * @tparam ANVector<T> the vector to be moved
 */
template<class T>
ANVector<T> & ANVector<T>::operator=( ANVector<T> &&Vector){
	if(this != &Vector) {
		delete[] data;
		cout << "move assignment" << endl;
		capacity = Vector.capacity;
		size = Vector.size;
		data = new T[Vector.capacity];
		for (int i = 0; i < Vector.Size(); ++i) {
			data[i] = Vector.data[i];
		}
	}
	Vector.data= nullptr;
	Vector.size=0;
	Vector.capacity=0;
	return *this;
}
/**
 * @brief  compare two vectors and return true if the first is smaller than the second
 * @tparam T
 * @param other
 * @return
 */
template<class T>
bool ANVector<T>::operator <(const ANVector<T> &other){
	if(*this ==other)return false;
	if(size<other.size){
		for(int i=0;i<size;i++){
			if(data[i]>other.data[i])return false;
		}
		return true;
	}
	else if(other.size<size){
		return false;
	}
	else{
		for(int i=0;i<other.size;i++){
			if(data[i]>other.data[i])return false;
		}
		return true;
	}
}
/**
 * @brief resize the vector and add its capacity
 *
 */
template<class T>
int ANVector<T>::resize(){
	capacity *= 2;
	T* newData = new T [capacity];
	for(int i =0; i<size;i++){
		newData[i] = data[i];
	}
	for(int i=size;i<capacity;i++){
		newData[i]=0;
	}
	delete[] data;
	data = new T[capacity];
	for(int i=0;i<capacity;i++){
		data[i]=newData[i];
	}
	return capacity;
}
/**
 * @brief function to return the begin of the vector
 * @tparam T
 * @return
 */
template<class T>
typename ANVector<T>::iterator ANVector<T>::begin(){
	return data;
}
/**
 * @brief function to return the end of the vector
 * @tparam T 
 * @return
 */
template<class T>
typename ANVector<T>::iterator ANVector<T>::end(){
	return data+size;
}
/**
 * @brief erase the element at the given position
 *
 * @tparam iter
 */
template<class T>
void ANVector<T>::erase(iterator iter){
	try {
		if(iter-data>=size||iter-data<0) {
			throw(-1);
		}
		T *newData = new T[capacity];
		for (int i = 0; i < iter - data; i++) {
			newData[i] = data[i];
		}
		for (int i = iter - data + 1; i < size; i++) {
			newData[i - 1] = data[i];
		}
		size--;
		delete[] data;
		data = newData;
		return;
	}
	catch(int e){
		cout<<"\nERROR:iterator out of range\n";
		exit(EXIT_FAILURE);
	}
}
/**
 * @brief erase within the given range
 *
 * @param iter1,iter1
 */
template<class T>
void ANVector<T>::erase(iterator iter1, iterator iter2){
	try {
		if (iter1 - data >= size||iter2 - data >= size||iter1 - data<0||iter2 - data<0) {
			throw(-1);
		}
		T *newData = new T[capacity];
		for (int i = 0; i < iter1 - data; i++) {
			newData[i] = data[i];
		}
		for (int i = iter2 - data; i < size; i++) {
			newData[i - (iter2 - iter1)] = data[i];
		}
		size -= (iter2 - iter1);
		delete[] data;
		data = newData;
		return;
	}
	catch(int e){
		cout<<"\nERROR:iterator out of range\n";
		exit(EXIT_FAILURE);
	}
}
/**
 * @brief insert the given element at the given position
 *
 * @tparam iter,T
 */
template<class T>
void ANVector<T>::insert(ANVector::iterator iter, T element) {
    try {
        if(iter < data || iter - data >= size){
            throw(-1);
        }
        if (capacity == size) {
            capacity *= 2;
        }
        size++;
        T *newData = new T[capacity];
        for (int i = 0; i < iter - data; ++i) {
            newData[i] = data[i];
        }
        newData[iter - data] = element;
        for (int i = iter - data; i < size; i++) {
            newData[i + 1] = data[i];
        }
        delete[] data;
        data = newData;
    }
    catch(int e){
        cout<<"\nERROR:iterator out of range\n";
        exit(EXIT_FAILURE);
    }
}
