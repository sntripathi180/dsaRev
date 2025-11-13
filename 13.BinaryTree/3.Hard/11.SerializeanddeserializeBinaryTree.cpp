// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/


//  Approach: Level Order Traversal (BFS)

// Time Complexity: O(N)  -> Each node is processed once
// Space Complexity: O(N) -> Queue + output string

string serialize(TreeNode* root){
    if(root == nullptr) return "";
    string s = "";
    queue<TreeNode*> st;
    q.push(root);
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        if(node == null) s.append("#,");
        else{
            s.append(to_string(node->val)+",");
            q.push(node->left);
            q.push(node->right);
        }
    }
    return s;
}


TreeNode* deserialize(string data){
    if(data == "") return NULL;
    stringstream s(data);
    string str ;
    getline(s,str,',');

    TreeNode *root = new TreeNode(stoi(str));
    queue<TreeNode*>q;
    q.push(root);

    while(!q.emtpy()){
        TreeNode *node = q.front();
        q.pop();
        
        getline(s,str,',');
        if(str == '#'){
            node->left = nullptr;

        }else{
            TreeNode* leftNode = new TreeNode(stoi(str));
            q.push(leftNode);
        }

        getline(s,str,',');
        if(str == '#'){
            node->right = nullptr;
        }else{
            TreeNode* rightNode = new TreeNode(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}


// ======= java =======

public String serialize(TreeNode root){
    if(root == null) return "";

    StringBuilder sb = new StringBuilder();
    Queue<TreeNode> q = new LinkedList<>();

    q.offer(root);
while(!q.isEmpty()){
    TreeNode node = q.poll();
    if(node == null) sb.append("#,");
    else{
        sb.append(node.val).append(",");
        q.offer(node.left);
        q.offer(node.right);
    }
}
return sb.toString();
}

public TreeNode deserialize(String data){
    if(data.isEmpty()) return null;

    String[] values = data.split(",");
    TreeNode root = new TreeNode(Integer.parseInt(values[0]));

    Queue<TreeNode> q = new LinkedList<>();
    q.offer(root);

    int i  = 1;
    while(!q.isEmtpy && i<values.length){
        TreeNode node = q.poll();
        if(!values[i].equals("#")){
            node.left = new TreeNode(Integer.parseInt(values[i]));
            q.offer(node.left);
        }
        i++;

        if(i<values.length && !values[i].equals("#")){
            node.right = new TreeNode(Integer.parseInt(values[i]));
            q.offer(node.right);
        }
        i++;
    }

    return root;
}