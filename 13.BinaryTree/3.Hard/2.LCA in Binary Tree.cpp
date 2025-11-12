// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

/*
Time Complexity:O(n)
Space Complexity:O(h) Recursion stack (h = height of tree).
*/


TreeNode* lca(TreeNode *root,TreeNode *p, TreeNode *q){
    if(!root || root == p || root == q) return root;

    TreeNode *left = lca(root->left,p,q);
    TreeNode *right = lca(root->right,p,q);

    if(left && right) return root;
    if(left) return left;
    else return right;
}


// ====== java ======

public TreeNode lca(TreeNode root, TreeNode p , TreeNode q){
    if(root == null || root == q || root == p) return root;
    TreeNode left = lca(root.left,p,q);
    TreeNode right = lca(root.right,p,q);
    if(left != null && right != null) return root;
    if(left!=null) return left;
    else return right;
}
