class Solution {
public:
    //Moore's Voting Algorithm
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0;
        int cnt2=0;
        int el1=0;
        int el2=0;
        int n=nums.size();
        vector<int>majElements;
        
        for(int i=0;i<n;i++)
        {
            if(cnt1==0 && nums[i]!=el2)
            {
                el1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0 && nums[i]!=el1)
            {
                el2=nums[i];
                cnt2=1;
            }
            else if(nums[i]==el1)cnt1++;
            else if(nums[i]==el2)cnt2++;
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        
        cnt1=0;
        cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==el1)cnt1++;
            else if(nums[i]==el2)cnt2++;
        }
        
        int minMaj=n/3+1;
        if(cnt1>=minMaj)majElements.push_back(el1);
        if(cnt2>=minMaj)majElements.push_back(el2);
        return majElements; 
    }
    
};