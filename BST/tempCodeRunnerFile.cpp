#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left,*right;

    Node(int value)
    {
        data=value;
        left=right=NULL;
    }
};

Node* insert(Node *root,int target)
{
    if(!root){
        Node *temp=new Node(target);
        return temp;
    }

    if(target < root->data)
    {
        root->left=insert(root->left,target);    
    }
    if(target > root->data)
    {
        root->right=insert(root->right,target);
    }

    return root;
}

void inorder(Node *root){
    if(!root){
        return ;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){

    Node* root=NULL;

    int arr[]={2,43,56,21,144,77,9,4,32,90};
    for(int i=0;i<10;i++){
        insert(root,arr[i]);
    }

    //traverse
    inorder(root);

}