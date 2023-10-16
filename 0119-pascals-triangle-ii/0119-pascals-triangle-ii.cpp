class Solution {
public:
    int nCr(int n,int r)
    {
        long long res=1;
        for(int i=0;i<r;i++)
        {
            res*=(n-i);
            res/=(i+1);
        }
        return res;
    }

    vector<int> getRow(int rowIndex) {
      vector<int>pascalCol; 
      for(int i=1;i<=rowIndex+1;i++)
      {
          pascalCol.push_back(nCr(rowIndex,i-1));
      } 
      return pascalCol; 
    }
};