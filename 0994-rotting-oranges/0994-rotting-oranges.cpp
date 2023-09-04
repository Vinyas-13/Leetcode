class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> Q; //Queue<{row,col},time>
        vector<vector<int>> dupGrid=grid; //duplicate of grid
        int countFresh=0;
        int n=dupGrid.size();
        int m=dupGrid[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dupGrid[i][j]==2) 
                {
                    Q.push({{i,j},0});//insert all rotten oranges in Queue with t=0
                }
                if(dupGrid[i][j]==1) countFresh++;//count fresh orange
            }
        }
        int maxiTime=0;
        int delRow[]={-1,0,+1,0}; //4 directional row Traversal 
        int delCol[]={0,+1,0,-1}; //4 directional col Traversal
        int count=0;
        
        while(!Q.empty())
        {
            auto it = Q.front(); // get the element form queue
            int r=it.first.first;
            int c=it.first.second;
            int time=it.second;
            
            Q.pop();
            
            for(int i=0;i<4;i++) //check in all 4 direction
            {
                int newRow=r+delRow[i];
                int newCol=c+delCol[i];
                
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && dupGrid[newRow][newCol]!=2 &&dupGrid[newRow][newCol]==1) //if cell is valid and contains fresh orange
                {
                    dupGrid[newRow][newCol]=2; //mark it as rotten orange
                    Q.push({{newRow,newCol},time+1}); //insert the cell in Q with t=t+1
                    count++; //to keep count if all fresh orange has rotten at the end
                }
                
            }
            maxiTime=max(maxiTime,time); //maximize the time
            
        }
        if(countFresh!=count)return -1; //if all fresh oranges are not rotten return -1
        return maxiTime;
    }
};