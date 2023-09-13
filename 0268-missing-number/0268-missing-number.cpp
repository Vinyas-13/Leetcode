class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum1=0;
        for(int i=0;i<n;i++)
        {
            sum1+=nums[i];
        }

        int sum2=n*(n+1)/2;//sum of first n natural numbers

        return sum2-sum1; //diff will give us missing element
    }
};