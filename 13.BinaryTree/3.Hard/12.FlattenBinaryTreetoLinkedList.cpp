https://leetcode.com/problems/flatten-binary-tree-to-linked-list/


// Approach 1:
// Time Complexity: O(N²)
// Space Complexity: O(H) -> recursion stack
// Steps:
// 1. Recursively flatten left and right subtrees.
// 2. Move the left flattened subtree to the right.
// 3. Traverse to the end of the new right chain.
// 4. Attach the original right subtree there.


 void flatten(TreeNode* root) {
        if(!root) return ;
        flatten(root->left);
        flatten(root->right);

        TreeNode *left = root->left;
        TreeNode *right = root->right;

        root->left = nullptr;
        root->right = left;
        TreeNode *temp = root;
        while(temp->right) temp = temp ->right;
        temp->right = right;

    }

// Apporach 2 :
// Time Complexity: O(N)
// Space Complexity: O(H) -> recursion stack
// Steps:
// 1. Traverse in **reverse preorder** (right → left → root).
// 2. Maintain a global pointer `prev` that always points to
//    the previously processed node.
// 3. Set `root->right = prev` and `root->left = nullptr`.


TreeNode *prev =nullptr;

void flatten(TreeNode *root){
    if(!root) return;
    flatten(root->right);
    flatten(root->left);

    root->right = prev;
    root->left =  nullptr;
    prev = root;
 }


 ======= java =======

 public void flatten(TreeNode root){
    if(root == null) return ;
    flatten(root.left);
    flatten(root.right);

    TreeNode left = root.left;
    TreeNode right = root.right;

    root.left = null;
    root.right = left;

    TreeNode temp = root;
    while(temp.right !=null){
        temp = temp.right;
    }

    temp.right = right;
 }



//  Approach 2:
private TreeNode prev =null;

public void flatten(TreeNode root){

    if(root == null) return;
    
    flatten(root.right);
    flatten(root.left);
    
    root.right = prev;
    root.left = null;
    prev = root;
}