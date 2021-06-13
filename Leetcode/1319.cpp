#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int nums=0;int union_count=0;
	int *boss;int cnt=0;//代表可以使用的线的个数
	void load(){
		boss =new int [nums+1];
		for(int i=0;i<nums;i++){
			boss[i]=i;
		}
	}
	int find(int x){
		return x==boss[x]?x:find(boss[x]);
	}
	void add(int a,int b){
		if(find(a)==find(b)){
			cnt++;
		}
		else{
			boss[find(b)]=find(a);union_count--;
		}
	}
    int makeConnected(int n, vector<vector<int>>& connections) {
		nums=n;load();union_count=nums;
		for(int i=0;i<connections.size();i++){
			add(connections[i][0],connections[i][1]);
		}
		if(cnt<union_count-1){
			return -1;
		}
		else{
			return union_count-1;
		}
    }
};

int main (){
	vector<vector<int> > vtest={{0,1},{0,2},{0,3},{1,2}};
	Solution test;int n;cin>>n;
	cout<<test.makeConnected(n,vtest);
	return 0;
}