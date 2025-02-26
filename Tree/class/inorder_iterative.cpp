void inorder(Node* root){
    stack<Node*> s;

    while(root!=NULL or !s.empty()){
        while(!root){
            s.push(root);
            root=root->left;
        }
        root=s.top();
        s.pop();
        cout<<root->val<<endl;
        root=root->right;
    }
}