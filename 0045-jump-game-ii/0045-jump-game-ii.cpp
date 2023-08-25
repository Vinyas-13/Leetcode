class Solution {
public:
    int jump(vector<int>& nums) {
        int jump=0;
        int farthest=0;
        int curr=0;

        for(int i=0;i<nums.size()-1;i++)
        {
            farthest=max(farthest,i+nums[i]);
            if(curr==i)
            {
                jump++;
                curr=farthest;
            }
        }
        return jump;
    }
};