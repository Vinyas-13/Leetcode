class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        if(nums[0]>nums[1])return 0; //edge case
        if(nums[n-1]>nums[n-2])return n-1; //edge case
        
        int low=1;
        int high=n-2;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid; //if peak is at mid
            else if(nums[mid]>nums[mid-1])low=mid+1; //if mid is part of increasing curve,eliminate left half
            else high=mid-1;//else eliminate right half
        }
        return -1;
    }
};