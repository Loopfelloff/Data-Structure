#include<iostream>
using namespace std;
#define MAX 5
class queue{
public:
int front = -1 , rear = -1;
int arr[MAX];
public:
bool isFull(){
    // return (rear + 1) % MAX == front; // myversion rear - front = MAX -1;
    return (rear - front) == MAX-1;
}
bool isEmpty(){
    return front == -1;
}
void enqueue(int val)
{
    if(isFull()) return;
    if(isEmpty()) front = 0 , rear = 0; // in my way i only had front = 0;
    /*yesma rear lai zero nagarera ani else block ma vayeko statement lai else hatayera lekhda same kaam garxa.*/
    else rear = (rear + 1) % MAX;
    arr[rear] = val;
    /*
    my version.
      ++rear;
    arr[(rear)%MAX] = val;
    * */
}
int dequeue()
{
   if(isEmpty()) return -1;
   int value = arr[front];
   if(front == rear) front = rear = -1;
    else front = (front+1) % MAX;
   return value;
   //one thing k kura yaad rakhnu vane chai if front = (front+1) % MAX chai value = arr[front] garne bittikai garyo vane chai full hune condition chai front > rear hunxa hai       
   /*
   my version.
   if(isEmpty()) return -1;
   int value = arr[(front)%MAX];
   front++;
   if(front > rear) front = -1 , rear = -1;
   return value;*/
}
int Front(){
    if(isEmpty()) return -1;
    return arr[(front%MAX)];
}
int Rear(){
    if(isEmpty()) return -1;
    return arr[(rear%MAX)];
}
};
int main()
{
    queue q;
    q.enqueue(50);
    q.enqueue(40);
    q.enqueue(30);
    q.enqueue(20);
    cout<<q.isFull()<<endl;
    q.enqueue(10);
    cout<<q.isFull()<<endl;
    cout << q.dequeue()<<endl;
    cout << q.dequeue()<<endl;
    cout<<q.isFull()<<endl;
    cout<<q.isEmpty()<<endl;
    q.enqueue(60);
    q.enqueue(70);
    cout<<q.Front()<<endl;
    cout<<q.Rear()<<endl;
    cout<<q.front<<endl;
    cout<<q.isEmpty()<<endl;
    cout << q.dequeue()<<endl;
    cout << q.dequeue()<<endl;
    cout << q.dequeue()<<endl;
    cout << q.dequeue()<<endl;
    cout << q.dequeue()<<endl;
    cout<<q.isEmpty()<<endl;
    cout<<q.isFull()<<endl;
}