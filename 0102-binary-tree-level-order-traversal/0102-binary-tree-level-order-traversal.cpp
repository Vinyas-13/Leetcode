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
    vector<vector<int>>bfs;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return bfs;

        queue<TreeNode* > nodesQueue;
        nodesQueue.push(root);
        while(!nodesQueue.empty())
        {
            int size=nodesQueue.size();
            vector<int> ds;

            for(int i=0;i<size;i++)
            {
                TreeNode* node=nodesQueue.front();
                nodesQueue.pop();
                ds.push_back(node->val);

                if(node->left) nodesQueue.push(node->left);
                if(node->right) nodesQueue.push(node->right);
            }

            bfs.push_back(ds);
        }

        return bfs;
    }
};