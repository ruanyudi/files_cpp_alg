#include <string>
#include <iostream>
using namespace std;
int main (){
	string test;
	cin>>test;
	for(int i=0;i<test.length();i++){
		if(test[i]=='['){
			cout<<'{';
		}
		else if(test[i]==']'){
			cout<<'}';
		}
		else{
			cout<<test[i];
		}
	}
	return 0;
}