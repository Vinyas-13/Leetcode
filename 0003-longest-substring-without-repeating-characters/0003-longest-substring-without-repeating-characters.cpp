class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int n=s.size();
        int maxi=0;
        unordered_set<char>st;
        
        for(;r<n;)
        {
            if(st.find(s[r])==st.end())//if char doesnt exist in set
            {
               st.insert(s[r]); //insert the char in set
               r++;//move right ptr a head
            }
            else
            {
                st.erase(s[l]);// if char already exist, erase it from set
                l++;//move left pointer a head
            }
            maxi=max(maxi,r-l);
        }
        return maxi;
    }
};