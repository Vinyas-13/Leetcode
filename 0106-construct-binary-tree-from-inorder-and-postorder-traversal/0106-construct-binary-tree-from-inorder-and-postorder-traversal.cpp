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
    TreeNode* constructTree(vector<int>postOrder,int postStart,int postEnd,vector<int>inOrder,int inStart,int inEnd,unordered_map<int,int>&mpp)
    {
        if(postStart>postEnd || inStart>inEnd)return NULL; //edge case
        
        TreeNode* root=new TreeNode(postOrder[postEnd]); //make root node
        int inRoot=mpp[root->val]; //get index of root element in inorder
        int numsLeft=inRoot-inStart; //get number of elements before root in inorder
        
        root->left=constructTree(postOrder,postStart, postStart+numsLeft-1,inOrder,inStart,inRoot-1,mpp);//recursive build left
        root->right=constructTree(postOrder,postStart+numsLeft,postEnd-1,inOrder,inRoot+1,inEnd,mpp); //recursive build right
            
        return root;
    
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mpp;

        for(int i=0;i<inorder.size();i++)//map inorder traversal node->index
        {
            mpp[inorder[i]]=i;
        }
        
        TreeNode *root=constructTree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mpp);
        return root;
    }
};