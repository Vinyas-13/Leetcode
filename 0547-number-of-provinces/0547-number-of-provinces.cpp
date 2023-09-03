class Solution {
public:
    void dfs(int i,vector<int>adjList[],vector<int>&visited)
    {
        visited[i]=1;
        for(auto it:adjList[i])
        {
            if(!visited[it]) dfs(it,adjList,visited);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>adjList[n];
        
        for(int i=0;i<isConnected.size();i++) //creating adj list from adj matrix
        {
            for(int j=0;j<isConnected[0].size();j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i); 
                }
            }
        }
        
        vector<int>visited(n,0);
        int provinces=0;
        
        for(int i=0;i<n;i++)//check for every node
        {
            if(!visited[i]) //if node is not visited
            {
                provinces++; //increments whenever connected component appears
                dfs(i,adjList,visited); 
            }
        }
        return provinces;
        
        
        
    }
};