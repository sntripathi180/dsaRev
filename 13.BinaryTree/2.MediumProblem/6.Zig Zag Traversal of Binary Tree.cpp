// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

/*
Time: O(n) - each node visited once.
Space: O(n) - queue and result storage.
*/


vector<vector<int>> zigzag(TreeNode *root){
    vector<vector<int>> res;
    if(!root) return res;

    queue<TreeNode*> q;
    q.push(root);
    bool flag = true;

    while(!q.empty()){
        int n = q.size();
        vector<int> temp(n);
        for(int i = 0;i<n;i++){
            TreeNode* node = q.front();
            q.pop();
            if(flag)temp[i] = node->val;
            else temp[n-i-1] = node->val;

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        flag = !flag;
        res.push_back(temp);
    }
    return res;

}