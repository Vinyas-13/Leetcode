class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable=0;//variable to keep count of index reached
        for(int i=0;i<nums.size();i++)
        {
            if(reachable<i)return false;//at any point if reachable is less then the curr index return false;
            reachable=max(reachable,i+nums[i]);//maximize the reachable value 
        }
        return true;

        }
};