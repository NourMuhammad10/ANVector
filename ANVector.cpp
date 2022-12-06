#include "ANVector.h"
#include<bits/stdc++.h>
using namespace std;

template<typename T> ANVector<T>::ANVector(int c): capacity(c), size(0){
    data = new T [capacity];
}
template<typename T> ANVector<T>::ANVector(T arr[], int n) {
    if(n<0){
        cout<<"Error, negative size array"<<endl;
    }
    capacity = n;
    size = n;
    data = new T[n];
    for (int i = 0; i < n; ++i) {
        data[i] = arr[i];
    }
}
template<typename T> ANVector<T>::~ANVector() {
    delete data;
}
template<typename T> ANVector<T>::ANVector(const ANVector<T> & other) {
    capacity = other.capacity;
    size = other.size;
    data = new T[other.size];
    for (int i = 0; i < other.size(); ++i) {
        data[i] = other.data[i];
    }
}