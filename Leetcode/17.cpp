#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
class Solution {
public:
    string chartostr(char temp []){
    	string ans="";
		for(int i=0;i<strlen(temp);i++){
            //cout<<i<<endl;
			ans+=temp[i];
		} 
		return ans ;
	}
	vector<string> ans ;
	int limit_data=0;
	char temp [100001]; 
    int a[10001];
	vector<string> letterCombinations(string digits) {
		if(digits.size()==0){
            return vector<string> {};
        }
        for(int i=0;i<digits.size();i++){
            a[i]=digits[i]-'0';
        }
        limit_data=digits.size();
		dfs(0);
		return ans;
    }
    void dfs(int loc){
    	if(loc==limit_data){
    		//cout<<"setup\n";
    		ans.push_back(chartostr(temp));
			return ;
		}
		else {
            if(a[loc]<=6){
			    for(int i=0;i<3;i++){
			    	int id = (a[loc]-2)*3 + i + 'a';
				    temp[loc]=char(id);
				    dfs(loc+1); 
			    }
            }else {
                vector<char> chr[3];
                chr[0]={'p','q','r','s'};
                chr[1]={'t','u','w'};
                chr[2]={'w','x','y','z'};
                if(a[loc]==7){
                    for(int i=0;i<4;i++){
                        temp[loc]=chr[0][i];
                        dfs(loc+1);
                    }
                }else if(a[loc]==8){
                    for(int i=0;i<3;i++){
                        temp[loc]=chr[1][i];
                        dfs(loc+1);
                    }
                }else{
                    for(int i=0;i<4;i++){
                        temp[loc]=chr[2][i];
                        dfs(loc+1);
                    }
                }
            }
		}
	}
};
int main (){
	Solution test;
	string test_data; cin>>test_data;
	vector<string> ans = test.letterCombinations(test_data);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}