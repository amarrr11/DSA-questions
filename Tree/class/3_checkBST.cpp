bool check(Node* root,int &prev){
    if(!root) return true;
    
    if(!check(root->left,prev))return false;

    if(root->val<=prev){
        return false;
    }else{
        prev=root->val;
    }
    if(!check(root->right,prev))return false;
    
    return true;
}