/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> largestValues(TreeNode root) {
        List<Integer> ans= new ArrayList<>();
        
        if(root==null)return ans;
        
        Queue<TreeNode> Q=new LinkedList<>();
        Q.add(root);
        
        while(!Q.isEmpty())
        {
            int maxi=Integer.MIN_VALUE;
            int levelSize=Q.size();
            
            while(levelSize--!=0)
            {
                TreeNode node=Q.poll();
                maxi=Math.max(maxi,node.val);
                
                if(node.left!=null)Q.add(node.left);
                if(node.right!=null)Q.add(node.right);
            }
            ans.add(maxi);
            
        }
        
       return ans; 
    }
}