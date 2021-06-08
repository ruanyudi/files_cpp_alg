#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <limits.h>
using namespace std;


class Solution {
public:
    int calculate_s(string s,int l,int r) {
        int p=-1;int maxn=INT_MIN;//记录当前的最小优先级
        int nums=0;//记录括号的个数
        //接下来这里最重要的是找出优先级最低的符号
        for(int i=l;i<=r;i++){
            //这一题是没有括号的  我写一个有括号的版本
            //+ - 的优先级是2 * /的优先级是1 括号的优先级是100
            if(s[i]=='('){
                nums++;//当前括号加一
            }
            else if(s[i]==')'){
                nums--;
            }
            else if (s[i]=='+'){
                if(nums*100+2>maxn){
                    maxn=nums*100+1;
                    p=i;
                }
            }
            else if (s[i]=='-'){
                if(nums*100+2>maxn){
                    maxn=nums*100+1;
                    p=i;
                }
            }
            else if (s[i]=='*'){
                if(nums*100+1>maxn){
                    maxn=nums*100+2;
                    p=i;
                }
            }
            else if(s[i]=='/'){
                if(nums*100+1>maxn){
                    maxn=nums*100+2;
                    p=i;
                }
            }
        }
        if(p==-1){
            //说明当前的是l到r是数字
            int ans =0 ;
            for(int i=l;i<=r;i++){
                if(s[i]>='0'&&s[i]<='9'){
                    ans=ans*10+(int)(s[i]-'0');
                }
            }
            return ans;
        }
        int a=calculate_s(s,l,p-1);
        int b=calculate_s(s,p+1,r);
        if(s[p]=='/'){
            return a/b;
        }
        else if (s[p]=='*'){
            return a*b;
        }
        else if (s[p]=='+'){
            return a+b;
        }
        else if(s[p]=='-'){
            return a-b;
        }
    }
};

int main (){
    Solution test;
    string test_data="3+2*2*2";
    cout<<test_data<<"="<<test.calculate_s(test_data,0,test_data.size()-1);
    return 0;
}