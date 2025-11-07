// https://leetcode.com/problems/binary-tree-right-side-view/description/

// Time Complexity: O(N)
// Space Complexity: O(N)

vector<int> rightView(TreeNode* root){
    if(!root)  return {};
    vector<int> ans;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        int tempV = 0;
        for(int i = 0;i<n;i++){
            TreeNode* temp = q.front();
            q.pop();
            tempV= temp->val;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        ans.push_back(tempV);

    }
    return ans;
}