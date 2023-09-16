class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    int n = nums.size(); // size of the nums
    int low = 0, high = n-1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (nums[mid] >= target)// maybe an answer
        {
            ans = mid;
            high = mid - 1;//look for smaller index on the left
        }
        else low = mid + 1; // look on the right
    }
    return ans;
    }
};