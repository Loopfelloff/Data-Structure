    #include<iostream>
    #include "linkedlist.cpp"
    Node* reverseList(Node* head)
    {
        Node* a = nullptr;
        Node* b = head;
        Node* c = nullptr;
        while(b != nullptr)
        {
            c = b->next;
            b->next =a;
            a = b;
            b = c;
        }
        return a;

    }
    int main(){
        List* myList = new List();
        myList->addToHead(5);
        myList->addToHead(4);
        myList->addToHead(3);
        myList->addToHead(2);
        myList->addToHead(1); 
        myList->Traverse();
        cout<<"--------------------------------"<<endl;
        Node* something = reverseList(myList->Head);
        while(something != nullptr)
        {
            cout<<something->info<<endl;
            something = something->next;
        }
        return 0;
    }