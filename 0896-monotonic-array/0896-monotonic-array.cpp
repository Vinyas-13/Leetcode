class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increasing=false;
        bool decreasing=false;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]<nums[i])increasing=true; //if curr ele is greater than prev ele set increaseFlag as true 
            else if(nums[i-1]>nums[i])decreasing=true; //if curr ele is less than prev ele set decreaseFlag as true
            
            if(increasing && decreasing)return false; //if both flags are true then return its not monotonic
        }
        return true;
    }
};