// https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Approach: Simple recursive DFS — depth = max(leftDepth, rightDepth) + 1
// Time Complexity: O(n)
// Space Complexity: O(h)  // h = height of tree

int maxDepth(TreeNode* root){
    if(root == NULL) return 0;
    return max(maxDepth(root->left),maxDepth(root->right))+1;
}

