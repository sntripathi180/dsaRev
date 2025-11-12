// https://www.geeksforgeeks.org/problems/children-sum-parent/1

/*
Approach 1 - Level Order
Time Complexity: O(N)
Space Complexity: O(N) — queue stores up to O(N) nodes in the worst case.
*/

 bool isSum(Node *root, Node *left, Node *right) {
        if (!left && !right) return true;
        int sum = 0;
        if (left) sum += left->data;
        if (right) sum += right->data;
        return sum == root->data;
    }


int isSumProperty(Node *root){
    if(!root) return true;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        for(int i = 0;i<n;i++){
            Node  *curr = q.front();
            q.pop();
            if(!isSum(curr,curr->left,curr->right));
            return false;

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }

    return true;
}


/*
Approach 2 - Recursive DFS

Time Complexity: O(N)
Space Complexity: O(H) — recursion stack depth = height of tree.
*/


int isSumProperty(Node *root) {
        if (!root) return true;
        if (!root->left && !root->right) return true;

        int left = root->left ? root->left->data : 0;
        int right = root->right ? root->right->data : 0;

        if (root->data != left + right) return false;

        return isSumProperty(root->left) && isSumProperty(root->right);
    }


    // ===== java =====

//    Approach 1 (BFS)
   
boolean isSum(Node root,Node left, Node right){
    if(left == null && right == null) return true;
    int sum = 0;
    if(left!=null) sum+= left.data;
    if(right!= null) sum+= right.data;
    return sum == root.data;
}

boolean isSumProperty(Node root){
    if(root == null) return true;

    Queue<Node> q = new LinkedList<>();
    q.offer(root);

    while(!q.isEmpty()){
        int n = q.size();
        for(int i  = 0;i<n;i++){
            Node curr = q.poll();
            if(!isSum(curr,curr.left,curr.right))
            return false;

            if(curr.left!=null) q.offer(curr.left);
            if(curr.right!=null) q.offer(curr.right);
        }
    }
    return true;
}


// Approach 2 (Recursive)

boolean isSumProperty(Node root){
    if(root == null) return true;
    if(root.left == null && root.right == null) return true;
    int left = (root.left != null) ? root.left.data : 0;
    int right = (root.right != null)?root.right.data:0;

    if(root.data != left + right) return false;

    return isSumProperty(root.left) && isSumProperty(root.right);
}