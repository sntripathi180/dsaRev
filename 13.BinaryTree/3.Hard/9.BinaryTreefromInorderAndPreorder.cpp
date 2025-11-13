https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

// Approach 1:
// Time Complexity: O(N^2)
// Space Complexity: O(N^2)
// Approach: Recursive construction using preorder root selection + inorder partition


int findInd(vector<int> &inorder,int rootVal){
    int n = inorder.size();
    for(int i = 0;i<n;i++){
        if(inorder[i] == rootVal) return i;
    }
    return -1;
}

TreeNode *buildTree(vector<int> &preorder,vector<int> &inorder){
    if(preorder.empty()) return nullptr;
    int rootVal = preorder[0];
    TreeNode *root = new TreeNode(rootVal);
    int index = findInd(inorder,rootVal);

    vector<int> leftPre(preorder.begin()+1,preorder.begin()+index + 1);
    vector<int> leftIn(inorder.begin(),inorder.begin()+index);
    vector<int> rightPre(preorder.begin()+1+index,preorder.end());
    vector<int> rightIn(inorder.begin() + index +1,inorder.end());

    root->left = buildTree(leftPre,leftIn);
    root->right = buildTree(rightPre,rightIn);

    return root;
}


// Approach 2:O(N) Time, O(N) Space
// Approach:
// 1. Preorder gives root nodes in order.
// 2. Inorder helps identify left/right subtrees.
// 3. Use HashMap to store inorder indices for O(1) lookup.
// 4. Recurse using index boundaries instead of slicing lists.


int preIndex = 0;
unordered_map<int,int>inMap;

TreeNode* build(vector<int>&preorder,int inStart,int inEnd){
    if(inStart>inEnd) return nullptr;

    int rootVal = preorder[preIndex++];
    TreeNode *root = new TreeNode(rootVal);

    int inIndex = inMap[rootVal];

    root->left = build(preorder,inStart,inIndex - 1);
    root->right = build(preorder,inIndex+1,inEnd);

    return root;
}

TreeNode* buildTree(vector<int>& preorder,vector<int> &inorder){
    for(int i =0;i<inorder.size();i++){
        inMap[inorder[i]] = i;
    }

    preIndex = 0;
    return build(preorder,0,inorder.size()-1);
}


// ===== java =====

// Approach 1:


private static int findIndex(List<Integer> inorder,int rootVal){
    for(int i = 0;i<inorder.size();i++){
        if(inorder.get(i) == rootVal) return i;

    }

    return -1;
}

public static TreeNode buildTree(List<Integer> preorder,List<Integer> inorder){
    if(preorder.isEmpty()) return null;

    int rootVal = preorder.get(0);
    TreeNode root = new TreeNode(rootVal);

    int index = findIndex(inorder,rootVal);

    List<Integer> leftPre = preorder.subList(1,index+1);
    List<Integer> leftIn = inorder.subList(0,index);
    List<Integer> rightPre(index+1,preorder.size());
    List<Integer> rightIn = inorder.subList(index+1,inorder.size());

    root.left = buildTree(leftPre,leftIn);
    root.right = buildTree(rightPre,rightIn);

    return root;
}


// approach 2

private static int preIndex = 0;
private static Map<Integer,Integer> inorderMap  = new HashMap<>();

private static TreeNode buildTree(int[] preorder,int[] inorder){
    for(int i = 0;i<inorder.length;i++){
        inorderMap.put(inorder[i],i);

    }
    preIndex = 0;
    return build(preorder,o,inorder.length-1);

}

private static TreeNode build(int[] preorder,int inStart,int inEnd){
    if(inStart>inEnd) return null;
    
    int rootVal = preorder[preIndex++];
    TreeNode root = new TreeNode(rootVal);
    int inIndex = inorderMap.get(rootVal);

    root.left = build(preorder,inStart,inIndex-1);
    root.right = build(preorder,inIndex+1,inEnd);

    return root ;
}