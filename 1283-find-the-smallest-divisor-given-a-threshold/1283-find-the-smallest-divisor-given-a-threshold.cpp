class Solution {
public:
    int calculateThreshold(vector<int>& nums,long mid)
    {
        int divSum=0;
        for(int i=0;i<nums.size();i++)
        {
            divSum+=ceil(((double)nums[i])/mid); //gets the sum of divisors when divided by mid
        }
        return divSum;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            maxi=max(maxi,nums[i]);
        }
        int low=1;
        int high=maxi;
        
        while(low<=high)
        {
            long mid=(low+high)/2;
            if(calculateThreshold(nums,mid)<=threshold) //if divisors sum is less then threshold then eliminate right half
            {
                high=mid-1;
            }
            else low=mid+1;            
        }
        return low;
    }
};