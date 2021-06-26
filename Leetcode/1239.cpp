#include <iostream>
#include <vector>
#include <limits.h>
#include <cstring>
using namespace std;
class Solution {
public:
	bool *visited = new bool [20];
	bool *mp = new bool [600];
	int ans=INT_MIN,size;
	bool temp_char[26]={};
	int getidx(int a,int b){
		return a*26 + b;
	}
	int maxLength(vector<string>& arr) {
		size=arr.size();
		for(int i=0;i<arr.size();i++){
			for(int j=0;j<arr[i].length();j++){
				if(mp[getidx(i,arr[i][j]-'a')]){
					visited[i]=true;
				}else{
					mp[getidx(i,arr[i][j]-'a')]=true;
				}
			}
		}
		/*bool *mp1 = new bool [arr.size()*26+1];
		memcpy(mp1,mp,sizeof(mp));*/
		/*for(int i=0;i<arr.size();i++){
			//cout<<i<<" : ";
			for(int j=0;j<26;j++){
				if(mp[getidx(i,j)]){
					cout<<char(j+'a');
				}
			}
			//cout<<" visited : "<<visited[i];
			//cout<<endl;
		}*/
		dfs(0,true);
		return ans;
    }
	int max(int a,int b){
		return a>b?a:b;
	}
	void dfs(int temp_ans,bool flag){
		if(!flag)return ;
		//cout<<"\ntemp_ans ："<<temp_ans<<endl;
		ans=max(ans,temp_ans);
		for(int i=0;i<size;i++){//cout<<"i : "<<i<<endl;
			if(!visited[i]){
				visited[i]=true;int count=0;bool temp_char1[26]={};
				memcpy(temp_char1,temp_char,sizeof(temp_char));
				for(int j=0;j<26;j++){
					if(mp[getidx(i,j)]){
						count++;
						if(temp_char[j]==true){
							flag=false;
						}	
						else{
							temp_char[j]=true;
						}
					}
				}
				//cout<<"count : "<<count<<" flag : "<<flag<<endl;
				dfs(temp_ans+count,flag);
				visited[i]=false;flag=true;
				memcpy(temp_char,temp_char1,sizeof(temp_char1));
			}
		}
	}
};
int main (){
	Solution test;
	vector<string> test_vct={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p"};
	cout<<test.maxLength(test_vct)<<endl;
	return 0;
}