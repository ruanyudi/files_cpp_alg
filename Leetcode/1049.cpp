#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0;if(stones.size()==0)return 0;
        for(int i=0;i<stones.size();i++)sum+=stones[i];
        vector<int> dp (sum/2);dp[0]=true;
        for(auto weight : stones){
            for(int j=sum/2;j>=weight;j--){
                dp[j]=dp[j]||dp[j-weight];
            }
        }
        for(int i=sum/2;i>=0;i--){
            if(dp[i]){
                return sum-2*i;
            }
        }
    }
};

int main (){
    Solution test;
    vector<int> tmp={2,7,4,1,8,1};
    cout<<test.lastStoneWeightII(tmp);
    return 0;
}