#include <iostream>
#include <utility>
using namespace std;



pair<int,int> make_p(){
    return {1,2};
}


int main (){
    auto tmp=make_p();
    cout<<tmp.first;cout<<endl<<tmp.second<<endl;
    return 0;
}