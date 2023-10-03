class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=0;
        int max_1s=0;
        int count_0=0;
        
        for(;r<n;r++)
        {
            if(nums[r]==0)count_0++;
            for(;count_0>k;l++)
            {
                if(nums[l]==0)count_0--;
            }
            max_1s=max(max_1s,r-l+1);
        }
        return max_1s;
        
    }
};