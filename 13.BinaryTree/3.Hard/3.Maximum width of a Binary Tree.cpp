// https://leetcode.com/problems/maximum-width-of-binary-tree/description/


/*
 * Time Complexity:  O(N)
 *   - Each node is visited exactly once in the BFS traversal.
 * Space Complexity: O(N)
 *   - Queue stores up to O(N) nodes in the worst case (for a full level).
 */


int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        long long ans = 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while (!q.empty()) {
            int n = q.size();
            long long start = q.front().second;
            long long end = q.back().second;
            ans = max(ans,end-start+1);

            for (int i = 0; i < n; i++) {
        
           auto [node,lvl] = q.front();
            
                q.pop();
long long idx = lvl - start; 
             
                if (node->left)
                    q.push({node->left,(long long)2*idx+1});
                if (node->right)
                    q.push({node->right,(long long)2*idx+2});
            }
          
        }
        return ans;
    }


    // ===== java ====

     public int widthOfBinaryTree(TreeNode root) {
        if(root == null) return 0 ;
        long  ans = 0;
        Queue<Pair<TreeNode,Long>> q = new LinkedList<>();
        q.offer(new Pair<>(root,0L));
          while(!q.isEmpty()){
            int size = q.size();
            long start = q.peek().getValue();
            long end = ((LinkedList<Pair<TreeNode,Long>>) q).getLast().getValue();
            ans = Math.max(ans ,  end -start+1);

            for(int i = 0;i<size;i++){
                Pair<TreeNode,Long> current = q.poll();
                TreeNode node = current.getKey();
                long index = current.getValue() - start;

                if(node.left!=null)
                q.offer(new Pair<>(node.left,2*index+1));
                if(node.right!=null)
                q.offer(new Pair<>(node.right,2*index+2));
            }
          }

          return (int)ans;

    }