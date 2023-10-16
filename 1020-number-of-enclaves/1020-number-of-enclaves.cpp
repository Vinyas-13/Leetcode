class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&visited)
    {
        int n=grid.size();
        int m=grid[0].size();        
        if(row<0 || col<0 || row>=n || col>=m || visited[row][col]==1 || grid[row][col]==0)return;//invalid cases
        visited[row][col]=1;
        dfs(row-1,col,grid,visited);
        dfs(row,col+1,grid,visited);
        dfs(row+1,col,grid,visited);
        dfs(row,col-1,grid,visited);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();//row
        int m=grid[0].size();//col
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || i==n-1 || j==0 || j==m-1)//if its a boundary cell
                {
                    if((grid[i][j]==1) && !visited[i][j])dfs(i,j,grid,visited);  
                }
            }
        }
        
        int noEscapeCells=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==0 && grid[i][j]==1)noEscapeCells++;
            }
        }
        return noEscapeCells;
        
    }
};