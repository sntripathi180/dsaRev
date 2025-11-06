// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

vector<int> boundaryTaversal(Node *root){
    if(!root) return {};
    vector<int> ans;
    ans.push_back(root->data);
    left(root->left,ans);
    leaf(root->left,ans);
    leaf(root->right,ans);
    right(root->right,ans);


    return ans;
}

void left(Node *root,vector<int>& ans){
    if(!root) return ;
    if(!root->left && !root->right) return ;
    ans.push_back(root->data);

    if(!root->left && root->right!= nullptr) left(root->right,ans);
    left(root->left,ans);
}

void right(Node *root,vector<int> &ans){
if(!root) return ;
if(!root->right && !root->left) return;

if(!root->right && root->left!=nullptr) right(root->left,ans);
right(root->right,ans);

ans.push_back(root->data);
}


void leaf(Node* root, vector<int> &ans){
    if(!root) return;
    if(!root->left && !root->right) ans.push_back(root->data);
    leaf(root->left,ans);
    leaf(root->right,ans);
}
