//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int>Q;
        vector<int>visited(V,0);//make visited array of size nodes and mark them all unvisited
        Q.push(0);//push starting node
        visited[0]=1;//mark it as visited
        vector<int>bfs;
        while(!Q.empty()) //untill Q is not empty
        {
            int node=Q.front();
            Q.pop();
            bfs.push_back(node);
            
            for(auto it:adj[node]) //push all elements which are neighbour of curr node
            {
                if(!visited[it])//if not visited
                {
                    visited[it]=1; 
                    Q.push(it);
                }
            }
        }
        return bfs;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends