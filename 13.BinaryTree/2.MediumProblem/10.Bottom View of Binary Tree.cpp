// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

// Time Complexity: O(N)
// Space Complexity: O(N)

void findHd(Node *root,int hd,int &minHd,int &maxHd){
    if(!root)return;

    minHd = min(minHd,hd);
    maxHd = max(maxHd,hd);

    findHd(root->left,hd-1,minHd,maxHd);
    findHd(root->right,hd+1,minHd,maxHd);

}

vector<int> bottomView(Node *root){
    
    if(!root) return {};
    int minHd = 0;
    int maxHd = 0;
    findHd(root,0,minHd,maxHd);
    int width = maxHd - minHd +1;
    vector<int> res(size,INT_MIN);

    queue<pair<Node*,int>>q;
    q.push({root,-minHd});
    while(!q.empty()){
        auto [node,hd] = q.front();
        q.pop();

        res[hd] = node->data;
        if(node->left) q.push(root->left,hd-1);
        if(node->right,hd+1) q.push(root->right);
    }
return res;
}