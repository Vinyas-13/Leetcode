class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        
        while(left<right)
        {
            if((nums[left]&1)==0){left++; continue;}//if even increase left ptr
            else if ((nums[right]&1)==1){right--;continue;}//if odd move right ptr
            else {swap(nums[left],nums[right]);left++;right--;}//else swap elements
            cout<<left<<right<<endl;
        }
        return nums;
    }
};