// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/



// ================================
// Approach 1: Recursive (DFS)
// ================================
// Time Complexity: O(N)
// Space Complexity: O(H)  -> recursion stack depth
// Explanation:
// 1. Search for the target node using recursion.
// 2. Once found, collect all nodes at distance K in its subtree.
// 3. As recursion unwinds, calculate distances from ancestors and explore the opposite subtree.


void subtreeNodes(TreeNode *root,int k,vector<int>&res){
    if(root == NULL || k<0){
        return;
    }
    if(k == 0){
        res.push_back(root->val);
        return;
    }
    subtreeNodes(root->left,k-1,res);
    subtreeNodes(root->right,k-1,res);
}

int nodesAtK(TreeNode *root,TreeNode *target,int k,vector<int>& res){
if(root == NULL){
    return -1;
}

if(root == target){
    subtreeNodes(root,k,res);
    return 0;
}

int dl = nodesAtK(root->left,target,k,res);
if(dl != -1){
    if(dl+1 == k)
    res.push_back(root->val);
    else
    subtreeNodes(root->right,k-dl-2,res);

    return 1+dl;
}

int dr = nodesAtK(root->right,target,k,res);
if(dr!=-1){
    if(dr+1 == k)
    res.push_back(root->vala);
    else
    subtreeNodes(root->left,k-dr-2,res);

    return 1+dr;
}

return -1;
}

vector<int> distanceK(TreeNode* root,TreeNode *target,int k){
    vector<int> res;
    int temp= nodesAtK(root,target,k,res);
    return res;

}



// ================================
// Approach 2: BFS + Parent Map
// ================================
// Time Complexity: O(N)
// Space Complexity: O(N)
// Explanation:
// 1. Build a parent map for all nodes using BFS.
// 2. Start BFS from the target node.
// 3. Traverse in all 3 directions (left, right, parent) while maintaining visited set.
// 4. Stop when distance == k.


void buildParentMap(TreeNode* root,
                        unordered_map<TreeNode*, TreeNode*>& parent) {
        if (!root)
            return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                q.push(node->left);
                parent[node->left] = node;
            }
            if (node->right){
                q.push(node->right);
                parent[node->right] = node;

            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root)
            return {};
        unordered_map<TreeNode*, TreeNode*> parent;
        buildParentMap(root, parent);

        unordered_set<TreeNode*> vis;
        queue<TreeNode*>q;
        q.push(target);
        vis.insert(target);
        int dist = 0;
        while(!q.empty()){
             int size = q.size();
             if(dist == k) break;

             for(int i = 0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !vis.count(node->left)){
                    vis.insert(node->left);
                    q.push(node->left);
                }
                if(node->right && !vis.count(node->right)){
                    vis.insert(node->right);
                    q.push(node->right);
                }

                if(parent.count(node) && !vis.count(parent[node])){
                    vis.insert(parent[node]);
                    q.push(parent[node]);
                }
             }
             dist++;
        }

        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;

    }



// ==== java =====

// approach 1;

private void subtreeNodes(TreeNode root, int k, List<Integer>res){
    if(root == null || k<0) return ;
    if(k == 0){
        res.add(root.val);
        return;
    }

    subtreeNodes(root.left,k-1,res);
    subtreeNodes(root.right,k-1,res);
}

private int nodesAtK(TreeNode root,TreeNode target,int k,List<Integer> res){
    if(root == null) return -1;
    if(root == target){
        subtreeNodes(root,k,res);
        return 0;
    }

    int dl = nodesAtK(root.left,target,k,res);
    if(dl !=  -1){
        if(dl+1 == k)
        res.add(root.val);
        else
        subtreeNodes(root.right,k-dl-2,res);

        return dl+1;
    }

    int dr = nodesAtK(root.right,target,k,res);
    if(dr!=-1){
        if(dr+1 == k)
        res.add(root.val);
        else 
        subtreeNodes(root.left,k-dr-2,res);
        return dr +1;
    }
    return -1;
}

public List<Integer> distanceK(TreeNode root,TreeNode target,int k){
    List<Integer> res = new ArrayList<>();
    nodeAtK(root,target,k,res);
    return res;
}



// approach 2:

public List<Integer> distanceK(TreeNode root,TreeNode target,int k){
    Map<TreeNode,TreeNode> parent = new HashMap<>();
    buildParentMap(root,parent);

    Set<TreeNode> vis = new HashSet<>();
    Queue<TreeNode> q = new LinkedList<>();
    q.offer(target);
    vis.add(target);

    int dist = 0;
    while(!q.isEmpty()){
        int size = q.size();
        if(dist == k) break;

        for(int i = 0;i<size;i++){
            TreeNode node = q.poll();
            if(node.left!=null && !vis.contains(node.left)){
                vis.add(node.left);
                q.offer(node.left);
                
            }

            if(node.right != null && !vis.contains(node.right)){
                vis.add(node.right);
                q.offer(node.right);
            }

            if(parent.contains(node) && !vis.contains(parent.get(node))){
                vis.add(parent.get(node));
                q.offer(parent.get(node));
            }
        }
         dist++;
    }

    List<Integer> res = new ArrayList<>();
    while (!q.isEmpty())
    {
        res.add.(q.poll().val);
    }
    return res;
}