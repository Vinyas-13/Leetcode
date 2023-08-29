/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//Time Complexity -> O(log(n)^2)
//Space Complexity ->O(log n)

class Solution {
public:
    int leftHeight(TreeNode* node)
    {
        int Lheight=0;
        while(node)
        {
            Lheight++;
            node=node->left;
        }
        return Lheight;
    }
    
    int rightHeight(TreeNode* node)
    {
        int Rheight=0;
        while(node)
        {
            Rheight++;
            node=node->right;
        }
        return Rheight;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        
        int lh=leftHeight(root);
        int rh=rightHeight(root);
        
        if(lh==rh)return (1<<lh)-1; //if lh==rh then no of nodes=2^h -1
        
        int leftNode=countNodes(root->left) ;
        int rightNode=countNodes(root->right);
        
        return 1+leftNode+rightNode; //else no of nodes=1+lh+rh
    }
};