// https://leetcode.com/problems/balanced-binary-tree/description/



/*
Approach 1: Double-pass Solution
Time Complexity: O(n^2)
Space Complexity: O(h) — due to recursion stack
*/

bool isBalanced(TreeNode *root)
{
    if (!root) return true;
    int left = height(root->left);
    int right = height(root->right);
    if (abs(left - right) > 1)
        return false;

    return isBalanced(root->left) && isBalanced(root->right);
}

int height(TreeNode *root)
{
    if (!root)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}


/*
Approach 2: Optimized One-pass Solution
Time Complexity: O(n)
Space Complexity: O(h)
*/
                                        bool isBalanced(TreeNode *root)
{
    return height(root) != -1;
}

int height(TreeNode *root)
{
    if (!root)
        return 0;

    int left = height(root->left);
    if (left == -1)
        return -1;
    int right = height(root->right);
    if (right == -1)
        return -1;

    if (abs(left - right) > 1)
        return -1;
    return max(left, right) + 1;
}
