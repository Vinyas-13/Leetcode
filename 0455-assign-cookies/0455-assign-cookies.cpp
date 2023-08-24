class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
  int n=g.size();//no of childrens
  int m=s.size(); //no of cookies

  int i=0,j=0; //two pointers to traverse the vector
  int satisfiedChildrens=0; //to store the count
  sort(g.begin(),g.end()); //sort both the vectors
  sort(s.begin(),s.end());

  while(i<n && j<m) //while any one of them becomes zero
  {
    if(g[i]<=s[j]) //if greed of child is satisfied
    {
      satisfiedChildrens++; //increase the count
      i++; //move to next child
    }

    j++; //move to next cookie size
  }
        
    return satisfiedChildrens;
    }
};