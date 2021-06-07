#include <iostream>
using namespace std;
void print(int x){
    cout<<(x&-x)<<" ";
    if(x-(x&-x))print(x-(x&-x));
}
int main (){
    for(int i=1;i<=64;i++){
        cout<<i<<" ";
        print(i);cout<<endl;
    }
    return 0;
}