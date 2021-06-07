#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    int ans=0;
    int findTargetSumWays(vector<int>& nums, int target) {
        bfs(nums,target,0,0);
        return ans;
    }
    int bfs(vector<int> nums,int target,int index,int sum){
        if(index==nums.size()){
            if(target==sum){
                ans++;  
            }
        }
        else{
            bfs(nums,target,index+1,sum+nums[index]);
            bfs(nums,target,index+1,sum-nums[index]);
        }
    }
};

int main (){
    Solution test;
    int target=1;
    vector<int> test_v={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
    clock_t start=clock();
    cout<<test.findTargetSumWays(test_v,target)<<endl;
    clock_t end=clock();
    cout<<"system time :"<<(double)(end-start)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
    return 0;
}