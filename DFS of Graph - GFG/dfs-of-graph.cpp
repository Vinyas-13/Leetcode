//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int>dfsAns;
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node,vector<int> &visited,vector<int> adj[])
    {
        visited[node]=1; //mark node as visited
        dfsAns.push_back(node); //enter into ds
        for(auto it:adj[node]) //enter neighbour nodes
        {
            if(!visited[it]) dfs(it,visited,adj); //if not visited, call dfs(node)
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) 
    {
    vector<int>visited(V,0);
    visited[0]=1; //mark starting node as visited
    dfs(0,visited,adj);
    return dfsAns;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends