#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val)
    {
        this->val = val;
    }
    Node* insert(Node* root , int value)
    {
        if(root == nullptr) return new Node(value);
        if(root->val < value) root->right = insert(root->right , value);
        else if(root->val > value) root->left = insert(root->left , value);
        return root; 
    }
    void inorder(Node* root)
    {
        if(root == nullptr) return;
        inorder(root->left);
        cout<<root->val<<" \t";
        inorder(root->right);
    }
    void preorder(Node* root)
    {
        if(root == nullptr) return;
        cout<<root->val<<" \t";
        preorder(root->left);
        preorder(root->right); 
    }
    Node* removeNode(Node* root , int value)
    {
        if(root == nullptr) return nullptr;
        // traversing the tree 
        if(root->val < value) root->right = removeNode(root->right , value);
        else if(root->val > value) root->left = removeNode(root->left , value);
        else{
            if(root->left == nullptr && root->right == nullptr)
            {
                delete root;
                root = nullptr;
                return nullptr;
            }
            else if(root->left == nullptr)
            {
                Node* tempNode = root->right;
                delete root;
                return tempNode;
            }
            else if(root->right == nullptr)
            {
                Node* tempNode = root->left;
                delete root;
                return tempNode;
            }
            else{
                int minNode = findMin(root);
                root->val = minNode;
                root->right = removeNode(root->right,minNode);
            }
        }
        return root;
    }
    int findMin(Node* root)
    {
        Node* temp = root;
        while(temp->left != nullptr)
        {
            temp = temp->left;
        }
        return temp->val;
    }
};
int main(){
    Node *root = nullptr;
    root = root->insert(root , 100);
    root->insert(root , 150);
    root->insert(root , 50);
    root->insert(root , 60);
    root->insert(root , 40);
    root->insert(root , 160);
    root->insert(root , 145);
    root->removeNode(root , 50);
    root->inorder(root);
    cout<<endl;
    cout<<"---------------------------"<<endl;
    root->preorder(root);
    cout<<endl;
    cout<<"---------------------------"<<endl;

    return 0;
}