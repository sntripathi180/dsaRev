https://leetcode.com/problems/symmetric-tree/

/*
Approach 1: Recursive Mirror Check
Time Complexity : O(N) — every node visited once
Space Complexity: O(H) recursion stack (O(N) worst case)

*/

bool isSymmetric(TreeNode* root){
    if(!root) return true;
    return mirror(root->left,root->right);


}

bool mirror(TreeNode* root1,TreeNode* root2){
    if(!root1 && !root2) return true;
    if((!root1 && root2!=nullptr) || (root1!= nullptr && !root2)) return false;

    if(root2->val!=root1->val)return false;

   return mirror(root1->left,root2->right) && mirror(root1->right ,root2->left);

}


/*
 Approach 2:Iterative (BFS using queue)
Time Complexity : O(N) — every node visited once
Space Complexity: O(W) queue (O(N) worst case)
*/
bool isSymmetric(TreeNode* root){
    if(!root) return true;

    queue<pair<TreeNode*,TreeNode*>> q;
    q.push({root->left,root->right});
    while(!q.empty()){
        auto [node1,node2] = q.front();
        q.pop();
        if(!node1 && !node2) continue;
        if((!node1 && node2!=nullptr) || (!node2 && node1!=nullptr)) return false;
        if(node1->val!= node2->val) return false;

        q.push({node1->left,node2->right});
        q.push({node1->right,node2->left});

    }

    return true;
}