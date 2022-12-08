#ifndef ANVECTOR__ANVECTOR_H
#define ANVECTOR__ANVECTOR_H

#include<bits/stdc++.h>
using namespace std;

template<class T>
class ANVector;

template<class T>
ostream& operator << (ostream& out, ANVector<T> other);

template<class T>
class ANVector {
    T* data;
    int capacity;
    int size;
public:
    //Constructors and Big 4
    explicit ANVector(int c = 5);
    ANVector(T *arr, int n);
    ANVector(const ANVector<T>& other);
    ~ANVector();
    ANVector& operator=(const ANVector<T> &Vector){
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
    ANVector& operator=( ANVector<T> &&Vector){
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
    //Access operations
    T& operator[] (int index);
    //Modifying operations
    void push_back(T element);
    T pop_back();
    void clear();
    //Comparison operations
    bool operator ==(const ANVector<T> &other);
    bool operator <(const ANVector<T> &other);
    //Capacity operations
    int Size() const;
    int Capacity() const;
    int resize();
    bool empty();
    friend ostream& operator << (ostream& out, ANVector<T> other);


};


#endif //ANVECTOR__ANVECTOR_H
