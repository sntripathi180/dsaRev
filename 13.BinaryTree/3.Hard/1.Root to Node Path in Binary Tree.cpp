// https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

/*

Time Complexity: O(n * h)
n = number of nodes
h = height of the tree (worst-case O(n) for skewed tree)

Total Space Complexity: O(h) + O(L * h) (Backtracking stack + storage for all paths)
*/
void helper(Node *root,vector<int> &temp,vector<vector<int>> &res){
    if(!root){
        return;
    } 
    temp.push_back(root->data);
    if(!root->left && !root->right) {
        res.push_back(temp);
    }
    helper(root->left,temp,res);
    helper(root->right,temp,res);
    temp.pop_back();

}
  

vector<vector<int>> Paths(Node *root){
vector<int> temp;
vector<vector<int>> ans;
helper(root,temp,ans);

return ans;
}



// ======== java =============
private void helper(Node root, ArrayList<Integer> temp,ArrayList<ArrayList<Integer>> res){
    if(root == null) return;
    temp.add(root.data);
    if(root.left == null && root.right == null){
        res.add(new ArrayList<>(temp));
    }
    helper(root.left,temp,res);
    helper(root.right,temp,res);

    temp.remove(temp.size()-1);
}


public static  ArrayList<ArrayList<Integer>> Paths(Node root){
    ArrayList<ArrayList<Integer>> res = new ArrayList<>();
    ArrayList<Integer> temp = new ArrayList<>();
    helper(root,temp,res);
    return res;
}