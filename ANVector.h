#ifndef ANVECTOR__ANVECTOR_H
#define ANVECTOR__ANVECTOR_H

#include<bits/stdc++.h>
using namespace std;
template<class T>
class ANVector {
T* data;
int capacity;
int size;
public:
ANVector(int c = 5);
ANVector(T arr[], int n);
ANVector(const ANVector<T>& other);
~ANVector();

};


#endif //ANVECTOR__ANVECTOR_H
