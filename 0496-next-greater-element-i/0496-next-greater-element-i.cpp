class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mpp;
        stack<int>st;
        
        for(int i=nums2.size()-1;i>=0;i--) //start traversing from last element
        {
            while(!st.empty() && st.top()<nums2[i])st.pop();//while !stack.empty and stack.top<curr, pop all elements lesser then curr
            
            if(!st.empty()) mpp[nums2[i]]=st.top(); //st.top element will be next greater element
            else mpp[nums2[i]]=-1;//if stack is empty implies there is no greater element
            
            st.push(nums2[i]);//push curr element to stack
        }
        
        for(int i=0;i<nums1.size();i++)
        {
            nums1[i]=mpp[nums1[i]];
        }
        return nums1;
    }
};