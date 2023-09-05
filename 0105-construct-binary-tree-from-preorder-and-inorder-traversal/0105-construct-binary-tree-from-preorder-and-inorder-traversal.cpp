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
    TreeNode* constructTree(vector<int> &preorder,vector<int> &inorder, int preStart,int preEnd,int inStart, int inEnd, unordered_map<int,int>&mpp)
    {
        if(preStart>preEnd || inStart>inEnd)return NULL;//edge case
        
        TreeNode* root= new TreeNode(preorder[preStart]);
        
        int elem = mpp[root->val]; //get the index for root element
        int numsLeft=elem-inStart;//get the number of elements before root in inorder
        
        root->left=constructTree(preorder,inorder,preStart+1,preStart+numsLeft,inStart,elem-1,mpp);//recursive build left 
        root->right=constructTree(preorder,inorder,preStart+numsLeft+1,preEnd,elem+1,inEnd,mpp);//recursive build right
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) { 
        unordered_map<int,int> mpp;
        
        for(int i=0;i<inorder.size();i++) //map the inorder traversal node->index
        {
            mpp[inorder[i]]=i;
        }
       
        TreeNode* root=constructTree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1,mpp);
        return root;
        
    }
};