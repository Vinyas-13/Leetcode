class Solution {
private:
    void dfs(int row,int col,int initialColor,int newColor,vector<vector<int>> &dupImage,int delRow[],int delCol[])
    {
        dupImage[row][col]=newColor; //color the pixel with new color
        int n=dupImage.size();
        int m=dupImage[0].size();

        for(int i=0;i<4;i++) //check in four direction
        {
            int newRow=row+delRow[i];
            int newCol=col+delCol[i];

            if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && dupImage[newRow][newCol]!=newColor && dupImage[newRow][newCol]==initialColor) //check if pixel is valid && pixel has intialcolor && its not coloured with newColor
            {
                dfs(newRow,newCol,initialColor,newColor,dupImage,delRow,delCol);//color the adjacent pixel recursively
            }
        }
         
    }  
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int initialColor=image[sr][sc]; //initial color
        
        vector<vector<int>> dupImage=image; //duplicate of image
        int delRow[]={-1,0,+1,0}; //stores fourdirectional deltaRow values
        int delCol[]={0,+1,0,-1}; //stores fourdirectional deltaCol values
        
        dfs(sr,sc,initialColor,color,dupImage,delRow,delCol);
        return dupImage;
        
    }
};