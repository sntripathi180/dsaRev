// https://www.geeksforgeeks.org/problems/burning-tree/1


// Approach 1: Recursive DFS

// Time Complexity: O(N)
// Space Complexity: O(H)  (Recursion stack)
// -----------------------------------------------
// Explanation:
// - Find the target node and recursively compute time taken to spread fire.
// - If target is found in left subtree → right subtree burns later (and vice versa).
// - Timer keeps track of max time seen while burning in both directions.
// - Compute height of target subtree for remaining unburnt portion.


int minTime(Node *root, int target)
{
    int timer = 0;
    burnTime(root, target, timer);
    Node *BurnNode = NULL;
    find(root, target, BurnNode);
    int high = heightTree(BurnNode) - 1;
    return max(timer, high);
}

int burnTime(Node *root, int &target, int &timer)
{
    if (!root)
        return 0;
    if (root->data == target)
        return -1;
    int left = burnTime(root->left, target, timer);
    int right = burnTime(root->right, target, timer);

    if (left < 0)
    {
        timer = max(timer, abs(left) + right);
        return left - 1;
    }

    if (right < 0)
    {
        timer = max(timer, left + (abs)right);
        return right - 1;
    }

    return 1 + max(left, right);
}

void find(Node *root,int target,Node* &BurnNode){
    if(!root) return;
    if(root->data == target){
        BurnNode = root;
        return;
    }

    find(root->left,target,BurnNode);
    find(root->right,target,BurnNode);
}

int heightTree(Node* root){
    if(!root) return 0;
    return 1+max(heightTree(root->left),heightTree(root->right));
}


//  Approach 2: BFS + Parent Mapping

// Time Complexity: O(N)
// Space Complexity: O(N)
// -----------------------------------------------
// Explanation:
// 1. Create a mapping of each node to its parent using BFS.
// 2. Start BFS from the target node.
// 3. In each second, all connected (left, right, parent) unburnt nodes catch fire.
// 4. Continue until no nodes are left unburnt.


int minTime(Node *root,int target){
    unordered_map<Node*,Node*> parent;
    Node* targetNode = maping(root,target,parent);
    return burnTree(targetNode,parent);
}

Node *mapping(Node *root,int target,unordered_map<Node*,Node*>&parent){
    Node *targetNode = nullptr;
    queue<Node*> q;
    q.push(root);
    parent[root] = NULL;
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr->data == target)
        targetNode =  curr;

        if(curr->left){
            parent[curr->left] = curr;
            q.push(curr->left);
        }

        if(curr->right){
            parent[curr->right] = curr;
            q.push(curr->right);
        }

    }

    return targetNode;
}

int burnTree(Node *tragetNode,unordered_map<Node*,Node*> &parent){
    queue<Node*>q;
    unoredered_map<Node*,bool> vis;
    q.push(targetNode);
    vis[targetNode] = true;

    int time = 0;
    while(!q.emtpy()){
        int size = q.size();
        bool burnedThislevel = false;
        for(int i =0;i<size;i++){
            Node *curr = q.front();
            q.pop();

            if(curr->left && !vis[curr->left]){
                burnedThislevel = true;
                q.push(curr->left);
                vis[curr->left] = true;
            }

            if(curr->right && !vis[curr->right]){
                burnedThislevel = true;
                q.push(curr->right);
                vis[curr->right] =true;


            }

            if(parent[curr] && !vis[parent[curr]]){
                burnedThislevel = true;
                q.push(parent[curr]);
                vis[parent[curr]] = true;
            }
        }

        if(burnedThislevel) time++;
    }
    return time;
}


// ==== java =====

// approach 1:



public static int minTime(Node root, int target){
   int[] timer = new int[1];
   burnTime(root,target,timer);
   Node burnNode = find(root,target);
   int height = 0;
   if(burnNode!=null){
    height = heightTree(burnNode)-1;

   }
   return Math.max(timer[0],height);
}
public static int burnTime(Node root,int target,int[] timer){
    if(root == null) return 0;
    if(root.data == target) return -1;

    int left = burnTime(root.left,target,timer);
    int right = burnTime(root.right,target,timer);

    if(left<0){
        timer[0] = Math.max(timer[0],Math.abs(left) + right);
        return left-1;
    }

    if(right<0){
        timer[0] = Math.max(timer[0],left+Math.abs(right));
        return right -1;
    }

    return 1+Math.max(left,right);
}


public static Node find(Node root,int target){
    if(root == null) return null;
    if(root.data == target) return root;
    Node left = find(root.left,target);
    if(left !=null) return left;
    return find(root.right,target);
}

public static int heightTree(Node root){
    if(root == null) return 0;
    return 1+Math.max(heightTree(root.left),heightTree(root.right));
}



// Approach 2:



public static int minTime(Node root,int target){
    if(root == null) return 0;
    HashMap<Node,Node> parent = new HashMap<>();
    Node targetNode = mapping(root,target,parent);
    return burnTree(targetNode);
}

public static Node mapping(Node root,int target,HashMap<Node,Node> parent){
    if(root == null) return null;
    Node targetNode = null;
    Queue<Node>q = new LinkedList<>();
    q.add(root);
    parent.put(root,null);

    while(!q.isEmpty()){
        Node curr = q.poll();
        if(curr.data == target)targetNode = curr;
        if(curr.left!=null){
            parent.put(curr.left,curr);
            q.add(curr.left);
        }

        if(curr.right!=null){
            parent.put(curr.rigth,curr);
            q.add(curr.right);
        }
    }

    return targetNode;
}


public static burnTree(Node targetNode,HashMap<Node,Node> parent){
    if(targetNode == null) return 0;
    Queue<Node> q = new LinkedList<>();
    HashSet<Node> vis = new HashSet<>();
    q.add(targetNode);
    vis.add(targetNode);

    int time = 0;
    while(!q.isEmpty()){
        int size = q.size();
        boolean burnedThislevel = false;

        for(int i = 0;i<size;i++){
            Node curr = q.poll();
            if(curr.left != null && !vis.contains(curr.left)){
                burnedThislevel = true;
                vis.add(curr.left);
                q.add(curr.left);
            }

            if(curr.right!=null && !vis.contains(curr.right)){
                burnedThislevel = true;
                vis.add(curr.right);
                q.add(curr.right);
            }

            Node par = parent.get(curr);
            if(par!=null && !vis.contains(par)){
                burnedThislevel = true;
                vis.add(par);
                q.add(par);
            }
        }

        if(burnedThislevel) time++;
    }

    return time;
}