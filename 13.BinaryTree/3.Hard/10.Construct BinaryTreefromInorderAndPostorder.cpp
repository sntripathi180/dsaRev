// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/


// Approach 1:
// Time: O(N^2)
// Space: O(N^2)
// Approach 1: Recursive using array slicing
// Explanation:
// - Each recursion call copies subarrays of inorder/postorder → O(N²) total.
// - Each findInd() call takes O(N).

int findInd(vector<int> &postorder,int rootVal){
    for(int i = 0;i<postorder.size();i++){
        if(rootVal == postorder[i])
        return i;
    }
    return -1;
}

TreeNode* buildTree(vector<int>& inorder,vector<int>postorder){
    if(postorder.empty()) return nullptr;
    int rootVal = postorder[postorder.size()-1];
    TreeNode* root = new TreeNode(rootval);
    int index = findInd(inorder,rootVal);

    vector<int>leftIn(inorder.begin(),inorder.begin()+index);
    vector<int>rightIn(inorder.begin()+index+1,inorder.end());
    vector<int>leftPost(postorder.begin(),postorder.begin()+index+1);
    vector<int>rightPost(postorder.begin()+index+1,postorder.end()-1);

    root->left = buildTree(leftIn,leftPost);
    root->right = buildTree(rightIn,rightPost);
return root;
}


// Approach 2:
// Time: O(N)
// Space: O(N)
// Approach 2: Optimized using HashMap + index ranges
//  Process right subtree first because postorder = [Left, Right, Root].


unordered_map<int,int>mp;
int postInd ;
TreeNode* buildTree(vector<int>&inorder,vector<int> &postorder){

    for(int i = 0;i<inorder.size();i++){
        mp[inorder[i]] = i;
    }
    postInd = postorder.size()-1;
    return build(inorder,postorder,0,inorder.size()-1);
}

TreeNode* build(vector<int>& inorder,vector<int>&postorder,int isStart,int isEnd){
    if(isStart>isEnd){
        return nullptr;
    }

    int rootVal = postorder[postInd--];
    TreeNode *root = new TreeNode(rootVal);

    int index = mp[rootVal];
// Build right first because postorder
root->right = build(inorder,postorder,index+1,isEnd);
    root->left = build(inorder,postorder,isStart,index-1);
    return root;
}


// === java =======

Approach 1:

int findIndex(vector<int> &inorder,int rootVal){
    for(int i = 0;i<inorder.length;i++){
        if(inorder[i] == rootVal) return i;
    }
    return -1;
}

public TreeNode buildTree(int[] inorder,int[] postorder){
    if(postorder.length == 0) return null;

    int rootVal = postorder[postorder.length - 1];
    TreeNode root = new TreeNode(rootVal);

    int index = findIndex(inorder,rootVal);

    int[] leftIn = Arrays.copyOfRange(inorder,0,index);
    int[] rightIn = Arrays.copyOfRange(inorder,index+1,inorder.length);

    int[] leftPost = Arrays.copyOfRange(postorder,0,index);
    int[] rightPost = Arrays.copyOfRange(postorder,index,postorder.length-1);

    root.left = buildTree(leftIn,leftPost);
    root.right = buildTree(rightIn,rightPost);

    return root;

}


// approach 2:

private Map<Integer,Integer> inMap;
private int postIndex;

public TreeNode buildTree(int[] inorder,int[] postorder){
    inMap = new Hashmap<>();

    for(int i=0 ;i<inorder.length;i++){
        inMap.put(inorder[i],i);
    }

    postIndex = postorder.length - 1;
    return build(inorder,postorder,0,inorder.length -1);

}

private TreeNode build(int[] inorder,int[] postorder,int inStart,int isEnd){
    if(inStart > inEnd)
    return null;

    int rootVal = postorder[postInd--];
    TreeNode root = new TreeNode(rootVal);

    int inRoot = inMap.get(rootVal);
    root.right = build(inorder,postorder,inRoot+1,inEnd);
    root.right = build(inorder,postorder,inStart,inRoot-1);

    return root;
}