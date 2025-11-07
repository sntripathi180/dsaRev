// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
/*
Time Complexity:O(N)
Space Complexity:O(N)
*/
void findHd(Node *root,int hd,int &minHd,int &maxHd){
    if(!root) return;
    minHd = min(hd,minHd);
    maxHd = max(hd,maxHd);

    findHd(root->left,hd-1,minHd,maxHd);
    findHd(root->right,hd+1,minHd,maxHd);
}


vector<int> topView(Node *root){
    if(!root) return {};

    int minHd =0,maxHd = 0;
    findHd(root,0,minHd,maxHd);
    int width = maxHd-minHd+1;
    vector<int> res(width,INT_MIN);
    queue<pair<Node*,int>> q;
    q.push({root,-minHd});

    while(!q.empty()){
        auto [node,hd] = q.front();
        q.pop();
        if(res[hd] == INT_MIN) res[hd] = node->data;
        if(node->left) q.push({node->left,hd-1});
        if(node->right) q.push({node->right,hd+1});
    }

    return res;
}