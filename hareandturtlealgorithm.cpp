    #include<iostream>
    #include "linkedlist.cpp"
    Node* findmiddle(Node* head)
    {
        Node* turtle = head;
        Node* hare = head;
        while(hare != nullptr && hare->next != nullptr ) // here we check for hare->next != nullptr when odd no of items present and hare != nullptr when even no of items are present.
        {
            turtle = turtle->next;
            hare = hare->next->next;
        }
        return turtle;
    }
    int main(){
        List* myList = new List();
        myList->addToHead(5);
        myList->addToHead(4);
        myList->addToHead(3);
        myList->addToHead(2);// if even numbers are present it gives off the right most value between the two middle items.
        myList->addToHead(1); 
        Node* middle = findmiddle(myList->Head);
        cout<<middle->info<<endl;
        return 0;
    }