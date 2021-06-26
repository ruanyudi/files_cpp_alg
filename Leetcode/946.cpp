#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int> temp;int count =0 ; 
		for(int i=0;i<popped.size();i++){
			while((temp.empty()||popped[i]!=temp.top())&&count<pushed.size()){
				temp.push(pushed[count]);count++;
			}
			if(temp.top()!=popped[i])return false;
			temp.pop();
		}
		return true;
    }
};
int main (){
	vector<int> pushed ={1,2,3,4,5};
	vector<int> popped ={4,5,3,2,1};
	Solution test;
	if(test.validateStackSequences(pushed,popped))cout<<"true"<<endl;
	else cout<<"false"<<endl;
	return 0;
}