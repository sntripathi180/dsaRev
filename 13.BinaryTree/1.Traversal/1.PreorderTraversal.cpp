// vector<int> preOrderTraversal(TreeNode* root){
//     if(root == NULL) return ans;
//     ans.push_back(root->val);
//     preOrderTraversal(root->left);
//     preOrderTraversal(root->right);
// return ans;
// }

// =============================

// vector<int> preorderTraversal(TreeNode * root){
//     vector<int> ans;
//     if(root == NULL) return ans;
//     stack<TreeNode*> st;
//     st.push(root);

//     while(!st.empty()){
//         TreeNode* node = st.top();
//         st.pop();
//         ans.push_back(node->val);
//         if(node->right){
//             st.push(node->right);
//         }
//         if(node->left) {
//             st.push(node->left);

//         }

//     }
//     return ans;
// }



// =============================


// vector<int> preorderTraversal(TreeNode* root){
//     vector<int> ans;
//     while(root){
//         if(!root->left){
//             ans.push_back(root->val);
//             root = root->right;
//         }
//         else{
//             TreeNode* curr = root->left;
//             while(curr->right && curr->right!=root)
//             curr = curr->right;
//             if(curr->right == NULL){
//                 ans.push_back(root->val);
//                 curr->right = root;
//                 root = root->left;
//             }else{
//                 curr->right = NULL;
//                 root = root->right;
//             }
//         }
//     }
//     return ans;
// }