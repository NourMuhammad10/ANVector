#ifndef ANVECTOR__ANVECTOR_H
#define ANVECTOR__ANVECTOR_H

#include<bits/stdc++.h>
using namespace std;

template<class T>
class ANVector;

template<class T>
ostream& operator << (ostream& out, ANVector<T> &other);

template<class T>
class ANVector {
	T* data;
	int capacity;
	int size;
public:
	using iterator = T*;
	//Constructors and Big 4
	explicit ANVector(int c = 5);
	ANVector(T *arr, int n);
	ANVector(const ANVector<T>& other);
	~ANVector();
	ANVector &operator=(const ANVector& Vector);
	ANVector &operator=(ANVector&& Vector);
	//Access operations
	T& operator[] (int index);
	//Modifying operations
	int push_back(T element);
	T pop_back();
	void clear();
    void erase(iterator iter);
    void erase(iterator iter1, iterator iter2);
    void insert(iterator iter, T element);
    //Comparison operations
	bool operator ==(const ANVector<T> &other);
	bool operator <(const ANVector<T> &other);
	//Capacity operations
	int Size() const;
	int Capacity() const;
	int resize();
	bool empty();
    //Iterators
    iterator begin();
    iterator end();
    //Friend functions
	friend ostream& operator << <T> (ostream& out, ANVector<T>& other);
};





#endif //ANVECTOR__ANVECTOR_H
