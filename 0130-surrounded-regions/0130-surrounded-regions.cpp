class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& visited )
    {
        if(row<0 || col<0 || row>=board.size() || col>=board[0].size() || visited[row][col]==1 || board[row][col]=='X')  //all invalid case
        return;

        visited[row][col]=1;
        
        dfs(row+1, col, board,visited); //↓
        dfs(row,col+1,board,visited); //→
        dfs(row-1,col,board,visited); //↑
        dfs(row,col-1,board,visited); //←

    }
    void solve(vector<vector<char>>& board) 
    {

        int n=board.size();
        int m=board[0].size();


        vector<vector<int>> visited(n, vector<int>(m,0));
      

      //check all boundaries
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
          {
              if(i==0 || j==0 || i==n-1 || j==m-1)
              {
                  if(visited[i][j]!=1)
                  {
                      dfs(i,j,board,visited);
                  }
              }
          }
      }

//converting the unmarked Os to Xs

      for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
          {
              if(board[i][j]=='O' && visited[i][j]!=1)
              board[i][j]='X';
          }
      }
        
    }
};