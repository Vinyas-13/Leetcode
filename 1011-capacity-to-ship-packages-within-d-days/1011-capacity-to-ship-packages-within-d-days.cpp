class Solution {
public:
    int minShipCapacity(vector<int>& weights,int mid)
    {
        int noOfDays=1;
        int currWeight=0;
        for(int i=0;i<weights.size();i++)
        {
             if(currWeight+weights[i]>mid) //if weights exceed
             {
                noOfDays++; //increase the no of days
                currWeight=weights[i]; //update the curr weight
             }
             else
             {
                currWeight+=weights[i];
             }
        }
        return noOfDays;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<weights.size();i++)
        {
            maxi=max(maxi,weights[i]);
            sum+=weights[i];
        }
        int low=maxi;
        int high=sum;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(minShipCapacity(weights,mid)<=days)
            {
                high=mid-1;
            }
            else low=mid+1;   
        }
        return low;
    }
};