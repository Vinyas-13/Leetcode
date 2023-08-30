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
//TC->O(N)
//SC->O(N)
class Solution {
public:
    vector<int>inorderAns;
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        while(1)
        {
            if(root!=NULL)
            {
                st.push(root);
                root=root->left;
            }
            else
            {
                if(st.empty())break;
                root=st.top();
                inorderAns.push_back(root->val);
                st.pop();
                root=root->right;

            }
        }
        return inorderAns;
    }
};