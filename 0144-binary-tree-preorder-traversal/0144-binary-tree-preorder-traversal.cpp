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

 //Iterative Solution
 //Space Complexity->O(N)
 //Time Complexity->O(N)
class Solution {
public:
    vector<int>preorderAns;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL) return preorderAns;
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty())
        {
            TreeNode *node=st.top();
            preorderAns.push_back(node->val);
            st.pop();
            if(node->right!=NULL) st.push(node->right);
            if(node->left!=NULL) st.push(node->left);
        }
    return preorderAns;
    }
};