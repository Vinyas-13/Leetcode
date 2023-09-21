class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0]; //edge case
        if(nums[0]!=nums[1]) return nums[0]; //edge case
        if(nums[n-1]!=nums[n-2])return nums[n-1]; //edge case
        
        int low=1;
        int high=n-2;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])return nums[mid]; //if unique is at mid
            
            else if((mid%2==0 && nums[mid]==nums[mid+1]) or (mid%2==1 && nums[mid]==nums[mid-1])) low=mid+1; //eliminate left half
            
            else high=mid-1; //eliminate right half
        }
        return -1;
    }
};