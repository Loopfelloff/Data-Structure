#include<iostream>
#include "linkedlist.cpp"
class stack{
public:
List *myList = new List();
bool isEmpty(){
    myList->isEmpty();
}
void push(int n)
{
    myList->addToHead(n);
}
int pop()
{
    if(isEmpty()) return -1;
    int val = myList->Head->info;
    myList->removeFromHead();
    return val;
}
int top(){
    return myList->Head->info;
}
};
int main(){
    stack st;
    cout<<st.isEmpty()<<endl;
    st.push(1);
    st.push(4);
    st.push(3);
    st.push(2);
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.isEmpty()<<endl;
    cout<<st.pop()<<endl;
    return 0;
}