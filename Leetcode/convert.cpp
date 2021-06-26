#include <iostream>
using namespace std;
string x;
int main (){
	cin>> x;
	for(int i=0;i<x.length();i++){
		if(x[i]=='['){
			cout<<"{";
		}else if(x[i]==']'){
			cout<<"}";
		}else{
			cout<<x[i];
		}
	}cout<<endl;
	return 0;
}