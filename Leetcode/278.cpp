#include <iostream>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

long long global=0;
bool isBadVersion(long long x){
	return x>=global;
}

class Solution {
public:
    int firstBadVersion(long long n) {
        long long l=1,r=n;
	while(l<r){
		long long mid=l+(r-l)/2;
		if(!isBadVersion(mid)){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	return l ;
    }
};

int main (){
	int n;cin>>n>>global;
	Solution test;
	cout << test.firstBadVersion(n);
	return 0;
}