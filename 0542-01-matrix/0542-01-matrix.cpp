class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m=mat.size();
    int n=mat[0].size();
    vector<vector<int>> visited(m,vector<int>(n,0));
    queue<pair<pair<int,int>,int>>Q; //(i,j),distance;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mat[i][j]==0)
            {
                Q.push({{i,j},0}); //if ele is 0 push it in Q with dist as 0
                visited[i][j]=1; //mark it as visited
            }    
        }
    }
    int delrow[]={-1,0,+1,0};
    int delcol[]={0,+1,0,-1};
    while(!Q.empty())
    {
        int row=Q.front().first.first;
        int col=Q.front().first.second;
        int d=Q.front().second;
        Q.pop();
        mat[row][col]=d;

        for(int i=0;i<4;i++)//check in all 4 direction
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && visited[nrow][ncol]==0)//if cell id valid and not visited
            {
                visited[nrow][ncol]=1;
                Q.push({{nrow,ncol},d+1});
            }
        }

    } 
    return mat;
    }
};