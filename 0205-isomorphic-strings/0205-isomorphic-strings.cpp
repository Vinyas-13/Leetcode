class Solution {
public:
    bool isIsomorphic(string s, string t) {
    if(s.size()!=t.size()) return false;
    
    int mp1[256]={0};//hash array mp1
    int mp2[256]={0};//hash array mp2

    for(int i=0;i<s.size();i++)
    {
        if(!mp1[s[i]] &&!mp2[t[i]])//if there exist no existing values in both hash array
        {
            mp1[s[i]]=t[i];//store ascii of t[i] in hash array of s
            mp2[t[i]]=s[i];//store ascii of s[i] in hash array of t
        }
        else if(mp1[s[i]]!=t[i]) return false; //if ascii of t[i] is not present in hash array s[i] return false 
    }
    return true;
    }
};