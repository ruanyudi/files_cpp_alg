#include <iostream>
#include <stdio.h>

using namespace std;
int getidx(int a,int b){
	return a*26 + b; 
}
int main (){
	for(int i=0;i<26;i++){
		for(int j=0;j<26;j++){
			cout<<getidx(i,j)<<" ";
		}
	}
}