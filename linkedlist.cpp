    #include<iostream>
    using namespace std;
    class Node{
    public:
    int info;
    Node* next;
    };

    class List{
        public:
        Node* Head = nullptr;
        Node* Tail = nullptr;
        bool isEmpty(){
            return Head == nullptr;
        }
        void addToHead(int value)
        {
            Node *newNode = new Node();
            newNode->info = value;
            Node* tempNode = new Node();
            tempNode = Head;
            Head = newNode;
            newNode->next = tempNode;
            if(Tail == nullptr) Tail = Head;
        }
        void addToTail(int value)
        {
            Node *newNode = new Node();
            newNode->info = value;
            Tail->next = newNode;
            newNode->next = nullptr;
            Tail = newNode;
            if(Head == nullptr) Head = Tail;
        }
        void addToNode(int value , Node* predecessor)
        {
            Node *newNode = new Node();
            newNode->info = value;
            newNode->next = predecessor->next;
            predecessor->next = newNode;

        }
        void removeFromHead(){
            if(isEmpty()) return;
            Node* tempNode = Head;
            Head = Head->next;
            delete tempNode;
            tempNode = nullptr;
            if(Head == nullptr) Tail = Head;
        }
        void removeFromTail(){ 
            if(isEmpty()) return;
            if(Head == Tail) Head=Tail=nullptr;
            else{
            Node* tempNode = Head;
            while(tempNode->next != Tail)
            {
                tempNode = tempNode->next;
            } 
            tempNode->next = nullptr; 
            Node* toremoveNode = Tail;
            delete toremoveNode;
            toremoveNode = nullptr;
            Tail = tempNode;
        }
        }
        void Traverse()
        {
            Node* tempNode = new Node();
            tempNode = Head;
            while(tempNode !=nullptr)
            {
                cout<<tempNode->info<<endl;
                tempNode = tempNode->next;
            }
        }
    };
   