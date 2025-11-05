// vector<int> ans;
// vector<int> inorder(TreeNode* root){
//     if(root ==  NULL) return ans;

//     inorder(root->left);
//     ans.push_back(root->val);
//     inorder(root->right);

//     return ans;
// }


// ==============Iterative==========

// vector<int> ans;
// vector<int> inorder(TreeNode* root){
//     if(root== NULL) return ans;
//     stack<TreeNode*> st;

//     while (root != nullptr || !st.empty())
//     {
//         while(root!=nullptr){
//             st.push(root);
//             root->left;
//         }
//         root = st.top();
//         st.pop();
//         ans.push_back(root->val);
//         root = root->right;
//     }
//     return ans;
// }




// =============o(1) space =======
// vector<int> inorder(TreeNode* root){
//     vector<int> ans;
//     while(root){
//         if(!root->left){
//             ans.push_back(root->val);
//             root = root->right;

//         }else{
//             TreeNode* curr = root->left;
//             while(curr->right && curr->right!= root) curr = curr->right;
//             if(curr->right ==   NULL){
//                 curr->right = root;
//                 root = root->left;

//             }else{
//                 curr->right = NULL;
//                 ans.push_back(root->val);
//                 root= root->right;
//             }
//         }
//         return ans;
//     }
// }

