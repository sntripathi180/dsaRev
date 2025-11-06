// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

/*
Approach 1 : 2 pass
    Find horizontal distance range (findHDRange)
    BFS traversal
    Sorting each column

Time : O(N log K) + recursion overhead
Space : O(N)

*/

void findHDRange(TreeNode* root,int hd,int &minHd,int &maxHd){
    if(!root)
    return;
    minHd = min(minHd,hd);
    maxHd = max(maxHd,hd);
    findHDRange(root->left,hd-1,minHd,maxHd);
    findHDRange(root->right,hd+1,minHd,maxHd);
}

vector<vector<int>> verticalTraversal(TreeNode* root){
    if(!root) return {};
    int minHd = 0, maxHd = 0;
    findHDRange(root,0,minHd,maxHd);

    int width = maxHd - minHd +1;

    vector<vector<pair<int,int>>> temp(width);
    queue<tuple<TreeNode*,int,int>>q;
    q.push({root,-minHd,0});
    while(!q.empty()){
        auto [node,hd,lvl] = q.front();
        q.pop();
        temp[hd].push_back({node->val,lvl});

        if(node->left)
        q.push({node->left,hd-1,lvl+1});

        if(node->right)
        q.push({node->right,hd+1,lvl+1});
    }

    vector<vector<int>> res;
    for(auto &bucket:temp){
        sort(bucket.begin(),bucket.end(),[](pair<int,int>&a,pair<int,int>& b){
            return a.second == b.second ? a.first < b.first : a.second < b.second;
        });
        vector<int> col;
        for(auto &p:bucket)
        col.push_back(p.first);
        res.push_back(col);
    }

    return res;
}

/*
Approach 2: Cal horiz dis on the go
Time Complexity O(N log N)
Space Complexity O(N)
 */

vector<vector<int> verticalTraversal(TreeNode* root){
     //horizontal distance -> level -> multiset of values in sorted order
     
    map<int,map<int,multiset<int>>> nodes;
    queue<tuple<TreeNode* , int,int>>q;
    q.push({root,0,0});

while (!q.empty())
    {
        auto [node,col,row]  = q.front();
        q.pop();
        nodes[col][row].insert(node->val);
        if(node->left)
        q.push({node->left,col-1,row+1});

        if(node->right)
        q.push({node->right,col+1,row+1});
    }


    vector<vector<int>> res;

    for(auto &[col,rowMap]:nodes){
        vector<int> colValues;

        for(auto &[row,values]:rowMap){
            colValues.insert(colValues.end(),values.begin(),values.end());
        }

        res.push_back(colValues);
    }
    return res;
    
}