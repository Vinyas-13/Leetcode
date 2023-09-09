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
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr=root; //make a node that points to root
        if(root==NULL)return new TreeNode(val); //edge case
        while(1)
        {
            if(root->val>val)
            {
                if(root->left!=NULL)root=root->left; //attach the node to extreme left
                else
                {
                    root->left=new TreeNode(val);
                    break;
                }
            }
            else
            {
                if(root->right!=NULL)root=root->right; //attach the node to extreme right
                else
                {
                    root->right=new TreeNode(val);
                    break;
                }
            }
        }
        return curr;
    }
};