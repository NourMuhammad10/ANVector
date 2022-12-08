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
private:
    T* data;
    int capacity;
    int size;
public:
    //Constructors and Big 4
    explicit ANVector(int c = 5);
    ANVector(T *arr, int n);
    ANVector(const ANVector<T>& other);
    ~ANVector();
    ANVector<T>& operator=(const ANVector<T> &Vector);
    ANVector<T>& operator=( ANVector<T> &&Vector);
    //Access operations
    T& operator[] (int index);
    //Modifying operations
    void push_back(T element);
    T pop_back();
    void clear();
    //Comparison operations
    bool operator == (const ANVector<T> &other);
    bool operator <(const ANVector<T> &other);
    //Capacity operations
    int Size() const;
    int Capacity() const;
    int resize();
    bool empty();
    friend ostream& operator << (ostream& out, ANVector<T> other);
    };


#endif //ANVECTOR__ANVECTOR_H
