#include"ANVector.cpp"
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    ANVector<int> obj(arr, 5);
//    cout<<obj; //complete operator of cout
    ANVector<int> obj2(7);
    cout<<obj[1]<<endl;
    cout<<obj2.empty()<<endl;
    obj.push_back(6);
    cout<<obj.Size()<<endl;
    cout<<obj[5]<<endl;
    ANVector<int> obj3(obj);
    cout<<obj3[3]<<endl;
//    vector<int> vec = {1,2,4};
//    vec.insert(vec.begin()+2,3);
//    for(int i = 0; i < vec.size();i++){
//        cout<<vec[i]<<" ";
//    } //How insert works on regular vector
	if(obj == obj3){
	    cout<<"Equal"<<endl;
	}

	ANVector<int> obj4(arr, 5);
	ANVector<int> obj5(7);
	obj5=obj4;
	obj5=move(obj4);
	obj5=ANVector<int>(arr,5);


}