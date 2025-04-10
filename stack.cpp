#include<iostream>
using namespace std;
#define MAX 5
class Stack{
private:
int top = - 1;
int stack[MAX];
public:
bool isEmpty(){
    return top == -1;
}
bool isFull(){
    return top == MAX-1;
}
int Top(){
    if(isEmpty()) return -1;
    else return stack[top];
}
void Push(int val){
    if(isFull()) cout << "Stack overflow" << endl;
    else stack[++top] = val;
}
int Pop()
{
    if(isEmpty()) return -1;
    else return stack[top--];
}

};
