#include "ANVector.h"
#include<bits/stdc++.h>
using namespace std;

template<class T>
ANVector<T>::ANVector(int c) : capacity(c), size(0) {
    data = new T [capacity];
}

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

template<class T>
ANVector<T>::~ANVector() {
    delete[] data;
}
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
template<class T>
int ANVector<T>::Size() const {
    return size;
}
template<class T>
T &ANVector<T>::operator[](int index) {
    if(index < 0 || index>= size){
        cout<<"An error has occurred, index out of range"<<endl;
        exit(-1);
    }
    return data[index];
}

template<class T>
ostream &operator<<(ostream &out, ANVector<T> other) {
    for(int i = 0; i < other.size();i++){
        out<<other[i]<<" ";
    }
    out<<endl;
    return out;
}
template<class T>
bool ANVector<T>::empty() {
    if(size = 0) {
        return true;
    }else{
        return false;
    }
}

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
	data = new T [capacity];
	for(int i=0;i<size;i++){
		newData[i]=data[i];
	}
	return lastElement;
}
template<class T>
void ANVector<T>::clear() {
	delete []data;
	size = 0;
	capacity=5;
	data=new T [capacity];
}

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

template<class T>
int ANVector<T>::Capacity() const {
    return capacity;
}

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
