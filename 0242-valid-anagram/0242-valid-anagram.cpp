class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;//edge case
        
        int hash[26]={0};
        for(int i=0;i<s.size();i++)
        {
           hash[s[i]-'a']++;
           hash[t[i]-'a']--;
        }
        
        for(int i=0;i<26;i++)
        {
            if(hash[i]) return false;
        }
        return true;
    }
};