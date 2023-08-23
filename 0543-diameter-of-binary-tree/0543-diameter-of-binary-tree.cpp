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
    int findDiameter(TreeNode*root , int &maxi)
    {
        //base case
        if(root == NULL) return 0;

        int left=findDiameter(root->left,maxi);
        int right=findDiameter(root->right,maxi);

        maxi=max(maxi,right+left);
        return 1+max(left,right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        int height=findDiameter(root ,diameter);
        return diameter;
    }
};