#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template<typename T> 
class Stack{
private:
    vector<T> rhs;
public:
    Stack(){}
    void push(T x){
        rhs.push_back(x);
        return ;
    }
    void pop(){
        if(isEmpty())return ;
        rhs.pop_back();
    }
    bool isEmpty(){
        return rhs.size()==0;
    }
    int size(){
        return rhs.size();
    }
};
int main (){
    Stack<int> test;
    test.push(1);
    cout<<"After push 1 the stack size is :"<< test.size()<< endl ;
    test.pop();
    cout<<"After test.pop() the stack size is :"<< test.size()<<endl ;
    return 0;
}