#include"ANVector.cpp"
#include<bits/stdc++.h>
using namespace std;

int main(){
	int arr[] = {1, 2, 3, 4, 5};
	ANVector<int> obj(arr, 5);
	cout<<obj; //complete operator of cout
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

	if(obj < obj3){//false
		cout<<"true"<<endl;
	}else cout<<"false\n";    //because they are equal

	obj.push_back(5);
	if(obj < obj3){//false
		cout<<"true"<<endl;
	}else cout<<"false\n";

	if(obj3 < obj){//true
		cout<<"true"<<endl;
	}else cout<<"false\n";

	obj3.push_back(6);

	if(obj < obj3){//true
		cout<<"true"<<endl;
	}else cout<<"false\n";

	if(obj3 < obj){//false
		cout<<"true"<<endl;
	}else cout<<"false\n";

	ANVector<int> obj4(arr, 5);
	for(int i=0;i<obj4.Size();i++){
		cout<<obj4[i]<<' ';
	}cout<<'\n';
	obj4.pop_back();
	obj4.pop_back();
	for(int i=0;i<obj4.Size();i++){
		cout<<obj4[i]<<' ';
	}cout<<'\n';

	ANVector<int> obj5(7);
	obj5=obj4;
	obj5=move(obj4);
	obj5=ANVector<int>(arr,5);

//	cout<<obj[7]; //Testing access operator
	int a1[]={5,6,7,8,9,10};
	int a2[]={11,12,13,14,15,16};
	ANVector<int> asmaa(a1,6);
	ANVector<int> asma(a2,6);
	asmaa.erase(asmaa.begin()+2);
	cout<<asmaa<<endl;

	asma.erase(asma.begin(),asma.begin()+3);
	cout<<asma;
}