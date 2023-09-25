class Solution {
public:
    char findTheDifference(string s, string t) {
        char missing=0;
        for(auto it:s)
        {
            missing=missing^it;
        }
        
        for(auto it:t)
        {
            missing=missing^it;
        }
        return missing;
    }
};