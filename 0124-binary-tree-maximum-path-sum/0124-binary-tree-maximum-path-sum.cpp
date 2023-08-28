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
    int maxSum(TreeNode* node,int &maximumSum)
    {
        if(node==NULL) return 0;//base case
        int left=max(0,maxSum(node->left,maximumSum));//ignores all nodes that adds negtive sum
        int right=max(0,maxSum(node->right,maximumSum));//ignores all nodes that adds negtive sum
        maximumSum=max(maximumSum,node->val+left+right);
        return node->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        int maximumSum=INT_MIN;
        maxSum(root,maximumSum);
        return maximumSum;  
    }
};