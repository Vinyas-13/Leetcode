class Solution {
public:
    int noOfMissingElements(vector<int>& arr,int k,int mid)
    {
        int noOfMissing=arr[mid]-(mid+1);//calculates no of missing elements at mid
        return noOfMissing;     
    }
    
    int findKthPositive(vector<int>& arr, int k) {
        int low=0;
        int high=arr.size()-1;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(noOfMissingElements(arr,k,mid)>=k)high=mid-1;
            else low=mid+1;
        }
        
        return low+k;//refer derivation
    }
};