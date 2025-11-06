// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/


/*
Time: O(n) — every node visited once.
Space: O(h) — recursion stack.
*/

int maxPathSum(TreeNode* root){
    int ans =INT_MIN;
    heightSum(root,ans);
    return ans;
}

int heightSum(TreeNode* root,int &ans){
    if(!root) return 0;
    int left = max(heightSum(root->left),0);
    int right = max(heightSum(root->right),0);
    int priceNow = left + right + root->val;

    ans = max(priceNow,ans);

    return max(left,right)+root->val;
}