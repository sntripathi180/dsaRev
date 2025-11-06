// https://leetcode.com/problems/diameter-of-binary-tree/

/*
Time Complexity: O(n)
Space Complexity: O(h) (recursion stack)
*/


int diameterOfBinaryTree(TreeNode* root){
    int ans =0;
    height(root,ans);
    return ans;
}

int height(TreeNode* root,int &ans){
    if(!root) return 0;
    int left = height(root->left,ans);
    int right = height(root->right,ans);
    ans = max(left+right,ans);
    return max(left,right)+1;
}