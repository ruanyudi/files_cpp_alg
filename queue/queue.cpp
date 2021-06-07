#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node *next,*pre;
    Node(int val=0,Node *next=nullptr):val(val),next(next){}
    void insert_next(Node *p){
        p->pre=this;
        p->next=this->next;
        if(this->next){
            this->next->pre=p;
        }
        this->next=p;
        return ;
    }
    void insert_pre(Node *p){
        p->pre=this->pre;
        p->next=this;
        if(this->pre){
            this->pre->next=p;
        }
        this->pre=p;
        return ;
    }
    void delete_next(){
        Node *p=this->next;
        this->next=p->next;
        if(p->next)p->next->pre=this;
        delete p;
        return ;
    }
    void delete_pre(){
        Node *p=this->pre;
        this->pre=p->pre;
        if(p->pre)p->pre->next=p;
        delete p;
        return ;
    }
};

class Queue{
private:
    Node head,tail;int cnt;
public:
    Queue():cnt(0){
        head.pre=nullptr;
        tail.next=nullptr;
        head.next=&tail;
        tail.pre=&head;
    }
    void push_front(int x){
        cnt++;head.insert_next(new Node (x));
        return ;
    }
    void push_back(int x){
        cnt++;tail.insert_pre(new Node (x));
        return ;
    }
    void pop_front(){
        if(isEmpty())return ;
        cnt--;head.delete_next();
        return ;
    }
    void pop_back(){
        if(isEmpty())return ;
        cnt--;tail.delete_pre();
        return ;
    }
    bool isEmpty(){
        return head.next==&tail;
    }
    int size(){
        return cnt;
    }
    void print(){
        Node *p=&head;
        while(p->next!=&tail){
            p=p->next;
            cout<<p->val;
            if(p->next!=&tail)cout<<"->";
        }
        return ;
    }
};
int main (){
    Queue test;
    for(int i=1;i<=100;i++)test.push_back(i);
    cout<<"The Dqueue which is auto-make by system is : \n";
    test.print();
    return 0;
}