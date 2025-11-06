// https://leetcode.com/problems/same-tree/description/


/*
Time: O(n) - every node compared once
Space: O(h) - recursion stack (height of tree)
*/

bool isSame(TreeNode* p,TreeNode* q){
    if(!q && !p) return true;
    if((!q && p) ||(!p && q) )return false;

    if(p->val != q->val) return false;

    return isSame(p->left,q->left) && isSame(p->right,q->right);
}