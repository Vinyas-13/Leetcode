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
    vector<vector<int>> verticalOrderAns;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;// <verticalAxis,<level,multinodes>>
        queue <pair<TreeNode*,pair<int,int>>> nodesQueue; //(node,verticalAxis,level)
        nodesQueue.push({root,{0,0}});//push root node in Q

        while(!nodesQueue.empty()) //Untill Q is empty
        {
            auto i=nodesQueue.front(); //get the front element of Q 
            nodesQueue.pop(); //remove the element form Q
            TreeNode* node=i.first; //store the node
            int y=i.second.first; //store verticalAxis
            int x=i.second.second; //store the level

            nodes[y][x].insert(node->val); //store in map
            if(node->left) nodesQueue.push({node->left,{y-1,x+1}}); //if there exists left subtree push it into Q,reduce the vertical axis by 1,increase the level by 1
            if(node->right) nodesQueue.push({node->right,{y+1,x+1}}); //if there exists right subtree push it into Q,increase the vertical axis by 1,increase the level by 1
        }

        for(auto i:nodes) //traverse in map
        {
            vector<int>col;
            for(auto j:i.second) //for every verticalAxis
            {
                col.insert(col.end(),j.second.begin(),j.second.end()); //start from the end of col, and insert the multiset
            }
            verticalOrderAns.push_back(col); //store the traversal in vector
        }
        return verticalOrderAns;
        
    }
};