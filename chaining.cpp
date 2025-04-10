#include<iostream>
using namespace std;

class Node
{
private:
int value;
Node* next;
public:
Node() {} 
Node(int value):value(value) , next(nullptr)
{
    
} 
friend void pushToHead(int value , Node* &header);
friend void listTraverse(Node* header);
friend void pushToTail(int value , Node* &header);
friend void removeFromTail(Node* &header);
friend void removeFromHead(Node* &header);
friend Node* reverseknodes(int k , Node* &header);
};
void pushToHead(int value , Node* &header)
{
   Node *newNode = new Node(value);
   newNode->next = header;
   header = newNode;
}
void pushToTail(int value , Node* &header){
    Node *newNode = new Node(value);
    Node *tempNode = header;
    while(tempNode->next != nullptr)
{
    tempNode = tempNode->next;
}
tempNode->next = newNode;
}
void removeFromTail(Node* &header)
{
    Node *tempNode = header;
    while(tempNode->next->next != nullptr)
{
    tempNode = tempNode->next;
}
 Node *toFree = tempNode->next;
tempNode->next = nullptr;
delete toFree;
}
void removeFromHead(Node* &header)
{
    Node *tempNode = header;
    header = header->next;
    delete tempNode;
}
void listTraverse(Node* header)
{
    while(header !=NULL)
    {
        cout << "the value of the thing is: " <<header->value << endl;
        header = header->next;
    }
}
Node* reverseknodes(int k , Node* &header){
  Node* prevptr = NULL;
  Node* currptr = header;
  Node* nextptr;
  int count =0;
  while(currptr != NULL && count<k)
  {
    nextptr = currptr->next;
    currptr->next = prevptr;
    prevptr = currptr;
    currptr = nextptr;
    count++;
  }
    if(nextptr != NULL)
    {
     header->next = reverseknodes(k,nextptr);
    }
    return prevptr;

}



int main(){
    cout<<"chaining";;;
    return 0;
}