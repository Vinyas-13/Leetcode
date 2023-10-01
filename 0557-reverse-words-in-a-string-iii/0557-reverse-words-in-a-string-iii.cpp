class Solution {
public:
    string reverseWords(string s) {
        string temp="";
        string ans="";
        
        for(char c:s)
        {
            if(c==' ') //if you encounter space
            {
                reverse(temp.begin(),temp.end()); //reverse the temp string
                ans+=temp+" "; //add reversed string in ans folowed by space
                temp=""; //reset temp 
            }
            else temp+=c; //else keep adding char to temp
        }
        reverse(temp.begin(),temp.end()); //reverse the last word too
        ans+=temp; //add it into final ans as well
        
        return ans;
    }
};