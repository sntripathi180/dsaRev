// #include <bits/stdc++.h>

// vector<int> ans;
// vector<int> postorder(TreeNode *root)
// {
//     if (root == NULL)
//         return ans;
//     postorder(root->left);
//     postorder(root->right);
//     ans.push_back(root->val);
//     return ans;
// }

// == == == == == = iterative two stack == == ==

//                  vector<int> postorder(TreeNode * root)
// {
//     vector<int> ans;
//     if (!root)
//     {
//         return ans;
//     }
//     stack<TreeNode *> st1, st2;
//     st1.push(root);
//     while (!st1.empty())
//     {
//         TreeNode *curr = st1.top();
//         st1.pop();
//         st2.push(curr);
//         if (curr->left != nullptr)
//         {
//             st1.push(curr->left);
//         }
//         if (curr->right != nullptr)
//         {
//             st1.push(curr->right);
//         }
//     }

//     while (!st2.empty())
//     {
//         st2.push_back(ans.top()->val);
//         st2.pop();
//     }

//     return ans;
// }

// == == == == == == == = one stack == == == =

//                                               vector<int> postorder(TreeNode * root)
// {
//     vector<int> res;
//     if (!root)
//         return res;
//     stack<TreeNode *> st;
//     TreeNode *curr = root;
//     TreeNode *lastVisited = nullptr;
//     while (curr || !st.empty())
//     {
//         if (curr)
//         {
//             st.push(curr);
//             curr = curr->left;
//         }
//         else
//         {
//             TreeNode* peekNode = st.top();
//             if(peekNode->right && peekNode->right != lastVisited){
//                 curr = peekNode->right;
//             }
//             else{
//                 res.push(peekNode->val);
//                 lastVisited = peekNode;
//                 st.pop();
//             }
//         }
//     }
//     return res;
// }