class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int goodPairs=0;
        for(int n:nums)
        {
            mpp[n]++; //store how many times no. appeared in arr
        }
        
        for(auto it:mpp)
        {
            int count=it.second;
            goodPairs+=(count*(count-1))/2; //calculate no of pairs possible using formula (count*(count-1))/2
        }
        return goodPairs;
    }
};