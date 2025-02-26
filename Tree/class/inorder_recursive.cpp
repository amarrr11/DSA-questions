#include<bits/stdc++.h>
using namespace std;

class Node{
    int data;
    Node* left,*right;

    Node(int val){
        data=val;
        right=NULL;
        left=NULL;
    }
};

void solve(Node* root){
    if(root==NULL){
        return;
    }
    solve(root->left);
    cout<<root->data<<endl;
    solve(root->right);
}

int main(){
    int x;
    cin>>x;
    Node* root=new Node(x);

    queue<Node*> q;
    q.push(x);
    
    while(!q.empty()){
        cout<<"Enter value of left"<<endl;
        cin>>first;
        
    }
}


