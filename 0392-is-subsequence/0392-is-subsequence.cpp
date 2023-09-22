class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j=0;
        for(int i=0;i<t.size() and j<s.size();i++)
        {
            if(t[i]==s[j])j++;
        }
        return (j==s.size());
    }
};