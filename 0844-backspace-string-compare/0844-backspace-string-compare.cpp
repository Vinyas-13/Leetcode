class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>s1;
        stack<char>s2;
        
        for(auto i: s)
        {
            if(i=='#' && s1.empty())continue;
            if(i=='#')s1.pop();
            else s1.push(i);
        }
       
        for(auto i: t)
        {
            if(i=='#' && s2.empty())continue;
            if(i=='#')s2.pop();
            else s2.push(i);
        }
        return s1==s2;    
    }
};