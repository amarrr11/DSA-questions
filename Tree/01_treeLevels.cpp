#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *left,*right;

    Node(int value){
        data=value;
        left=right=NULL;
    }
};

void PreOrder(Node *root){
    if(root==NULL){
        return ;
    }

    //Node
    cout<<root->data<<endl;
    //left
    PreOrder(root->left);
    //right
    PreOrder(root->right);
    
}
void InOrder(Node *root){
    if(root==NULL){
        return ;
    }

    //left
    InOrder(root->left);
    //Node
    cout<<root->data<<endl;
    //right
    InOrder(root->right);
    
}
void PostOrder(Node *root){
    if(root==NULL){
        return ;
    }

    //left
    PostOrder(root->left);
    //right
    PostOrder(root->right);
    //Node
    cout<<root->data<<endl;
}

int main(){

    int x;
    cout<<"Enter the root element: ";
    cin>>x;

    int first,second;
    queue<Node*> q;
    Node *root=new Node(x);
    q.push(root);

    //Build the binary tree
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        cout<<"Enter the left value of "<<temp->data<<" : ";
        cin>>first; //left node ki value
        //left node
        if(first!=-1){
            temp->left=new Node(first);
            q.push(temp->left);
        }

        //right node
        cout<<"enter the right value of "<<temp->data<<" : ";
        cin>>second;
        if(second!=-1){
            temp->right=new Node(second);
            q.push(temp->right);
        }
    }

}
Node* build(vector<int>&v){
	
    Node* root=new Node(v[0]);
    size_t=1;

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        if(i<v.size()){
            Node* l=new Node(v[i++]);
            temp->left=l;
            q.push(l);
        }
        if(i<v.size()){
            Node* r=new Node(v[i++]);
            temp->right=r;
            q.push(r);
        }
        
    }
    return root;

}