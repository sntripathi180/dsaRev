
// Approach 1:
// Time Complexity: O(N)
// Space Complexity: O(H)  -> recursion stack, H = height of tree
// Explanation: Visits every node once to count them.


int Count(TreeNode* root){
    if(!root) return 0;
    return 1+Count(root->left) + Count(root->right);
}


// Approach 2: log2N
// Time Complexity: O((log N)²)
// Space Complexity: O(log N) -> recursion stack depth
// Explanation:
// For a complete binary tree:
// - If left height == right height → it’s a perfect tree → nodes = (2^h) - 1
// - Else recursively count left and right subtrees.

int cntLeft(TreeNode *temp){
    if(!root) return 0;
    TreeNode *root = temp;
    int cnt= 0;
    while (root)
    {
        cnt++;
       root= root->left ;
    }
    return cnt;
}

int cntRight(TreeNode *temp){
    if(!root) reutrn 0;
    TreeNode *root = temp;
    int cnt = 0;
    while(root){
        cnt++;
        root=root->right;
    }
    return cnt;
}

int countNodes(TreeNode* root){
    if(!root) return 0;
    int l =  cntLeft(root);
    int r = cntRight(root);

    if(l == r) return (1<<l)-1;
    return 1 + countNode(root->left) + countNode(root->right);
}

// ===========java ========

int Count(TreeNode root){
    if(root == null) return 0;
    return 1 + Count(root.left) + Count(root.right);
}


public int countNode(TreeNode root){
    if(root == null) return 0;
    int l = countLeft(root);
    int r = countRight(root);

    if(l == r) return (1<<l)-1;
    else return 1 + countNode(root.left) + countNode(root.right);
}

private int countLeft(TreeNode root){
    int cnt = 0;
    while(root!=null){
        cnt++;
        root = root->left;
    }
    return cnt;

}

private int countRight(TreeNode root){
    int cnt = 0;
    while(root!=null){
        cnt++;
        root=root->right;
    }
    return cnt;
}


