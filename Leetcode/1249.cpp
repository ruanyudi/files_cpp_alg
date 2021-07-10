#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;
class Solution {
public:
    string minRemoveToMakeValid(string s) {
		char * ans_temp = new char [s.size() + 1 ];
		char * ans = new char [s.size() + 1 ];
		int cnt=0;int len =0 ; 
		for(int i=0;i<s.length();i++){
			if(s[i]==')'){
				if(cnt==0)continue;
				cnt -- ;
				ans_temp[len++]=s[i];
			}else{
				ans_temp[len++]=s[i];
				cnt+=(s[i]=='(');
			}
		}cnt = 0 ;ans[len]='\0';cout<<"ans_temp: "<<ans_temp<<endl;
		for(int i=len-1;i>=0;i--){
			if(ans_temp[i]=='('){
				if(cnt==0)continue;
				cnt--;
				ans[--len]=ans_temp[i];
			}else {
				cnt+=(s[i]==')');
				ans[--len]=ans_temp[i];
			}
		}
		return string(ans+len);
    }
};
int main (){
	Solution test;
	string test_data="))((";
	cout<<test.minRemoveToMakeValid(test_data);
	return 0;
}