/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL|| root==p || root==q) return root; //if node is one amoung req node return value of node

        TreeNode* l=lowestCommonAncestor(root->left,p,q); //check left subtree
        TreeNode* r=lowestCommonAncestor( root->right,p,q); //check right subtree

        if(l==NULL)return r;
        else if(r==NULL)return l;
        else return root; //when one of the l or r is not null implies that node is a LCA
    }
};