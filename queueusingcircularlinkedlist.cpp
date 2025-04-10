// here you can see me using stack instead of queue , the operation are the same as queue but i didn't bother changign pop to dequeue and push to enqueue and stack to queue but it does follow FIFO order.
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
stack = tempNode; // this is the only differnece between stack and queue and circular linkedlist.cpp
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
    s.push(3);
    s.push(2);
    s.push(5);
    s.push(4);
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    return 0;
}