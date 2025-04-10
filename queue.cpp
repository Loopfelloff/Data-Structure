#include<iostream>
using namespace std;
#define MAX 5
class queue{
public:
int front = -1 , rear = -1;
int arr[MAX];
public:
bool isFull(){
    return rear - front == MAX -1;
}
bool isEmpty(){
    return front == -1;
}
void enqueue(int val)
{
    if(isFull()) return;
    if(isEmpty()) front = 0;
    arr[++rear] = val;
}
int dequeue()
{
   if(isEmpty()) return -1;
   int value = arr[front++];
   if(front > rear) front = -1 , rear = -1;
   return value;
}
int Front(){
    if(isEmpty()) return -1;
    return arr[front];
}
int Rear(){
    if(isEmpty()) return -1;
    return arr[rear];
}
};
int main()
{
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();
    q.enqueue(60);
    cout<<q.arr[5]<<endl;
    cout<<q.rear<<endl;
    q.dequeue();
    q.enqueue(70);
    cout<<q.arr[6]<<endl;
    cout<<q.rear<<endl;
}