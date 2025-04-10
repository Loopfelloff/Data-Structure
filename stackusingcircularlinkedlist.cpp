#include<iostream>
#include "linkedlist.cpp"
using namespace std;
class Stack{
public:
Node* stack = nullptr;
void push(int n){
Node* tempNode = new Node();
tempNode->info = n;
if(stack == nullptr) stack = tempNode;
else{
    tempNode->next = stack->next;
}
stack->next = tempNode;
}
int pop()
{
    if(stack == nullptr) return -1;
    int val = stack->next->info;
    Node* tempNode = stack->next;
    if(stack == tempNode)
    {
        stack == nullptr;
        return val;
    }
    stack->next = tempNode->next;
    delete tempNode;
    tempNode = nullptr;

    return val;
}
int top(){
    int val = stack->next->info;
}
};
int main(){
    Stack s;
    s.push(5);
    cout<<s.pop();
    s.push(6);
    s.push(7);
    cout<<s.pop();
    return 0;
}