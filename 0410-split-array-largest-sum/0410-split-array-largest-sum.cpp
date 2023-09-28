class Solution {
public:
    
    int isPossible(vector<int>& nums,int m,long mid)
    {
        int noOfSubnumsay=1;
        int currSum=0;

        for(int i=0;i<nums.size();i++)
        {
            if(currSum+nums[i]<=mid)
            {
                currSum+=nums[i];
            }
            else
            {
                noOfSubnumsay++;
                currSum=nums[i];
            }
        }
        return noOfSubnumsay;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n)return -1;    //edge case
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,nums[i]);
            sum+=nums[i]; 
        }
        int low=maxi;
        int high=sum;

        while(low<=high)
        {
            long mid=(low+high)/2;
            int noOfSubnumsay=isPossible(nums,k,mid);
            if(noOfSubnumsay>k)//if no of subnumsay is greater eliminate left half
            {   
                low=mid+1;
            }
            else high=mid-1;
        }
        return low;    
    }
};